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

#include "WaypointEditorComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WaypointEditorComponent::WaypointEditorComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _waypointMapComponent.reset (new WaypointMapComponent());
    addAndMakeVisible (_waypointMapComponent.get());
    _waypointMapComponent->setName ("waypoint map component");

    _waypointEditComponent.reset (new WaypointEditComponent());
    addAndMakeVisible (_waypointEditComponent.get());
    _waypointEditComponent->setName ("new component");

    _waypointTableComponent.reset (new WaypointTableComponent());
    addAndMakeVisible (_waypointTableComponent.get());
    _waypointTableComponent->setName ("waypoints list");

    _buttonDelete.reset (new juce::ImageButton ("delete button"));
    addAndMakeVisible (_buttonDelete.get());
    _buttonDelete->setTooltip (TRANS("Delete selected waypoint"));
    _buttonDelete->setButtonText (TRANS("new button"));
    _buttonDelete->addListener (this);

    _buttonDelete->setImages (false, true, true,
                              juce::ImageCache::getFromMemory (minus_png, minus_pngSize), 1.000f, juce::Colour (0x00000000),
                              juce::ImageCache::getFromMemory (minus_png, minus_pngSize), 1.000f, juce::Colour (0xffababab),
                              juce::ImageCache::getFromMemory (minus_png, minus_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonAdd.reset (new juce::ImageButton ("add button"));
    addAndMakeVisible (_buttonAdd.get());
    _buttonAdd->setTooltip (TRANS("Add new waypoint"));
    _buttonAdd->setButtonText (TRANS("new button"));
    _buttonAdd->addListener (this);

    _buttonAdd->setImages (false, true, true,
                           juce::ImageCache::getFromMemory (plus_png, plus_pngSize), 1.000f, juce::Colour (0x00000000),
                           juce::ImageCache::getFromMemory (plus_png, plus_pngSize), 1.000f, juce::Colour (0xffababab),
                           juce::ImageCache::getFromMemory (plus_png, plus_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonLoad.reset (new juce::TextButton ("load button"));
    addAndMakeVisible (_buttonLoad.get());
    _buttonLoad->setTooltip (TRANS("Load a set of waypoints from file"));
    _buttonLoad->setButtonText (TRANS("Load"));
    _buttonLoad->addListener (this);

    _buttonSave.reset (new juce::TextButton ("save button"));
    addAndMakeVisible (_buttonSave.get());
    _buttonSave->setTooltip (TRANS("Save the current set of waypoints to file"));
    _buttonSave->setButtonText (TRANS("Save"));
    _buttonSave->addListener (this);

    _buttonSend.reset (new juce::TextButton ("send button"));
    addAndMakeVisible (_buttonSend.get());
    _buttonSend->setTooltip (TRANS("Send the current set of waypoints to the speaker platform"));
    _buttonSend->setButtonText (TRANS("Send"));
    _buttonSend->addListener (this);

    _waypointTableLabel.reset (new juce::Label ("waypoint table label",
                                                TRANS("Waypoints")));
    addAndMakeVisible (_waypointTableLabel.get());
    _waypointTableLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _waypointTableLabel->setJustificationType (juce::Justification::centredLeft);
    _waypointTableLabel->setEditable (false, false, false);
    _waypointTableLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _waypointTableLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _waypointEditLabel.reset (new juce::Label ("waypoint edit label",
                                               TRANS("Editor")));
    addAndMakeVisible (_waypointEditLabel.get());
    _waypointEditLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _waypointEditLabel->setJustificationType (juce::Justification::centredLeft);
    _waypointEditLabel->setEditable (false, false, false);
    _waypointEditLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _waypointEditLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _waypointMapLabel.reset (new juce::Label ("waypoint map label",
                                              TRANS("Map")));
    addAndMakeVisible (_waypointMapLabel.get());
    _waypointMapLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _waypointMapLabel->setJustificationType (juce::Justification::centredLeft);
    _waypointMapLabel->setEditable (false, false, false);
    _waypointMapLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _waypointMapLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _trailHideSlider.reset (new juce::Slider ("trail hiding slider"));
    addAndMakeVisible (_trailHideSlider.get());
    _trailHideSlider->setRange (0, 10, 1);
    _trailHideSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    _trailHideSlider->setTextBoxStyle (juce::Slider::TextBoxRight, false, 30, 20);
    _trailHideSlider->addListener (this);

    _trailHideLabel.reset (new juce::Label ("trail hiding label",
                                            TRANS("Trail hiding")));
    addAndMakeVisible (_trailHideLabel.get());
    _trailHideLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _trailHideLabel->setJustificationType (juce::Justification::centredLeft);
    _trailHideLabel->setEditable (false, false, false);
    _trailHideLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _trailHideLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    _waypointEditComponent->addChangeListener(this);
    _waypointMapComponent->addChangeListener(this);

    MainManager::instance().getWaypointsManager().addChangeListener(this);


    //[/Constructor]
}

WaypointEditorComponent::~WaypointEditorComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _waypointMapComponent = nullptr;
    _waypointEditComponent = nullptr;
    _waypointTableComponent = nullptr;
    _buttonDelete = nullptr;
    _buttonAdd = nullptr;
    _buttonLoad = nullptr;
    _buttonSave = nullptr;
    _buttonSend = nullptr;
    _waypointTableLabel = nullptr;
    _waypointEditLabel = nullptr;
    _waypointMapLabel = nullptr;
    _trailHideSlider = nullptr;
    _trailHideLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaypointEditorComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaypointEditorComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _waypointMapComponent->setBounds (2, 28, getWidth() - 310, getHeight() - 56);
    _waypointEditComponent->setBounds (getWidth() - 2 - 298, getHeight() - 2 - 200, 298, 200);
    _waypointTableComponent->setBounds (getWidth() - 2 - 298, 28, 298, getHeight() - 300);
    _buttonDelete->setBounds (getWidth() - 2 - 24, 28 + (getHeight() - 300) - -5, 24, 24);
    _buttonAdd->setBounds (getWidth() - 32 - 24, 28 + (getHeight() - 300) - -5, 24, 24);
    _buttonLoad->setBounds ((getWidth() - 2 - 298) + 0, 28 + (getHeight() - 300) - -5, 50, 24);
    _buttonSave->setBounds (((getWidth() - 2 - 298) + 0) + 50 - -5, (28 + (getHeight() - 300) - -5) + 0, 50, 24);
    _buttonSend->setBounds ((((getWidth() - 2 - 298) + 0) + 50 - -5) + 50 - -5, ((28 + (getHeight() - 300) - -5) + 0) + 0, 50, 24);
    _waypointTableLabel->setBounds ((getWidth() - 2 - 298) + 0, 28 + -26, 79, 24);
    _waypointEditLabel->setBounds ((getWidth() - 2 - 298) + 2, (getHeight() - 2 - 200) + -26, 53, 24);
    _waypointMapLabel->setBounds (2 + 0, 28 + -26, 38, 24);
    _trailHideSlider->setBounds (2 + (getWidth() - 310) - 5 - 126, 28 + (getHeight() - 56) - -2, 126, 24);
    _trailHideLabel->setBounds ((2 + (getWidth() - 310) - 5 - 126) + 0 - 80, (28 + (getHeight() - 56) - -2) + 0, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void WaypointEditorComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _buttonDelete.get())
    {
        //[UserButtonCode__buttonDelete] -- add your button handler code here..
        MainManager::instance().getWaypointsManager().deleteCheckedOutWaypoint();
        _waypointTableComponent->updateTable();
        //[/UserButtonCode__buttonDelete]
    }
    else if (buttonThatWasClicked == _buttonAdd.get())
    {
        //[UserButtonCode__buttonAdd] -- add your button handler code here..
        MainManager::instance().getWaypointsManager().commitWaypoint();
        MainManager::instance().getWaypointsManager().checkoutWaypoint(MainManager::instance().getWaypointsManager().addNewWaypoint());
        _waypointTableComponent->updateTable();
        //[/UserButtonCode__buttonAdd]
    }
    else if (buttonThatWasClicked == _buttonLoad.get())
    {
        //[UserButtonCode__buttonLoad] -- add your button handler code here..
        FileChooser fc(
            "Choose a waypoint file to load...",
            File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory),
            "*.json"
        );


        if (fc.browseForFileToOpen()) {
            File f(fc.getResult());

            if (!MainManager::instance().getWaypointsManager().loadWaypoints(f)) {
                AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Error", "Failed to load waypoints from file\n" + f.getFullPathName(), "Quit");
            }
            else {
                _waypointTableComponent->updateTable();
            }
        }

        //[/UserButtonCode__buttonLoad]
    }
    else if (buttonThatWasClicked == _buttonSave.get())
    {
        //[UserButtonCode__buttonSave] -- add your button handler code here..
        FileChooser fc(
            "Choose a file to save waypoints...",
            File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory),
            "*.json"
        );

        if (fc.browseForFileToSave(true)) {
            File f(fc.getResult());

            if (!MainManager::instance().getWaypointsManager().saveWaypoints(f, false)) {
                AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Error", "Failed to save waypoints to file\n" + f.getFullPathName(), "Quit");
            }
        }


        //[/UserButtonCode__buttonSave]
    }
    else if (buttonThatWasClicked == _buttonSend.get())
    {
        //[UserButtonCode__buttonSend] -- add your button handler code here..
        //[/UserButtonCode__buttonSend]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void WaypointEditorComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == _trailHideSlider.get())
    {
        //[UserSliderCode__trailHideSlider] -- add your slider handling code here..
        //[/UserSliderCode__trailHideSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void WaypointEditorComponent::changeListenerCallback(ChangeBroadcaster* source) {
    if (dynamic_cast<WaypointsManager*>(source)) {
        _waypointEditComponent->setWaypoint(dynamic_cast<WaypointsManager*>(source)->getCheckedOutWaypoint());
        _waypointMapComponent->repaint();
    }
    else if (dynamic_cast<WaypointEditComponent*>(source)) {
        _waypointTableComponent->updateTable();
        _waypointMapComponent->repaint();
    }
    else if (dynamic_cast<WaypointMapComponent*>(source)) {
        _waypointEditComponent->updateValues();
    }
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaypointEditorComponent"
                 componentName="" parentClasses="public juce::Component, public juce::ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="waypoint map component" id="d65263966a94c1f6" memberName="_waypointMapComponent"
                    virtualName="" explicitFocusOrder="0" pos="2 28 310M 56M" class="WaypointMapComponent"
                    params=""/>
  <GENERICCOMPONENT name="new component" id="bf5ef8d35dbf4612" memberName="_waypointEditComponent"
                    virtualName="" explicitFocusOrder="0" pos="2Rr 2Rr 298 200" class="WaypointEditComponent"
                    params=""/>
  <GENERICCOMPONENT name="waypoints list" id="a77f7f5f159169f" memberName="_waypointTableComponent"
                    virtualName="" explicitFocusOrder="0" pos="2Rr 28 298 300M" class="WaypointTableComponent"
                    params=""/>
  <IMAGEBUTTON name="delete button" id="59cdf533dc1b3b86" memberName="_buttonDelete"
               virtualName="" explicitFocusOrder="0" pos="2Rr -5R 24 24" posRelativeY="a77f7f5f159169f"
               tooltip="Delete selected waypoint" buttonText="new button" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="minus_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="minus_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="minus_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="add button" id="57398d1530ac5714" memberName="_buttonAdd"
               virtualName="" explicitFocusOrder="0" pos="32Rr -5R 24 24" posRelativeY="a77f7f5f159169f"
               tooltip="Add new waypoint" buttonText="new button" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="plus_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="plus_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="plus_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <TEXTBUTTON name="load button" id="4ad0b6b394697c87" memberName="_buttonLoad"
              virtualName="" explicitFocusOrder="0" pos="0 -5R 50 24" posRelativeX="a77f7f5f159169f"
              posRelativeY="a77f7f5f159169f" tooltip="Load a set of waypoints from file"
              buttonText="Load" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="save button" id="d92027cd0c2d684b" memberName="_buttonSave"
              virtualName="" explicitFocusOrder="0" pos="-5R 0 50 24" posRelativeX="4ad0b6b394697c87"
              posRelativeY="4ad0b6b394697c87" tooltip="Save the current set of waypoints to file"
              buttonText="Save" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="send button" id="3f7b716f29e59a3e" memberName="_buttonSend"
              virtualName="" explicitFocusOrder="0" pos="-5R 0 50 24" posRelativeX="d92027cd0c2d684b"
              posRelativeY="d92027cd0c2d684b" tooltip="Send the current set of waypoints to the speaker platform"
              buttonText="Send" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="waypoint table label" id="27cf2f5b01a4f49c" memberName="_waypointTableLabel"
         virtualName="" explicitFocusOrder="0" pos="0 -26 79 24" posRelativeX="a77f7f5f159169f"
         posRelativeY="a77f7f5f159169f" edTextCol="ff000000" edBkgCol="0"
         labelText="Waypoints" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="waypoint edit label" id="ba002db26aa2e533" memberName="_waypointEditLabel"
         virtualName="" explicitFocusOrder="0" pos="2 -26 53 24" posRelativeX="bf5ef8d35dbf4612"
         posRelativeY="bf5ef8d35dbf4612" edTextCol="ff000000" edBkgCol="0"
         labelText="Editor" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="waypoint map label" id="9c3ddf7e3252d0a0" memberName="_waypointMapLabel"
         virtualName="" explicitFocusOrder="0" pos="0 -26 38 24" posRelativeX="d65263966a94c1f6"
         posRelativeY="d65263966a94c1f6" edTextCol="ff000000" edBkgCol="0"
         labelText="Map" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="trail hiding slider" id="febd189a10da8af6" memberName="_trailHideSlider"
          virtualName="" explicitFocusOrder="0" pos="5Rr -2R 126 24" posRelativeX="d65263966a94c1f6"
          posRelativeY="d65263966a94c1f6" min="0.0" max="10.0" int="1.0"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="30" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="trail hiding label" id="ae674b5dcfb89da4" memberName="_trailHideLabel"
         virtualName="" explicitFocusOrder="0" pos="0r 0 80 24" posRelativeX="febd189a10da8af6"
         posRelativeY="febd189a10da8af6" edTextCol="ff000000" edBkgCol="0"
         labelText="Trail hiding" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: minus_png, 491, "../Assets/ButtonGraphics/png/minus.png"
static const unsigned char resource_WaypointEditorComponent_minus_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,
104,73,68,65,84,120,156,237,221,61,74,197,64,20,64,225,59,67,210,10,143,188,34,174,193,229,88,187,53,43,123,23,98,237,10,44,28,36,1,177,13,100,44,252,193,74,139,57,48,68,206,87,165,8,151,203,129,105,66,
96,210,178,44,53,212,36,247,94,224,63,24,190,30,82,74,87,219,182,45,61,151,57,146,113,28,207,181,214,199,136,31,17,183,109,91,230,121,126,233,183,214,177,148,82,98,24,62,242,121,156,1,70,4,24,17,96,68,
128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,192,240,247,43,191,91,215,245,34,34,174,129,
93,186,200,57,223,159,78,167,215,150,25,205,17,247,125,191,76,41,221,182,206,233,165,214,250,16,17,77,17,61,206,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,
154,63,133,229,156,159,107,173,55,196,50,157,60,181,14,104,142,56,77,211,91,68,220,181,206,57,50,143,51,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,
140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,248,254,161,105,28,199,115,41,165,231,46,135,242,121,247,64,68,68,36,175,18,105,231,113,6,188,3,71,179,50,104,104,
190,167,228,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointEditorComponent::minus_png = (const char*) resource_WaypointEditorComponent_minus_png;
const int WaypointEditorComponent::minus_pngSize = 491;

// JUCER_RESOURCE: plus_png, 625, "../Assets/ButtonGraphics/png/plus.png"
static const unsigned char resource_WaypointEditorComponent_plus_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,
238,73,68,65,84,120,156,237,221,49,106,27,65,20,135,241,55,195,142,170,96,16,90,9,229,12,185,128,193,228,20,73,233,180,169,114,29,183,14,129,148,1,95,32,133,123,215,62,129,139,44,98,22,66,98,210,204,178,
47,133,19,147,46,120,230,11,139,194,255,87,169,208,91,61,62,152,102,89,177,33,231,236,38,77,226,210,11,252,15,186,223,31,66,8,47,74,41,121,201,101,142,73,74,169,119,247,91,179,63,34,150,82,242,126,191,
63,44,183,214,113,25,134,193,186,238,33,159,142,51,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,64,247,247,175,252,91,135,195,225,217,106,181,218,214,206,151,82,242,118,
187,253,78,238,244,84,139,71,140,49,190,158,166,233,125,237,124,8,225,157,153,93,128,43,61,153,142,51,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,208,124,
43,108,28,199,19,51,123,213,112,137,51,247,166,71,36,79,199,113,252,81,59,28,99,188,90,175,215,95,91,22,104,142,56,207,243,243,16,194,101,235,117,26,156,187,251,121,237,176,187,223,152,89,83,68,29,103,
128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,160,249,86,88,140,241,139,187,191,169,157,15,33,188,116,247,183,13,43,124,48,179,207,13,243,119,13,179,102,6,
68,220,108,54,223,204,236,99,237,124,206,185,51,179,150,136,55,125,223,87,255,62,65,199,25,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,88,252,175,186,243,
60,127,74,41,93,215,206,79,211,52,130,235,84,89,60,226,110,183,187,55,179,251,165,247,104,161,227,12,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,240,120,3,34,165,212,15,
195,176,228,46,71,229,215,187,7,204,204,44,232,85,34,237,116,156,1,63,1,143,238,94,156,25,149,32,227,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointEditorComponent::plus_png = (const char*) resource_WaypointEditorComponent_plus_png;
const int WaypointEditorComponent::plus_pngSize = 625;


//[EndFile] You can add extra defines here...
//[/EndFile]

