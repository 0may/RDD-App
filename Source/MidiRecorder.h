/*
  ==============================================================================

    MidiRecorder.h
    Created: 8 Oct 2020 11:52:51am
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma 

#include <JuceHeader.h>


namespace rdd {

	class MidiRecorder {

	public:
		MidiRecorder();

		~MidiRecorder();

		bool startRecording(MidiMessageSequence& sequence);

		bool stopRecording();
		
		bool isRecording();


	protected:
		bool _recording;

		MidiMessageSequence _midiSequence;

	};

}