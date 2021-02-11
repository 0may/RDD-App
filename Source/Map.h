/*
  ==============================================================================

    Map.h
    Created: 11 Feb 2021 10:11:09pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace rdd {

    class Map {

    public:
        Map();


        bool loadMap(File yamlFile);

        Image& getMapImage();

        inline float getResolution() { return _resolution; }

        inline Vector3D<float>& getOrigin();

        float getOccupiedThresh();

        float getFreeThresh();

        bool getNegate();

        inline bool isLoaded() { return _resolution != 0.0f; };


    protected:
        String _mapImagePath;
        Image _mapImage;
        float _resolution;
        Vector3D<float> _origin;
        float _occupiedThresh;
        float _freeThresh;
        bool _negate;

    };
};