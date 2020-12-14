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
#include "JuceHeader.h"

namespace rdd {

	class MainManager {


	public:

		~MainManager();

		static MainManager& instance();

		MidiController& midiController();
		MidiSequenceManager& midiSequenceManager();
		ApplicationCommandManager& commandManager();


	private:
		MainManager();

		MainManager(const MainManager&);

		MainManager & operator = (const MainManager&);




	private:
		MidiController _midiController;
		MidiSequenceManager _midiSequenceManager;
		ApplicationCommandManager _cmdManager;
	};



}