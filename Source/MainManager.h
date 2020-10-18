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

namespace rdd {

	class MainManager {


	public:

		~MainManager();

		static MainManager& instance();

		MidiController& midiController();
		MidiSequenceManager& midiSequenceManager();


	private:
		MainManager();

		MainManager(const MainManager&);

		MainManager & operator = (const MainManager&);




	private:
		MidiController _midiController;
		MidiSequenceManager _midiSequenceManager;
	};



}