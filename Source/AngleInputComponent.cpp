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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "AngleInputComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
AngleInputComponent::AngleInputComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	_min = 0.0f;
	_max = 360.0f;
	_angle = 0.0f;


	setColour(ColourIds::indicatorColourId, Colour(0xffa45c94));
	setColour(ColourIds::backgroundColourId, Colour(0xff121e24));
	setColour(ColourIds::borderColourId, Colour(0xffafafaf));
    //[/Constructor]
}

AngleInputComponent::~AngleInputComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AngleInputComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]



    //[UserPaint] Add your own custom painting code here..

	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));


	int s = (getWidth() > getHeight()) ? getHeight() : getWidth();

	// draw background
	g.setColour(findColour(ColourIds::backgroundColourId));
	g.drawEllipse(s*0.25f, s*0.25f, s*0.5f, s*0.5f, s*0.4f);

	// draw indicator



	// draw borders
	g.setColour(findColour(ColourIds::borderColourId));
	g.drawEllipse(s*0.05f, s*0.05f, s*0.9f, s*0.9f, 1.0f);
	g.drawEllipse(s*0.45f, s*0.45f, s*0.1f, s*0.1f, 1.0f);


    //[/UserPaint]
}

void AngleInputComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void AngleInputComponent::setMapping(float min, float max) {
	_min = min;
	_max = max;
}


float AngleInputComponent::getAngle() const {
	return _angle;
}


float AngleInputComponent::getMappedAngle() const {
	return _angle / (float_Pi*2.0f) * (_max - _min) + _min;
}



//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="AngleInputComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

