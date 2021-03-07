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

#include "WaypointPlayerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WaypointPlayerComponent::WaypointPlayerComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _buttonStop.reset (new juce::ImageButton ("stop button"));
    addAndMakeVisible (_buttonStop.get());
    _buttonStop->setButtonText (TRANS("new button"));
    _buttonStop->addListener (this);

    _buttonStop->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0xffababab),
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonStop->setBounds (0, 0, 24, 24);

    _buttonArm.reset (new juce::ImageButton ("arm button"));
    addAndMakeVisible (_buttonArm.get());
    _buttonArm->setButtonText (TRANS("new button"));
    _buttonArm->addListener (this);

    _buttonArm->setImages (false, true, true,
                           juce::ImageCache::getFromMemory (rec_png, rec_pngSize), 1.000f, juce::Colour (0x00000000),
                           juce::ImageCache::getFromMemory (rec_png, rec_pngSize), 1.000f, juce::Colour (0xffababab),
                           juce::ImageCache::getFromMemory (rec_png, rec_pngSize), 1.000f, juce::Colours::red);
    _buttonPlay.reset (new juce::ImageButton ("play button"));
    addAndMakeVisible (_buttonPlay.get());
    _buttonPlay->setButtonText (TRANS("new button"));
    _buttonPlay->addListener (this);

    _buttonPlay->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0x00000000),
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0xffababab),
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colours::chartreuse);
    _playtimeComponent.reset (new TimeEditComponent());
    addAndMakeVisible (_playtimeComponent.get());
    _playtimeComponent->setName ("playtime component");


    //[UserPreSize]

    _buttonPlay->setClickingTogglesState(true);
    _buttonArm->setClickingTogglesState(true);


    _playtimeComponent->setTimeObject(&_playTime);
    _playtimeComponent->setEditable(false);
    //[/UserPreSize]

    setSize (208, 24);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WaypointPlayerComponent::~WaypointPlayerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _buttonStop = nullptr;
    _buttonArm = nullptr;
    _buttonPlay = nullptr;
    _playtimeComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WaypointPlayerComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WaypointPlayerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _buttonArm->setBounds (0 + 24 - -4, 0, 24, 24);
    _buttonPlay->setBounds ((0 + 24 - -4) + 24 - -4, 0, 24, 24);
    _playtimeComponent->setBounds (((0 + 24 - -4) + 24 - -4) + 24 - -16, 0, 112, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void WaypointPlayerComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _buttonStop.get())
    {
        //[UserButtonCode__buttonStop] -- add your button handler code here..
        RobotsManager::instance().getSelectedRobot()->waypointsPlayer.pause();
        RobotsManager::instance().getSelectedRobot()->waypointsPlayer.reset();

        if (_buttonPlay->getToggleState() == true)
            _buttonPlay->setToggleState(false, NotificationType::dontSendNotification);
        //[/UserButtonCode__buttonStop]
    }
    else if (buttonThatWasClicked == _buttonArm.get())
    {
        //[UserButtonCode__buttonArm] -- add your button handler code here..

        if (_buttonArm->getToggleState()) {
            RobotsManager::instance().getSelectedRobot()->waypointsPlayer.startTimingThread();
        }
        else {
            RobotsManager::instance().getSelectedRobot()->waypointsPlayer.pause();
            RobotsManager::instance().getSelectedRobot()->waypointsPlayer.reset();

            if (_buttonPlay->getToggleState() == true)
                _buttonPlay->setToggleState(false, NotificationType::dontSendNotification);

            RobotsManager::instance().getSelectedRobot()->waypointsPlayer.stopTimingThread();
        }
        //[/UserButtonCode__buttonArm]
    }
    else if (buttonThatWasClicked == _buttonPlay.get())
    {
        //[UserButtonCode__buttonPlay] -- add your button handler code here..

        if (_buttonPlay->getToggleState()) {
            if (RobotsManager::instance().getSelectedRobot()->waypointsPlayer.isTimerRunning())
                RobotsManager::instance().getSelectedRobot()->waypointsPlayer.play();
            else
                _buttonPlay->setToggleState(false, NotificationType::dontSendNotification);
        }
        else {
            RobotsManager::instance().getSelectedRobot()->waypointsPlayer.pause();

        }
        //[/UserButtonCode__buttonPlay]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void WaypointPlayerComponent::update() {

    WaypointsPlayer* wpp = &RobotsManager::instance().getSelectedRobot()->waypointsPlayer;

    _buttonArm->setToggleState(wpp->isTimerRunning(), NotificationType::dontSendNotification);
    _buttonPlay->setToggleState(wpp->isPlaying(), NotificationType::dontSendNotification);

    _playTime.setTime(wpp->getPlayTime());
    _playtimeComponent->update();
}

