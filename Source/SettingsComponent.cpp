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
#include "MainManager.h"
//[/Headers]

#include "SettingsComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SettingsComponent::SettingsComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _midiSettingsComponent.reset (new MidiSettingsComponent());
    addAndMakeVisible (_midiSettingsComponent.get());
    _midiSettingsComponent->setName ("new component");

    _midiSettingsComponent->setBounds (248, 0, 600, 500);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	_midiInputComponent.addChangeListener(&rdd::MainManager::instance().getMidiController());
	_midiOutputComponent.addChangeListener(&rdd::MainManager::instance().getMidiController());

	addAndMakeVisible(_midiInputComponent);
	addAndMakeVisible(_midiOutputComponent);

    //[/Constructor]
}

SettingsComponent::~SettingsComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _midiSettingsComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SettingsComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SettingsComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

	// now position the child components
    setBounds(0, 0, _midiSettingsComponent->getWidth(), _midiInputComponent.getHeight() + _midiOutputComponent.getHeight() + _midiSettingsComponent->getHeight());

	auto area = getLocalBounds();

	_midiInputComponent.setBounds(area.removeFromTop(_midiInputComponent.getBounds().getHeight()));

	_midiOutputComponent.setBounds(area.removeFromTop(_midiOutputComponent.getBounds().getHeight()));


    _midiSettingsComponent->setBounds(area.removeFromTop(500));
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

<JUCER_COMPONENT documentType="Component" className="SettingsComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="new component" id="40bc1408f763c95c" memberName="_midiSettingsComponent"
                    virtualName="" explicitFocusOrder="0" pos="248 0 600 500" class="MidiSettingsComponent"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

