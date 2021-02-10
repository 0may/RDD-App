/*
  ==============================================================================

    Util.h
    Created: 10 Feb 2021 8:46:51pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace rdd {

    class Util {

    protected:
        Util() {};

    public:
        static Point<float> polarToCartesian(float angle, float dist, bool flipY = false) {
            if (flipY)
               return Point<float>(dist * cos(angle), -dist * sin(angle));
            else
               return Point<float>(dist * cos(angle), dist * sin(angle));
        }







    };
};