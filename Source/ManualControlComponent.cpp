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

//[Headers] You can add your own extra header files here...
#include "MainManager.h"
//[/Headers]

#include "ManualControlComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ManualControlComponent::ManualControlComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _inputTranslation.reset (new XYInputComponent (511, 511, "Translation"));
    addAndMakeVisible (_inputTranslation.get());
    _inputTranslation->setName ("translation input");

    _labelTranslation.reset (new juce::Label ("translation label",
                                              TRANS("Translational motion")));
    addAndMakeVisible (_labelTranslation.get());
    _labelTranslation->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelTranslation->setJustificationType (juce::Justification::centredLeft);
    _labelTranslation->setEditable (false, false, false);
    _labelTranslation->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelTranslation->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelTranslation->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelRotation.reset (new juce::Label ("rotation label",
                                           TRANS("Rotational motion")));
    addAndMakeVisible (_labelRotation.get());
    _labelRotation->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelRotation->setJustificationType (juce::Justification::centredLeft);
    _labelRotation->setEditable (false, false, false);
    _labelRotation->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelRotation->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelRotation->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _inputRotation.reset (new XYInputComponent (511, 31, "Rotation"));
    addAndMakeVisible (_inputRotation.get());
    _inputRotation->setName ("rotation input");

    _inputSpkRotation.reset (new XYInputComponent (31, 511, "Speaker Rotation"));
    addAndMakeVisible (_inputSpkRotation.get());
    _inputSpkRotation->setName ("speaker rotation input");

    _labelSpkRotation.reset (new juce::Label ("speaker rotation label",
                                              TRANS("Speaker rotation")));
    addAndMakeVisible (_labelSpkRotation.get());
    _labelSpkRotation->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpkRotation->setJustificationType (juce::Justification::centredLeft);
    _labelSpkRotation->setEditable (false, false, false);
    _labelSpkRotation->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelSpkRotation->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpkRotation->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _inputSpkAngle.reset (new AngleInputComponent());
    addAndMakeVisible (_inputSpkAngle.get());
    _inputSpkAngle->setName ("speaker angle input");

    _labelSpkAngle.reset (new juce::Label ("speaker angle label",
                                           TRANS("Speaker angle")));
    addAndMakeVisible (_labelSpkAngle.get());
    _labelSpkAngle->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpkAngle->setJustificationType (juce::Justification::centredLeft);
    _labelSpkAngle->setEditable (false, false, false);
    _labelSpkAngle->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelSpkAngle->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpkAngle->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _sliderSpkVelocity.reset (new juce::Slider ("speaker velocity slider"));
    addAndMakeVisible (_sliderSpkVelocity.get());
    _sliderSpkVelocity->setTooltip (TRANS("Speaker rotation velocity used for keyboard or angle input"));
    _sliderSpkVelocity->setRange (1, 127, 1);
    _sliderSpkVelocity->setSliderStyle (juce::Slider::LinearHorizontal);
    _sliderSpkVelocity->setTextBoxStyle (juce::Slider::TextBoxRight, false, 50, 20);
    _sliderSpkVelocity->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff121e24));
    _sliderSpkVelocity->setColour (juce::Slider::thumbColourId, juce::Colour (0xffa45c94));
    _sliderSpkVelocity->setColour (juce::Slider::trackColourId, juce::Colour (0xffa45c94));
    _sliderSpkVelocity->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff121e24));
    _sliderSpkVelocity->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colour (0xff121e24));
    _sliderSpkVelocity->addListener (this);

    _labelSpkVelocity.reset (new juce::Label ("speaker velocity label",
                                              TRANS("Speaker rotation")));
    addAndMakeVisible (_labelSpkVelocity.get());
    _labelSpkVelocity->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSpkVelocity->setJustificationType (juce::Justification::centredLeft);
    _labelSpkVelocity->setEditable (false, false, false);
    _labelSpkVelocity->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelSpkVelocity->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpkVelocity->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _sliderRotationVelocity.reset (new juce::Slider ("rotation velocity slider"));
    addAndMakeVisible (_sliderRotationVelocity.get());
    _sliderRotationVelocity->setTooltip (TRANS("Robot rotation velocity used for keyboard or angle input"));
    _sliderRotationVelocity->setRange (1, 127, 1);
    _sliderRotationVelocity->setSliderStyle (juce::Slider::LinearHorizontal);
    _sliderRotationVelocity->setTextBoxStyle (juce::Slider::TextBoxRight, false, 50, 20);
    _sliderRotationVelocity->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff121e24));
    _sliderRotationVelocity->setColour (juce::Slider::thumbColourId, juce::Colour (0xffa45c94));
    _sliderRotationVelocity->setColour (juce::Slider::trackColourId, juce::Colour (0xffa45c94));
    _sliderRotationVelocity->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff121e24));
    _sliderRotationVelocity->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colour (0xff121e24));
    _sliderRotationVelocity->addListener (this);

    _labelRotationVelocity.reset (new juce::Label ("rotation velocity label",
                                                   TRANS("Rotation")));
    addAndMakeVisible (_labelRotationVelocity.get());
    _labelRotationVelocity->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelRotationVelocity->setJustificationType (juce::Justification::centredLeft);
    _labelRotationVelocity->setEditable (false, false, false);
    _labelRotationVelocity->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelRotationVelocity->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelRotationVelocity->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _sliderTranslationVelocity.reset (new juce::Slider ("translation velocity slider"));
    addAndMakeVisible (_sliderTranslationVelocity.get());
    _sliderTranslationVelocity->setTooltip (TRANS("Robot translation velocity used for keyboard or angle input"));
    _sliderTranslationVelocity->setRange (1, 127, 1);
    _sliderTranslationVelocity->setSliderStyle (juce::Slider::LinearHorizontal);
    _sliderTranslationVelocity->setTextBoxStyle (juce::Slider::TextBoxRight, false, 50, 20);
    _sliderTranslationVelocity->setColour (juce::Slider::backgroundColourId, juce::Colour (0xff121e24));
    _sliderTranslationVelocity->setColour (juce::Slider::thumbColourId, juce::Colour (0xffa45c94));
    _sliderTranslationVelocity->setColour (juce::Slider::trackColourId, juce::Colour (0xffa45c94));
    _sliderTranslationVelocity->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff121e24));
    _sliderTranslationVelocity->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colour (0xff121e24));
    _sliderTranslationVelocity->addListener (this);

    _labelTranslationVelocity.reset (new juce::Label ("translation velocity label",
                                                      TRANS("Translation")));
    addAndMakeVisible (_labelTranslationVelocity.get());
    _labelTranslationVelocity->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelTranslationVelocity->setJustificationType (juce::Justification::centredLeft);
    _labelTranslationVelocity->setEditable (false, false, false);
    _labelTranslationVelocity->setColour (juce::Label::textColourId, juce::Colour (0xffcdcdcd));
    _labelTranslationVelocity->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelTranslationVelocity->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelDefaultVelos.reset (new juce::Label ("default velocities label",
                                               TRANS("Velocity scalings")));
    addAndMakeVisible (_labelDefaultVelos.get());
    _labelDefaultVelos->setTooltip (TRANS("Velocity scalings are used to reduce velocities to the configured percentage of the maximum velocities"));
    _labelDefaultVelos->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelDefaultVelos->setJustificationType (juce::Justification::centredLeft);
    _labelDefaultVelos->setEditable (false, false, false);
    _labelDefaultVelos->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelDefaultVelos->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelDefaultVelos->setBounds (608, 0, 150, 24);

    _labelInput.reset (new juce::Label ("input label",
                                        TRANS("Motion input")));
    addAndMakeVisible (_labelInput.get());
    _labelInput->setTooltip (TRANS("Controls for motion input"));
    _labelInput->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelInput->setJustificationType (juce::Justification::centredLeft);
    _labelInput->setEditable (false, false, false);
    _labelInput->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelInput->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelInput->setBounds (0, 0, 150, 24);

    _buttonSpkPositionReset.reset (new juce::TextButton ("speaker position reset"));
    addAndMakeVisible (_buttonSpkPositionReset.get());
    _buttonSpkPositionReset->setTooltip (TRANS("Reset speaker position to zero position"));
    _buttonSpkPositionReset->setButtonText (TRANS("Reset"));
    _buttonSpkPositionReset->addListener (this);

    _buttonSpkPositionReset->setBounds (624, 176, 46, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..
	_inputTranslation->addChangeListener(&rdd::MainManager::instance().midiController());

	_inputRotation->addChangeListener(&rdd::MainManager::instance().midiController());
	_inputRotation->setMapping(-1, 1, 0, 0);

	_inputSpkRotation->addChangeListener(&rdd::MainManager::instance().midiController());
	_inputSpkRotation->setMapping(0, 0, -1, 1);


	_inputSpkAngle->setMapping(-255.999f, 255.999f);
	_inputSpkAngle->addChangeListener(&rdd::MainManager::instance().midiController());

	_sep1x = 100;
	_sep2x = 200;

	_sliderTranslationVelocity->setValue(127);
	_sliderRotationVelocity->setValue(127);
	_sliderSpkVelocity->setValue(127);

	setColour(ColourIds::backgroundColourId, Colour(0xff323e44));
	setColour(ColourIds::separatorColourId, Colour(0xffafafaf));


	// variables and init of application commands

	_moveFB = 0;
	_moveLR = 0;
	_rotateLR = 0;
	_speakerUD = 0;

	rdd::MainManager::instance().commandManager().registerAllCommandsForTarget(this);


    //[/Constructor]
}

