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
#include "MainManager.h"
//[/Headers]

#include "WaypointEditComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WaypointEditComponent::WaypointEditComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _tLabel.reset (new juce::Label ("new label",
                                    TRANS("t")));
    addAndMakeVisible (_tLabel.get());
    _tLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _tLabel->setJustificationType (juce::Justification::centredLeft);
    _tLabel->setEditable (false, false, false);
    _tLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _tLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _tLabel->setBounds (16, 16, 48, 24);

    _BLabel.reset (new juce::Label ("new label",
                                    TRANS("B")));
    addAndMakeVisible (_BLabel.get());
    _BLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _BLabel->setJustificationType (juce::Justification::centredLeft);
    _BLabel->setEditable (false, false, false);
    _BLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _BLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _BLabel->setBounds (16, 48, 48, 24);

    _xLabel.reset (new juce::Label ("new label",
                                    TRANS("x")));
    addAndMakeVisible (_xLabel.get());
    _xLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _xLabel->setJustificationType (juce::Justification::centredLeft);
    _xLabel->setEditable (false, false, false);
    _xLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _xLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _xLabel->setBounds (16, 80, 48, 24);

    _yLabel.reset (new juce::Label ("new label",
                                    TRANS("y")));
    addAndMakeVisible (_yLabel.get());
    _yLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _yLabel->setJustificationType (juce::Justification::centredLeft);
    _yLabel->setEditable (false, false, false);
    _yLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _yLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _yLabel->setBounds (16, 112, 48, 24);

    _alphaLabel.reset (new juce::Label ("new label",
                                        TRANS("alpha")));
    addAndMakeVisible (_alphaLabel.get());
    _alphaLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _alphaLabel->setJustificationType (juce::Justification::centredLeft);
    _alphaLabel->setEditable (false, false, false);
    _alphaLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _alphaLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _alphaLabel->setBounds (16, 144, 48, 24);

    _betaLabel.reset (new juce::Label ("new label",
                                       TRANS("beta")));
    addAndMakeVisible (_betaLabel.get());
    _betaLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _betaLabel->setJustificationType (juce::Justification::centredLeft);
    _betaLabel->setEditable (false, false, false);
    _betaLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _betaLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _betaLabel->setBounds (16, 176, 48, 24);

    _nameLabel.reset (new juce::Label ("new label",
                                       TRANS("name")));
    addAndMakeVisible (_nameLabel.get());
    _nameLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _nameLabel->setJustificationType (juce::Justification::centredLeft);
    _nameLabel->setEditable (false, false, false);
    _nameLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _nameLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _nameLabel->setBounds (16, 208, 48, 24);

    _alphaTextEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (_alphaTextEditor.get());
    _alphaTextEditor->setMultiLine (false);
    _alphaTextEditor->setReturnKeyStartsNewLine (false);
    _alphaTextEditor->setReadOnly (false);
    _alphaTextEditor->setScrollbarsShown (true);
    _alphaTextEditor->setCaretVisible (true);
    _alphaTextEditor->setPopupMenuEnabled (true);
    _alphaTextEditor->setText (juce::String());

    _alphaTextEditor->setBounds (72, 144, 150, 24);

    _betaTextEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (_betaTextEditor.get());
    _betaTextEditor->setMultiLine (false);
    _betaTextEditor->setReturnKeyStartsNewLine (false);
    _betaTextEditor->setReadOnly (false);
    _betaTextEditor->setScrollbarsShown (true);
    _betaTextEditor->setCaretVisible (true);
    _betaTextEditor->setPopupMenuEnabled (true);
    _betaTextEditor->setText (juce::String());

    _betaTextEditor->setBounds (72, 176, 150, 24);

    _yTextEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (_yTextEditor.get());
    _yTextEditor->setMultiLine (false);
    _yTextEditor->setReturnKeyStartsNewLine (false);
    _yTextEditor->setReadOnly (false);
    _yTextEditor->setScrollbarsShown (true);
    _yTextEditor->setCaretVisible (true);
    _yTextEditor->setPopupMenuEnabled (true);
    _yTextEditor->setText (juce::String());

    _yTextEditor->setBounds (72, 112, 150, 24);

    _xTextEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (_xTextEditor.get());
    _xTextEditor->setMultiLine (false);
    _xTextEditor->setReturnKeyStartsNewLine (false);
    _xTextEditor->setReadOnly (false);
    _xTextEditor->setScrollbarsShown (true);
    _xTextEditor->setCaretVisible (true);
    _xTextEditor->setPopupMenuEnabled (true);
    _xTextEditor->setText (juce::String());

    _xTextEditor->setBounds (72, 80, 150, 24);

    _nameTextEditor.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (_nameTextEditor.get());
    _nameTextEditor->setMultiLine (false);
    _nameTextEditor->setReturnKeyStartsNewLine (false);
    _nameTextEditor->setReadOnly (false);
    _nameTextEditor->setScrollbarsShown (true);
    _nameTextEditor->setCaretVisible (true);
    _nameTextEditor->setPopupMenuEnabled (true);
    _nameTextEditor->setText (juce::String());

    _nameTextEditor->setBounds (72, 208, 150, 24);

    _BComboBox.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (_BComboBox.get());
    _BComboBox->setEditableText (false);
    _BComboBox->setJustificationType (juce::Justification::centredLeft);
    _BComboBox->setTextWhenNothingSelected (juce::String());
    _BComboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    _BComboBox->addListener (this);

    _BComboBox->setBounds (72, 48, 150, 24);

    _tTimeEdit.reset (new TimeEditComponent());
    addAndMakeVisible (_tTimeEdit.get());
    _tTimeEdit->setName ("new component");

    _tTimeEdit->setBounds (72, 16, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    _BComboBox->addItem("0", 1);
    _BComboBox->setSelectedId(1);

    _xTextEditor->setInputFilter(new TextEditor::LengthAndCharacterRestriction(-1, "0123456789."), true);
    _xTextEditor->onTextChange = [&]() {
        String s = correctFloatInput(_xTextEditor.get());

        if (_waypoint)
            _waypoint->x = (float)atof(s.toStdString().c_str());
    };

    _yTextEditor->setInputFilter(new TextEditor::LengthAndCharacterRestriction(-1, "0123456789."), true);
    _yTextEditor->onTextChange = [&]() {
        String s = correctFloatInput(_yTextEditor.get());

        if (_waypoint)
            _waypoint->y = (float)atof(s.toStdString().c_str());
    };

    _alphaTextEditor->setInputFilter(new TextEditor::LengthAndCharacterRestriction(-1, "0123456789."), true);
    _alphaTextEditor->onTextChange = [&]() {
        String s = correctFloatInput(_alphaTextEditor.get());

        if (_waypoint)
            _waypoint->alpha = (float)atof(s.toStdString().c_str());
    };

    _betaTextEditor->setInputFilter(new TextEditor::LengthAndCharacterRestriction(-1, "0123456789."), true);
    _betaTextEditor->onTextChange = [&]() {
        String s = correctFloatInput(_betaTextEditor.get());

        if (_waypoint)
            _waypoint->beta = (float)atof(s.toStdString().c_str());
    };

    _nameTextEditor->onTextChange = [&]() {

        if (_waypoint)
            _waypoint->name = _nameTextEditor->getText();
    };

    setWaypoint(nullptr);

    _tTimeEdit->_timeInputListener->addChangeListener(this);
    MainManager::instance().getWaypointsManager().addChangeListener(this);

    //[/Constructor]
}

