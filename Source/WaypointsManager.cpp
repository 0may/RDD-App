/*
  ==============================================================================

    WaypointsManager.cpp
    Created: 5 Jan 2021 1:22:13pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#include "WaypointsManager.h"
#include "Util.h"



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
		delete (*_checkoutIterator);
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

bool WaypointsManager::saveWaypoints(File f, bool minify) {

	if (_waypoints.empty())
		return false;

	commitWaypoint();
	
	set<Waypoint*, WaypointsManager::WaypointComparator>::const_iterator it = _waypoints.cbegin();
	size_t n = 0;
	FileOutputStream outfile(f);


	if (!outfile.openedOk()) 
		return false;


	outfile.setPosition(0);
	outfile.truncate();

	if (minify) {
		outfile << "{\"waypoints\":[";

		while (it != _waypoints.cend()) {

			outfile << "{";

			outfile << "\"n\":" << String(n) << ",";
			outfile << "\"t\":" << Util::toString((*it)->t) << ",";
			outfile << "\"B\":" << String((*it)->B) << ",";
			outfile << "\"x\":" << Util::toString((*it)->x) << ",";
			outfile << "\"y\":" << Util::toString((*it)->y) << ",";
			outfile << "\"alpha\":" << Util::toString((*it)->alpha) << ",";
			outfile << "\"beta\":" << Util::toString((*it)->beta) << ",";
			outfile << "\"name\":\"" << (*it)->name << "\"";

			if (n < _waypoints.size()-1)
				outfile << "},";
			else
				outfile << "}";

			n++;
			it++;
		}

		outfile << "]}";
	}
	else {
		outfile << "{\n\t\"waypoints\": [\n";

		while (it != _waypoints.cend()) {

			outfile << "\t{\n";

			outfile << "\t\t\"n\": " << String(n) << ",\n";
			outfile << "\t\t\"t\": " << Util::toString((*it)->t) << ",\n";
			outfile << "\t\t\"B\": " << String((*it)->B) << ",\n";
			outfile << "\t\t\"x\": " << Util::toString((*it)->x) << ",\n";
			outfile << "\t\t\"y\": " << Util::toString((*it)->y) << ",\n";
			outfile << "\t\t\"alpha\": " << Util::toString((*it)->alpha) << ",\n";
			outfile << "\t\t\"beta\": " << Util::toString((*it)->beta) << ",\n";
			outfile << "\t\t\"name\": \"" << (*it)->name << "\"\n";

			if (n < _waypoints.size() - 1)
				outfile << "\t},\n";
			else
				outfile << "\t}\n";

			n++;
			it++;
		}

		outfile << "\t]\n}";
	}

	outfile.flush();

	return true;
}


bool WaypointsManager::loadWaypoints(File f) {
	bool success;
	DynamicObject* wpObj;
	Waypoint* wp;

	commitWaypoint();
	clear();


	var json = JSON::parse(f);



	if (json.isObject()) {
		auto* obj = json.getDynamicObject();

		auto* wpArray = Util::getArrayFromJsonObject(obj, "waypoints");

		if (!wpArray)
			return false;

		for (int i = 0; i < wpArray->size(); i++) {
			if (wpArray->operator[](i).isObject()) {

				

				wpObj = wpArray->operator[](i).getDynamicObject();

				wp = checkoutWaypoint(addNewWaypoint());

				success = true;

				success &= Util::getDoubleFromJsonObject(wpObj, "t", wp->t);
				success &= Util::getFloatFromJsonObject(wpObj, "x", wp->x);
				success &= Util::getFloatFromJsonObject(wpObj, "y", wp->y);
				success &= Util::getFloatFromJsonObject(wpObj, "alpha", wp->alpha);
				success &= Util::getFloatFromJsonObject(wpObj, "beta", wp->beta);
				success &= Util::getStringFromJsonObject(wpObj, "name", wp->name);

				wp = nullptr;

				if (success)
					commitWaypoint();
				else
					deleteCheckedOutWaypoint();
			}
		}

		sendChangeMessage();

		return true;
	}
	else
		return false;
	
}