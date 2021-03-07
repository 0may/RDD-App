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
#include "RobotsManager.h"

using namespace rdd;

MidiController::MidiController() {
	//_configured = false;
	_loggingEnabled = false;
	_midiClock = 0;
	_midiClockStarted = false;

	_wpIdxResend.resend = 0;
}


MidiController::~MidiController() {

}

//
//bool MidiController::config(const MidiSettings& settings) {
//	_configured = true;
//	_midiSettings = settings;
//
//	return true;
//}



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


bool MidiController::startCommand(MidiSettings::BotCommand cmd, uint8 velocity, const MidiSettings& settings) {
	
	//if (!_configured)
	//	return false;


	MidiMessage m = MidiMessage::noteOn(settings.getChannel(), settings.getNote(cmd), velocity);
	
	//MainManager::instance().midiSequenceManager().receiveMidiMessage(m);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	// update resend control items
	if (settings.getNumResends() > 0) {

		std::map<MidiSettings::BotCommand, MidiMessageResend>::iterator it = _mapCmdResend.find(cmd);

		if (it != _mapCmdResend.end()) {
			it->second.resend = settings.getNumResends();
			it->second.msg = m;
		}
		else {
			MidiMessageResend r;
			r.resend = settings.getNumResends();
			r.msg = m;
			_mapCmdResend.insert(std::pair<MidiSettings::BotCommand, MidiMessageResend>(cmd, r));
		}
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: NoteOn(%d,%d,%d)", m.getChannel(), m.getNoteNumber(), velocity);
		Logger::writeToLog(_logMsg);
	}

	return true;
}


bool MidiController::stopCommand(MidiSettings::BotCommand cmd, const MidiSettings& settings) {

	//if (!_configured)
	//	return false;

	MidiMessage m = MidiMessage::noteOff(settings.getChannel(), settings.getNote(cmd));

	//MainManager::instance().midiSequenceManager().receiveMidiMessage(m);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	// update resend control items
	if (settings.getNumResends() > 0) {

		std::map<MidiSettings::BotCommand, MidiMessageResend>::iterator it = _mapCmdResend.find(cmd);

		if (it != _mapCmdResend.end()) {
			it->second.resend = settings.getNumResends();
			it->second.msg = m;
		}
		else {
			MidiMessageResend r;
			r.resend = settings.getNumResends();
			r.msg = m;
			_mapCmdResend.insert(std::pair<MidiSettings::BotCommand, MidiMessageResend>(cmd, r));
		}
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: NoteOff(%d,%d,0)", m.getChannel(), m.getNoteNumber());
		Logger::writeToLog(_logMsg);
	}

	return true;
}


bool MidiController::sendParameter(MidiSettings::BotParameter param, uint8 value, const MidiSettings& settings) {

	//if (!_configured)
	//	return false;

	MidiMessage m = MidiMessage::controllerEvent(settings.getChannel(), settings.getCC(param), value);

	//MainManager::instance().midiSequenceManager().receiveMidiMessage(m);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}


	// update resend control items
	if (settings.getNumResends() > 0) {
		std::map<MidiSettings::BotParameter, MidiMessageResend>::iterator it;


		// SPEAKER_POSITION_XX parameters should not be resend if another SPEAKER_POSITION_XY
		// is parameter is sent, as the all affect a single real value, the speaker's angle.
		// Use only one MidiMessageResend item for all SPEAKER_POSITION_ parameters represented 
		// by the key SPEAKER_POSITION_Q1
		if (param == MidiSettings::SPEAKER_POSITION_Q1
			|| param == MidiSettings::SPEAKER_POSITION_Q2
			|| param == MidiSettings::SPEAKER_POSITION_Q3
			|| param == MidiSettings::SPEAKER_POSITION_Q4
			|| param == MidiSettings::SPEAKER_POSITION_RESET)
		{
			it = _mapParamResend.find(MidiSettings::SPEAKER_POSITION_Q1);

			if (it != _mapParamResend.end()) {
				it->second.resend = settings.getNumResends();
				it->second.msg = m;
			}
			else {
				MidiMessageResend r;
				r.resend = settings.getNumResends();
				r.msg = m;
				_mapParamResend.insert(std::pair<MidiSettings::BotParameter, MidiMessageResend>(MidiSettings::SPEAKER_POSITION_Q1, r));
			}
		}
		else { // default speed values may be resent without any trouble

			it = _mapParamResend.find(param);		
			
			if (it != _mapParamResend.end()) {
				it->second.resend = settings.getNumResends();
				it->second.msg = m;
			}
			else {
				MidiMessageResend r;
				r.resend = settings.getNumResends();
				r.msg = m;
				_mapParamResend.insert(std::pair<MidiSettings::BotParameter, MidiMessageResend>(param, r));
			}
		}
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: CC(%d,%d,%d)", m.getChannel(), m.getControllerNumber(), value);
		Logger::writeToLog(_logMsg);
	}

	return true;
}


