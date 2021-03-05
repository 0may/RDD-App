/*
  ==============================================================================

    MidiSettings.h
    Created: 6 May 2020 9:26:49pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

using namespace juce;

namespace rdd {

	class MidiSettings {

	public:

		enum BotCommand {
			MOVE_FORWARD,
			MOVE_BACKWARD,
			STRAFE_LEFT,
			STRAFE_RIGHT,
			ROTATE_LEFT,
			ROTATE_RIGHT,
			SPEAKER_UP,
			SPEAKER_DOWN
		};

		enum BotParameter {
			MOVE_SPEED,
			ROTATE_SPEED,
			SPEAKER_SPEED,
			SPEAKER_POSITION_Q1,
			SPEAKER_POSITION_Q2,
			SPEAKER_POSITION_Q3,
			SPEAKER_POSITION_Q4,
			SPEAKER_POSITION_RESET
		};



		MidiSettings();

		virtual ~MidiSettings();


		bool load(const File& file);

		bool save(File f) const;

		int getChannel() const { return _channel; }

		int getNote(BotCommand cmd) const { return _notes.find(cmd)->second; }

		int getCC(BotParameter param) const { return _cc.find(param)->second; }

		int getNumResends() const { return _resend; }

		bool setChannel(int channel);
		bool setNote(BotCommand cmd, int note);
		bool setCC(BotParameter param, int cc);
		bool setNumResends(int resends);

		String toString() const;


	protected:
		
		bool validateAndRead(var json);


	protected:

		int	_channel;

		std::map<BotCommand, int> _notes;

		std::map<BotParameter, int>	_cc;

		int _resend;

	};

}