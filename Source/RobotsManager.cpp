/*
  ==============================================================================

    RobotsManager.cpp
    Created: 5 Mar 2021 2:20:14pm
    Author:  omay

  ==============================================================================
*/

#include "RobotsManager.h"
#include "MainManager.h"

using namespace rdd;


RobotsManager::RobotsManager() {

    _selectedIdx = (size_t)-1;

}


RobotsManager::~RobotsManager() {
    for (size_t i = 0; i < _robots.size(); i++)
        delete _robots[i];
}

RobotsManager& RobotsManager::instance() {
	static RobotsManager _instance;
	return _instance;
}



bool  RobotsManager::select(size_t robotIdx) {
    if (robotIdx < _robots.size()) {
        _selectedIdx = robotIdx;
        sendChangeMessage();
        return true;
    }
    else
        return false;
}


//void RobotsManager::deselect() {
//    
//    if (_selectedIdx != (size_t)-1) {
//        _selectedIdx = (size_t)-1;
//        sendChangeMessage();
//    }
//}


bool RobotsManager::addRobot() {
    Robot* r = new Robot();

    File rdir = MainManager::instance().getProjectDirectory().getChildFile("robot" + String(_robots.size() + 1));
   
    if (!rdir.isDirectory() && rdir.createDirectory().failed()) {
        delete r;
        return false;    
    }

    File mfile = rdir.getChildFile("midiconfig.json");

    if (!mfile.existsAsFile() || !r->midiSettings.load(mfile)) {

        r->midiSettings.setChannel(_robots.size() + 1);
        
        if (!r->midiSettings.save(mfile)) {
            delete r;
            return false;
        }
    }

    r->waypointsPlayer.setWaypointsManager(&r->waypointsManager);
    r->waypointsPlayer.startTimingThread();

    _robots.push_back(r);

    if (_robots.size() == 1)
        select(0);

    sendChangeMessage();

    return true;
}

