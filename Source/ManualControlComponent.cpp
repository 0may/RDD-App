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

    _sequenceManager.reset (new MidiSequenceManagerComponent());
    addAndMakeVisible (_sequenceManager.get());
    _sequenceManager->setName ("new component");

    _inputTranslation.reset (new XYInputComponent (511, 511, "Translation"));
    addAndMakeVisible (_inputTranslation.get());
    _inputTranslation->setName ("translation input");

    _labelTranslation.reset (new juce::Label ("translation label",
                                              TRANS("Translational motion")));
    addAndMakeVisible (_labelTranslation.get());
    _labelTranslation->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelTranslation->setJustificationType (juce::Justification::centredLeft);
    _labelTranslation->setEditable (false, false, false);
    _labelTranslation->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelTranslation->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelTranslation->setBounds (0, 0, 150, 24);

    _labelRotation.reset (new juce::Label ("rotation label",
                                           TRANS("Rotational motion")));
    addAndMakeVisible (_labelRotation.get());
    _labelRotation->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelRotation->setJustificationType (juce::Justification::centredLeft);
    _labelRotation->setEditable (false, false, false);
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
    _labelSpkAngle->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSpkAngle->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 600);


    //[Constructor] You can add your own custom stuff here..
	_inputTranslation->addChangeListener(&rdd::MainManager::instance().midiController());

	_inputRotation->addChangeListener(&rdd::MainManager::instance().midiController());
	_inputRotation->setMapping(-1, 1, 0, 0);

	_inputSpkRotation->addChangeListener(&rdd::MainManager::instance().midiController());
	_inputSpkRotation->setMapping(0, 0, -1, 1);
    //[/Constructor]
}

ManualControlComponent::~ManualControlComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _sequenceManager = nullptr;
    _inputTranslation = nullptr;
    _labelTranslation = nullptr;
    _labelRotation = nullptr;
    _inputRotation = nullptr;
    _inputSpkRotation = nullptr;
    _labelSpkRotation = nullptr;
    _inputSpkAngle = nullptr;
    _labelSpkAngle = nullptr;


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
    //[/UserPaint]
}

void ManualControlComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _sequenceManager->setBounds (getWidth() - 500, 0, 500, proportionOfHeight (1.0000f));
    _inputTranslation->setBounds (0, 0 + 32, getWidth() - 700, 500);
    _labelRotation->setBounds (0, (0 + 32) + 500 - -30, 150, 24);
    _inputRotation->setBounds (0, ((0 + 32) + 500 - -30) + 32, juce::roundToInt ((getWidth() - 700) * 1.0000f), 31);
    _inputSpkRotation->setBounds (0 + (getWidth() - 700) - -96 - 31, (0 + 32) + 0, 31, juce::roundToInt (500 * 1.0000f));
    _labelSpkRotation->setBounds (0 + (getWidth() - 700) - -24, 0, 120, 24);
    _inputSpkAngle->setBounds (0 + (juce::roundToInt ((getWidth() - 700) * 1.0000f)) - -30, ((0 + 32) + 0) + (juce::roundToInt (500 * 1.0000f)) - -30, 100, 100);
    _labelSpkAngle->setBounds ((0 + (juce::roundToInt ((getWidth() - 700) * 1.0000f)) - -30) + 2, (((0 + 32) + 0) + (juce::roundToInt (500 * 1.0000f)) - -30) + 100 - -6, 100, 24);
    //[UserResized] Add your own custom resize handling here..

	auto area = getLocalBounds();

	_sequenceManager->setBounds(area.removeFromRight(500));

	int w = area.getWidth() - 154;
	int h = area.getHeight() - 184;

	int s = (w > h) ? h : w;

	_labelTranslation->setBounds(4, 2, 150, 24);
	_inputTranslation->setBounds(4, 34, s, s);

	_labelSpkRotation->setBounds(s + 26, 2, 120, 24);
	_inputSpkRotation->setBounds(s + 68, 34, 31, s);

	_labelRotation->setBounds(4, s + 64, 150, 24);
	_inputRotation->setBounds(4, s + 64 + 32, s, 31);

	_inputSpkAngle->setBounds(s + 34, s + 32 + 32, 100, 100);
	_labelSpkAngle->setBounds(s + 34, s + 32 + 32 + 100 + 16, 100, 24);






	//_translationInput.setBounds(30, 30, 511, 511);
	//_rotationInput.setBounds(30, 571, 511, 31);
	//_speakerAngleInput.setBounds(571, 30, 31, 511);
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ManualControlComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="new component" id="47ca8be8a00e3ab8" memberName="_sequenceManager"
                    virtualName="" explicitFocusOrder="0" pos="500R 0 500 100%" class="MidiSequenceManagerComponent"
                    params=""/>
  <GENERICCOMPONENT name="translation input" id="51b2d13e951c1c36" memberName="_inputTranslation"
                    virtualName="" explicitFocusOrder="0" pos="0 32 700M 500" posRelativeY="b2fcac2b642bd3cd"
                    class="XYInputComponent" params="511, 511, &quot;Translation&quot;"/>
  <LABEL name="translation label" id="b2fcac2b642bd3cd" memberName="_labelTranslation"
         virtualName="" explicitFocusOrder="0" pos="0 0 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Translational motion" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="rotation label" id="3f5312a800ec5984" memberName="_labelRotation"
         virtualName="" explicitFocusOrder="0" pos="0 -30R 150 24" posRelativeY="51b2d13e951c1c36"
         edTextCol="ff000000" edBkgCol="0" labelText="Rotational motion"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <GENERICCOMPONENT name="rotation input" id="4fe9eb57af480cb5" memberName="_inputRotation"
                    virtualName="" explicitFocusOrder="0" pos="0 32 100% 31" posRelativeY="3f5312a800ec5984"
                    posRelativeW="51b2d13e951c1c36" class="XYInputComponent" params="511, 31, &quot;Rotation&quot;"/>
  <GENERICCOMPONENT name="speaker rotation input" id="bb192f3df5a8603b" memberName="_inputSpkRotation"
                    virtualName="" explicitFocusOrder="0" pos="-96Rr 0 31 100%" posRelativeX="51b2d13e951c1c36"
                    posRelativeY="51b2d13e951c1c36" posRelativeH="51b2d13e951c1c36"
                    class="XYInputComponent" params="31, 511, &quot;Speaker Rotation&quot;"/>
  <LABEL name="speaker rotation label" id="aa7d76a9a553223" memberName="_labelSpkRotation"
         virtualName="" explicitFocusOrder="0" pos="-24R 0 120 24" posRelativeX="51b2d13e951c1c36"
         edTextCol="ff000000" edBkgCol="0" labelText="Speaker rotation"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <GENERICCOMPONENT name="speaker angle input" id="8fb7635da3960044" memberName="_inputSpkAngle"
                    virtualName="" explicitFocusOrder="0" pos="-30R -30R 100 100"
                    posRelativeX="4fe9eb57af480cb5" posRelativeY="bb192f3df5a8603b"
                    class="AngleInputComponent" params=""/>
  <LABEL name="speaker angle label" id="2aa9e54fcf6b5790" memberName="_labelSpkAngle"
         virtualName="" explicitFocusOrder="0" pos="2 -6R 100 24" posRelativeX="8fb7635da3960044"
         posRelativeY="8fb7635da3960044" edTextCol="ff000000" edBkgCol="0"
         labelText="Speaker angle" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

