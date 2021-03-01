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

    _trailsSlider.reset (new juce::Slider ("trails slider"));
    addAndMakeVisible (_trailsSlider.get());
    _trailsSlider->setRange (0, 10, 1);
    _trailsSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    _trailsSlider->setTextBoxStyle (juce::Slider::TextBoxRight, false, 30, 20);
    _trailsSlider->addListener (this);

    _trailHideLabel.reset (new juce::Label ("trail hiding label",
                                            TRANS("Trails")));
    addAndMakeVisible (_trailHideLabel.get());
    _trailHideLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _trailHideLabel->setJustificationType (juce::Justification::centredLeft);
    _trailHideLabel->setEditable (false, false, false);
    _trailHideLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _trailHideLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _playTimeComponent.reset (new TimeEditComponent());
    addAndMakeVisible (_playTimeComponent.get());
    _playTimeComponent->setName ("play time component");

    _buttonSkipBack.reset (new juce::ImageButton ("skip back button"));
    addAndMakeVisible (_buttonSkipBack.get());
    _buttonSkipBack->setButtonText (TRANS("skip back"));
    _buttonSkipBack->addListener (this);

    _buttonSkipBack->setImages (false, true, true,
                                juce::ImageCache::getFromMemory (skip_b_png, skip_b_pngSize), 1.000f, juce::Colour (0x00000000),
                                juce::ImageCache::getFromMemory (skip_b_png, skip_b_pngSize), 1.000f, juce::Colour (0xffababab),
                                juce::ImageCache::getFromMemory (skip_b_png, skip_b_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonStop.reset (new juce::ImageButton ("stop button"));
    addAndMakeVisible (_buttonStop.get());
    _buttonStop->setButtonText (TRANS("stop"));
    _buttonStop->addListener (this);

    _buttonStop->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0xffababab),
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonPlay.reset (new juce::ImageButton ("play button"));
    addAndMakeVisible (_buttonPlay.get());
    _buttonPlay->setButtonText (TRANS("play"));
    _buttonPlay->addListener (this);

    _buttonPlay->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0xffababab),
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonSkipForward.reset (new juce::ImageButton ("skip forward button"));
    addAndMakeVisible (_buttonSkipForward.get());
    _buttonSkipForward->setButtonText (TRANS("stop"));
    _buttonSkipForward->addListener (this);

    _buttonSkipForward->setImages (false, true, true,
                                   juce::ImageCache::getFromMemory (skip_f_png, skip_f_pngSize), 1.000f, juce::Colour (0x00000000),
                                   juce::ImageCache::getFromMemory (skip_f_png, skip_f_pngSize), 1.000f, juce::Colour (0xffababab),
                                   juce::ImageCache::getFromMemory (skip_f_png, skip_f_pngSize), 1.000f, juce::Colour (0xffa45c94));

    //[UserPreSize]


    _buttonPlay->setClickingTogglesState(true);

    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    _playTimeComponent->setTimeObject(&_playTime);

    _waypointEditComponent->addChangeListener(this);
    _waypointMapComponent->addChangeListener(this);

    MainManager::instance().getWaypointsManager().addChangeListener(this);
    MainManager::instance().getWaypointsPlayer().addChangeListener(this);
    MainManager::instance().getWaypointsPlayer().addChangeListener(_waypointMapComponent.get());
    MainManager::instance().getWaypointsPlayer().startTimingThread();
    MainManager::instance().getWaypointsPlayer().reset();

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
    _trailsSlider = nullptr;
    _trailHideLabel = nullptr;
    _playTimeComponent = nullptr;
    _buttonSkipBack = nullptr;
    _buttonStop = nullptr;
    _buttonPlay = nullptr;
    _buttonSkipForward = nullptr;


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
    _trailsSlider->setBounds (2 + (getWidth() - 310) - 5 - 126, 28 + (getHeight() - 56) - -2, 126, 24);
    _trailHideLabel->setBounds ((2 + (getWidth() - 310) - 5 - 126) + 0 - 44, (28 + (getHeight() - 56) - -2) + 0, 44, 24);
    _playTimeComponent->setBounds (((((2 + 5) + 24 - -4) + 24 - -4) + 24 - -4) + 24 - -15, 28 + (getHeight() - 56) - -2, 112, 24);
    _buttonSkipBack->setBounds (2 + 5, 28 + (getHeight() - 56) - -2, 24, 24);
    _buttonStop->setBounds ((2 + 5) + 24 - -4, 28 + (getHeight() - 56) - -2, 24, 24);
    _buttonPlay->setBounds (((2 + 5) + 24 - -4) + 24 - -4, 28 + (getHeight() - 56) - -2, 24, 24);
    _buttonSkipForward->setBounds ((((2 + 5) + 24 - -4) + 24 - -4) + 24 - -4, 28 + (getHeight() - 56) - -2, 24, 24);
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
    else if (buttonThatWasClicked == _buttonSkipBack.get())
    {
        //[UserButtonCode__buttonSkipBack] -- add your button handler code here..
        //[/UserButtonCode__buttonSkipBack]
    }
    else if (buttonThatWasClicked == _buttonStop.get())
    {
        //[UserButtonCode__buttonStop] -- add your button handler code here..
        MainManager::instance().getWaypointsPlayer().pause();
        MainManager::instance().getWaypointsPlayer().reset();

        if (_buttonPlay->getToggleState() == true)
            _buttonPlay->setToggleState(false, NotificationType::dontSendNotification);
        //[/UserButtonCode__buttonStop]
    }
    else if (buttonThatWasClicked == _buttonPlay.get())
    {
        //[UserButtonCode__buttonPlay] -- add your button handler code here..

        if (_buttonPlay->getToggleState()) {

            _playTimeComponent->setEditable(false);

            //MainManager::instance().getWaypointsPlayer().reset();
            MainManager::instance().getWaypointsPlayer().play();
        }
        else {
            MainManager::instance().getWaypointsPlayer().pause();

            _playTimeComponent->setEditable(false);
        }
        //[/UserButtonCode__buttonPlay]
    }
    else if (buttonThatWasClicked == _buttonSkipForward.get())
    {
        //[UserButtonCode__buttonSkipForward] -- add your button handler code here..
        //[/UserButtonCode__buttonSkipForward]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void WaypointEditorComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == _trailsSlider.get())
    {
        //[UserSliderCode__trailsSlider] -- add your slider handling code here..
        _waypointMapComponent->setTrails((uint16)_trailsSlider->getValue());
        _waypointMapComponent->repaint();
        //[/UserSliderCode__trailsSlider]
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
    else if (dynamic_cast<WaypointsPlayer*>(source)) {
        _playTime.setTime(dynamic_cast<WaypointsPlayer*>(source)->getPlayTime());
        _playTimeComponent->update();
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
  <SLIDER name="trails slider" id="febd189a10da8af6" memberName="_trailsSlider"
          virtualName="" explicitFocusOrder="0" pos="5Rr -2R 126 24" posRelativeX="d65263966a94c1f6"
          posRelativeY="d65263966a94c1f6" min="0.0" max="10.0" int="1.0"
          style="LinearHorizontal" textBoxPos="TextBoxRight" textBoxEditable="1"
          textBoxWidth="30" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="trail hiding label" id="ae674b5dcfb89da4" memberName="_trailHideLabel"
         virtualName="" explicitFocusOrder="0" pos="0r 0 44 24" posRelativeX="febd189a10da8af6"
         posRelativeY="febd189a10da8af6" edTextCol="ff000000" edBkgCol="0"
         labelText="Trails" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="play time component" id="3a9758dff8dc15b" memberName="_playTimeComponent"
                    virtualName="" explicitFocusOrder="0" pos="-15R -2R 112 24" posRelativeX="f71e9a6ccf1784e"
                    posRelativeY="d65263966a94c1f6" class="TimeEditComponent" params=""/>
  <IMAGEBUTTON name="skip back button" id="67b2579411eda22d" memberName="_buttonSkipBack"
               virtualName="" explicitFocusOrder="0" pos="5 -2R 24 24" posRelativeX="d65263966a94c1f6"
               posRelativeY="d65263966a94c1f6" buttonText="skip back" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="skip_b_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="skip_b_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="skip_b_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="stop button" id="60da11a2f25f4ffa" memberName="_buttonStop"
               virtualName="" explicitFocusOrder="0" pos="-4R -2R 24 24" posRelativeX="67b2579411eda22d"
               posRelativeY="d65263966a94c1f6" buttonText="stop" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="stop_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="stop_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="stop_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="play button" id="5cad63f18ab60b03" memberName="_buttonPlay"
               virtualName="" explicitFocusOrder="0" pos="-4R -2R 24 24" posRelativeX="60da11a2f25f4ffa"
               posRelativeY="d65263966a94c1f6" buttonText="play" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="play_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="play_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="play_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="skip forward button" id="f71e9a6ccf1784e" memberName="_buttonSkipForward"
               virtualName="" explicitFocusOrder="0" pos="-4R -2R 24 24" posRelativeX="5cad63f18ab60b03"
               posRelativeY="d65263966a94c1f6" buttonText="stop" connectedEdges="0"
               needsCallback="1" radioGroupId="0" keepProportions="1" resourceNormal="skip_f_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="skip_f_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="skip_f_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
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

// JUCER_RESOURCE: skip_b_png, 739, "../Assets/graphics/png/skip_b.png"
static const unsigned char resource_WaypointEditorComponent_skip_b_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,2,96,73,68,65,84,120,156,237,221,49,171,19,65,16,192,241,153,120,23,176,48,41,238,21,105,131,68,132,87,217,248,9,222,103,240,27,249,105,30,126,14,121,157,141,240,138,20,175,203,33,3,73,163,120,156,222,
90,152,17,43,45,118,118,119,102,119,254,16,200,65,24,150,31,119,77,50,16,36,162,0,94,84,171,210,7,168,161,142,223,32,226,237,60,207,84,242,48,150,234,251,254,38,132,240,25,224,47,196,121,158,105,183,219,
125,41,119,44,91,141,227,8,93,247,155,207,31,103,129,28,81,32,71,20,200,17,5,114,68,129,28,81,32,71,20,200,17,5,114,68,129,28,81,32,71,20,200,17,5,234,254,255,145,127,23,66,192,211,233,244,156,175,167,
105,90,246,251,253,247,216,185,185,10,33,116,136,248,35,102,70,244,157,72,68,175,214,235,245,87,126,109,54,155,143,177,51,115,68,68,119,68,244,112,62,159,95,199,206,138,190,19,173,69,68,119,0,240,30,0,
222,74,205,108,6,49,5,30,87,61,98,74,60,174,90,196,28,120,92,117,136,57,241,184,106,16,75,224,113,230,17,75,226,113,102,17,53,224,113,230,16,53,225,113,102,16,53,226,113,234,17,53,227,113,106,17,45,224,
113,234,16,45,225,113,106,16,45,226,113,197,17,45,227,113,197,16,107,192,227,178,35,214,132,199,101,67,172,17,143,75,142,88,51,30,151,12,177,5,60,78,28,49,132,240,130,136,30,160,1,60,46,197,157,248,242,
250,106,166,232,159,76,87,171,213,51,137,131,88,46,26,113,89,150,159,18,7,177,156,248,26,9,34,62,1,192,163,244,92,205,165,216,197,185,12,195,112,139,136,239,160,17,204,36,11,77,136,184,12,195,112,223,
10,102,210,173,176,86,48,179,172,214,213,142,153,117,63,177,86,204,34,75,158,181,97,22,221,148,173,5,83,197,186,177,117,76,21,136,156,85,76,85,136,156,53,76,149,136,156,21,76,213,136,156,118,76,19,136,
156,86,76,83,136,156,54,76,147,136,156,22,76,211,136,92,105,204,42,16,185,82,152,85,33,114,185,49,171,68,228,114,97,86,141,200,165,198,108,2,145,75,133,25,253,227,253,229,114,121,218,110,183,111,248,26,
17,191,197,206,76,29,34,46,0,112,31,66,248,112,60,30,251,216,121,209,136,135,195,97,2,128,79,177,115,74,116,197,156,98,231,52,245,56,167,202,17,5,114,68,129,28,81,32,71,20,200,17,5,114,68,129,28,81,32,
71,20,200,17,5,114,68,129,28,81,160,63,95,64,244,125,127,51,142,99,201,179,152,234,250,223,3,0,0,128,254,87,34,241,249,227,44,208,47,98,34,238,230,230,89,107,185,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointEditorComponent::skip_b_png = (const char*) resource_WaypointEditorComponent_skip_b_png;
const int WaypointEditorComponent::skip_b_pngSize = 739;

// JUCER_RESOURCE: stop_png, 492, "../Assets/graphics/png/stop.png"
static const unsigned char resource_WaypointEditorComponent_stop_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,
105,73,68,65,84,120,156,237,221,189,74,196,64,20,64,225,123,37,83,239,22,41,182,176,209,86,124,255,23,81,176,17,44,20,130,12,236,110,61,66,44,252,193,74,139,57,48,68,206,87,165,8,151,203,129,105,2,97,
178,214,186,134,186,92,140,94,224,63,152,190,30,50,243,166,181,86,71,46,179,37,165,148,121,93,215,251,136,31,17,91,107,245,112,56,188,142,91,107,91,150,101,137,105,250,200,231,113,6,24,17,96,68,128,17,
1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,211,223,175,252,110,93,215,114,62,159,47,137,101,70,216,237,118,207,153,217,122,102,116,71,172,181,94,103,230,67,239,156,81,142,199,227,109,68,220,
245,204,240,56,3,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,
35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,232,254,85,119,158,231,199,211,233,116,69,44,51,194,126,191,127,233,157,209,29,49,
51,223,34,226,169,119,206,150,121,156,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,192,247,7,136,82,202,188,44,203,200,93,54,229,243,238,129,136,136,72,175,18,233,231,113,6,188,
3,229,194,52,144,182,227,223,99,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointEditorComponent::stop_png = (const char*) resource_WaypointEditorComponent_stop_png;
const int WaypointEditorComponent::stop_pngSize = 492;

// JUCER_RESOURCE: play_png, 649, "../Assets/graphics/png/play.png"
static const unsigned char resource_WaypointEditorComponent_play_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,2,
6,73,68,65,84,120,156,237,221,49,78,228,64,16,133,225,174,149,125,129,145,131,201,17,17,210,222,102,67,226,189,10,167,32,36,224,52,36,196,147,90,168,103,14,128,119,85,4,240,16,17,4,126,118,87,85,215,31,
77,50,163,210,55,106,187,109,7,150,90,171,150,108,85,191,90,15,16,161,1,31,68,228,102,89,150,218,114,24,79,141,227,56,169,234,115,41,95,16,151,101,169,199,227,241,165,221,88,190,154,231,185,12,195,59,
95,46,103,66,137,72,40,17,9,37,34,161,68,36,148,136,132,18,145,80,34,18,74,68,66,137,72,40,17,9,37,34,161,213,136,170,58,168,170,48,134,241,218,106,196,90,235,85,173,245,233,124,62,255,233,21,147,178,
156,69,228,183,170,62,246,138,73,61,38,246,138,185,201,137,165,55,204,77,207,206,189,96,238,178,197,137,142,185,235,62,49,42,102,147,205,118,52,204,166,87,44,81,48,77,92,246,121,199,52,129,136,188,98,
154,66,68,222,48,77,34,34,47,152,166,17,145,117,76,23,136,200,42,166,43,68,100,13,211,37,34,178,130,233,26,17,181,198,12,129,136,90,97,134,66,68,123,99,134,68,68,123,97,134,70,68,91,99,118,129,136,182,
194,236,10,17,1,243,114,185,60,168,234,240,243,55,190,175,75,68,85,61,169,234,223,195,225,112,43,34,255,214,254,222,234,127,193,83,170,122,42,165,220,77,211,116,207,192,67,93,32,110,133,135,66,35,110,
141,135,66,34,238,133,135,66,33,238,141,135,66,32,182,194,67,174,17,91,227,33,151,136,86,240,144,43,68,107,120,200,5,162,85,60,100,26,209,58,30,50,137,232,5,15,153,66,244,134,135,76,32,122,197,67,77,17,
189,227,161,38,136,81,240,208,174,136,209,240,208,46,136,81,241,208,166,136,209,241,208,38,136,189,224,33,42,98,111,120,136,130,216,43,30,90,141,56,77,211,169,148,114,45,34,255,9,243,184,108,53,162,136,
188,50,6,241,92,151,15,239,217,37,34,161,68,36,148,136,132,18,145,80,34,18,74,68,66,137,72,40,17,9,37,34,161,68,36,148,136,132,62,111,64,140,227,56,205,243,220,114,22,87,125,188,123,160,148,82,138,228,
171,68,214,151,203,153,208,27,52,114,249,232,172,17,69,155,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointEditorComponent::play_png = (const char*) resource_WaypointEditorComponent_play_png;
const int WaypointEditorComponent::play_pngSize = 649;

// JUCER_RESOURCE: skip_f_png, 742, "../Assets/graphics/png/skip_f.png"
static const unsigned char resource_WaypointEditorComponent_skip_f_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,2,99,73,68,65,84,120,156,237,221,193,138,19,65,16,198,241,250,116,58,30,132,132,64,31,130,87,81,15,194,62,199,190,128,207,224,171,248,20,62,128,55,223,68,4,175,134,133,61,12,166,67,206,217,201,82,30,
220,146,61,136,10,93,51,221,213,93,127,8,100,32,20,195,143,153,204,76,134,48,72,41,49,121,89,61,41,189,2,45,52,200,27,0,111,167,105,74,37,87,198,82,33,132,200,204,223,136,30,33,78,211,148,118,187,221,
143,114,171,101,171,113,28,105,24,126,241,249,238,172,144,35,42,228,136,10,57,162,66,142,168,144,35,42,228,136,10,57,162,66,142,168,144,35,42,228,136,10,57,162,66,195,191,63,242,247,152,121,32,162,123,
0,38,126,151,60,28,14,47,66,8,207,100,121,179,217,220,2,152,114,102,102,111,137,41,165,151,41,165,47,199,227,241,29,51,35,119,222,220,1,248,124,185,92,190,203,235,116,58,189,201,157,169,178,59,3,184,98,
230,79,150,48,53,83,253,78,236,21,115,150,3,75,111,152,179,30,157,123,193,92,228,20,167,117,204,69,207,19,91,197,44,114,178,221,26,102,209,43,150,86,48,171,184,236,179,142,89,5,162,100,21,179,42,68,201,
26,102,149,136,146,21,204,170,17,165,218,49,77,32,74,181,98,154,66,148,106,195,52,137,40,213,130,105,26,81,42,141,217,4,162,84,10,179,41,68,105,105,204,38,17,165,165,48,179,239,246,89,232,17,230,87,0,
207,181,231,119,129,40,1,184,154,99,110,211,187,243,255,4,224,105,238,140,238,17,153,249,62,119,70,87,136,204,188,39,162,27,237,185,93,32,50,243,158,153,223,199,24,95,19,209,65,123,126,211,7,150,135,45,
239,67,140,241,35,128,11,17,81,74,250,127,26,107,18,241,79,120,115,214,20,226,210,120,82,19,136,165,240,36,211,136,165,241,36,147,136,181,224,73,166,16,107,195,147,76,32,214,138,39,85,141,88,59,158,84,
37,162,21,60,169,42,68,107,120,82,21,136,86,241,164,162,136,214,241,164,34,136,173,224,73,139,34,182,134,39,45,130,216,42,158,52,43,98,235,120,210,44,136,189,224,73,170,136,189,225,73,42,136,189,226,73,
217,136,49,198,61,17,189,2,144,125,235,113,137,86,171,213,245,249,124,94,201,242,118,187,205,190,113,149,141,8,224,46,119,198,146,173,215,235,163,246,204,46,110,153,206,157,35,42,228,136,10,57,162,66,
142,168,144,35,42,228,136,10,57,162,66,142,168,144,35,42,228,136,10,57,162,66,191,127,128,8,33,196,113,28,75,174,139,169,30,158,61,64,68,68,240,71,137,228,231,187,179,66,63,1,217,57,243,163,101,136,57,
187,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointEditorComponent::skip_f_png = (const char*) resource_WaypointEditorComponent_skip_f_png;
const int WaypointEditorComponent::skip_f_pngSize = 742;


//[EndFile] You can add extra defines here...
//[/EndFile]

