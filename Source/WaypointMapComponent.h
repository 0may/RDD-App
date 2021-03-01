/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "Waypoint.h"
#include "Map.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaypointMapComponent  : public juce::Component,
                              public juce::ChangeBroadcaster,
                              public juce::ChangeListener
{
public:
    //==============================================================================
    WaypointMapComponent ();
    ~WaypointMapComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void calculateMapArea();

    void drawWaypoint(juce::Graphics& g, rdd::Waypoint* wp, bool highlight, float opaqueness = 1.0f);

    bool waypointHit(Point<int> mousePosition, size_t& wpIdx);
    inline float waypointHitDistance(Point<int> mousePosition, rdd::Waypoint* wp) {
        return mapToScreen(wp->x, wp->y).getDistanceFrom(Point<float>((float)mousePosition.x, (float)mousePosition.y));
    }

    Point<float> mapToScreen(float mapX, float mapY);
    Point<float> screenToMap(float screenX, float screenY);
    void setTrails(uint16 trails);

    void changeListenerCallback(ChangeBroadcaster* source) override;

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void mouseDown (const juce::MouseEvent& e) override;
    void mouseDrag (const juce::MouseEvent& e) override;
    void mouseUp (const juce::MouseEvent& e) override;
    void mouseDoubleClick (const juce::MouseEvent& e) override;
    void mouseWheelMove (const juce::MouseEvent& e, const juce::MouseWheelDetails& wheel) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    rdd::Map _map;
	Image _mapImg;
	float _mapZoom;
	float _mapOffsetX;
	float _mapOffsetY;

	float _mapDisplayX, _mapDisplayY, _mapDisplayW, _mapDisplayH;
    float _mapDisplayScaling;

	Point<int> _mousePosition;

    float _wpSizeS, _wpSizeS2, _wpOffS, _wpOffS2;
    float _wpSizeL, _wpSizeL2, _wpOffL, _wpOffL2;

    bool _wpMove, _wpRotateA, _wpRotateB;

    uint16 _wpTrails;

public:
    enum ColourIds {
        wpAlphaColourId,
        wpBetaColourId,
        trailsPastColourId,
        trailsFutureColourId
    };
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaypointMapComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