bool MidiController::sendMidiMessage(const MidiMessage& msg) {
	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(msg);
	}

	return true;
}


bool MidiController::sendWaypointIndex(int idx, const MidiSettings& settings) {
	//if (!_configured)
	//	return false;

	MidiMessage m = MidiMessage::pitchWheel(settings.getChannel(), idx);

	for (size_t i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}

	if (settings.getNumResends() > 0) {
		_wpIdxResend.resend = settings.getNumResends();
		_wpIdxResend.msg = m;
	}

	if (_loggingEnabled) {
		sprintf(_logMsg, "Midi Send: PitchBend(%d,%d)", m.getChannel(), idx);
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

		for (size_t i = 0; i < RobotsManager::instance().numRobots(); i++)
			RobotsManager::instance().getRobots()[i]->waypointsPlayer.play();

	}
	else if (message.isMidiStop()) {

		_midiClockStarted = false;
		//Logger::writeToLog("Midi Stop received");

		for (size_t i = 0; i < RobotsManager::instance().numRobots(); i++)
			RobotsManager::instance().getRobots()[i]->waypointsPlayer.pause();
	} 
	else if (message.isMidiContinue()) {

		_midiClockStarted = true;
		//Logger::writeToLog("Midi Continue received");

		for (size_t i = 0; i < RobotsManager::instance().numRobots(); i++)
			RobotsManager::instance().getRobots()[i]->waypointsPlayer.play();
	}
	else if (message.isMidiClock()) {

		if (_midiClockStarted)
			_midiClock++;
	}
	else if (message.isSongPositionPointer()) {
		_midiClock = (uint64_t)message.getSongPositionPointerMidiBeat() * 6;
		
		if (message.getSongPositionPointerMidiBeat() == 0) {

			for (size_t i = 0; i < RobotsManager::instance().numRobots(); i++)
				RobotsManager::instance().getRobots()[i]->waypointsPlayer.reset();
		}
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
					startCommand(rdd::MidiSettings::STRAFE_LEFT, (uint8)(abs(input.x)*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else if (input.x > 0.0f) {
					startCommand(rdd::MidiSettings::STRAFE_RIGHT, (uint8)(input.x*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else {

					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.x < 0.0f)
						stopCommand(rdd::MidiSettings::STRAFE_LEFT, RobotsManager::instance().getSelectedRobot()->midiSettings);
					else if (inputPrev.x > 0.0f)
						stopCommand(rdd::MidiSettings::STRAFE_RIGHT, RobotsManager::instance().getSelectedRobot()->midiSettings);
				}

				if (input.y < 0.0f) {
					startCommand(rdd::MidiSettings::MOVE_FORWARD, (uint8)(abs(input.y)*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else if (input.y > 0.0f) {
					startCommand(rdd::MidiSettings::MOVE_BACKWARD, (uint8)(input.y*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else {

					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.y < 0.0f)
						stopCommand(rdd::MidiSettings::MOVE_FORWARD, RobotsManager::instance().getSelectedRobot()->midiSettings);
					else if (inputPrev.y > 0.0f)
						stopCommand(rdd::MidiSettings::MOVE_BACKWARD, RobotsManager::instance().getSelectedRobot()->midiSettings);
				}

			}
			else {

				auto inputPrev = xyInput->getMappedInputPrevious();

				if (inputPrev.x < 0.0f)
					stopCommand(rdd::MidiSettings::STRAFE_LEFT, RobotsManager::instance().getSelectedRobot()->midiSettings);
				else if (inputPrev.x > 0.0f)
					stopCommand(rdd::MidiSettings::STRAFE_RIGHT, RobotsManager::instance().getSelectedRobot()->midiSettings);

				if (inputPrev.y < 0.0f)
					stopCommand(rdd::MidiSettings::MOVE_FORWARD, RobotsManager::instance().getSelectedRobot()->midiSettings);
				else if (inputPrev.y > 0.0f)
					stopCommand(rdd::MidiSettings::MOVE_BACKWARD, RobotsManager::instance().getSelectedRobot()->midiSettings);
			}
		}
		else if (xyInput->getIdentifier() == "Rotation") {

			if (xyInput->hasInput()) {

				auto input = xyInput->getMappedInput();

				if (input.x < 0.0f) {
					startCommand(rdd::MidiSettings::ROTATE_LEFT, (uint8)(abs(input.x)*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else if (input.x > 0.0f) {
					startCommand(rdd::MidiSettings::ROTATE_RIGHT, (uint8)(input.x*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else {

					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.x < 0.0f)
						stopCommand(rdd::MidiSettings::ROTATE_LEFT, RobotsManager::instance().getSelectedRobot()->midiSettings);
					else if (inputPrev.x > 0.0f)
						stopCommand(rdd::MidiSettings::ROTATE_RIGHT, RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
			}
			else {
				auto inputPrev = xyInput->getMappedInputPrevious();

				if (inputPrev.x < 0.0f)
					stopCommand(rdd::MidiSettings::ROTATE_LEFT, RobotsManager::instance().getSelectedRobot()->midiSettings);
				else if (inputPrev.x > 0.0f)
					stopCommand(rdd::MidiSettings::ROTATE_RIGHT, RobotsManager::instance().getSelectedRobot()->midiSettings);
			}
		}

		else if (xyInput->getIdentifier() == "Speaker Rotation") {

			if (xyInput->hasInput()) {

				auto input = xyInput->getMappedInput();

				if (input.y < 0.0f) {
					startCommand(rdd::MidiSettings::SPEAKER_UP, (uint8)(abs(input.y)*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else if (input.y > 0.0f) {
					startCommand(rdd::MidiSettings::SPEAKER_DOWN, (uint8)(input.y*127.0 + 0.5), RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
				else {
					auto inputPrev = xyInput->getMappedInputPrevious();

					if (inputPrev.y < 0.0f)
						stopCommand(rdd::MidiSettings::SPEAKER_UP, RobotsManager::instance().getSelectedRobot()->midiSettings);
					else if (inputPrev.y > 0.0f)
						stopCommand(rdd::MidiSettings::SPEAKER_DOWN, RobotsManager::instance().getSelectedRobot()->midiSettings);
				}
			}
			else {
				auto inputPrev = xyInput->getMappedInputPrevious();

				if (inputPrev.y < 0.0f)
					stopCommand(rdd::MidiSettings::SPEAKER_UP, RobotsManager::instance().getSelectedRobot()->midiSettings);
				else if (inputPrev.y > 0.0f)
					stopCommand(rdd::MidiSettings::SPEAKER_DOWN, RobotsManager::instance().getSelectedRobot()->midiSettings);
			}
		}
	}



	auto angleInput = dynamic_cast<AngleInputComponent*>(source);

	if (angleInput) {
		auto input = angleInput->getMappedAngle();

		if (input <= -128.0f) {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q4, (uint8)(abs(input) - 128.0), RobotsManager::instance().getSelectedRobot()->midiSettings);
		}
		else if (input < 0.0f) {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q3, (uint8)(abs(input)), RobotsManager::instance().getSelectedRobot()->midiSettings);
		}
		else if (input < 128.0f) {
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q1, (uint8)(input), RobotsManager::instance().getSelectedRobot()->midiSettings);
		}
		else {  // (input >= 128.0f)
			sendParameter(rdd::MidiSettings::SPEAKER_POSITION_Q2, (uint8)(input - 128.0), RobotsManager::instance().getSelectedRobot()->midiSettings);
		}
	}

}


void MidiController::timerCallback() {
	size_t i;
	MidiMessage m = MidiMessage::midiClock();


	// send alive signal (MIDI clock message)
	for (i = 0; i < _midiOutputs.size(); i++) {
		_midiOutputs[i]->sendMessageNow(m);
	}


	// resend latest MIDI messages for bot commands and parameters

	std::map<MidiSettings::BotCommand, MidiMessageResend>::iterator itCmdResend = _mapCmdResend.begin();

	while (itCmdResend != _mapCmdResend.end()) {
		if ((itCmdResend->second).resend != 0) {

			m = (itCmdResend->second).msg;

			for (i = 0; i < _midiOutputs.size(); i++) {
				_midiOutputs[i]->sendMessageNow(m);
			}

			if ((itCmdResend->second).resend > 0) {
				(itCmdResend->second).resend--;
			}

			if (_loggingEnabled) {
				sprintf(_logMsg, "Midi Send: NoteOn(%d,%d,%d)", m.getChannel(), m.getNoteNumber(), m.getVelocity());
				Logger::writeToLog(_logMsg);
			}
		}

		itCmdResend++;
	}


	std::map<MidiSettings::BotParameter, MidiMessageResend>::iterator itParamResend = _mapParamResend.begin();

	while (itParamResend != _mapParamResend.end()) {
		if ((itParamResend->second).resend != 0) {

			m = (itParamResend->second).msg;

			for (i = 0; i < _midiOutputs.size(); i++) {
				_midiOutputs[i]->sendMessageNow(m);
			}

			if ((itParamResend->second).resend > 0) {
				(itParamResend->second).resend--;
			}

			if (_loggingEnabled) {
				sprintf(_logMsg, "Midi Send: CC(%d,%d,%d)", m.getChannel(), m.getControllerNumber(), m.getControllerValue());
				Logger::writeToLog(_logMsg);
			}
		}

		itParamResend++;
	}

	if (_wpIdxResend.resend != 0) {
		for (i = 0; i < _midiOutputs.size(); i++) {
			_midiOutputs[i]->sendMessageNow(_wpIdxResend.msg);
		}

		if (_wpIdxResend.resend > 0)
			_wpIdxResend.resend--;

		if (_loggingEnabled) {
			sprintf(_logMsg, "Midi Send: PitchBend(%d,%d)", _wpIdxResend.msg.getChannel(), _wpIdxResend.msg.getPitchWheelValue());
			Logger::writeToLog(_logMsg);
		}
	}
}