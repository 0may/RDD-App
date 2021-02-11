/*
  ==============================================================================

    MainManager.h
    Created: 8 Oct 2020 6:37:08am
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once


#include "MidiController.h"
#include "MidiSequenceManager.h"
#include "WaypointsManager.h"
#include "Map.h"
#include "JuceHeader.h"

namespace rdd {

	class MainManager {


	public:

		~MainManager();

		static MainManager& instance();

		MidiController& getMidiController()				{ return _midiController; };
		inline WaypointsManager& getWaypointsManager()	{ return _waypointsManager; };
		inline Map& getMap()							{ return _map; };

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
		MidiSequenceManager _midiSequenceManager;
		ApplicationCommandManager _cmdManager;
		Map _map;
		File _assetsDirectory;
	};



}