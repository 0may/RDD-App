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
#include "RobotsManager.h"
//[/Headers]

#include "MidiSettingsComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiSettingsComponent::MidiSettingsComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _labelChannel.reset (new juce::Label ("channel label",
                                          TRANS("Channel")));
    addAndMakeVisible (_labelChannel.get());
    _labelChannel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelChannel->setJustificationType (juce::Justification::centredLeft);
    _labelChannel->setEditable (false, false, false);
    _labelChannel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelChannel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelChannel->setBounds (20, 21, 88, 24);

    _sliderChannel.reset (new juce::Slider ("channel slider"));
    addAndMakeVisible (_sliderChannel.get());
    _sliderChannel->setRange (1, 16, 1);
    _sliderChannel->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderChannel->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderChannel->addListener (this);

    _labelResend.reset (new juce::Label ("resend label",
                                         TRANS("Resend")));
    addAndMakeVisible (_labelResend.get());
    _labelResend->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelResend->setJustificationType (juce::Justification::centredLeft);
    _labelResend->setEditable (false, false, false);
    _labelResend->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelResend->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelResend->setBounds (20, 61, 88, 24);

    _sliderResend.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderResend.get());
    _sliderResend->setRange (0, 5, 1);
    _sliderResend->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderResend->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderResend->addListener (this);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("-- Note Commands --")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (64, 109, 150, 24);

    _labelMoveForward.reset (new juce::Label ("note1 label",
                                              TRANS("Move Forward")));
    addAndMakeVisible (_labelMoveForward.get());
    _labelMoveForward->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelMoveForward->setJustificationType (juce::Justification::centredLeft);
    _labelMoveForward->setEditable (false, false, false);
    _labelMoveForward->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelMoveForward->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelMoveForward->setBounds (22, 147, 110, 24);

    _sliderMoveForward.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderMoveForward.get());
    _sliderMoveForward->setRange (1, 127, 1);
    _sliderMoveForward->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderMoveForward->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderMoveForward->addListener (this);

    _labelMoveBack.reset (new juce::Label ("note1 label",
                                           TRANS("Move Backward")));
    addAndMakeVisible (_labelMoveBack.get());
    _labelMoveBack->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelMoveBack->setJustificationType (juce::Justification::centredLeft);
    _labelMoveBack->setEditable (false, false, false);
    _labelMoveBack->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelMoveBack->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelMoveBack->setBounds (22, 190, 110, 24);

    _sliderMoveBack.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderMoveBack.get());
    _sliderMoveBack->setRange (1, 127, 1);
    _sliderMoveBack->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderMoveBack->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderMoveBack->addListener (this);

    _labelStrafeLeft.reset (new juce::Label ("note1 label",
                                             TRANS("Strafe Left")));
    addAndMakeVisible (_labelStrafeLeft.get());
    _labelStrafeLeft->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelStrafeLeft->setJustificationType (juce::Justification::centredLeft);
    _labelStrafeLeft->setEditable (false, false, false);
    _labelStrafeLeft->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelStrafeLeft->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelStrafeLeft->setBounds (22, 235, 110, 24);

    _sliderStrafeLeft.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderStrafeLeft.get());
    _sliderStrafeLeft->setRange (1, 127, 1);
    _sliderStrafeLeft->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderStrafeLeft->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderStrafeLeft->addListener (this);

    _labelStrafeRight.reset (new juce::Label ("note1 label",
                                              TRANS("Strafe Right")));
    addAndMakeVisible (_labelStrafeRight.get());
    _labelStrafeRight->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelStrafeRight->setJustificationType (juce::Justification::centredLeft);
    _labelStrafeRight->setEditable (false, false, false);
    _labelStrafeRight->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelStrafeRight->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelStrafeRight->setBounds (22, 278, 110, 24);

    _sliderStrafeRight.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderStrafeRight.get());
    _sliderStrafeRight->setRange (1, 127, 1);
    _sliderStrafeRight->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderStrafeRight->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderStrafeRight->addListener (this);

    _labelRotateLeft.reset (new juce::Label ("note1 label",
                                             TRANS("Rotate Left")));
    addAndMakeVisible (_labelRotateLeft.get());
    _labelRotateLeft->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelRotateLeft->setJustificationType (juce::Justification::centredLeft);
    _labelRotateLeft->setEditable (false, false, false);
    _labelRotateLeft->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelRotateLeft->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelRotateLeft->setBounds (22, 320, 110, 24);

    _sliderRotateLeft.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderRotateLeft.get());
    _sliderRotateLeft->setRange (1, 127, 1);
    _sliderRotateLeft->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderRotateLeft->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderRotateLeft->addListener (this);

    _labelRotateRight.reset (new juce::Label ("note1 label",
                                              TRANS("Rotate Right")));
    addAndMakeVisible (_labelRotateRight.get());
    _labelRotateRight->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelRotateRight->setJustificationType (juce::Justification::centredLeft);
    _labelRotateRight->setEditable (false, false, false);
    _labelRotateRight->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelRotateRight->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelRotateRight->setBounds (22, 363, 110, 24);

    _sliderRotateRight.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderRotateRight.get());
    _sliderRotateRight->setRange (1, 127, 1);
    _sliderRotateRight->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderRotateRight->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderRotateRight->addListener (this);

    _labelSpeakerUp.reset (new juce::Label ("note1 label",
                                            TRANS("Speaker Up")));
    addAndMakeVisible (_labelSpeakerUp.get());
    _labelSpeakerUp->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerUp->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerUp->setEditable (false, false, false);
    _labelSpeakerUp->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerUp->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerUp->setBounds (22, 408, 110, 24);

    _sliderSpeakerUp.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerUp.get());
    _sliderSpeakerUp->setRange (1, 127, 1);
    _sliderSpeakerUp->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerUp->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerUp->addListener (this);

    _labelSpeakerDown.reset (new juce::Label ("note1 label",
                                              TRANS("Speaker Down")));
    addAndMakeVisible (_labelSpeakerDown.get());
    _labelSpeakerDown->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerDown->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerDown->setEditable (false, false, false);
    _labelSpeakerDown->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerDown->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerDown->setBounds (22, 451, 110, 24);

    _sliderSpeakerDown.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerDown.get());
    _sliderSpeakerDown->setRange (1, 127, 1);
    _sliderSpeakerDown->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerDown->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerDown->addListener (this);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("-- CC Commands --")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (367, 110, 150, 24);

    _labelMoveSpeed.reset (new juce::Label ("note1 label",
                                            TRANS("Move Speed")));
    addAndMakeVisible (_labelMoveSpeed.get());
    _labelMoveSpeed->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelMoveSpeed->setJustificationType (juce::Justification::centredLeft);
    _labelMoveSpeed->setEditable (false, false, false);
    _labelMoveSpeed->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelMoveSpeed->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelMoveSpeed->setBounds (325, 148, 110, 24);

    _sliderMoveSpeed.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderMoveSpeed.get());
    _sliderMoveSpeed->setRange (1, 127, 1);
    _sliderMoveSpeed->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderMoveSpeed->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderMoveSpeed->addListener (this);

    _labelRotateSpeed.reset (new juce::Label ("note1 label",
                                              TRANS("Rotate Speed")));
    addAndMakeVisible (_labelRotateSpeed.get());
    _labelRotateSpeed->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelRotateSpeed->setJustificationType (juce::Justification::centredLeft);
    _labelRotateSpeed->setEditable (false, false, false);
    _labelRotateSpeed->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelRotateSpeed->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelRotateSpeed->setBounds (325, 191, 110, 24);

    _sliderRotateSpeed.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderRotateSpeed.get());
    _sliderRotateSpeed->setRange (1, 127, 1);
    _sliderRotateSpeed->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderRotateSpeed->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderRotateSpeed->addListener (this);

    _labelSpeakerSpeed.reset (new juce::Label ("note1 label",
                                               TRANS("Speaker Speed")));
    addAndMakeVisible (_labelSpeakerSpeed.get());
    _labelSpeakerSpeed->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerSpeed->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerSpeed->setEditable (false, false, false);
    _labelSpeakerSpeed->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerSpeed->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerSpeed->setBounds (325, 236, 110, 24);

    _sliderSpeakerSpeed.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerSpeed.get());
    _sliderSpeakerSpeed->setRange (1, 127, 1);
    _sliderSpeakerSpeed->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerSpeed->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerSpeed->addListener (this);

    _labelSpeakerPosQ1.reset (new juce::Label ("note1 label",
                                               TRANS("Speaker Position Q1")));
    addAndMakeVisible (_labelSpeakerPosQ1.get());
    _labelSpeakerPosQ1->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerPosQ1->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerPosQ1->setEditable (false, false, false);
    _labelSpeakerPosQ1->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerPosQ1->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerPosQ1->setBounds (325, 279, 141, 24);

    _sliderSpeakerPosQ1.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerPosQ1.get());
    _sliderSpeakerPosQ1->setRange (1, 127, 1);
    _sliderSpeakerPosQ1->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerPosQ1->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerPosQ1->addListener (this);

    _labelSpeakerPosQ2.reset (new juce::Label ("note1 label",
                                               TRANS("Speaker Position Q2")));
    addAndMakeVisible (_labelSpeakerPosQ2.get());
    _labelSpeakerPosQ2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerPosQ2->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerPosQ2->setEditable (false, false, false);
    _labelSpeakerPosQ2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerPosQ2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerPosQ2->setBounds (325, 321, 141, 24);

    _sliderSpeakerPosQ2.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerPosQ2.get());
    _sliderSpeakerPosQ2->setRange (1, 127, 1);
    _sliderSpeakerPosQ2->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerPosQ2->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerPosQ2->addListener (this);

    _labelSpeakerPosQ3.reset (new juce::Label ("note1 label",
                                               TRANS("Speaker Position Q3")));
    addAndMakeVisible (_labelSpeakerPosQ3.get());
    _labelSpeakerPosQ3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerPosQ3->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerPosQ3->setEditable (false, false, false);
    _labelSpeakerPosQ3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerPosQ3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerPosQ3->setBounds (325, 364, 141, 24);

    _sliderSpeakerPosQ3.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerPosQ3.get());
    _sliderSpeakerPosQ3->setRange (1, 127, 1);
    _sliderSpeakerPosQ3->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerPosQ3->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerPosQ3->addListener (this);

    _labelSpeakerPosQ4.reset (new juce::Label ("note1 label",
                                               TRANS("Speaker Position Q4")));
    addAndMakeVisible (_labelSpeakerPosQ4.get());
    _labelSpeakerPosQ4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerPosQ4->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerPosQ4->setEditable (false, false, false);
    _labelSpeakerPosQ4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerPosQ4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerPosQ4->setBounds (325, 409, 141, 24);

    _sliderSpeakerPosQ4.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerPosQ4.get());
    _sliderSpeakerPosQ4->setRange (1, 127, 1);
    _sliderSpeakerPosQ4->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerPosQ4->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerPosQ4->addListener (this);

    _labelSpeakerPosRst.reset (new juce::Label ("note1 label",
                                                TRANS("Speaker Position Reset")));
    addAndMakeVisible (_labelSpeakerPosRst.get());
    _labelSpeakerPosRst->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpeakerPosRst->setJustificationType (juce::Justification::centredLeft);
    _labelSpeakerPosRst->setEditable (false, false, false);
    _labelSpeakerPosRst->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpeakerPosRst->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSpeakerPosRst->setBounds (325, 452, 157, 24);

    _sliderSpeakerPosRst.reset (new juce::Slider ("resend slider"));
    addAndMakeVisible (_sliderSpeakerPosRst.get());
    _sliderSpeakerPosRst->setRange (1, 127, 1);
    _sliderSpeakerPosRst->setSliderStyle (juce::Slider::IncDecButtons);
    _sliderSpeakerPosRst->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 40, 40);
    _sliderSpeakerPosRst->addListener (this);

    juce__groupComponent.reset (new juce::GroupComponent ("new group",
                                                          TRANS("Midi Settings")));
    addAndMakeVisible (juce__groupComponent.get());

    juce__groupComponent->setBounds (0, 0, 576, 496);

    _buttonInvertSpeaker.reset (new juce::ToggleButton ("invert speaker rotation button"));
    addAndMakeVisible (_buttonInvertSpeaker.get());
    _buttonInvertSpeaker->setButtonText (TRANS("invert speaker rotation"));
    _buttonInvertSpeaker->addListener (this);

    _buttonInvertSpeaker->setBounds (328, 60, 180, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (580, 497);


    //[Constructor] You can add your own custom stuff here..
    this->setMidiSettings(nullptr);
    rdd::RobotsManager::instance().addChangeListener(this);
    //[/Constructor]
}

