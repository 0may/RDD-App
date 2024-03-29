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

	setProjectDirectory(File::getCurrentWorkingDirectory());//.getChildFile("../../ExampleProject/"));
	//setAssetsDirectory("Assets/");


	if (!_map.loadMap(_projectDirectory.getChildFile("map/map.yaml").getFullPathName())) {
		AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Warning", "Failed to load map from file\n" + _projectDirectory.getChildFile("map/map.yaml").getFullPathName(), "Quit");
	}



	/*File midiSettingsFile(_projectDirectory.getChildFile("config/midiconfig.json"));*/


	//if (midiSettings.load(midiSettingsFile) && _midiController.config(midiSettings)) {

		_midiController.enableLogging(true);

		_midiController.startTimer(150);
	//}
	//else {

	//	AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Error", "Failed to load MIDI settings from file 'midiconfig.json'", "Quit");

	//	JUCEApplication::getInstance()->systemRequestedQuit();
	//}
}


MainManager::~MainManager() {

}

MainManager& MainManager::instance() {
	static MainManager _instance;
	return _instance;
}


MidiSequenceManager& MainManager::getMidiSequenceManager() {
	return _midiSequenceManager;

}


ApplicationCommandManager& MainManager::getCommandManager() {
	return _cmdManager;
}


const File MainManager::getProjectDirectory() const {
	return _projectDirectory;
}


void MainManager::setProjectDirectory(String path) {
	_projectDirectory = File(path).getFullPathName();
}


void MainManager::setProjectDirectory(File path) {
	_projectDirectory = path.getFullPathName();
}

bool MainManager::initAppSettings() {

	static juce::Identifier idAppSettings("AppSettings");
	static juce::Identifier idRecentProjects("RecentProjects");


	_appDataDir = File::getSpecialLocation(File::SpecialLocationType::userApplicationDataDirectory).getChildFile("RDD-App");

	if (!_appDataDir.isDirectory() && _appDataDir.createDirectory().failed())
		return false;

	File appSettingsFile = _appDataDir.getChildFile("app-settings.xml");

	if (appSettingsFile.existsAsFile()) {
		shared_ptr<XmlElement> e = parseXML(appSettingsFile);
		_appSettings = ValueTree::fromXml(*e);
	}
	else {
		_appSettings = ValueTree(idAppSettings);
		_appSettings.addChild(ValueTree(idRecentProjects), -1, nullptr);
	}

}
