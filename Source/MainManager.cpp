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

		Waypoint* wp = _waypointsManager.checkoutWaypoint(_waypointsManager.addNewWaypoint());
		wp->x = 100.5;
		wp->y = 100.101;
		wp->alpha = 45.0;
		wp->beta = 10.453;
		_waypointsManager.commitWaypoint();

		wp = _waypointsManager.checkoutWaypoint(_waypointsManager.addNewWaypoint());
		wp->x = 150.5;
		wp->y = 120.101;
		wp->alpha = 40.0;
		wp->beta = 20.453;
		_waypointsManager.commitWaypoint();

		wp = _waypointsManager.checkoutWaypoint(_waypointsManager.addNewWaypoint());
		wp->x = 160.5;
		wp->y = 200.101;
		wp->alpha = 15.0;
		wp->beta = 50.453;
		_waypointsManager.commitWaypoint();

		wp = _waypointsManager.checkoutWaypoint(_waypointsManager.addNewWaypoint());
		wp->x = 300.5;
		wp->y = 400.101;
		wp->alpha = 95.0;
		wp->beta = 110.453;
		_waypointsManager.commitWaypoint();
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


WaypointsManager& MainManager::getWaypointsManager() {
	return _waypointsManager;
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