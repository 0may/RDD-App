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
	_checkoutIdx = -1;
}


WaypointsManager::~WaypointsManager() {

}


size_t WaypointsManager::getNumWaypoints() const {
	return _waypoints.size();
}


const rdd::Waypoint* WaypointsManager::getWaypoint(size_t idx) const {

	jassert(idx < _waypoints.size());

	set<Waypoint*, WaypointComparator>::const_iterator it = _waypoints.begin();

	for (size_t i = 0; i < idx; i++)
		it++;

	return *it;
}


size_t WaypointsManager::addNewWaypoint() {


	if (!isCheckedOut()) {

		Waypoint* wp = new Waypoint();
		size_t i = _waypoints.size();

		wp->name = String("wp") + String(i + 1).paddedLeft('0', 3);

		if (!_waypoints.empty()) {
			set<Waypoint*, WaypointComparator>::reverse_iterator it = _waypoints.rbegin();

			wp->t = (*it)->t + 10.0f;
			wp->B = (*it)->B;
			wp->x = (*it)->x;
			wp->y = (*it)->y;
			wp->alpha = (*it)->alpha;
			wp->beta = (*it)->beta;
		}

		_waypoints.insert(wp);
		_checkoutIterator = _waypoints.end();

		return i;
	}
	else
		return -1;
}


rdd::Waypoint* WaypointsManager::checkoutWaypoint(size_t idx) {

	jassert(idx < _waypoints.size());

	if (!isCheckedOut()) {

		_checkoutIterator = _waypoints.begin();

		for (size_t i = 0; i < idx; i++)
			_checkoutIterator++;

		_checkoutIdx = idx;

		sendChangeMessage();

		return *_checkoutIterator;
	}
	else
		return nullptr;
}



rdd::Waypoint* WaypointsManager::getCheckedOutWaypoint() {
	if (isCheckedOut())
		return *_checkoutIterator;
	else
		return nullptr;
}


bool WaypointsManager::commitWaypoint() {

	if (isCheckedOut()) {
		rdd::Waypoint* wp = *_checkoutIterator;

		_waypoints.erase(_checkoutIterator);
		_waypoints.insert(wp);

		_checkoutIterator = _waypoints.end();

		_checkoutIdx = -1;

		sendChangeMessage();

		return true;
	}
	else
		return false;
}


bool  WaypointsManager::isCheckedOut() {
	return (_checkoutIterator != _waypoints.end());
}

size_t WaypointsManager::getCheckedOutIdx() {
	return _checkoutIdx;
}