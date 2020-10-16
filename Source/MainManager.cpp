/*
  ==============================================================================

    MainManager.cpp
    Created: 8 Oct 2020 6:37:08am
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "MainManager.h"
#include "MidiSettings.h"


using namespace rdd;

MainManager::MainManager() {


	MidiSettings midiSettings;

	//File midiSettingsFile(File::getCurrentWorkingDirectory().getChildFile("../../midiconfig.json"));
	File midiSettingsFile(File::getCurrentWorkingDirectory().getChildFile("../../Assets/ConfigFiles/midiconfig.json"));

	if (midiSettings.load(midiSettingsFile) && _midiController.config(midiSettings)) {

		Logger::writeToLog(midiSettings.toString());

		_midiController.startTimer(200);

		_midiController.enableLogging(true);


	}
	else {

		AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Error", "Failed to load MIDI settings from file 'midiconfig.json'", "Quit");

		JUCEApplication::getInstance()->systemRequestedQuit();
	}
}


MainManager::~MainManager() {

}

MainManager& MainManager::instance() {
	static MainManager _instance;
	return _instance;
}


MidiController& MainManager::midiController() {
	return _midiController;
}


MidiSequenceManager& MainManager::midiSequenceManager() {
	return _midiSequenceManager;

}