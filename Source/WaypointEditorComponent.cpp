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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "WaypointEditorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WaypointEditorComponent::WaypointEditorComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _waypointMapComponent.reset (new WaypointMapComponent());
    addAndMakeVisible (_waypointMapComponent.get());
    _waypointMapComponent->setName ("waypoint map component");

    _waypointEditComponent.reset (new WaypointEditComponent());
    addAndMakeVisible (_waypointEditComponent.get());
    _waypointEditComponent->setName ("new component");

    _waypointTableComponent.reset (new WaypointTableComponent());
    addAndMakeVisible (_waypointTableComponent.get());
    _waypointTableComponent->setName ("waypoints list");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WaypointEditorComponent::~WaypointEditorComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _waypointMapComponent = nullptr;
    _waypointEditComponent = nullptr;
    _waypointTableComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaypointEditorComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaypointEditorComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _waypointMapComponent->setBounds (0, 0, getWidth() - 300, proportionOfHeight (1.0000f));
    _waypointEditComponent->setBounds (getWidth() - 295, getHeight() - 200, 295, 200);
    _waypointTableComponent->setBounds (getWidth() - 295, 0, 295, getHeight() - 205);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaypointEditorComponent"
                 componentName="" parentClasses="public juce::Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="waypoint map component" id="d65263966a94c1f6" memberName="_waypointMapComponent"
                    virtualName="" explicitFocusOrder="0" pos="0 0 300M 100%" class="WaypointMapComponent"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="bf5ef8d35dbf4612" memberName="_waypointEditComponent"
                    virtualName="" explicitFocusOrder="0" pos="0Rr 0Rr 295 200" class="WaypointEditComponent"
                    params=""/>
  <GENERICCOMPONENT name="waypoints list" id="a77f7f5f159169f" memberName="_waypointTableComponent"
                    virtualName="" explicitFocusOrder="0" pos="0Rr 0 295 205M" class="WaypointTableComponent"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

