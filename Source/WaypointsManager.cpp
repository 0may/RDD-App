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
	_isClearing = false;
}


WaypointsManager::~WaypointsManager() {
	clear(false);
}


size_t WaypointsManager::getNumWaypoints() const {
	if (_isClearing)
		return 0;
	else
		return _waypoints.size();
}


const rdd::Waypoint* WaypointsManager::getWaypoint(size_t idx) const {

	if (_isClearing || idx >= _waypoints.size())
		return nullptr;

	set<Waypoint*, WaypointComparator>::const_iterator it = _waypoints.begin();

	for (size_t i = 0; i < idx; i++)
		it++;

	return *it;
}


size_t WaypointsManager::addNewWaypoint() {


	if (!isCheckedOut() && !_isClearing) {

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

	if (!isCheckedOut() && !_isClearing && idx < _waypoints.size()) {

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
	if (isCheckedOut() && !_isClearing)
		return *_checkoutIterator;
	else
		return nullptr;
}


bool WaypointsManager::commitWaypoint() {

	if (isCheckedOut() && !_isClearing) {
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


bool WaypointsManager::isCheckedOut() {
	return (_checkoutIterator != _waypoints.end());
}

size_t WaypointsManager::getCheckedOutIdx() {
	return _checkoutIdx;
}



bool WaypointsManager::deleteCheckedOutWaypoint() {
	if (isCheckedOut() && !_isClearing) {
		_waypoints.erase(_checkoutIterator);
		_checkoutIterator = _waypoints.end();
		_checkoutIdx = -1;

		sendChangeMessage();

		return true;
	}
	else
		return false;
}

set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator WaypointsManager::cbegin() {
	return _waypoints.cbegin();
}


set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator WaypointsManager::cend() {
	return _waypoints.cend();
}




bool WaypointsManager::clear(bool requireNoCheckOut) {

	if (requireNoCheckOut && isCheckedOut()) {
		return false;
	}
	else {
		_isClearing = true;

		commitWaypoint();

		set<Waypoint*, WaypointComparator>::iterator it = _waypoints.begin();

		while (it != _waypoints.end()) {
			delete (*it);
			it++;
		}

		_waypoints.clear();

		_checkoutIterator = _waypoints.end();
		_checkoutIdx = -1;

		_isClearing = false;

		return true;
	}


}

void WaypointsManager::saveWaypoints(File f, bool minify) {

}

void WaypointsManager::loadWaypoints(File f) {

}