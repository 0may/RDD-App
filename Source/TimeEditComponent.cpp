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
//[/Headers]

#include "TimeEditComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TimeEditComponent::TimeEditComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _mins.reset (new juce::TextEditor ("mins text editor"));
    addAndMakeVisible (_mins.get());
    _mins->setMultiLine (false);
    _mins->setReturnKeyStartsNewLine (false);
    _mins->setReadOnly (false);
    _mins->setScrollbarsShown (false);
    _mins->setCaretVisible (true);
    _mins->setPopupMenuEnabled (true);
    _mins->setText (TRANS("00"));

    _mins->setBounds (32, 0, 24, 24);

    _secs.reset (new juce::TextEditor ("secs text editor"));
    addAndMakeVisible (_secs.get());
    _secs->setMultiLine (false);
    _secs->setReturnKeyStartsNewLine (false);
    _secs->setReadOnly (false);
    _secs->setScrollbarsShown (false);
    _secs->setCaretVisible (true);
    _secs->setPopupMenuEnabled (true);
    _secs->setText (TRANS("00"));

    _secs->setBounds (56, 0, 24, 24);

    _millis.reset (new juce::TextEditor ("millis text editor"));
    addAndMakeVisible (_millis.get());
    _millis->setMultiLine (false);
    _millis->setReturnKeyStartsNewLine (false);
    _millis->setReadOnly (false);
    _millis->setScrollbarsShown (false);
    _millis->setCaretVisible (true);
    _millis->setPopupMenuEnabled (true);
    _millis->setText (TRANS("000"));

    _millis->setBounds (80, 0, 32, 24);

    _hours.reset (new juce::TextEditor ("hours text editor"));
    addAndMakeVisible (_hours.get());
    _hours->setMultiLine (false);
    _hours->setReturnKeyStartsNewLine (false);
    _hours->setReadOnly (false);
    _hours->setScrollbarsShown (false);
    _hours->setCaretVisible (true);
    _hours->setPopupMenuEnabled (true);
    _hours->setText (TRANS("000"));

    _hours->setBounds (0, 0, 32, 24);

    _dpLabel.reset (new juce::Label ("new label",
                                     TRANS(":")));
    addAndMakeVisible (_dpLabel.get());
    _dpLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _dpLabel->setJustificationType (juce::Justification::centredLeft);
    _dpLabel->setEditable (false, false, false);
    _dpLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _dpLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _dpLabel->setBounds (24, 0, 14, 24);

    _dpLabel2.reset (new juce::Label ("new label",
                                      TRANS(":")));
    addAndMakeVisible (_dpLabel2.get());
    _dpLabel2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _dpLabel2->setJustificationType (juce::Justification::centredLeft);
    _dpLabel2->setEditable (false, false, false);
    _dpLabel2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _dpLabel2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _dpLabel2->setBounds (48, 0, 14, 24);

    _periodLabel.reset (new juce::Label ("new label",
                                         TRANS(".")));
    addAndMakeVisible (_periodLabel.get());
    _periodLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _periodLabel->setJustificationType (juce::Justification::centredLeft);
    _periodLabel->setEditable (false, false, false);
    _periodLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _periodLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _periodLabel->setBounds (72, 0, 14, 24);


    //[UserPreSize]
    _hours->setColour(TextEditor::outlineColourId, Colour(0x00ffffff));
    _mins->setColour(TextEditor::outlineColourId, Colour(0x00ffffff));
    _secs->setColour(TextEditor::outlineColourId, Colour(0x00ffffff));
    _millis->setColour(TextEditor::outlineColourId, Colour(0x00ffffff));
    //[/UserPreSize]

    setSize (112, 24);


    //[Constructor] You can add your own custom stuff here..

    _timeInputListener = new TimeInputListener(nullptr);
    _timeInputListener->setColours(_hours->findColour(TextEditor::textColourId), Colour(0xffccff0f), Colour(0xffff0000));


    _hours->setInputFilter(new TextEditor::LengthAndCharacterRestriction(3, "0123456789"), true);
    _hours->setJustification(Justification(2)); // justify right
    _hours->addListener(_timeInputListener);

    _mins->setInputFilter(new TextEditor::LengthAndCharacterRestriction(2, "0123456789"), true);
    _mins->setJustification(Justification(2));
    _mins->addListener(_timeInputListener);

    _secs->setInputFilter(new TextEditor::LengthAndCharacterRestriction(2, "0123456789"), true);
    _secs->setJustification(Justification(2));
    _secs->addListener(_timeInputListener);

    _millis->setInputFilter(new TextEditor::LengthAndCharacterRestriction(3, "0123456789"), true);
    _millis->setJustification(Justification(2)); // justify left
    _millis->addListener(_timeInputListener);

    setTimeObject(nullptr);

    //[/Constructor]
}

TimeEditComponent::~TimeEditComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _mins = nullptr;
    _secs = nullptr;
    _millis = nullptr;
    _hours = nullptr;
    _dpLabel = nullptr;
    _dpLabel2 = nullptr;
    _periodLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    delete _timeInputListener;
    _timeInputListener = nullptr;
    //[/Destructor]
}

//==============================================================================
void TimeEditComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TimeEditComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TimeEditComponent::setTimeObject(rdd::Time* time) {

    _time = time;
    _timeInputListener->setTimeObject(_time);

    update();
}

void TimeEditComponent::update() {
    if (_time == nullptr) {

        _hours->setText("");
        _mins->setText("");
        _secs->setText("");
        _millis->setText("");
        this->setEnabled(false);
    }
    else {
        _hours->setText(String(_time->getHours()));
        _mins->setText(String(_time->getMins()));
        _secs->setText(String(_time->getSecs()));
        _millis->setText(String(_time->getMillis()));
        _timeInputListener->textEditorReturnKeyPressed(*_hours);
        _timeInputListener->textEditorReturnKeyPressed(*_mins);
        _timeInputListener->textEditorReturnKeyPressed(*_secs);
        _timeInputListener->textEditorReturnKeyPressed(*_millis);


        this->setEnabled(true);
    }
}


void TimeEditComponent::setEditable(bool editable) {

    _hours->setEnabled(editable);
    _mins->setEnabled(editable);
    _secs->setEnabled(editable);
    _millis->setEnabled(editable);

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TimeEditComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="112" initialHeight="24">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="mins text editor" id="660c95f56ccff56" memberName="_mins"
              virtualName="" explicitFocusOrder="0" pos="32 0 24 24" initialText="00"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="secs text editor" id="43150819d58dff57" memberName="_secs"
              virtualName="" explicitFocusOrder="0" pos="56 0 24 24" initialText="00"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="millis text editor" id="24e812cf7814308e" memberName="_millis"
              virtualName="" explicitFocusOrder="0" pos="80 0 32 24" initialText="000"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="hours text editor" id="7efbf261910f7241" memberName="_hours"
              virtualName="" explicitFocusOrder="0" pos="0 0 32 24" initialText="000"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="0"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="fd1b32edbcc6fd66" memberName="_dpLabel"
         virtualName="" explicitFocusOrder="0" pos="24 0 14 24" edTextCol="ff000000"
         edBkgCol="0" labelText=":" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="bf7c2631e8168cd4" memberName="_dpLabel2"
         virtualName="" explicitFocusOrder="0" pos="48 0 14 24" edTextCol="ff000000"
         edBkgCol="0" labelText=":" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a5896f9c7c12865e" memberName="_periodLabel"
         virtualName="" explicitFocusOrder="0" pos="72 0 14 24" edTextCol="ff000000"
         edBkgCol="0" labelText="." editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

