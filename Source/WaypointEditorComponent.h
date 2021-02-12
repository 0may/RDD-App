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
#include "WaypointMapComponent.h"
#include "WaypointEditComponent.h"
#include "WaypointTableComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaypointEditorComponent  : public juce::Component,
                                 public juce::ChangeListener,
                                 public juce::Button::Listener,
                                 public juce::Slider::Listener
{
public:
    //==============================================================================
    WaypointEditorComponent ();
    ~WaypointEditorComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback(ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;

    // Binary resources:
    static const char* minus_png;
    static const int minus_pngSize;
    static const char* plus_png;
    static const int plus_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<WaypointMapComponent> _waypointMapComponent;
    std::unique_ptr<WaypointEditComponent> _waypointEditComponent;
    std::unique_ptr<WaypointTableComponent> _waypointTableComponent;
    std::unique_ptr<juce::ImageButton> _buttonDelete;
    std::unique_ptr<juce::ImageButton> _buttonAdd;
    std::unique_ptr<juce::TextButton> _buttonLoad;
    std::unique_ptr<juce::TextButton> _buttonSave;
    std::unique_ptr<juce::TextButton> _buttonSend;
    std::unique_ptr<juce::Label> _waypointTableLabel;
    std::unique_ptr<juce::Label> _waypointEditLabel;
    std::unique_ptr<juce::Label> _waypointMapLabel;
    std::unique_ptr<juce::Slider> _trailHideSlider;
    std::unique_ptr<juce::Label> _trailHideLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaypointEditorComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

