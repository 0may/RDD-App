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

using namespace std;


class WaypointsManager {

public: 
	struct Waypoint {
		double t;
		int B;
		float x;
		float y;
		float alpha;
		float beta;
		String name;
	};

	struct WaypointComparator {
		bool operator() (const Waypoint& lhs, const Waypoint& rhs) const
		{
			return lhs.t < rhs.t;
		}
	};


public:
	WaypointsManager();
	~WaypointsManager();

	size_t getNumWaypoínts() const;

	const Waypoint& getWaypoint(size_t idx) const;

	bool addWaypoint(Waypoint wp);

	Waypoint& checkoutWaypoint(size_t idx);

	bool commitWaypoint();



private:
	set<Waypoint, WaypointComparator> _waypoints;

	set<Waypoint, WaypointComparator>::iterator _checkoutIterator;

};