/*
  ==============================================================================

    RobotsManager.h
    Created: 5 Mar 2021 2:20:14pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MidiSettings.h"
#include "WaypointsManager.h"
#include "WaypointsPlayer.h"

namespace rdd {

	class RobotsManager : public ChangeBroadcaster {


	public:

		struct Robot {
			MidiSettings midiSettings;
			File midiSettingsPath;
			WaypointsManager waypointsManager;
			WaypointsPlayer waypointsPlayer;
		};


		~RobotsManager();

		static RobotsManager& instance();

		size_t numRobots() { return _robots.size(); };

		std::vector<Robot*>& getRobots() { return _robots; };

		Robot* getRobot(size_t idx) { return _robots[idx]; };


		Robot* getSelectedRobot() { return (_selectedIdx < _robots.size() ? _robots[_selectedIdx] : nullptr); };

		size_t getSelectedIdx() { return _selectedIdx; };

		bool select(size_t robotIdx);

		//void deselect();

		bool addRobot();


	private:
		RobotsManager();

		RobotsManager(const RobotsManager&);

		RobotsManager& operator = (const RobotsManager&);


	private:
		std::vector<Robot*> _robots;

		size_t _selectedIdx;







	};



}