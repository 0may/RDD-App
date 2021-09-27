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
#include "MidiSettings.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiSettingsComponent  : public juce::Component,
                               public juce::ChangeListener,
                               public juce::Slider::Listener,
                               public juce::Button::Listener
{
public:
    //==============================================================================
    MidiSettingsComponent ();
    ~MidiSettingsComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setMidiSettings(rdd::MidiSettings* midiSettings);

    void changeListenerCallback(ChangeBroadcaster* source) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    rdd::MidiSettings* _midiSettings;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> _labelChannel;
    std::unique_ptr<juce::Slider> _sliderChannel;
    std::unique_ptr<juce::Label> _labelResend;
    std::unique_ptr<juce::Slider> _sliderResend;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Label> _labelMoveForward;
    std::unique_ptr<juce::Slider> _sliderMoveForward;
    std::unique_ptr<juce::Label> _labelMoveBack;
    std::unique_ptr<juce::Slider> _sliderMoveBack;
    std::unique_ptr<juce::Label> _labelStrafeLeft;
    std::unique_ptr<juce::Slider> _sliderStrafeLeft;
    std::unique_ptr<juce::Label> _labelStrafeRight;
    std::unique_ptr<juce::Slider> _sliderStrafeRight;
    std::unique_ptr<juce::Label> _labelRotateLeft;
    std::unique_ptr<juce::Slider> _sliderRotateLeft;
    std::unique_ptr<juce::Label> _labelRotateRight;
    std::unique_ptr<juce::Slider> _sliderRotateRight;
    std::unique_ptr<juce::Label> _labelSpeakerUp;
    std::unique_ptr<juce::Slider> _sliderSpeakerUp;
    std::unique_ptr<juce::Label> _labelSpeakerDown;
    std::unique_ptr<juce::Slider> _sliderSpeakerDown;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> _labelMoveSpeed;
    std::unique_ptr<juce::Slider> _sliderMoveSpeed;
    std::unique_ptr<juce::Label> _labelRotateSpeed;
    std::unique_ptr<juce::Slider> _sliderRotateSpeed;
    std::unique_ptr<juce::Label> _labelSpeakerSpeed;
    std::unique_ptr<juce::Slider> _sliderSpeakerSpeed;
    std::unique_ptr<juce::Label> _labelSpeakerPosQ1;
    std::unique_ptr<juce::Slider> _sliderSpeakerPosQ1;
    std::unique_ptr<juce::Label> _labelSpeakerPosQ2;
    std::unique_ptr<juce::Slider> _sliderSpeakerPosQ2;
    std::unique_ptr<juce::Label> _labelSpeakerPosQ3;
    std::unique_ptr<juce::Slider> _sliderSpeakerPosQ3;
    std::unique_ptr<juce::Label> _labelSpeakerPosQ4;
    std::unique_ptr<juce::Slider> _sliderSpeakerPosQ4;
    std::unique_ptr<juce::Label> _labelSpeakerPosRst;
    std::unique_ptr<juce::Slider> _sliderSpeakerPosRst;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent;
    std::unique_ptr<juce::ToggleButton> _buttonInvertSpeaker;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiSettingsComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