ManualControlComponent::~ManualControlComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _inputTranslation = nullptr;
    _labelTranslation = nullptr;
    _labelRotation = nullptr;
    _inputRotation = nullptr;
    _inputSpkRotation = nullptr;
    _labelSpkRotation = nullptr;
    _inputSpkAngle = nullptr;
    _labelSpkAngle = nullptr;
    _sliderSpkVelocity = nullptr;
    _labelSpkVelocity = nullptr;
    _sliderRotationVelocity = nullptr;
    _labelRotationVelocity = nullptr;
    _sliderTranslationVelocity = nullptr;
    _labelTranslationVelocity = nullptr;
    _labelDefaultVelos = nullptr;
    _labelInput = nullptr;
    _buttonSpkPositionReset = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

    //[/Destructor]
}

//==============================================================================
void ManualControlComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..

	g.fillAll(findColour(ColourIds::backgroundColourId));

	g.setColour(findColour(ColourIds::separatorColourId));

	g.drawVerticalLine(_sep1x, 0.0f, getHeight() - 1.0f);
	//g.drawVerticalLine(_sep2x, 0.0f, getHeight() - 1.0f);


    //[/UserPaint]
}

void ManualControlComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _inputTranslation->setBounds (0, (0 + 40) + -8, getWidth() - 1192, 400);
    _labelTranslation->setBounds (0, 0 + 40, 150, 24);
    _labelRotation->setBounds (0, ((0 + 40) + -8) + 400 - -30, 150, 24);
    _inputRotation->setBounds (0, (((0 + 40) + -8) + 400 - -30) + 32, juce::roundToInt ((getWidth() - 1192) * 1.0000f), 0);
    _inputSpkRotation->setBounds (0 + (getWidth() - 1192) - -31 - 31, ((0 + 40) + -8) + -32, 31, juce::roundToInt (400 * 1.0000f));
    _labelSpkRotation->setBounds (0 + (getWidth() - 1192), (0 + 40) + -40, 120, 24);
    _inputSpkAngle->setBounds (0 + (juce::roundToInt ((getWidth() - 1192) * 1.0000f)), (((0 + 40) + -8) + -32) + (juce::roundToInt (400 * 1.0000f)) - 400, 100, 100);
    _labelSpkAngle->setBounds ((0 + (juce::roundToInt ((getWidth() - 1192) * 1.0000f))) + 2, ((((0 + 40) + -8) + -32) + (juce::roundToInt (400 * 1.0000f)) - 400) + 100 - -6, 100, 24);
    _sliderSpkVelocity->setBounds (((608 + -608) + 0) + 0, (((0 + 40) + 40) + 0) + -54, 208, 31);
    _labelSpkVelocity->setBounds ((608 + -608) + 0, ((0 + 40) + 40) + 0, 130, 24);
    _sliderRotationVelocity->setBounds ((608 + -608) + 0, ((0 + 40) + 40) + -54, 208, 31);
    _labelRotationVelocity->setBounds (608 + -608, (0 + 40) + 40, 130, 24);
    _sliderTranslationVelocity->setBounds (608 + -608, (0 + 40) + -14, 208, 31);
    _labelTranslationVelocity->setBounds (608, 0 + 40, 130, 24);
    //[UserResized] Add your own custom resize handling here..


	auto area = getLocalBounds();

	// layout sequence manager
	//_sequenceManager->setBounds(area.removeFromRight(500));


	// layout default velocity sliders
	auto areaParams = area.removeFromRight(250);

	_sep1x = areaParams.getX() + 10;
	_sep2x = areaParams.getX() + areaParams.getWidth() - 10;

	int dx = _sep1x + 10;
	int dy = 4;

	_labelDefaultVelos->setBounds(dx, dy, 150, 24);

	dy += 40;
	_labelTranslationVelocity->setBounds(dx, dy, 130, 24);
	_sliderTranslationVelocity->setBounds(dx, dy + 26, 208, 31);

	dy += 80;
	_labelRotationVelocity->setBounds(dx, dy, 130, 24);
	_sliderRotationVelocity->setBounds(dx, dy + 26, 208, 31);

	dy += 80;
	_labelSpkVelocity->setBounds(dx, dy, 130, 24);
	_sliderSpkVelocity->setBounds(dx, dy + 26, 208, 31);


	// layout input components

	int w = area.getWidth() - 220;
	int h = area.getHeight() - 320;

	int s = (w > h) ? h : w;

	dx = 4;
	dy = 2;

	_labelInput->setBounds(dx, dy, 150, 24);

	dy += 40;
	_labelTranslation->setBounds(dx, dy, 150, 24);
	_inputTranslation->setBounds(dx, dy + 32, s, s);

	dx = s + 72;
	_labelSpkRotation->setBounds(dx, dy, 120, 24);
	_inputSpkRotation->setBounds(dx + 42, dy + 32, 31, s);

	dx = 4;
	dy = s + 144;
	_labelRotation->setBounds(dx, dy, 150, 24);
	_inputRotation->setBounds(dx, dy + 32, s, 31);

	dx = s + 70;
	dy = s + 102;
	_labelSpkAngle->setBounds(dx + 10, dy, 100, 24);
	_inputSpkAngle->setBounds(dx, dy + 30, 120, 120);
	_buttonSpkPositionReset->setBounds(dx + 38, dy + 160, 46, 24);


    //[/UserResized]
}

void ManualControlComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == _sliderSpkVelocity.get())
    {
        //[UserSliderCode__sliderSpkVelocity] -- add your slider handling code here..
		rdd::MainManager::instance().midiController().sendParameter(rdd::MidiSettings::SPEAKER_SPEED, (uint8)_sliderSpkVelocity->getValue());
        //[/UserSliderCode__sliderSpkVelocity]
    }
    else if (sliderThatWasMoved == _sliderRotationVelocity.get())
    {
        //[UserSliderCode__sliderRotationVelocity] -- add your slider handling code here..
		rdd::MainManager::instance().midiController().sendParameter(rdd::MidiSettings::ROTATE_SPEED, (uint8)_sliderRotationVelocity->getValue());
        //[/UserSliderCode__sliderRotationVelocity]
    }
    else if (sliderThatWasMoved == _sliderTranslationVelocity.get())
    {
        //[UserSliderCode__sliderTranslationVelocity] -- add your slider handling code here..
		rdd::MainManager::instance().midiController().sendParameter(rdd::MidiSettings::MOVE_SPEED, (uint8)_sliderTranslationVelocity->getValue());
        //[/UserSliderCode__sliderTranslationVelocity]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ManualControlComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _buttonSpkPositionReset.get())
    {
        //[UserButtonCode__buttonSpkPositionReset] -- add your button handler code here..
		rdd::MainManager::instance().midiController().sendParameter(rdd::MidiSettings::SPEAKER_POSITION_RESET, 1);
        //[/UserButtonCode__buttonSpkPositionReset]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

ApplicationCommandTarget * 	ManualControlComponent::getNextCommandTarget() {
	return nullptr;
}


void ManualControlComponent::getAllCommands(Array< CommandID > &commands) {
	//commands.clear();

	commands.add(1000); // move forward
	commands.add(1001); // move backward
	commands.add(1002); // move left
	commands.add(1003); // move right
	commands.add(1004); // rotate left
	commands.add(1005); // rotate right
	commands.add(1006); // rotate speaker up
	commands.add(1007); // rotate speaker down
}


void ManualControlComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo &result) {


	if (commandID == 1000) {
		result.setInfo("move_forward", "Move the RDD platform forward with default speed", "Translational Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress('w', ModifierKeys::noModifiers);
		//if (_moveFB == 1)
		//	result.setActive(false);
	}
	else if (commandID == 1001) {
		result.setInfo("move_backward", "Move the RDD platform backward with default speed", "Translational Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress('s', ModifierKeys::noModifiers);
		//if (_moveFB == -1)
		//	result.setActive(false);
	}
	else if (commandID == 1002) {
		result.setInfo("strafe_left", "Move the RDD platform left with default speed", "Translational Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress('a', ModifierKeys::noModifiers);
		//if (_moveLR == 1)
		//	result.setActive(false);
	}
	else if (commandID == 1003) {
		result.setInfo("strafe_right", "Move the RDD platform right with default speed", "Translational Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress('d', ModifierKeys::noModifiers);
		//if (_moveLR == -1)
		//	result.setActive(false);
	}
	else if (commandID == 1004) {
		result.setInfo("rotate_left", "Rotate the RDD platform left with default speed", "Rotational Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress(KeyPress::leftKey, ModifierKeys::noModifiers);
		//if (_rotateLR == 1)
		//	result.setActive(false);
	}
	else if (commandID == 1005) {
		result.setInfo("rotate_right", "Rotate the RDD platform right with default speed", "Rotational Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress(KeyPress::rightKey, ModifierKeys::noModifiers);
		//if (_rotateLR == -1)
		//	result.setActive(false);
	}
	else if (commandID == 1006) {
		result.setInfo("speaker_up", "Rotate the speaker up with default speed", "Speaker Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress(KeyPress::upKey, ModifierKeys::noModifiers);
		//if (_speakerUD == 1)
		//	result.setActive(false);
	}
	else if (commandID == 1007) {
		result.setInfo("speaker_down", "Rotate the speaker down with default speed", "Speaker Motion", ApplicationCommandInfo::wantsKeyUpDownCallbacks);
		result.addDefaultKeypress(KeyPress::downKey, ModifierKeys::noModifiers);
		//if (_rotateLR == -1)
		//	result.setActive(false);
	}
}


bool ManualControlComponent::perform(const InvocationInfo &info) {

	if (info.commandID == 1000) {  // move forward command

		if (info.isKeyDown && _moveFB == 0) {
			_moveFB = -1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::MOVE_FORWARD, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if ((!info.isKeyDown) && _moveFB == -1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::MOVE_FORWARD);
			_moveFB = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1001) { // move backward command

		if (info.isKeyDown && _moveFB == 0) {
			_moveFB = 1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::MOVE_BACKWARD, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _moveFB == 1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::MOVE_BACKWARD);
			_moveFB = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1002) { // strafe left command

		if (info.isKeyDown && _moveLR == 0) {
			_moveLR = -1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::STRAFE_LEFT, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _moveLR == -1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::STRAFE_LEFT);
			_moveLR = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1003) { // strafe right command

		if (info.isKeyDown && _moveLR == 0) {
			_moveLR = 1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::STRAFE_RIGHT, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _moveLR == 1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::STRAFE_RIGHT);
			_moveLR = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1004) { // rotate left command

		if (info.isKeyDown && _rotateLR == 0) {
			_rotateLR = -1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::ROTATE_LEFT, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _rotateLR == -1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::ROTATE_LEFT);
			_rotateLR = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1005) { // rotate right command

		if (info.isKeyDown && _rotateLR == 0) {
			_rotateLR = 1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::ROTATE_RIGHT, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _rotateLR == 1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::ROTATE_RIGHT);
			_rotateLR = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1006) { // rotate speaker up command  #TODO: fix bug with speaker commands only reacting to key presses after slider use

		if (info.isKeyDown && _speakerUD == 0) {
			_speakerUD = -1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::SPEAKER_UP, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _speakerUD == -1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::SPEAKER_UP);
			_speakerUD = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else if (info.commandID == 1007) { // rotate speaker down command

		if (info.isKeyDown && _speakerUD == 0) {
			_speakerUD = 1;
			rdd::MainManager::instance().midiController().startCommand(rdd::MidiSettings::SPEAKER_DOWN, 127);
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}
		else if (!info.isKeyDown && _speakerUD == 1) {
			rdd::MainManager::instance().midiController().stopCommand(rdd::MidiSettings::SPEAKER_DOWN);
			_speakerUD = 0;
			//rdd::MainManager::instance().commandManager().commandStatusChanged();
		}

		return true;
	}
	else {
		return false;
	}
}




//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ManualControlComponent" componentName=""
                 parentClasses="public Component, public ApplicationCommandTarget"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="translation input" id="51b2d13e951c1c36" memberName="_inputTranslation"
                    virtualName="" explicitFocusOrder="0" pos="0 -8 1192M 400" posRelativeY="b2fcac2b642bd3cd"
                    class="XYInputComponent" params="511, 511, &quot;Translation&quot;"/>
  <LABEL name="translation label" id="b2fcac2b642bd3cd" memberName="_labelTranslation"
         virtualName="" explicitFocusOrder="0" pos="0 40 150 24" posRelativeY="2856c3183c1225a"
         textCol="ffcdcdcd" edTextCol="ff000000" edBkgCol="0" labelText="Translational motion"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="rotation label" id="3f5312a800ec5984" memberName="_labelRotation"
         virtualName="" explicitFocusOrder="0" pos="0 -30R 150 24" posRelativeY="51b2d13e951c1c36"
         textCol="ffcdcdcd" edTextCol="ff000000" edBkgCol="0" labelText="Rotational motion"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <GENERICCOMPONENT name="rotation input" id="4fe9eb57af480cb5" memberName="_inputRotation"
                    virtualName="" explicitFocusOrder="0" pos="0 32 100% 0" posRelativeY="3f5312a800ec5984"
                    posRelativeW="51b2d13e951c1c36" class="XYInputComponent" params="511, 31, &quot;Rotation&quot;"/>
  <GENERICCOMPONENT name="speaker rotation input" id="bb192f3df5a8603b" memberName="_inputSpkRotation"
                    virtualName="" explicitFocusOrder="0" pos="-31Rr -32 31 100%"
                    posRelativeX="51b2d13e951c1c36" posRelativeY="51b2d13e951c1c36"
                    posRelativeH="51b2d13e951c1c36" class="XYInputComponent" params="31, 511, &quot;Speaker Rotation&quot;"/>
  <LABEL name="speaker rotation label" id="aa7d76a9a553223" memberName="_labelSpkRotation"
         virtualName="" explicitFocusOrder="0" pos="0R -40 120 24" posRelativeX="51b2d13e951c1c36"
         posRelativeY="b2fcac2b642bd3cd" textCol="ffcdcdcd" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker rotation" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="speaker angle input" id="8fb7635da3960044" memberName="_inputSpkAngle"
                    virtualName="" explicitFocusOrder="0" pos="0R 400R 100 100" posRelativeX="4fe9eb57af480cb5"
                    posRelativeY="bb192f3df5a8603b" class="AngleInputComponent" params=""/>
  <LABEL name="speaker angle label" id="2aa9e54fcf6b5790" memberName="_labelSpkAngle"
         virtualName="" explicitFocusOrder="0" pos="2 -6R 100 24" posRelativeX="8fb7635da3960044"
         posRelativeY="8fb7635da3960044" textCol="ffcdcdcd" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker angle" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="speaker velocity slider" id="4ad6a1a20f094c52" memberName="_sliderSpkVelocity"
          virtualName="" explicitFocusOrder="0" pos="0 -54 208 31" posRelativeX="b7a922d3c97653ae"
          posRelativeY="b7a922d3c97653ae" tooltip="Speaker rotation velocity used for keyboard or angle input"
          bkgcol="ff121e24" thumbcol="ffa45c94" trackcol="ffa45c94" rotarysliderfill="ff121e24"
          rotaryslideroutline="ff121e24" min="1.0" max="127.0" int="1.0"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="50" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="speaker velocity label" id="b7a922d3c97653ae" memberName="_labelSpkVelocity"
         virtualName="" explicitFocusOrder="0" pos="0 0 130 24" posRelativeX="f7484d74122f4e37"
         posRelativeY="f7484d74122f4e37" textCol="ffcdcdcd" edTextCol="ff000000"
         edBkgCol="0" labelText="Speaker rotation" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="rotation velocity slider" id="5467c2aadbf1b739" memberName="_sliderRotationVelocity"
          virtualName="" explicitFocusOrder="0" pos="0 -54 208 31" posRelativeX="f7484d74122f4e37"
          posRelativeY="f7484d74122f4e37" tooltip="Robot rotation velocity used for keyboard or angle input"
          bkgcol="ff121e24" thumbcol="ffa45c94" trackcol="ffa45c94" rotarysliderfill="ff121e24"
          rotaryslideroutline="ff121e24" min="1.0" max="127.0" int="1.0"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="50" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="rotation velocity label" id="f7484d74122f4e37" memberName="_labelRotationVelocity"
         virtualName="" explicitFocusOrder="0" pos="-608 40 130 24" posRelativeX="b58d566532bf862f"
         posRelativeY="b58d566532bf862f" textCol="ffcdcdcd" edTextCol="ff000000"
         edBkgCol="0" labelText="Rotation" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="translation velocity slider" id="3ded3cd63a4d5af8" memberName="_sliderTranslationVelocity"
          virtualName="" explicitFocusOrder="0" pos="-608 -14 208 31" posRelativeX="b58d566532bf862f"
          posRelativeY="b58d566532bf862f" tooltip="Robot translation velocity used for keyboard or angle input"
          bkgcol="ff121e24" thumbcol="ffa45c94" trackcol="ffa45c94" rotarysliderfill="ff121e24"
          rotaryslideroutline="ff121e24" min="1.0" max="127.0" int="1.0"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="50" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="translation velocity label" id="b58d566532bf862f" memberName="_labelTranslationVelocity"
         virtualName="" explicitFocusOrder="0" pos="608 40 130 24" posRelativeY="a3c518a62f7fb027"
         textCol="ffcdcdcd" edTextCol="ff000000" edBkgCol="0" labelText="Translation"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="default velocities label" id="a3c518a62f7fb027" memberName="_labelDefaultVelos"
         virtualName="" explicitFocusOrder="0" pos="608 0 150 24" tooltip="Velocity scalings are used to reduce velocities to the configured percentage of the maximum velocities"
         edTextCol="ff000000" edBkgCol="0" labelText="Velocity scalings"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="input label" id="2856c3183c1225a" memberName="_labelInput"
         virtualName="" explicitFocusOrder="0" pos="0 0 150 24" tooltip="Controls for motion input"
         edTextCol="ff000000" edBkgCol="0" labelText="Motion input" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="speaker position reset" id="ab4f9e33da19faf4" memberName="_buttonSpkPositionReset"
              virtualName="" explicitFocusOrder="0" pos="624 176 46 24" tooltip="Reset speaker position to zero position"
              buttonText="Reset" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

