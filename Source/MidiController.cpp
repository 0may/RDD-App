/*
  ==============================================================================

    MidiController.cpp
    Created: 18 Jun 2020 10:21:26am
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "MidiController.h"
#include "MidiInputDeviceSelectorComponent.h"
#include "MidiOutputDeviceSelectorComponent.h"
#include "XYInputComponent.h"
#include "AngleInputComponent.h"
#include "MainManager.h"

using namespace rdd;

MidiController::MidiController() {
	_configured = false;
	_loggingEnabled = false;
	_midiClock = 0;
	_midiClockStarted = false;
}


MidiController::~MidiController() {

}


bool MidiController::config(const MidiSettings& settings) {
	_configured = true;
	_midiSettings = settings;

	return true;
}



void MidiController::enableLogging(bool enable) {
	_loggingEnabled = enable;
}


bool MidiController::addMidiInput(String midiInputIdentifier) {

	if (_midiInputIdentifiers.find(midiInputIdentifier) == _midiInputIdentifiers.end()) {

		if (!_deviceManager.isMidiInputDeviceEnabled(midiInputIdentifier))
			_deviceManager.setMidiInputDeviceEnabled(midiInputIdentifier, true);

		_deviceManager.addMidiInputDeviceCallback(midiInputIdentifier, this);

		_midiInputIdentifiers.insert(midiInputIdentifier);

		return true;
	}
	else
		return false;
}


bool MidiController::removeMidiInput(String midiInputIdentifier) {

	std::set<String>::iterator it = _midiInputIdentifiers.find(midiInputIdentifier);

	if (it != _midiInputIdentifiers.end()) {
		_deviceManager.removeMidiInputCallback(midiInputIdentifier, this);
		_midiInputIdentifiers.erase(it);
		return true;
	}
	else
		return false;
}


bool MidiController::addMidiOuput(String midiOutputIdentifier) {

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		if (_midiOutputs[i]->getIdentifier() == midiOutputIdentifier)
			return false;
	}


	auto outputsInfo = MidiOutput::getAvailableDevices();

	for (auto output : outputsInfo) {
		if (output.identifier == midiOutputIdentifier) {
			_midiOutputs.push_back(MidiOutput::openDevice(midiOutputIdentifier));
			return true;
		}
	}
	
	return false;
}


bool MidiController::removeMidiOutput(String midiOutputIdentifier) {

	for (std::vector<std::unique_ptr<MidiOutput>>::iterator it = _midiOutputs.begin(); it != _midiOutputs.end(); it++) {
		if ((*it)->getIdentifier() == midiOutputIdentifier) {
			_midiOutputs.erase(it);
			return true;
		}
	}

	return false;
}


bool MidiController::startCommand(MidiSettings::BotCommand cmd, uint8 velocity) {
	
	if (!_configured)
		return false;


	MidiMessage m = MidiMessage::noteOn(_midiSettings.getChannel(), _midiSettings.getNote(cmd), velocity);
	
	MainManager::instance().midiSequenceManager().receiveMidiMessage(m);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: NoteOn(%d,%d,%d)", m.getChannel(), m.getNoteNumber(), velocity);
		Logger::writeToLog(_logMsg);
	}

	return true;
}


bool MidiController::stopCommand(MidiSettings::BotCommand cmd) {

	if (!_configured)
		return false;

	MidiMessage m = MidiMessage::noteOff(_midiSettings.getChannel(), _midiSettings.getNote(cmd));

	MainManager::instance().midiSequenceManager().receiveMidiMessage(m);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: NoteOff(%d,%d,0)", m.getChannel(), m.getNoteNumber());
		Logger::writeToLog(_logMsg);
	}

	return true;
}


bool MidiController::sendParameter(MidiSettings::BotParameter param, uint8 value) {

	if (!_configured)
		return false;

	MidiMessage m = MidiMessage::controllerEvent(_midiSettings.getChannel(), _midiSettings.getCC(param), value);

	MainManager::instance().midiSequenceManager().receiveMidiMessage(m);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: CC(%d,%d,%d)", m.getChannel(), m.getControllerNumber(), value);
		Logger::writeToLog(_logMsg);
	}

	return true;
}


void MidiController::handleIncomingMidiMessage(MidiInput* /*source*/, const MidiMessage& message) {
	// ....

	if (message.isMidiStart()) {

		//Logger::writeToLog("Midi Start received");
		_midiClock = 0;
		_midiClockStarted = true;
	}
	else if (message.isMidiStop()) {

		_midiClockStarted = false;
		//Logger::writeToLog("Midi Stop received");
	} 
	else if (message.isMidiContinue()) {

		_midiClockStarted = true;
		//Logger::writeToLog("Midi Continue received");
	}
	else if (message.isMidiClock()) {

		if (_midiClockStarted)
			_midiClock++;
	}
}