MidiSettingsComponent::~MidiSettingsComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _labelChannel = nullptr;
    _sliderChannel = nullptr;
    _labelResend = nullptr;
    _sliderResend = nullptr;
    juce__label = nullptr;
    _labelMoveForward = nullptr;
    _sliderMoveForward = nullptr;
    _labelMoveBack = nullptr;
    _sliderMoveBack = nullptr;
    _labelStrafeLeft = nullptr;
    _sliderStrafeLeft = nullptr;
    _labelStrafeRight = nullptr;
    _sliderStrafeRight = nullptr;
    _labelRotateLeft = nullptr;
    _sliderRotateLeft = nullptr;
    _labelRotateRight = nullptr;
    _sliderRotateRight = nullptr;
    _labelSpeakerUp = nullptr;
    _sliderSpeakerUp = nullptr;
    _labelSpeakerDown = nullptr;
    _sliderSpeakerDown = nullptr;
    juce__label2 = nullptr;
    _labelMoveSpeed = nullptr;
    _sliderMoveSpeed = nullptr;
    _labelRotateSpeed = nullptr;
    _sliderRotateSpeed = nullptr;
    _labelSpeakerSpeed = nullptr;
    _sliderSpeakerSpeed = nullptr;
    _labelSpeakerPosQ1 = nullptr;
    _sliderSpeakerPosQ1 = nullptr;
    _labelSpeakerPosQ2 = nullptr;
    _sliderSpeakerPosQ2 = nullptr;
    _labelSpeakerPosQ3 = nullptr;
    _sliderSpeakerPosQ3 = nullptr;
    _labelSpeakerPosQ4 = nullptr;
    _sliderSpeakerPosQ4 = nullptr;
    _labelSpeakerPosRst = nullptr;
    _sliderSpeakerPosRst = nullptr;
    juce__groupComponent = nullptr;
    _buttonInvertSpeaker = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiSettingsComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiSettingsComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _sliderChannel->setBounds (20 + 157, 21 + -1, 79, 24);
    _sliderResend->setBounds (20 + 157, 21 + 39, 80, 24);
    _sliderMoveForward->setBounds (20 + 157, 21 + 127, 80, 24);
    _sliderMoveBack->setBounds (20 + 157, 21 + 170, 80, 24);
    _sliderStrafeLeft->setBounds (20 + 157, 21 + 215, 80, 24);
    _sliderStrafeRight->setBounds (20 + 157, 21 + 258, 80, 24);
    _sliderRotateLeft->setBounds (20 + 157, 21 + 300, 80, 24);
    _sliderRotateRight->setBounds (20 + 157, 21 + 343, 80, 24);
    _sliderSpeakerUp->setBounds (20 + 157, 21 + 388, 80, 24);
    _sliderSpeakerDown->setBounds (20 + 157, 21 + 431, 80, 24);
    _sliderMoveSpeed->setBounds (20 + 460, 21 + 128, 80, 24);
    _sliderRotateSpeed->setBounds (20 + 460, 21 + 171, 80, 24);
    _sliderSpeakerSpeed->setBounds (20 + 460, 21 + 216, 80, 24);
    _sliderSpeakerPosQ1->setBounds (20 + 460, 21 + 259, 80, 24);
    _sliderSpeakerPosQ2->setBounds (20 + 460, 21 + 301, 80, 24);
    _sliderSpeakerPosQ3->setBounds (20 + 460, 21 + 344, 80, 24);
    _sliderSpeakerPosQ4->setBounds (20 + 460, 21 + 389, 80, 24);
    _sliderSpeakerPosRst->setBounds (20 + 460, 21 + 432, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiSettingsComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    if (!_midiSettings)
        return;
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == _sliderChannel.get())
    {
        //[UserSliderCode__sliderChannel] -- add your slider handling code here..
        _midiSettings->setChannel((int)_sliderChannel->getValue());
        //[/UserSliderCode__sliderChannel]
    }
    else if (sliderThatWasMoved == _sliderResend.get())
    {
        //[UserSliderCode__sliderResend] -- add your slider handling code here..
        _midiSettings->setNumResends((int)_sliderResend->getValue());
        //[/UserSliderCode__sliderResend]
    }
    else if (sliderThatWasMoved == _sliderMoveForward.get())
    {
        //[UserSliderCode__sliderMoveForward] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::MOVE_FORWARD, (int)_sliderMoveForward->getValue());
        //[/UserSliderCode__sliderMoveForward]
    }
    else if (sliderThatWasMoved == _sliderMoveBack.get())
    {
        //[UserSliderCode__sliderMoveBack] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::MOVE_BACKWARD, (int)_sliderMoveBack->getValue());
        //[/UserSliderCode__sliderMoveBack]
    }
    else if (sliderThatWasMoved == _sliderStrafeLeft.get())
    {
        //[UserSliderCode__sliderStrafeLeft] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::STRAFE_LEFT, (int)_sliderStrafeLeft->getValue());
        //[/UserSliderCode__sliderStrafeLeft]
    }
    else if (sliderThatWasMoved == _sliderStrafeRight.get())
    {
        //[UserSliderCode__sliderStrafeRight] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::STRAFE_RIGHT, (int)_sliderStrafeRight->getValue());
        //[/UserSliderCode__sliderStrafeRight]
    }
    else if (sliderThatWasMoved == _sliderRotateLeft.get())
    {
        //[UserSliderCode__sliderRotateLeft] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::ROTATE_LEFT, (int)_sliderRotateLeft->getValue());
        //[/UserSliderCode__sliderRotateLeft]
    }
    else if (sliderThatWasMoved == _sliderRotateRight.get())
    {
        //[UserSliderCode__sliderRotateRight] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::ROTATE_RIGHT, (int)_sliderRotateRight->getValue());
        //[/UserSliderCode__sliderRotateRight]
    }
    else if (sliderThatWasMoved == _sliderSpeakerUp.get())
    {
        //[UserSliderCode__sliderSpeakerUp] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::SPEAKER_UP, (int)_sliderSpeakerUp->getValue());
        //[/UserSliderCode__sliderSpeakerUp]
    }
    else if (sliderThatWasMoved == _sliderSpeakerDown.get())
    {
        //[UserSliderCode__sliderSpeakerDown] -- add your slider handling code here..
        _midiSettings->setNote(rdd::MidiSettings::BotCommand::SPEAKER_DOWN, (int)_sliderSpeakerDown->getValue());
        //[/UserSliderCode__sliderSpeakerDown]
    }
    else if (sliderThatWasMoved == _sliderMoveSpeed.get())
    {
        //[UserSliderCode__sliderMoveSpeed] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::MOVE_SPEED, (int)_sliderMoveSpeed->getValue());
        //[/UserSliderCode__sliderMoveSpeed]
    }
    else if (sliderThatWasMoved == _sliderRotateSpeed.get())
    {
        //[UserSliderCode__sliderRotateSpeed] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::ROTATE_SPEED, (int)_sliderRotateSpeed->getValue());
        //[/UserSliderCode__sliderRotateSpeed]
    }
    else if (sliderThatWasMoved == _sliderSpeakerSpeed.get())
    {
        //[UserSliderCode__sliderSpeakerSpeed] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::SPEAKER_SPEED, (int)_sliderSpeakerSpeed->getValue());
        //[/UserSliderCode__sliderSpeakerSpeed]
    }
    else if (sliderThatWasMoved == _sliderSpeakerPosQ1.get())
    {
        //[UserSliderCode__sliderSpeakerPosQ1] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q1, (int)_sliderSpeakerPosQ1->getValue());
        //[/UserSliderCode__sliderSpeakerPosQ1]
    }
    else if (sliderThatWasMoved == _sliderSpeakerPosQ2.get())
    {
        //[UserSliderCode__sliderSpeakerPosQ2] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q2, (int)_sliderSpeakerPosQ2->getValue());
        //[/UserSliderCode__sliderSpeakerPosQ2]
    }
    else if (sliderThatWasMoved == _sliderSpeakerPosQ3.get())
    {
        //[UserSliderCode__sliderSpeakerPosQ3] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q3, (int)_sliderSpeakerPosQ3->getValue());
        //[/UserSliderCode__sliderSpeakerPosQ3]
    }
    else if (sliderThatWasMoved == _sliderSpeakerPosQ4.get())
    {
        //[UserSliderCode__sliderSpeakerPosQ4] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q4, (int)_sliderSpeakerPosQ4->getValue());
        //[/UserSliderCode__sliderSpeakerPosQ4]
    }
    else if (sliderThatWasMoved == _sliderSpeakerPosRst.get())
    {
        //[UserSliderCode__sliderSpeakerPosRst] -- add your slider handling code here..
        _midiSettings->setCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_RESET, (int)_sliderSpeakerPosRst->getValue());
        //[/UserSliderCode__sliderSpeakerPosRst]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MidiSettingsComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _buttonInvertSpeaker.get())
    {
        //[UserButtonCode__buttonInvertSpeaker] -- add your button handler code here..
        _midiSettings->setInvertSpeakerRotation(_buttonInvertSpeaker->getToggleState());
        //[/UserButtonCode__buttonInvertSpeaker]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void MidiSettingsComponent::setMidiSettings(rdd::MidiSettings* midiSettings) {
    _midiSettings = midiSettings;

    if (_midiSettings) {
        this->setEnabled(true);

        _sliderChannel->setValue(_midiSettings->getChannel(), NotificationType::dontSendNotification);
        _sliderResend->setValue(_midiSettings->getNumResends(), NotificationType::dontSendNotification);
        _buttonInvertSpeaker->setToggleState(_midiSettings->isSpeakerRotationInverted(), NotificationType::dontSendNotification);

        _sliderMoveForward->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::MOVE_FORWARD), NotificationType::dontSendNotification);
        _sliderMoveBack->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::MOVE_BACKWARD), NotificationType::dontSendNotification);
        _sliderStrafeLeft->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::STRAFE_LEFT), NotificationType::dontSendNotification);
        _sliderStrafeRight->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::STRAFE_RIGHT), NotificationType::dontSendNotification);
        _sliderRotateLeft->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::ROTATE_LEFT), NotificationType::dontSendNotification);
        _sliderRotateRight->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::ROTATE_RIGHT), NotificationType::dontSendNotification);
        _sliderSpeakerUp->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::SPEAKER_UP), NotificationType::dontSendNotification);
        _sliderSpeakerDown->setValue(_midiSettings->getNote(rdd::MidiSettings::BotCommand::SPEAKER_DOWN), NotificationType::dontSendNotification);

        _sliderMoveSpeed->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::MOVE_SPEED), NotificationType::dontSendNotification);
        _sliderRotateSpeed->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::ROTATE_SPEED), NotificationType::dontSendNotification);
        _sliderSpeakerSpeed->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::SPEAKER_SPEED), NotificationType::dontSendNotification);
        _sliderSpeakerPosQ1->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q1), NotificationType::dontSendNotification);
        _sliderSpeakerPosQ2->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q2), NotificationType::dontSendNotification);
        _sliderSpeakerPosQ3->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q3), NotificationType::dontSendNotification);
        _sliderSpeakerPosQ4->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_Q4), NotificationType::dontSendNotification);
        _sliderSpeakerPosRst->setValue(_midiSettings->getCC(rdd::MidiSettings::BotParameter::SPEAKER_POSITION_RESET), NotificationType::dontSendNotification);
    }
    else
        this->setEnabled(false);

    repaint();
}



