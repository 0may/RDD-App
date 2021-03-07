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
#include "TimeEditComponent.h"
#include "Time.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaypointPlayerComponent  : public juce::Component,
                                 public juce::ChangeListener,
                                 public juce::Button::Listener
{
public:
    //==============================================================================
    WaypointPlayerComponent ();
    ~WaypointPlayerComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void update();
    void changeListenerCallback(ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* stop_png;
    static const int stop_pngSize;
    static const char* rec_png;
    static const int rec_pngSize;
    static const char* play_png;
    static const int play_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    rdd::Time _playTime;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ImageButton> _buttonStop;
    std::unique_ptr<juce::ImageButton> _buttonArm;
    std::unique_ptr<juce::ImageButton> _buttonPlay;
    std::unique_ptr<TimeEditComponent> _playtimeComponent;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaypointPlayerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

