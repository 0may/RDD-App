/*
  ==============================================================================

    Waypoint.h
    Created: 9 Feb 2021 10:04:42am
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>


namespace rdd {

    class Waypoint {

    public:

        Waypoint();


        double t;
        int B;
        float x;
        float y;
        float alpha;
        float beta;
        String name;
    };


};