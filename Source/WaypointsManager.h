/*
  ==============================================================================

    WaypointsManager.h
    Created: 5 Jan 2021 1:22:13pm
    Author:  Oliver Mayer

  ==============================================================================
*/

#pragma once

#include <set>

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
	};


public:
	WaypointsManager();
	~WaypointsManager();



private:
	set<Waypoint> _waypoints;

};