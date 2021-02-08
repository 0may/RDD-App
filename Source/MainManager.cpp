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

	setAssetsDirectory(File::getCurrentWorkingDirectory().getChildFile("../../Assets/"));
	//setAssetsDirectory("Assets/");


	File midiSettingsFile(_assetsDirectory.getChildFile("ConfigFiles/midiconfig.json"));

	if (midiSettings.load(midiSettingsFile) && _midiController.config(midiSettings)) {

		_midiController.enableLogging(true);

		_midiController.startTimer(150);

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


MidiController& MainManager::getMidiController() {
	return _midiController;
}


MidiSequenceManager& MainManager::getMidiSequenceManager() {
	return _midiSequenceManager;

}


ApplicationCommandManager& MainManager::getCommandManager() {
	return _cmdManager;
}


const File MainManager::getAssetsDirectory() const {
	return _assetsDirectory;
}


void MainManager::setAssetsDirectory(String path) {
	_assetsDirectory = File(path).getFullPathName();
}


void MainManager::setAssetsDirectory(File path) {
	_assetsDirectory = path.getFullPathName();
}