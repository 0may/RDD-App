/*
  ==============================================================================

    MainManager.h
    Created: 8 Oct 2020 6:37:08am
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>
#include "MidiController.h"
#include "WaypointsPlayer.h"
#include "WaypointsManager.h"
#include "Map.h"
#include "MidiSequenceManager.h"

namespace rdd {

	class MainManager {


	public:

		~MainManager();

		static MainManager& instance();

		MidiController& getMidiController()		{ return _midiController; };
		WaypointsManager& getWaypointsManager()	{ return _waypointsManager; };
		WaypointsPlayer& getWaypointsPlayer() { return _waypointsPlayer; };
		Map& getMap()							{ return _map; };

		MidiSequenceManager& getMidiSequenceManager();
		ApplicationCommandManager& getCommandManager();

		const File getAssetsDirectory() const;
		void setAssetsDirectory(String path);
		void setAssetsDirectory(File path);

	private:
		MainManager();

		MainManager(const MainManager&);

		MainManager & operator = (const MainManager&);




	private:
		MidiController _midiController;
		WaypointsManager _waypointsManager;
		WaypointsPlayer _waypointsPlayer;
		MidiSequenceManager _midiSequenceManager;
		ApplicationCommandManager _cmdManager;
		Map _map;
		File _assetsDirectory;
	};



}