void WaypointPlayerComponent::changeListenerCallback(ChangeBroadcaster* source) {

    if (dynamic_cast<WaypointsPlayer*>(source)) {

        _buttonPlay->setToggleState(RobotsManager::instance().getSelectedRobot()->waypointsPlayer.isPlaying(), NotificationType::dontSendNotification);
        _playTime.setTime(RobotsManager::instance().getSelectedRobot()->waypointsPlayer.getPlayTime());
        _playtimeComponent->update();
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaypointPlayerComponent"
                 componentName="" parentClasses="public juce::Component, public juce::ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="208"
                 initialHeight="24">
  <BACKGROUND backgroundColour="ff323e44"/>
  <IMAGEBUTTON name="stop button" id="875c710030571bea" memberName="_buttonStop"
               virtualName="" explicitFocusOrder="0" pos="0 0 24 24" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="stop_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="stop_png" opacityOver="1.0" colourOver="ffababab"
               resourceDown="stop_png" opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="arm button" id="4dc8954d3c39ff21" memberName="_buttonArm"
               virtualName="" explicitFocusOrder="0" pos="-4R 0 24 24" posRelativeX="875c710030571bea"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="rec_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="rec_png" opacityOver="1.0"
               colourOver="ffababab" resourceDown="rec_png" opacityDown="1.0"
               colourDown="ffff0000"/>
  <IMAGEBUTTON name="play button" id="b55760d789b11a2e" memberName="_buttonPlay"
               virtualName="" explicitFocusOrder="0" pos="-4R 0 24 24" posRelativeX="4dc8954d3c39ff21"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="play_png"
               opacityNormal="1.0" colourNormal="0" resourceOver="play_png"
               opacityOver="1.0" colourOver="ffababab" resourceDown="play_png"
               opacityDown="1.0" colourDown="ff7fff00"/>
  <GENERICCOMPONENT name="playtime component" id="e702653e6f6a8306" memberName="_playtimeComponent"
                    virtualName="" explicitFocusOrder="0" pos="-16R 0 112 24" posRelativeX="b55760d789b11a2e"
                    class="TimeEditComponent" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: stop_png, 492, "../Assets/graphics/png/stop.png"
static const unsigned char resource_WaypointPlayerComponent_stop_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,
105,73,68,65,84,120,156,237,221,189,74,196,64,20,64,225,123,37,83,239,22,41,182,176,209,86,124,255,23,81,176,17,44,20,130,12,236,110,61,66,44,252,193,74,139,57,48,68,206,87,165,8,151,203,129,105,2,97,
178,214,186,134,186,92,140,94,224,63,152,190,30,50,243,166,181,86,71,46,179,37,165,148,121,93,215,251,136,31,17,91,107,245,112,56,188,142,91,107,91,150,101,137,105,250,200,231,113,6,24,17,96,68,128,17,
1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,211,223,175,252,110,93,215,114,62,159,47,137,101,70,216,237,118,207,153,217,122,102,116,71,172,181,94,103,230,67,239,156,81,142,199,227,109,68,220,
245,204,240,56,3,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,
35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,232,254,85,119,158,231,199,211,233,116,69,44,51,194,126,191,127,233,157,209,29,49,
51,223,34,226,169,119,206,150,121,156,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,192,247,7,136,82,202,188,44,203,200,93,54,229,243,238,129,136,136,72,175,18,233,231,113,6,188,
3,229,194,52,144,182,227,223,99,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointPlayerComponent::stop_png = (const char*) resource_WaypointPlayerComponent_stop_png;
const int WaypointPlayerComponent::stop_pngSize = 492;

// JUCER_RESOURCE: rec_png, 1471, "../Assets/graphics/png/rec.png"
static const unsigned char resource_WaypointPlayerComponent_rec_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,
60,73,68,65,84,120,156,237,157,63,108,27,85,28,199,191,191,179,29,26,5,199,193,207,118,29,33,1,25,210,34,40,41,12,221,90,154,80,169,165,108,208,5,150,176,85,4,33,24,80,17,91,25,144,248,35,22,24,66,37,
6,68,6,254,84,128,96,66,16,32,137,144,96,139,82,42,80,75,36,172,74,136,56,246,123,118,156,18,5,108,231,126,12,189,162,74,132,36,248,126,239,206,169,222,71,178,148,193,249,188,231,143,238,236,243,187,187,
132,180,214,12,71,40,188,184,39,112,51,144,188,254,3,17,221,219,106,181,116,156,147,217,77,164,82,169,28,51,255,4,220,16,177,213,106,233,98,177,88,137,111,90,187,139,114,185,140,100,242,90,62,183,59,11,
224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,144,220,254,41,241,80,42,149,246,40,165,250,214,215,215,51,189,189,189,13,99,204,218,208,208,
208,159,113,207,107,51,186,34,226,210,210,82,190,167,167,103,140,153,71,1,28,4,176,31,128,106,54,155,72,36,18,104,54,155,72,167,211,208,90,27,0,151,1,92,32,162,217,102,179,57,51,56,56,88,141,115,238,0,
64,215,87,182,219,237,246,222,40,151,194,152,57,165,181,62,5,96,156,136,142,3,72,116,160,217,96,230,105,0,83,185,92,238,99,34,106,201,206,242,191,41,151,203,133,100,50,185,12,196,240,158,200,204,73,173,
245,132,49,230,23,34,250,128,136,78,162,179,128,0,144,32,162,135,137,232,125,99,204,162,214,122,130,153,83,146,243,221,9,145,70,172,213,106,135,141,49,243,0,38,1,220,37,172,191,19,192,164,49,102,190,82,
169,28,17,118,111,73,36,17,153,57,81,173,86,95,242,125,127,14,192,125,150,135,59,224,121,222,156,214,250,205,168,182,74,235,17,107,181,90,198,24,51,77,68,103,163,24,47,128,0,60,107,140,249,170,94,175,
15,216,30,204,234,139,90,94,94,222,203,204,179,0,198,108,142,179,5,163,237,118,123,174,82,169,20,109,14,98,45,162,49,166,63,145,72,124,193,204,247,219,26,99,39,16,209,136,231,121,211,43,43,43,183,217,
26,195,74,68,102,78,50,243,231,0,30,176,225,239,128,3,27,27,27,159,217,122,143,180,18,209,24,243,50,128,81,27,238,78,97,230,7,131,121,137,35,30,177,90,173,30,5,112,70,218,43,196,25,173,245,67,210,82,209,
136,204,220,67,68,147,210,94,65,8,192,219,139,139,139,183,72,74,69,95,172,49,230,41,0,247,72,58,45,176,47,155,205,78,72,10,197,34,6,111,218,207,75,249,108,194,204,47,148,74,165,61,82,62,177,136,198,152,
39,0,220,33,229,179,204,96,58,157,126,92,74,38,185,59,63,41,232,138,130,113,41,145,72,196,106,181,58,136,46,59,164,217,1,71,181,214,183,75,136,68,34,18,209,49,41,87,132,120,0,142,73,137,66,19,172,72,239,
70,68,190,211,75,109,137,7,37,60,49,48,34,33,145,218,5,247,9,121,162,102,63,51,83,88,73,232,136,198,152,126,0,253,97,61,49,209,215,104,52,66,175,55,134,142,200,204,233,176,142,56,241,125,63,244,252,67,
71,244,125,191,55,172,35,78,124,223,239,11,235,8,29,209,243,188,245,176,142,56,241,60,111,45,180,35,172,128,136,174,134,117,196,137,231,121,161,231,31,58,162,82,106,21,192,106,88,79,76,172,101,50,153,
149,176,18,169,67,156,203,66,158,168,185,68,68,161,239,109,148,250,198,114,65,194,19,3,63,74,72,164,182,196,89,33,79,212,204,72,72,164,182,196,111,0,248,18,174,8,241,131,121,135,70,36,98,161,80,40,3,248,
86,194,21,33,179,249,124,254,119,9,145,228,242,213,123,130,174,40,152,146,18,137,69,84,74,125,4,224,138,148,207,50,191,213,235,245,15,165,100,98,17,131,11,44,223,144,242,89,230,245,225,225,225,191,164,
100,162,171,209,74,169,115,204,44,114,216,96,145,159,149,82,231,36,133,162,17,137,168,205,204,207,160,123,63,169,125,102,126,90,250,178,100,241,243,34,133,66,225,59,0,175,72,123,133,120,53,159,207,207,
73,75,173,156,92,82,74,157,5,32,114,12,38,200,76,48,47,113,172,68,36,162,13,102,126,20,192,188,13,127,7,92,76,38,147,167,136,168,109,67,110,237,52,103,62,159,191,218,110,183,79,34,230,144,68,180,224,251,
254,241,129,129,129,186,173,49,172,158,43,46,22,139,21,34,26,3,48,109,115,156,45,248,154,136,70,131,111,84,214,176,126,194,93,41,181,170,148,58,1,224,69,0,27,182,199,11,96,0,111,41,165,30,201,102,179,
13,219,131,69,114,213,2,17,113,46,151,123,141,136,142,16,209,130,229,177,22,136,232,112,46,151,123,46,170,59,172,34,189,244,67,41,245,67,54,155,61,196,204,167,137,232,87,73,55,51,151,152,249,116,54,155,
61,164,148,250,94,210,189,29,145,223,32,25,124,66,190,195,204,239,214,106,181,199,0,140,51,243,137,14,231,210,38,162,47,1,76,41,165,62,181,245,233,187,29,177,221,101,26,188,224,243,0,206,175,174,174,170,
86,171,53,202,204,163,68,52,194,204,119,3,40,108,242,107,21,34,186,196,204,23,137,104,38,149,74,205,246,247,247,155,104,103,254,111,186,226,86,221,32,196,39,193,3,192,181,43,111,27,141,198,173,0,6,0,172,
100,50,153,63,162,188,139,244,255,208,21,17,55,35,8,86,15,30,93,205,110,187,166,176,43,113,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,248,103,1,34,149,
74,229,202,101,171,167,34,110,42,130,255,61,0,224,134,63,184,230,232,28,183,59,11,240,55,204,84,180,253,167,66,187,104,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* WaypointPlayerComponent::rec_png = (const char*) resource_WaypointPlayerComponent_rec_png;
const int WaypointPlayerComponent::rec_pngSize = 1471;

// JUCER_RESOURCE: play_png, 649, "../Assets/graphics/png/play.png"
static const unsigned char resource_WaypointPlayerComponent_play_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
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

const char* WaypointPlayerComponent::play_png = (const char*) resource_WaypointPlayerComponent_play_png;
const int WaypointPlayerComponent::play_pngSize = 649;


//[EndFile] You can add extra defines here...
//[/EndFile]

