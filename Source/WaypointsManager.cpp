/*
  ==============================================================================

    WaypointsManager.cpp
    Created: 5 Jan 2021 1:22:13pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "WaypointsManager.h"



WaypointsManager::WaypointsManager() {
	_checkoutIterator = _waypoints.end();
}


WaypointsManager::~WaypointsManager() {

}


size_t WaypointsManager::getNumWaypoínts() const {
	return _waypoints.size();
}


const WaypointsManager::Waypoint& WaypointsManager::getWaypoint(size_t idx) const {

	jassert(idx < _waypoints.size());

	set<Waypoint, WaypointComparator>::const_iterator it = _waypoints.begin();

	for (size_t i = 0; i < idx; i++)
		it++;

	return *it;
}


bool WaypointsManager::addWaypoint(WaypointsManager::Waypoint wp) {
	if (_checkoutIterator == _waypoints.end())
		return (_waypoints.insert(wp)).second;
	else
		return false;

}


WaypointsManager::Waypoint& WaypointsManager::checkoutWaypoint(size_t idx) {

	jassert(idx < _waypoints.size());

	set<Waypoint, WaypointComparator>::iterator it = _waypoints.begin();

	for (size_t i = 0; i < idx; i++)
		it++;

	_checkoutIterator = it;

	return const_cast<WaypointsManager::Waypoint&>(*it);
}


bool WaypointsManager::commitWaypoint() {
	WaypointsManager::Waypoint wp = *_checkoutIterator;

	_waypoints.erase(_checkoutIterator);
	_waypoints.insert(wp);

	_checkoutIterator = _waypoints.end();

	return true;
}