void MidiController::changeListenerCallback(ChangeBroadcaster* source) {

	// ### QUICK AND DIRTY: remove all inputs and add all selected ones.
	//     TODO: only remove deselected and add newly selected.

	auto midiInSelector = dynamic_cast<MidiInputDeviceSelectorComponent*>(source);

	if (midiInSelector) {
		
		for (std::set<String>::iterator it = _midiInputIdentifiers.begin(); it != _midiInputIdentifiers.end(); it++) {
			_deviceManager.removeMidiInputCallback(*it, this);
		}
		_midiInputIdentifiers.clear();


		auto selectedInputs = midiInSelector->getSelectedDeviceIdentifiers();

		for (std::set<String>::iterator it = selectedInputs.begin(); it != selectedInputs.end(); it++) {
			addMidiInput(*it);
		}

		return;
	}



	// ### QUICK AND DIRTY: remove all outputs and add all selected ones.
	//     TODO: only remove deselected and add newly selected.

	auto midiOutSelector = dynamic_cast<MidiOutputDeviceSelectorComponent*>(source);

	if (midiOutSelector) {
		auto selectedOutputs = midiOutSelector->getSelectedDeviceIdentifiers();

		_midiOutputs.clear();

		for (std::set<String>::iterator it = selectedOutputs.begin(); it != selectedOutputs.end(); it++) {
			addMidiOuput(*it);
		}

		return;
	}

	auto xyInput = dynamic_cast<XYInputComponent*>(source);

	if (xyInput) {


		if (xyInput->getIdentifier() == "Translation") {

			if (xyInput->hasInput()) {

				auto input = xyInput->getMappedInput();

				if (input.x < 0.0f) {
					startCommand(rdd::MidiSettings::STRAFE_LEFT, (uint8)(abs(input.x)*127.0 + 0.5));
				}
				else if (input.x > 0.0f) {
					startCommand(rdd::MidiSettings::STRAFE_RIGHT, (uint8)(input.x*127.0 + 0.5));
				}
				else {

					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.x < 0.0f)
						stopCommand(rdd::MidiSettings::STRAFE_LEFT);
					else if (inputPrev.x > 0.0f)
						stopCommand(rdd::MidiSettings::STRAFE_RIGHT);
				}

				if (input.y < 0.0f) {
					startCommand(rdd::MidiSettings::MOVE_FORWARD, (uint8)(abs(input.y)*127.0 + 0.5));
				}
				else if (input.y > 0.0f) {
					startCommand(rdd::MidiSettings::MOVE_BACKWARD, (uint8)(input.y*127.0 + 0.5));
				}
				else {

					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.y < 0.0f)
						stopCommand(rdd::MidiSettings::MOVE_FORWARD);
					else if (inputPrev.y > 0.0f)
						stopCommand(rdd::MidiSettings::MOVE_BACKWARD);
				}

			}
			else {

				auto inputPrev = xyInput->getMappedInputPrevious();

				if (inputPrev.x < 0.0f)
					stopCommand(rdd::MidiSettings::STRAFE_LEFT);
				else if (inputPrev.x > 0.0f)
					stopCommand(rdd::MidiSettings::STRAFE_RIGHT);

				if (inputPrev.y < 0.0f)
					stopCommand(rdd::MidiSettings::MOVE_FORWARD);
				else if (inputPrev.y > 0.0f)
					stopCommand(rdd::MidiSettings::MOVE_BACKWARD);
			}
		}
		else if (xyInput->getIdentifier() == "Rotation") {

			if (xyInput->hasInput()) {

				auto input = xyInput->getMappedInput();

				if (input.x < 0.0f) {
					startCommand(rdd::MidiSettings::ROTATE_LEFT, (uint8)(abs(input.x)*127.0 + 0.5));
				}
				else if (input.x > 0.0f) {
					startCommand(rdd::MidiSettings::ROTATE_RIGHT, (uint8)(input.x*127.0 + 0.5));
				}
				else {

					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.x < 0.0f)
						stopCommand(rdd::MidiSettings::ROTATE_LEFT);
					else if (inputPrev.x > 0.0f)
						stopCommand(rdd::MidiSettings::ROTATE_RIGHT);
				}
			}
			else {
				auto inputPrev = xyInput->getMappedInputPrevious();

				if (inputPrev.x < 0.0f)
					stopCommand(rdd::MidiSettings::ROTATE_LEFT);
				else if (inputPrev.x > 0.0f)
					stopCommand(rdd::MidiSettings::ROTATE_RIGHT);
			}
		}

		else if (xyInput->getIdentifier() == "Speaker Rotation") {

			if (xyInput->hasInput()) {

				auto input = xyInput->getMappedInput();

				if (input.y < 0.0f) {
					startCommand(rdd::MidiSettings::SPEAKER_UP, (uint8)(abs(input.y)*127.0 + 0.5));
				}
				else if (input.y > 0.0f) {
					startCommand(rdd::MidiSettings::SPEAKER_DOWN, (uint8)(input.y*127.0 + 0.5));
				}
				else {
					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.y < 0.0f)
						stopCommand(rdd::MidiSettings::SPEAKER_UP);
					else if (inputPrev.y > 0.0f)
						stopCommand(rdd::MidiSettings::SPEAKER_DOWN);
				}
			}
			else {
				auto inputPrev = xyInput->getMappedInputPrevious();

				if (inputPrev.y < 0.0f)
					stopCommand(rdd::MidiSettings::SPEAKER_UP);
				else if (inputPrev.y > 0.0f)
					stopCommand(rdd::MidiSettings::SPEAKER_DOWN);
			}
		}
	}



	auto angleInput = dynamic_cast<AngleInputComponent*>(source);

	if (angleInput) {
		auto input = angleInput->getMappedAngle();

		if (input < 90.0f) {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q1, (uint8)(input / 90.0 * 128.0));
		}
		else if (input < 180.0f) {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q2, (uint8)((input - 90.0f) / 90.0 * 128.0));
		}
		else if (input < 270.0f) {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q3, (uint8)((input - 180.0f) / 90.0 * 128.0));
		}
		else {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q4, (uint8)((input - 270.0f) / 90.0 * 128.0));
		}
	}

}


void MidiController::timerCallback() {
	MidiMessage m = MidiMessage::midiClock();

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	//if (_loggingEnabled) {
	//	Logger::writeToLog("Midi Send: Clock");
	//}
}