void MidiSettingsComponent::changeListenerCallback(ChangeBroadcaster* source) {
    rdd::RobotsManager* rm = dynamic_cast<RobotsManager*>(source);

    if (rm) {
        RobotsManager::Robot* robot = rm->getSelectedRobot();

        if (robot) {
            this->setMidiSettings(&robot->midiSettings);
        }
        else
            this->setMidiSettings(nullptr);
    }
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiSettingsComponent" componentName=""
                 parentClasses="public juce::Component, public juce::ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="580"
                 initialHeight="497">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="channel label" id="f791933f38ac713f" memberName="_labelChannel"
         virtualName="" explicitFocusOrder="0" pos="20 21 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Channel" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="channel slider" id="e08083554e61a935" memberName="_sliderChannel"
          virtualName="" explicitFocusOrder="0" pos="157 -1 79 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="16.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="resend label" id="635e9e04ae798c35" memberName="_labelResend"
         virtualName="" explicitFocusOrder="0" pos="20 61 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Resend" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="7cc214955bce3679" memberName="_sliderResend"
          virtualName="" explicitFocusOrder="0" pos="157 39 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="0.0" max="5.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="bbe425d6711be127" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="64 109 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="-- Note Commands --" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="note1 label" id="e667f84efd5ea3f7" memberName="_labelMoveForward"
         virtualName="" explicitFocusOrder="0" pos="22 147 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Move Forward" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="8a98432394dfb0e3" memberName="_sliderMoveForward"
          virtualName="" explicitFocusOrder="0" pos="157 127 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="a44f3dbe95f2ac9d" memberName="_labelMoveBack"
         virtualName="" explicitFocusOrder="0" pos="22 190 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Move Backward" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="bda8792f31a96d0b" memberName="_sliderMoveBack"
          virtualName="" explicitFocusOrder="0" pos="157 170 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="2003a2d18f6658b2" memberName="_labelStrafeLeft"
         virtualName="" explicitFocusOrder="0" pos="22 235 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Strafe Left" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="1c99a5cb5893bed1" memberName="_sliderStrafeLeft"
          virtualName="" explicitFocusOrder="0" pos="157 215 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="f99681b880d3c4c0" memberName="_labelStrafeRight"
         virtualName="" explicitFocusOrder="0" pos="22 278 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Strafe Right" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="7797693a43b850f1" memberName="_sliderStrafeRight"
          virtualName="" explicitFocusOrder="0" pos="157 258 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="5ec504f00d7d7721" memberName="_labelRotateLeft"
         virtualName="" explicitFocusOrder="0" pos="22 320 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rotate Left" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="21982e42284b2efd" memberName="_sliderRotateLeft"
          virtualName="" explicitFocusOrder="0" pos="157 300 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="e9977d8317895338" memberName="_labelRotateRight"
         virtualName="" explicitFocusOrder="0" pos="22 363 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rotate Right" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="9864f918cb8c6eb1" memberName="_sliderRotateRight"
          virtualName="" explicitFocusOrder="0" pos="157 343 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="3ce5a93500addbc1" memberName="_labelSpeakerUp"
         virtualName="" explicitFocusOrder="0" pos="22 408 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Up" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="2499d162481a5000" memberName="_sliderSpeakerUp"
          virtualName="" explicitFocusOrder="0" pos="157 388 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="7787f49d6ecaedca" memberName="_labelSpeakerDown"
         virtualName="" explicitFocusOrder="0" pos="22 451 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Down" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="50a698e838089246" memberName="_sliderSpeakerDown"
          virtualName="" explicitFocusOrder="0" pos="157 431 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="2f795816d0e2e2eb" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="367 110 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="-- CC Commands --" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="note1 label" id="1ada454d84934f6a" memberName="_labelMoveSpeed"
         virtualName="" explicitFocusOrder="0" pos="325 148 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Move Speed" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="de523266e9daaf" memberName="_sliderMoveSpeed"
          virtualName="" explicitFocusOrder="0" pos="460 128 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="3c6249cf7089fbd9" memberName="_labelRotateSpeed"
         virtualName="" explicitFocusOrder="0" pos="325 191 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Rotate Speed" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="4e674921f9bd5db3" memberName="_sliderRotateSpeed"
          virtualName="" explicitFocusOrder="0" pos="460 171 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="7fcd1117c4153f0b" memberName="_labelSpeakerSpeed"
         virtualName="" explicitFocusOrder="0" pos="325 236 110 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Speed" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="dd2d856fafea14cc" memberName="_sliderSpeakerSpeed"
          virtualName="" explicitFocusOrder="0" pos="460 216 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="7e745dd96f762b2f" memberName="_labelSpeakerPosQ1"
         virtualName="" explicitFocusOrder="0" pos="325 279 141 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Position Q1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="67fe5113b859b88d" memberName="_sliderSpeakerPosQ1"
          virtualName="" explicitFocusOrder="0" pos="460 259 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="dd6cadd96baeab90" memberName="_labelSpeakerPosQ2"
         virtualName="" explicitFocusOrder="0" pos="325 321 141 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Position Q2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="29247bd3c64247d9" memberName="_sliderSpeakerPosQ2"
          virtualName="" explicitFocusOrder="0" pos="460 301 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="a5d86ef66f40af4f" memberName="_labelSpeakerPosQ3"
         virtualName="" explicitFocusOrder="0" pos="325 364 141 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Position Q3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="61b41e73eb993b8" memberName="_sliderSpeakerPosQ3"
          virtualName="" explicitFocusOrder="0" pos="460 344 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="fbcb0069e2a8cb51" memberName="_labelSpeakerPosQ4"
         virtualName="" explicitFocusOrder="0" pos="325 409 141 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Position Q4" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="ba3678dc94d5346e" memberName="_sliderSpeakerPosQ4"
          virtualName="" explicitFocusOrder="0" pos="460 389 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="note1 label" id="5484044ee08c877a" memberName="_labelSpeakerPosRst"
         virtualName="" explicitFocusOrder="0" pos="325 452 157 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker Position Reset" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="resend slider" id="c7a626bbaf2c3bc9" memberName="_sliderSpeakerPosRst"
          virtualName="" explicitFocusOrder="0" pos="460 432 80 24" posRelativeX="f791933f38ac713f"
          posRelativeY="f791933f38ac713f" min="1.0" max="127.0" int="1.0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="40" skewFactor="1.0" needsCallback="1"/>
  <GROUPCOMPONENT name="new group" id="df94cfffa14b408d" memberName="juce__groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="0 0 576 496" title="Midi Settings"/>
  <TOGGLEBUTTON name="invert speaker rotation button" id="f00e402fd25a1531" memberName="_buttonInvertSpeaker"
                virtualName="" explicitFocusOrder="0" pos="328 60 180 24" buttonText="invert speaker rotation"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

