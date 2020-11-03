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
class ManualControlComponent  : public Component,
                                public ApplicationCommandTarget,
                                public juce::Slider::Listener
{
public:
    //==============================================================================
    ManualControlComponent ();
    ~ManualControlComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.


	// ApplicationCommandTarget methods to override
	ApplicationCommandTarget * 	getNextCommandTarget() override;
	void getAllCommands(Array< CommandID > &commands) override;
	void getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) override;
	bool perform(const InvocationInfo &info) override;


    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int _sep1x, _sep2x;  // x-coordinate of the two vertical separators

	int8 _moveFB;      // indicator if the forward (-1) or backward (1) move command is active, 0 for inactive
	int8 _moveLR;		// indicator if the left (-1) or right (1) move command is active, 0 for inactive
	int8 _rotateLR;    // indicator if the left (-1) or right (1) rotate command is active, 0 for inactive
	int8 _speakerUD;   // indicator if the up (-1) or down (1) speaker rotate command is active, 0 for inactive


public:

	enum ColourIds {
		backgroundColourId,
		separatorColourId
	};

private:

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
    std::unique_ptr<juce::Slider> _sliderSpkVelocity;
    std::unique_ptr<juce::Label> _labelSpkVelocity;
    std::unique_ptr<juce::Slider> _sliderRotationVelocity;
    std::unique_ptr<juce::Label> _labelRotationVelocity;
    std::unique_ptr<juce::Slider> _sliderTranslationVelocity;
    std::unique_ptr<juce::Label> _labelTranslationVelocity;
    std::unique_ptr<juce::Label> _labelDefaultVelos;
    std::unique_ptr<juce::Label> _labelInput;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ManualControlComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

