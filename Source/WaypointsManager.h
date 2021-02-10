/*
  ==============================================================================

    WaypointsManager.h
    Created: 5 Jan 2021 1:22:13pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <set>
#include <JuceHeader.h>
#include "Waypoint.h"

using namespace std;
using namespace rdd;


class WaypointsManager : public juce::ChangeBroadcaster {

public: 

	struct WaypointComparator {
		bool operator() (const Waypoint* lhs, const Waypoint* rhs) const
		{
			return lhs->t < rhs->t;
		}
	};


public:
	WaypointsManager();

	~WaypointsManager();

	/** Returns the number of waypoints stored in the manager */
	size_t getNumWaypoints() const;

	/** Get a waypoint by index in the set of waypoints, read only */
	const Waypoint* getWaypoint(size_t idx) const;

	/** Add a new waypoint, 10 seconds after the last waypoint. 
		Only successfull if no waypoint is checked out. Returns 
		the index of the new waypoint or size_t::max on failure.
	*/
	size_t addNewWaypoint();

	/** Checkout a waypoint, i.e. make it editable */
	Waypoint* checkoutWaypoint(size_t idx);

	/** Get a pointer to a checked out waypoint. Returns nullptr if none is checked out. */
	Waypoint* getCheckedOutWaypoint();

	/** Commit a checked out waypoint, i.e. it is newly inserted to be sorted by time */
	bool commitWaypoint();

	/** Returns true if a waypoint is checked out, false otherwise */
	bool isCheckedOut();

	/** Get the index of a checked out waypoint. Returns size_t::max if none is checked out. */
	size_t getCheckedOutIdx();

	/** Deletes the checked out waypoint. Returns true on success, false on failure or if no waypoint is checked out. */
	bool deleteCheckedOutWaypoint();

	set<Waypoint*, WaypointComparator>::const_iterator cbegin();
	set<Waypoint*, WaypointComparator>::const_iterator cend();

	bool clear(bool requireNoCheckOut = true);

	void saveWaypoints(File f, bool minify = true);

	void loadWaypoints(File f);



private:
	set<Waypoint*, WaypointComparator> _waypoints;

	set<Waypoint*, WaypointComparator>::iterator _checkoutIterator;

	size_t _checkoutIdx;

	bool _isClearing;

};