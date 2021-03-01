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
#include "TimeInputListener.h"
#include "Time.h"

using namespace rdd;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TimeEditComponent  : public juce::Component
{
public:
    //==============================================================================
    TimeEditComponent ();
    ~TimeEditComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.


    friend class WaypointEditComponent;

    void setTimeObject(rdd::Time* time);
    void update();

    void setEditable(bool editable);

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    rdd::Time* _time;
    TimeInputListener* _timeInputListener;


private:
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextEditor> _mins;
    std::unique_ptr<juce::TextEditor> _secs;
    std::unique_ptr<juce::TextEditor> _millis;
    std::unique_ptr<juce::TextEditor> _hours;
    std::unique_ptr<juce::Label> _dpLabel;
    std::unique_ptr<juce::Label> _dpLabel2;
    std::unique_ptr<juce::Label> _periodLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TimeEditComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

