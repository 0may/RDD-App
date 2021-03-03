/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MainMenuComponent.h"
#include "TabsComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    TabsComponent _tabsComponent;
    unique_ptr<MainMenuComponent> _menuComponent;

	//MidiInputDeviceSelectorComponent _midiInputComponent;
	//MidiOutputDeviceSelectorComponent _midiOutputComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