WaypointEditComponent::~WaypointEditComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _tLabel = nullptr;
    _BLabel = nullptr;
    _xLabel = nullptr;
    _yLabel = nullptr;
    _alphaLabel = nullptr;
    _betaLabel = nullptr;
    _nameLabel = nullptr;
    _alphaTextEditor = nullptr;
    _betaTextEditor = nullptr;
    _yTextEditor = nullptr;
    _xTextEditor = nullptr;
    _nameTextEditor = nullptr;
    _BComboBox = nullptr;
    _tTimeEdit = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaypointEditComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaypointEditComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..

    juce::Grid grid;

    using Track = juce::Grid::TrackInfo;
    using Fr = juce::Grid::Fr;

    grid.templateRows = { Track(Fr(1)), Track(Fr(1)), Track(Fr(1)), Track(Fr(1)), Track(Fr(1)), Track(Fr(1)), Track(Fr(1)) };
    grid.templateColumns = { Track(Fr(1)), Track(Fr(6)) };

    grid.items = {
        juce::GridItem(*_tLabel), juce::GridItem(*_tTimeEdit),
        juce::GridItem(*_BLabel), juce::GridItem(*_BComboBox),
        juce::GridItem(*_xLabel), juce::GridItem(*_xTextEditor),
        juce::GridItem(*_yLabel), juce::GridItem(*_yTextEditor),
        juce::GridItem(*_alphaLabel), juce::GridItem(*_alphaTextEditor),
        juce::GridItem(*_betaLabel), juce::GridItem(*_betaTextEditor),
        juce::GridItem(*_nameLabel), juce::GridItem(*_nameTextEditor),
    };

    grid.setGap(juce::Grid::Px(2));

    grid.performLayout(getLocalBounds());

    //[/UserResized]
}

