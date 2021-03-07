/*
  ==============================================================================

    WaypointsPlayer.cpp
    Created: 14 Feb 2021 1:59:21pm
    Author:  omay

  ==============================================================================
*/

#include "WaypointsPlayer.h"
#include "MainManager.h"
#include "RobotsManager.h"


WaypointsPlayer::WaypointsPlayer() {
	_playing = false;
	_playingIdx = (size_t)-1;

	_t0 = 0;
	_t = 0;
	_dt = 0;
	_cbCnt = 0;

	_waypointsManager = nullptr;
	_midiSettings = nullptr;
}


WaypointsPlayer::~WaypointsPlayer() {
	if (isTimerRunning())
		stopTimingThread();
}


void WaypointsPlayer::setWaypointsManager(WaypointsManager* wpm) {

	_waypointsManager = wpm;
}


void WaypointsPlayer::setMidiSettings(MidiSettings* midiSettings) {
	_midiSettings = midiSettings;
}


void WaypointsPlayer::startTimingThread() {
	startTimer(1);
}


bool WaypointsPlayer::play() {
	if (_waypointsManager && isTimerRunning() && !_playing) {

		if (_playingIdx == (size_t)-1)
			reset();

		_waypointsManager->lock();
		_cbCnt = 0;
		startTimer(1);
		_t0 = juce::Time::currentTimeMillis();
		//MainManager::instance().getMidiController().sendMidiMessage(MidiMessage::midiStart());
		_playing = true;
		return true;
	}
	else {
		return false;
	}
}


bool WaypointsPlayer::pause() {
	if (isTimerRunning() && _playing) {
		_playing = false;
		//MainManager::instance().getMidiController().sendMidiMessage(MidiMessage::midiStop());
		_t += _dt;
		_dt = 0;
		_cbCnt = 0;
		sendChangeMessage();
		return true;
	}
	else
		return false;

}


bool WaypointsPlayer::reset() {
	//MainManager::instance().getMidiController().sendMidiMessage(MidiMessage::songPositionPointer(0));

	if (_waypointsManager) {
		_waypointsManager->unlock();
		_t = 0;
		_dt = 0;
		_cbCnt = 0;

		_playingIdx = 0;
		_playingIterator = _waypointsManager->cbegin();

		sendChangeMessage();

		return true;
	}
	else
		return false;
}



bool WaypointsPlayer::isPlaying() {
	return _playing;
}


void WaypointsPlayer::stopTimingThread() {
	stopTimer();
	_playingIdx = (size_t)-1;
}





void WaypointsPlayer::hiResTimerCallback() {

	if (_playing) {
		_dt = (juce::Time::currentTimeMillis() - _t0);

		if (_waypointsManager && _playingIterator != _waypointsManager->cend()
			&& (_t + _dt) * 0.001 >= (*_playingIterator)->t)
		{

			const MessageManagerLock mmLock;
			if (_midiSettings)
				MainManager::instance().getMidiController().sendWaypointIndex((int)_playingIdx, *_midiSettings);

			_playingIterator++;
			_playingIdx++;
		}


		if (_cbCnt >= 50) {
			_cbCnt = 0;
			const MessageManagerLock mmLock;
			sendChangeMessage();
		}

		_cbCnt++;
	}
}
