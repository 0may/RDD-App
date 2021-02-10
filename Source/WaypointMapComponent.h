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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaypointMapComponent  : public juce::Component,
                              public juce::ChangeListener
{
public:
    //==============================================================================
    WaypointMapComponent ();
    ~WaypointMapComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void calculateMapArea();

    void drawWaypoint(juce::Graphics& g, rdd::Waypoint* wp, bool highlight);

    void changeListenerCallback(ChangeBroadcaster* source) override;

    Point<float> mapToScreen(float mapX, float mapY);
    Point<float> screenToMap(float screenX, float screenY);


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

	Image _mapImg;
	float _mapZoom;
	float _mapOffsetX;
	float _mapOffsetY;

	float _mapDisplayX, _mapDisplayY, _mapDisplayW, _mapDisplayH;

	Point<int> _mousePosition;

    float _wpSizeS, _wpSizeS2, _wpOffS, _wpOffS2;
    float _wpSizeL, _wpSizeL2, _wpOffL, _wpOffL2;

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaypointMapComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