void WaypointEditComponent::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == _BComboBox.get())
    {
        //[UserComboBoxCode__BComboBox] -- add your combo box handling code here..
        if (_waypoint) {
            _waypoint->B = _BComboBox->getSelectedId() - 1;
        }
        //[/UserComboBoxCode__BComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void WaypointEditComponent::setWaypoint(rdd::Waypoint* wp) {
    _waypoint = wp;

    if (_waypoint == nullptr) {

        _tTimeEdit->setTimeObject(nullptr);

        _xTextEditor->setText("");
        _yTextEditor->setText("");
        _alphaTextEditor->setText("");
        _betaTextEditor->setText("");
        _nameTextEditor->setText("");

        this->setEnabled(false);
    }
    else {

        _time.setTime(_waypoint->t);
        _tTimeEdit->setTimeObject(&_time);

        _xTextEditor->setText(String(_waypoint->x));
        _yTextEditor->setText(String(_waypoint->y));
        _alphaTextEditor->setText(String(_waypoint->alpha));
        _betaTextEditor->setText(String(_waypoint->beta));
        _nameTextEditor->setText(String(_waypoint->name));

        this->setEnabled(true);

    }
}



String WaypointEditComponent::correctFloatInput(TextEditor* e) {
    String s = e->getText();
    int i1 = s.indexOfChar('.');
    int i2 = s.lastIndexOfChar('.');

    if (!(i1 == -1 || i2 == -1 || i1 == i2)) {
        s = s.substring(0, e->getCaretPosition() - 1) + s.substring(e->getCaretPosition());
        e->setText(s);
        e->setCaretPosition(e->getCaretPosition() - 1);
    }

    return s;
}



void WaypointEditComponent::changeListenerCallback(ChangeBroadcaster* source) {
    WaypointsManager* wm = dynamic_cast<WaypointsManager*>(source);

    if (dynamic_cast<WaypointsManager*>(source)) {
        setWaypoint(dynamic_cast<WaypointsManager*>(source)->getCheckedOutWaypoint());
    }
    else if (dynamic_cast<TimeInputListener*>(source) && _waypoint) {
        _waypoint->t = _time.seconds();
    }

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaypointEditComponent" componentName=""
                 parentClasses="public juce::Component, public juce::ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="60e103e155afb29" memberName="_tLabel" virtualName=""
         explicitFocusOrder="0" pos="16 16 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="t" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1c49ef7d525b1c5e" memberName="_BLabel" virtualName=""
         explicitFocusOrder="0" pos="16 48 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="7d602451e05dc5e1" memberName="_xLabel" virtualName=""
         explicitFocusOrder="0" pos="16 80 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="x" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="6404b203b3903bd8" memberName="_yLabel" virtualName=""
         explicitFocusOrder="0" pos="16 112 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="y" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f182d8a897788a65" memberName="_alphaLabel"
         virtualName="" explicitFocusOrder="0" pos="16 144 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="alpha" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5a79031dfa60187" memberName="_betaLabel"
         virtualName="" explicitFocusOrder="0" pos="16 176 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="beta" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8e8662db35b6707b" memberName="_nameLabel"
         virtualName="" explicitFocusOrder="0" pos="16 208 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="name" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="8ae61513679e9a06" memberName="_alphaTextEditor"
              virtualName="" explicitFocusOrder="0" pos="72 144 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="4b7c572b1c8717de" memberName="_betaTextEditor"
              virtualName="" explicitFocusOrder="0" pos="72 176 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="34f250455b9f05b4" memberName="_yTextEditor"
              virtualName="" explicitFocusOrder="0" pos="72 112 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="d55e16339915f5a" memberName="_xTextEditor"
              virtualName="" explicitFocusOrder="0" pos="72 80 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="ccc2ba3efaeb9503" memberName="_nameTextEditor"
              virtualName="" explicitFocusOrder="0" pos="72 208 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="34bbdaec7c4125e2" memberName="_BComboBox"
            virtualName="" explicitFocusOrder="0" pos="72 48 150 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <GENERICCOMPONENT name="new component" id="33d6fd6fc16dd687" memberName="_tTimeEdit"
                    virtualName="" explicitFocusOrder="0" pos="72 16 150 24" class="TimeEditComponent"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

