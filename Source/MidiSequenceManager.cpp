/*
  ==============================================================================

    MidiSequenceManager.cpp
    Created: 8 Oct 2020 12:21:30pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "MidiSequenceManager.h"
#include "MainManager.h"


using namespace rdd;


MidiSequenceManager::MidiSequenceManager()
: _selectedSeqIdx(-1),
_recording(false),
_playing(false)
{

}


MidiSequenceManager::~MidiSequenceManager() {

}


int MidiSequenceManager::getNumMidiSequences() const {
	return _sequenceArray.size();
}


int MidiSequenceManager::selectMidiSequence(int idx) {
	
	if (!_recording && idx >= 0 && idx < _sequenceArray.size()) {
		_selectedSeqIdx = idx;
	}

	return _selectedSeqIdx;
}


void MidiSequenceManager::unselectMidiSequence() {
	if (!_recording)	
		_selectedSeqIdx = -1;
}


int MidiSequenceManager::getSelectedMidiSequenceIdx() {
	return _selectedSeqIdx;
}



MidiMessageSequence* MidiSequenceManager::getSelectedMidiSequence() {
	return getMidiSequence(_selectedSeqIdx);
}


MidiMessageSequence* MidiSequenceManager::getMidiSequence(int idx) {
	if (idx >= 0 && idx < _sequenceArray.size())
		return _sequenceArray[idx];
	else
		return nullptr;
}


String MidiSequenceManager::getSelectedMidiSequenceName() {
	return getMidiSequenceName(_selectedSeqIdx);
}


String MidiSequenceManager::getMidiSequenceName(int idx) {
	if (idx >= 0 && idx < _sequenceArray.size())
		return _sequenceNames[idx];
	else
		return String("");
}


void MidiSequenceManager::setMidiSequenceName(int idx, String name) {

	if (idx >= 0 && idx < _sequenceArray.size()) {
		_sequenceNames.set(idx, name);
	}
}


int MidiSequenceManager::addNewMidiSequence(String name) {
	_sequenceArray.add(new MidiMessageSequence());

	if (name.isNotEmpty())
		_sequenceNames.add(name);
	else {
		String str("Sequence");
		str.append(String(_sequenceArray.size()), 10);
		_sequenceNames.add(str);
	}

	_selectedSeqIdx = _sequenceArray.size() - 1;
	return _selectedSeqIdx;
}


bool MidiSequenceManager::removeSelectedMidiSequence() {
	bool ret = removeMidiSequence(_selectedSeqIdx);

	_selectedSeqIdx = -1;

	return ret;
}


bool MidiSequenceManager::removeMidiSequence(int idx) {
	if (!_recording && idx >= 0 && idx < _sequenceArray.size()) {
		_sequenceArray.remove(idx);
		_sequenceNames.remove(idx);
		return true;
	}
	else
		return false;
}


bool MidiSequenceManager::moveSelectedMidiSequence(bool toFront) {
	if (!_recording && _selectedSeqIdx > 0 && toFront) {
		_sequenceArray.swap(_selectedSeqIdx - 1, _selectedSeqIdx);
		_sequenceNames.move(_selectedSeqIdx, _selectedSeqIdx - 1);
		_selectedSeqIdx = _selectedSeqIdx - 1;
		return true;
	}
	else if (!_recording && _selectedSeqIdx >= 0 && _selectedSeqIdx < _sequenceArray.size() - 1 && !toFront) {
		_sequenceArray.swap(_selectedSeqIdx, _selectedSeqIdx + 1);
		_sequenceNames.move(_selectedSeqIdx, _selectedSeqIdx + 1);
		_selectedSeqIdx = _selectedSeqIdx + 1;
		return true;
	}
	else
		return false;
}



bool MidiSequenceManager::saveMidiSequence(int idx, File file) const {

	if (idx < 0 && idx >= _sequenceArray.size())
		return false;


	MidiFile mfile;
	mfile.setSmpteTimeFormat(25, 40);
	mfile.addTrack(*_sequenceArray[_selectedSeqIdx]);

	FileOutputStream outfile(file);

	if (outfile.openedOk()) {

		mfile.writeTo(outfile);
		outfile.flush();
	
		return true;
	}
	else
		return false;
}


int MidiSequenceManager::loadMidiSequence(File file) {

	FileInputStream infile(file);

	if (infile.failedToOpen())
		return -1;

	MidiFile mfile;
	if (!mfile.readFrom(infile, false))
		return -1;

	auto midiSequence = mfile.getTrack(0);

	if (!midiSequence)
		return -1;

	_sequenceArray.add(new MidiMessageSequence(*midiSequence));
	_sequenceNames.add(file.getFileNameWithoutExtension());

	return _sequenceArray.size() - 1;

}


bool MidiSequenceManager::startRecording() {
	if (!_recording && _selectedSeqIdx >= 0) {

		_startTime = Time::currentTimeMillis();
		_recording = true;

		return true;
	}
	else {
		return false;
	}

}


bool MidiSequenceManager::stopRecording() {
	if (_recording) {

		_recording = false;

		return true;
	}
	else {
		return false;
	}
}


bool MidiSequenceManager::isRecording() const {
	return _recording;
}



void MidiSequenceManager::receiveMidiMessage(const MidiMessage& msg) {
	if (_recording) {
		MidiMessage msgCopy(msg);
		msgCopy.setTimeStamp((Time::currentTimeMillis() - _startTime));
		_sequenceArray[_selectedSeqIdx]->addEvent(msgCopy);
	}
}