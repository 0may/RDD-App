/*
  ==============================================================================

    MidiSettings.cpp
    Created: 6 May 2020 9:26:49pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "MidiSettings.h"
#include "Util.h"

using namespace rdd;


MidiSettings::MidiSettings()
{

	_channel = 1;

	_notes[MOVE_FORWARD] = 20;
	_notes[MOVE_BACKWARD] = 21;
	_notes[STRAFE_LEFT] = 22;
	_notes[STRAFE_RIGHT] = 23;
	_notes[ROTATE_LEFT] = 24;
	_notes[ROTATE_RIGHT] = 25;
	_notes[SPEAKER_UP] = 26;
	_notes[SPEAKER_DOWN] = 27;

	_cc[MOVE_SPEED] = 30;
	_cc[ROTATE_SPEED] = 31;
	_cc[SPEAKER_SPEED] = 32;
	_cc[SPEAKER_POSITION_Q1] = 33;
	_cc[SPEAKER_POSITION_Q2] = 34;
	_cc[SPEAKER_POSITION_Q3] = 35;
	_cc[SPEAKER_POSITION_Q4] = 36;
	_cc[SPEAKER_POSITION_RESET] = 37;

	_resend = 0;
}


MidiSettings::~MidiSettings() {

}


bool MidiSettings::load(const File& file) {

	var midisettings = JSON::parse(file);

	return validateAndRead(midisettings);
}


String MidiSettings::toString() {
	String s = "MidiSettings:\n";

	s += " channel:            " + String(_channel) + "\n";

	s += " note move_forward:  " + String(getNote(MOVE_FORWARD)) + "\n";
	s += " note move_backward: " + String(getNote(MOVE_BACKWARD)) + "\n";
	s += " note strafe_left:   " + String(getNote(STRAFE_LEFT)) + "\n";
	s += " note strafe_right:  " + String(getNote(STRAFE_RIGHT)) + "\n";
	s += " note rotate_left:   " + String(getNote(ROTATE_LEFT)) + "\n";
	s += " note rotate_right:  " + String(getNote(ROTATE_RIGHT)) + "\n";
	s += " note speaker_up:    " + String(getNote(SPEAKER_UP)) + "\n";
	s += " note speaker_down:  " + String(getNote(SPEAKER_DOWN)) + "\n";

	s += " cc move_speed:      " + String(getCC(MOVE_SPEED)) + "\n";
	s += " cc rotate_speed:    " + String(getCC(ROTATE_SPEED)) + "\n";
	s += " cc speaker_speed:   " + String(getCC(SPEAKER_SPEED)) + "\n";
	s += " cc speaker_position_q1:  " + String(getCC(SPEAKER_POSITION_Q1)) + "\n";
	s += " cc speaker_position_q2:  " + String(getCC(SPEAKER_POSITION_Q2)) + "\n";
	s += " cc speaker_position_q3:  " + String(getCC(SPEAKER_POSITION_Q3)) + "\n";
	s += " cc speaker_position_q4:  " + String(getCC(SPEAKER_POSITION_Q4)) + "\n";
	s += " cc speaker_position_reset:  " + String(getCC(SPEAKER_POSITION_RESET)) + "\n";


	s += " resend:             " + String(_resend) + "\n";

	return s;
}



bool MidiSettings::validateAndRead(var json) {

	if (json.isObject()) {
		auto* obj = json.getDynamicObject();

		bool ret = true;

		ret &= Util::getIntFromJsonObject(obj, "channel", _channel);
		ret &= Util::getIntFromJsonObject(obj, "resend", _resend);

		if (_resend < 0)
			_resend = 0;


		auto* objNotes = Util::getChildObjectFromJsonObject(obj, "notes");
		if (objNotes != nullptr) {
			ret &= Util::getIntFromJsonObject(objNotes, "move_forward", _notes[MOVE_FORWARD]);
			ret &= Util::getIntFromJsonObject(objNotes, "move_backward", _notes[MOVE_BACKWARD]);
			ret &= Util::getIntFromJsonObject(objNotes, "strafe_left", _notes[STRAFE_LEFT]);
			ret &= Util::getIntFromJsonObject(objNotes, "strafe_right", _notes[STRAFE_RIGHT]);
			ret &= Util::getIntFromJsonObject(objNotes, "rotate_left", _notes[ROTATE_LEFT]);
			ret &= Util::getIntFromJsonObject(objNotes, "rotate_right", _notes[ROTATE_RIGHT]);
			ret &= Util::getIntFromJsonObject(objNotes, "speaker_up", _notes[SPEAKER_UP]);
			ret &= Util::getIntFromJsonObject(objNotes, "speaker_down", _notes[SPEAKER_DOWN]);
		}
		else
			ret = false;

		auto* objCC = Util::getChildObjectFromJsonObject(obj, "controlchange");
		if (objCC != nullptr) {
			ret &= Util::getIntFromJsonObject(objCC, "move_speed", _cc[MOVE_SPEED]);
			ret &= Util::getIntFromJsonObject(objCC, "rotate_speed", _cc[ROTATE_SPEED]);
			ret &= Util::getIntFromJsonObject(objCC, "speaker_speed", _cc[SPEAKER_SPEED]);
			ret &= Util::getIntFromJsonObject(objCC, "speaker_position_q1", _cc[SPEAKER_POSITION_Q1]);
			ret &= Util::getIntFromJsonObject(objCC, "speaker_position_q2", _cc[SPEAKER_POSITION_Q2]);
			ret &= Util::getIntFromJsonObject(objCC, "speaker_position_q3", _cc[SPEAKER_POSITION_Q3]);
			ret &= Util::getIntFromJsonObject(objCC, "speaker_position_q4", _cc[SPEAKER_POSITION_Q4]);
			ret &= Util::getIntFromJsonObject(objCC, "speaker_position_reset", _cc[SPEAKER_POSITION_RESET]);
		}
		else
			ret = false;


		return ret;
	}
	else
		return false;
}

