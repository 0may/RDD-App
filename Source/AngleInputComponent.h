/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class AngleInputComponent  : public juce::Component,
                             public ChangeBroadcaster
{
public:
    //==============================================================================
    AngleInputComponent ();
    ~AngleInputComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	// set a mapping from the internal radian representation (0 to 2*PI).
	// Default mapping is 0 to 360. Note that 'max' is exclusive
	void setMapping(float min, float max);

	float getAngle() const;
	float getMappedAngle() const;


	void mouseDown(const MouseEvent& event) override;
	void mouseDrag(const MouseEvent& event) override;
	void mouseUp(const MouseEvent& event) override;


	static Point<float> toPoint(float dist, float angle);
	static float toAngle(float x, float y);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool _mouseDown;

	float _angle;
	float _min, _max;


public:
	enum ColourIds {
		indicatorColourId,
		backgroundColourId,
		borderColourId
	};

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AngleInputComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

