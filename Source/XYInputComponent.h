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
class XYInputComponent  : public Component,
                          public ChangeBroadcaster
{
public:
    //==============================================================================
    XYInputComponent (int width, int height, String identifier);
    ~XYInputComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setMapping(float xLeft, float xRight, float yTop, float yBottom);

	bool hasInput() const;

	const Point<int>& getInput() const;
	Point<float> getMappedInput() const;


	const Point<int>& getInputPrevious() const;
	Point<float> getMappedInputPrevious() const;

	const String& getIdentifier() const;

	void mouseDown(const MouseEvent& event) override;
	void mouseDrag(const MouseEvent& event) override;
	void mouseUp(const MouseEvent& event) override;

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool _mouseDown;
	Point<int> _mouseInput;
	Point<int> _mouseInputPrevious;

	enum InputDimensions {
		XY,
		X,
		Y
	} _inputDims;

	float _mapX[2];
	float _mapY[2];

	String _identifier;


public:
	enum ColourIds {
		indicatorColourId,
		backgroundColourId,
		borderColourId
	};

    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (XYInputComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

