/*
  ==============================================================================

    MidiSequenceManager.h
    Created: 8 Oct 2020 12:21:30pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>
#include "MidiController.h"


namespace rdd {

	class MidiSequenceManager {

	public:
		MidiSequenceManager();
		~MidiSequenceManager();

		int getNumMidiSequences() const;

		/**
			Adds a new sequence, sets it as selected and returns its index.
		*/
		int addNewMidiSequence(String name = "");
		void setMidiSequenceName(int idx, String name);

		/**
	Sets the specified sequence as selected and returns its index.
	@return The selected sequence's index. In case of failure returns the last active index or -1 if none.
*/
		int selectMidiSequence(int idx);
		void unselectMidiSequence();
		int getSelectedMidiSequenceIdx();


		MidiMessageSequence* getSelectedMidiSequence();
		MidiMessageSequence* getMidiSequence(int idx);


		String getSelectedMidiSequenceName();
		String getMidiSequenceName(int idx);


		bool removeSelectedMidiSequence();
		bool removeMidiSequence(int idx);



		/**
			Moves the selected Midi sequence one step towards the front or back of the list, if possible.
			@param toFront if true moves towards front, if false moves towards back
		*/
		bool moveSelectedMidiSequence(bool toFront);

		bool saveMidiSequence(int idx, File file) const;

		/** 
		    Load a midi sequence from file, append to the end of the list
		    and return its index. Return -1 in case of error.
		*/
		int loadMidiSequence(File file);

		bool startRecording();

		bool stopRecording();

		bool isRecording() const;

		void receiveMidiMessage(const MidiMessage& msg);




	protected:

		int _selectedSeqIdx;
		OwnedArray<MidiMessageSequence> _sequenceArray;
		StringArray _sequenceNames;

		bool _recording;
		bool _playing;

		int64 _startTime;

	};


}