/*
  ==============================================================================

    Waypoint.cpp
    Created: 9 Feb 2021 10:04:42am
    Author:  omay

  ==============================================================================
*/

#include "Waypoint.h"


using namespace rdd;


Waypoint::Waypoint()
{
    t = 0.0;
    B = 0;
    x = 0.0;
    y = 0.0;
    alpha = 0.0;
    beta = 0.0;
    name = "wp";
}


String Waypoint::toJSON(bool minify) {
    String s = "";
    return s;
}