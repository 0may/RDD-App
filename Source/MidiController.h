/*
  ==============================================================================

    MidiController.h
    Created: 18 Jun 2020 10:21:26am
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <AppConfig.h>
#include <JuceHeader.h>
#include <set>
#include <map>
#include "MidiSettings.h"

using namespace juce;

namespace rdd {

	class MidiController : public MidiInputCallback, public ChangeListener, public Timer {

	public:
		MidiController();

		virtual ~MidiController();


		bool config(const MidiSettings& settings);

		void enableLogging(bool enable);

		bool addMidiInput(String midiInputIdentifier);
		bool removeMidiInput(String midiInputIdentifier);
		
		bool addMidiOuput(String midiOutputIdentifier);
		bool removeMidiOutput(String midiOutputIdentifier);
		

		// velocity must be in the range of 0 - 127
		bool startCommand(MidiSettings::BotCommand cmd, uint8 velocity);
		bool stopCommand(MidiSettings::BotCommand cmd);

		// value must be in the range of 0 - 127
		bool sendParameter(MidiSettings::BotParameter param, uint8 value);

		void handleIncomingMidiMessage(MidiInput* source, const MidiMessage& message) override;

		void changeListenerCallback(ChangeBroadcaster* source) override;

		void timerCallback() override;


	protected:
		MidiSettings _midiSettings;
		AudioDeviceManager _deviceManager;

		std::set<String> _midiInputIdentifiers;
		std::vector<std::unique_ptr<MidiOutput>> _midiOutputs;

		bool _loggingEnabled;
		char _logMsg[32];

		bool _configured;



		uint64_t _midiClock;
		bool _midiClockStarted;

		// item to control midi message resends
		struct MidiMessageResend {
			int resend;
			MidiMessage msg;
		};

		// maps to the MidiMessageResend items for the different commands and parameters
		std::map<MidiSettings::BotCommand, MidiMessageResend> _mapCmdResend;
		std::map<MidiSettings::BotParameter, MidiMessageResend> _mapParamResend;

	};
}
