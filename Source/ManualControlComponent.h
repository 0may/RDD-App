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
#include "XYInputComponent.h"
#include "AngleInputComponent.h"
#include "MidiController.h"
#include "MidiSequenceManagerComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ManualControlComponent  : public Component
{
public:
    //==============================================================================
    ManualControlComponent ();
    ~ManualControlComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<MidiSequenceManagerComponent> _sequenceManager;
    std::unique_ptr<XYInputComponent> _inputTranslation;
    std::unique_ptr<juce::Label> _labelTranslation;
    std::unique_ptr<juce::Label> _labelRotation;
    std::unique_ptr<XYInputComponent> _inputRotation;
    std::unique_ptr<XYInputComponent> _inputSpkRotation;
    std::unique_ptr<juce::Label> _labelSpkRotation;
    std::unique_ptr<AngleInputComponent> _inputSpkAngle;
    std::unique_ptr<juce::Label> _labelSpkAngle;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ManualControlComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

