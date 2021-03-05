/*
  ==============================================================================

    WaypointsPlayer.h
    Created: 14 Feb 2021 1:59:21pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "WaypointsManager.h"

namespace rdd {

	class WaypointsPlayer : public juce::ChangeBroadcaster, public juce::HighResolutionTimer {

	public:

		WaypointsPlayer();

		~WaypointsPlayer();

		void setWaypointsManager(WaypointsManager* wpm);

		void startTimingThread();

		bool play();

		bool pause();

		bool reset();

		bool isPlaying();

		double getPlayTime() { return (_t + _dt) * 0.001; };

		size_t getCurrentWaypointIdx() { return _playingIdx - 1; };

		void stopTimingThread();


		void hiResTimerCallback();

	private:
		bool _playing;


		WaypointsManager* _waypointsManager;
		set<Waypoint*, WaypointsManager::WaypointComparator>::iterator _playingIterator;
		size_t _playingIdx;

		int64 _t0;
		int64 _t;
		int64 _dt;
		uint8 _cbCnt;

	};
};