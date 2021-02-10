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
#include "Waypoint.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaypointEditComponent  : public juce::Component,
                               public juce::ChangeListener,
                               public juce::ChangeBroadcaster,
                               public juce::ComboBox::Listener
{
public:
    //==============================================================================
    WaypointEditComponent ();
    ~WaypointEditComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    void setWaypoint(rdd::Waypoint* wp);
    void changeListenerCallback(ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    String correctFloatInput(TextEditor* e);


    rdd::Waypoint* _waypoint;
    rdd::Time _time;  // time object buffer
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> _tLabel;
    std::unique_ptr<juce::Label> _BLabel;
    std::unique_ptr<juce::Label> _xLabel;
    std::unique_ptr<juce::Label> _yLabel;
    std::unique_ptr<juce::Label> _alphaLabel;
    std::unique_ptr<juce::Label> _betaLabel;
    std::unique_ptr<juce::Label> _nameLabel;
    std::unique_ptr<juce::TextEditor> _alphaTextEditor;
    std::unique_ptr<juce::TextEditor> _betaTextEditor;
    std::unique_ptr<juce::TextEditor> _yTextEditor;
    std::unique_ptr<juce::TextEditor> _xTextEditor;
    std::unique_ptr<juce::TextEditor> _nameTextEditor;
    std::unique_ptr<juce::ComboBox> _BComboBox;
    std::unique_ptr<TimeEditComponent> _tTimeEdit;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaypointEditComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

