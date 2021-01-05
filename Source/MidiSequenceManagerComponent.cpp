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

#include "MidiSequenceManagerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MidiSequenceManagerComponent::MidiSequenceManagerComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _labelSequence.reset (new juce::Label ("sequence label",
                                           TRANS("Sequences")));
    addAndMakeVisible (_labelSequence.get());
    _labelSequence->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    _labelSequence->setJustificationType (juce::Justification::centredLeft);
    _labelSequence->setEditable (false, false, false);
    _labelSequence->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    _labelSequence->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    _labelSequence->setBounds (0, 2, 150, 24);

    _tableComponent.reset (new MidiSequenceTableComponent());
    addAndMakeVisible (_tableComponent.get());
    _tableComponent->setName ("table component");

    _buttonDelete.reset (new juce::ImageButton ("delete button"));
    addAndMakeVisible (_buttonDelete.get());
    _buttonDelete->setTooltip (TRANS("delete selected sequence"));
    _buttonDelete->setButtonText (TRANS("delete sequence"));
    _buttonDelete->addListener (this);

    _buttonDelete->setImages (false, true, true,
                              juce::ImageCache::getFromMemory (minus_png, minus_pngSize), 1.000f, juce::Colour (0xffafafaf),
                              juce::ImageCache::getFromMemory (minus_png, minus_pngSize), 1.000f, juce::Colours::white,
                              juce::ImageCache::getFromMemory (minus_png, minus_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonExport.reset (new juce::TextButton ("export button"));
    addAndMakeVisible (_buttonExport.get());
    _buttonExport->setTooltip (TRANS("Export selected sequence"));
    _buttonExport->setButtonText (TRANS("Export"));
    _buttonExport->addListener (this);

    _buttonImport.reset (new juce::TextButton ("import button"));
    addAndMakeVisible (_buttonImport.get());
    _buttonImport->setTooltip (TRANS("Import selected sequence"));
    _buttonImport->setButtonText (TRANS("Import"));
    _buttonImport->addListener (this);
    _buttonImport->setColour (juce::TextButton::buttonColourId, juce::Colour (0xffa45c94));

    _buttonAdd.reset (new juce::ImageButton ("add button"));
    addAndMakeVisible (_buttonAdd.get());
    _buttonAdd->setTooltip (TRANS("add new sequence"));
    _buttonAdd->setButtonText (TRANS("add sequence"));
    _buttonAdd->addListener (this);

    _buttonAdd->setImages (false, true, true,
                           juce::ImageCache::getFromMemory (plus_png, plus_pngSize), 1.000f, juce::Colour (0xffafafaf),
                           juce::ImageCache::getFromMemory (plus_png, plus_pngSize), 1.000f, juce::Colours::white,
                           juce::ImageCache::getFromMemory (plus_png, plus_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonMoveDown.reset (new juce::ImageButton ("move down button"));
    addAndMakeVisible (_buttonMoveDown.get());
    _buttonMoveDown->setTooltip (TRANS("Move selected sequence down in the list"));
    _buttonMoveDown->setButtonText (TRANS("move sequence down"));
    _buttonMoveDown->addListener (this);

    _buttonMoveDown->setImages (false, true, true,
                                juce::ImageCache::getFromMemory (down_png, down_pngSize), 1.000f, juce::Colour (0xffafafaf),
                                juce::ImageCache::getFromMemory (down_png, down_pngSize), 1.000f, juce::Colours::white,
                                juce::ImageCache::getFromMemory (down_png, down_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonMoveUp.reset (new juce::ImageButton ("move up button"));
    addAndMakeVisible (_buttonMoveUp.get());
    _buttonMoveUp->setTooltip (TRANS("Move selected sequence up in the list"));
    _buttonMoveUp->setButtonText (TRANS("move sequence down"));
    _buttonMoveUp->addListener (this);

    _buttonMoveUp->setImages (false, true, true,
                              juce::ImageCache::getFromMemory (up_png, up_pngSize), 1.000f, juce::Colour (0xffafafaf),
                              juce::ImageCache::getFromMemory (up_png, up_pngSize), 1.000f, juce::Colours::white,
                              juce::ImageCache::getFromMemory (up_png, up_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonPlay.reset (new juce::ImageButton ("play button"));
    addAndMakeVisible (_buttonPlay.get());
    _buttonPlay->setTooltip (TRANS("Play"));
    _buttonPlay->setButtonText (TRANS("Play"));
    _buttonPlay->addListener (this);

    _buttonPlay->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0xffafafaf),
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colours::white,
                            juce::ImageCache::getFromMemory (play_png, play_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonStop.reset (new juce::ImageButton ("stop button"));
    addAndMakeVisible (_buttonStop.get());
    _buttonStop->setTooltip (TRANS("Stop"));
    _buttonStop->setButtonText (TRANS("Stop"));
    _buttonStop->addListener (this);

    _buttonStop->setImages (false, true, true,
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0xffafafaf),
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colours::white,
                            juce::ImageCache::getFromMemory (stop_png, stop_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonRecord.reset (new juce::ImageButton ("record button"));
    addAndMakeVisible (_buttonRecord.get());
    _buttonRecord->setTooltip (TRANS("Record"));
    _buttonRecord->setButtonText (TRANS("Record"));
    _buttonRecord->addListener (this);

    _buttonRecord->setImages (false, true, true,
                              juce::ImageCache::getFromMemory (rec_png, rec_pngSize), 1.000f, juce::Colour (0xffafafaf),
                              juce::ImageCache::getFromMemory (rec_png, rec_pngSize), 1.000f, juce::Colour (0xffff8b8b),
                              juce::ImageCache::getFromMemory (rec_png, rec_pngSize), 1.000f, juce::Colours::red);
    _buttonSkipBack.reset (new juce::ImageButton ("skip back button"));
    addAndMakeVisible (_buttonSkipBack.get());
    _buttonSkipBack->setTooltip (TRANS("Skip back"));
    _buttonSkipBack->setButtonText (TRANS("Skip back"));
    _buttonSkipBack->addListener (this);

    _buttonSkipBack->setImages (false, true, true,
                                juce::ImageCache::getFromMemory (skip_b_png, skip_b_pngSize), 1.000f, juce::Colour (0xffafafaf),
                                juce::ImageCache::getFromMemory (skip_b_png, skip_b_pngSize), 1.000f, juce::Colours::white,
                                juce::ImageCache::getFromMemory (skip_b_png, skip_b_pngSize), 1.000f, juce::Colour (0xffa45c94));
    _buttonSkipForward.reset (new juce::ImageButton ("skip forward button"));
    addAndMakeVisible (_buttonSkipForward.get());
    _buttonSkipForward->setTooltip (TRANS("Skip forward"));
    _buttonSkipForward->setButtonText (TRANS("Skip forward"));
    _buttonSkipForward->addListener (this);

    _buttonSkipForward->setImages (false, true, true,
                                   juce::ImageCache::getFromMemory (skip_f_png, skip_f_pngSize), 1.000f, juce::Colour (0xffafafaf),
                                   juce::ImageCache::getFromMemory (skip_f_png, skip_f_pngSize), 1.000f, juce::Colours::white,
                                   juce::ImageCache::getFromMemory (skip_f_png, skip_f_pngSize), 1.000f, juce::Colour (0xffa45c94));

    //[UserPreSize]

	_buttonPlay->setClickingTogglesState(true);
	_buttonRecord->setClickingTogglesState(true);



    //[/UserPreSize]

    setSize (500, 900);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MidiSequenceManagerComponent::~MidiSequenceManagerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _labelSequence = nullptr;
    _tableComponent = nullptr;
    _buttonDelete = nullptr;
    _buttonExport = nullptr;
    _buttonImport = nullptr;
    _buttonAdd = nullptr;
    _buttonMoveDown = nullptr;
    _buttonMoveUp = nullptr;
    _buttonPlay = nullptr;
    _buttonStop = nullptr;
    _buttonRecord = nullptr;
    _buttonSkipBack = nullptr;
    _buttonSkipForward = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MidiSequenceManagerComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MidiSequenceManagerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    _tableComponent->setBounds (0, 40, proportionOfWidth (1.0000f), getHeight() - 104);
    _buttonDelete->setBounds (0 + proportionOfWidth (1.0000f) - 4 - 24, 40 + (getHeight() - 104) - -4, 24, 24);
    _buttonExport->setBounds (((0 + proportionOfWidth (1.0000f) - 4 - 24) + 24 - 60) + 60 - 64 - 60, ((40 + (getHeight() - 104) - -4) + 24 - -8) + 0, 60, 24);
    _buttonImport->setBounds ((0 + proportionOfWidth (1.0000f) - 4 - 24) + 24 - 60, (40 + (getHeight() - 104) - -4) + 24 - -8, 60, 24);
    _buttonAdd->setBounds ((0 + proportionOfWidth (1.0000f) - 4 - 24) + 24 - 28 - 24, (40 + (getHeight() - 104) - -4) + 0, 24, 24);
    _buttonMoveDown->setBounds (((0 + proportionOfWidth (1.0000f) - 4 - 24) + 24 - 28 - 24) + 24 - 28 - 24, ((40 + (getHeight() - 104) - -4) + 0) + 0, 24, 24);
    _buttonMoveUp->setBounds ((((0 + proportionOfWidth (1.0000f) - 4 - 24) + 24 - 28 - 24) + 24 - 28 - 24) + 24 - 28 - 24, (((40 + (getHeight() - 104) - -4) + 0) + 0) + 0, 24, 24);
    _buttonPlay->setBounds (0 + 4, 40 + (getHeight() - 104) - -4, 24, 24);
    _buttonStop->setBounds ((0 + 4) + 28, (40 + (getHeight() - 104) - -4) + 0, 24, 24);
    _buttonRecord->setBounds (((((0 + 4) + 28) + 28) + 28) + 28, ((((40 + (getHeight() - 104) - -4) + 0) + 0) + 0) + 0, 24, 24);
    _buttonSkipBack->setBounds (((0 + 4) + 28) + 28, ((40 + (getHeight() - 104) - -4) + 0) + 0, 24, 24);
    _buttonSkipForward->setBounds ((((0 + 4) + 28) + 28) + 28, (((40 + (getHeight() - 104) - -4) + 0) + 0) + 0, 24, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MidiSequenceManagerComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _buttonDelete.get())
    {
        //[UserButtonCode__buttonDelete] -- add your button handler code here..


		auto name = rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequenceName();

		String msg("Please confirm deletion of sequence '");
		msg.append(name, 100);
		msg.append("'", 2);

		if (AlertWindow::showOkCancelBox(AlertWindow::QuestionIcon, "Delete sequence", msg)) {

			if (rdd::MainManager::instance().getMidiSequenceManager().removeSelectedMidiSequence()) {
				_tableComponent->updateTable();
			}
		}




        //[/UserButtonCode__buttonDelete]
    }
    else if (buttonThatWasClicked == _buttonExport.get())
    {
        //[UserButtonCode__buttonExport] -- add your button handler code here..

		if (rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequenceIdx() != -1) {

			FileChooser fc("Choose a file for export...", File::getCurrentWorkingDirectory().getChildFile(rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequenceName()), "*.mid;*.midi", true);
			if (fc.browseForFileToSave(true)) {
				auto result = fc.getURLResult();

				if (!result.isEmpty() && result.isLocalFile()) {

					rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequence()->updateMatchedPairs();

					if (rdd::MainManager::instance().getMidiSequenceManager().saveMidiSequence(rdd::MainManager::instance().getMidiSequenceManager().getSelectedMidiSequenceIdx(), result.getLocalFile())) {
						AlertWindow::showMessageBox(AlertWindow::InfoIcon, "MIDI file export",
							"MIDI sequence successfully exported.",
							"OK");
					}
					else {
						AlertWindow::showMessageBox(AlertWindow::WarningIcon, "MIDI file export",
							"Failed to export MIDI sequence.",
							"OK");
					}
				}

			}
		}

        //[/UserButtonCode__buttonExport]
    }
    else if (buttonThatWasClicked == _buttonImport.get())
    {
        //[UserButtonCode__buttonImport] -- add your button handler code here..
		FileChooser fc("Choose a file for import...", File::getCurrentWorkingDirectory(), "*.mid;*.midi", true);
		if (fc.browseForFileToOpen()) {
			auto result = fc.getURLResult();


			if (!result.isEmpty() && result.isLocalFile()) {
				if (rdd::MainManager::instance().getMidiSequenceManager().loadMidiSequence(result.getLocalFile()) != -1) {
					AlertWindow::showMessageBox(AlertWindow::InfoIcon, "MIDI file import",
						"MIDI sequence successfully imported.",
						"OK");

					_tableComponent->updateTable();
				}
				else {
					AlertWindow::showMessageBox(AlertWindow::WarningIcon, "MIDI file import",
						"Failed to import MIDI sequence.",
						"OK");
				}
			}
		}

        //[/UserButtonCode__buttonImport]
    }
    else if (buttonThatWasClicked == _buttonAdd.get())
    {
        //[UserButtonCode__buttonAdd] -- add your button handler code here..


		int n = rdd::MainManager::instance().getMidiSequenceManager().getNumMidiSequences() + 1;
		String name("Sequence");
		name.append(String(n), 10);

#if JUCE_MODAL_LOOPS_PERMITTED
		AlertWindow w( "Add new sequence", "Enter sequence name", AlertWindow::NoIcon);

		w.addTextEditor("Sequence name", name);
		w.addButton("OK", 1, KeyPress(KeyPress::returnKey, 0, 0));
		w.addButton("Cancel", 0, KeyPress(KeyPress::escapeKey, 0, 0));

		if (w.runModalLoop() != 0) // OK clicked
		{
			name = w.getTextEditorContents("text");
			rdd::MainManager::instance().getMidiSequenceManager().addNewMidiSequence(name);
			_tableComponent->updateTable();
		}
#else
		rdd::MainManager::instance().midiSequenceManager().addNewMidiSequence(name);
		_tableComponent->updateTable();
#endif


        //[/UserButtonCode__buttonAdd]
    }
    else if (buttonThatWasClicked == _buttonMoveDown.get())
    {
        //[UserButtonCode__buttonMoveDown] -- add your button handler code here..
		if (rdd::MainManager::instance().getMidiSequenceManager().moveSelectedMidiSequence(false)) {
			_tableComponent->updateTable();
		}
        //[/UserButtonCode__buttonMoveDown]
    }
    else if (buttonThatWasClicked == _buttonMoveUp.get())
    {
        //[UserButtonCode__buttonMoveUp] -- add your button handler code here..
		if (rdd::MainManager::instance().getMidiSequenceManager().moveSelectedMidiSequence(true)) {
			_tableComponent->updateTable();
		}
        //[/UserButtonCode__buttonMoveUp]
    }
    else if (buttonThatWasClicked == _buttonPlay.get())
    {
        //[UserButtonCode__buttonPlay] -- add your button handler code here..
        //[/UserButtonCode__buttonPlay]
    }
    else if (buttonThatWasClicked == _buttonStop.get())
    {
        //[UserButtonCode__buttonStop] -- add your button handler code here..
        //[/UserButtonCode__buttonStop]
    }
    else if (buttonThatWasClicked == _buttonRecord.get())
    {
        //[UserButtonCode__buttonRecord] -- add your button handler code here..
		if (buttonThatWasClicked->getToggleState()) {
			rdd::MainManager::instance().getMidiSequenceManager().startRecording();
		}
		else {
			rdd::MainManager::instance().getMidiSequenceManager().stopRecording();
			_tableComponent->updateTable();
		}

		// set toggle state to the actual recording state... just in case if a recording command failed
		buttonThatWasClicked->setToggleState(rdd::MainManager::instance().getMidiSequenceManager().isRecording(), NotificationType::dontSendNotification);

        //[/UserButtonCode__buttonRecord]
    }
    else if (buttonThatWasClicked == _buttonSkipBack.get())
    {
        //[UserButtonCode__buttonSkipBack] -- add your button handler code here..
        //[/UserButtonCode__buttonSkipBack]
    }
    else if (buttonThatWasClicked == _buttonSkipForward.get())
    {
        //[UserButtonCode__buttonSkipForward] -- add your button handler code here..
        //[/UserButtonCode__buttonSkipForward]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MidiSequenceManagerComponent"
                 componentName="" parentClasses="public juce::Component" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="500" initialHeight="900">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="sequence label" id="73d617a819b42f9d" memberName="_labelSequence"
         virtualName="" explicitFocusOrder="0" pos="0 2 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sequences" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="table component" id="73bbbf9ac926ed51" memberName="_tableComponent"
                    virtualName="" explicitFocusOrder="0" pos="0 40 100% 104M" class="MidiSequenceTableComponent"
                    params=""/>
  <IMAGEBUTTON name="delete button" id="4e09b5c4a2436584" memberName="_buttonDelete"
               virtualName="" explicitFocusOrder="0" pos="4Rr -4R 24 24" posRelativeX="73bbbf9ac926ed51"
               posRelativeY="73bbbf9ac926ed51" tooltip="delete selected sequence"
               buttonText="delete sequence" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="minus_png"
               opacityNormal="1.0" colourNormal="ffafafaf" resourceOver="minus_png"
               opacityOver="1.0" colourOver="ffffffff" resourceDown="minus_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <TEXTBUTTON name="export button" id="43808a6856bc7d97" memberName="_buttonExport"
              virtualName="" explicitFocusOrder="0" pos="64Rr 0 60 24" posRelativeX="71f7301213eb10d4"
              posRelativeY="71f7301213eb10d4" tooltip="Export selected sequence"
              buttonText="Export" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="import button" id="71f7301213eb10d4" memberName="_buttonImport"
              virtualName="" explicitFocusOrder="0" pos="0Rr -8R 60 24" posRelativeX="4e09b5c4a2436584"
              posRelativeY="4e09b5c4a2436584" tooltip="Import selected sequence"
              bgColOff="ffa45c94" buttonText="Import" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <IMAGEBUTTON name="add button" id="3c240286f727c533" memberName="_buttonAdd"
               virtualName="" explicitFocusOrder="0" pos="28Rr 0 24 24" posRelativeX="4e09b5c4a2436584"
               posRelativeY="4e09b5c4a2436584" tooltip="add new sequence" buttonText="add sequence"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="plus_png" opacityNormal="1.0" colourNormal="ffafafaf"
               resourceOver="plus_png" opacityOver="1.0" colourOver="ffffffff"
               resourceDown="plus_png" opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="move down button" id="8e07a669d63b6cb2" memberName="_buttonMoveDown"
               virtualName="" explicitFocusOrder="0" pos="28Rr 0 24 24" posRelativeX="3c240286f727c533"
               posRelativeY="3c240286f727c533" tooltip="Move selected sequence down in the list"
               buttonText="move sequence down" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="down_png"
               opacityNormal="1.0" colourNormal="ffafafaf" resourceOver="down_png"
               opacityOver="1.0" colourOver="ffffffff" resourceDown="down_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="move up button" id="2dc8f1d0a4f92eb3" memberName="_buttonMoveUp"
               virtualName="" explicitFocusOrder="0" pos="28Rr 0 24 24" posRelativeX="8e07a669d63b6cb2"
               posRelativeY="8e07a669d63b6cb2" tooltip="Move selected sequence up in the list"
               buttonText="move sequence down" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="up_png"
               opacityNormal="1.0" colourNormal="ffafafaf" resourceOver="up_png"
               opacityOver="1.0" colourOver="ffffffff" resourceDown="up_png"
               opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="play button" id="1ee09d11b2a18e8f" memberName="_buttonPlay"
               virtualName="" explicitFocusOrder="0" pos="4 -4R 24 24" posRelativeX="73bbbf9ac926ed51"
               posRelativeY="73bbbf9ac926ed51" tooltip="Play" buttonText="Play"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="play_png" opacityNormal="1.0" colourNormal="ffafafaf"
               resourceOver="play_png" opacityOver="1.0" colourOver="ffffffff"
               resourceDown="play_png" opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="stop button" id="52d115beaa7d3ac9" memberName="_buttonStop"
               virtualName="" explicitFocusOrder="0" pos="28 0 24 24" posRelativeX="1ee09d11b2a18e8f"
               posRelativeY="1ee09d11b2a18e8f" tooltip="Stop" buttonText="Stop"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="stop_png" opacityNormal="1.0" colourNormal="ffafafaf"
               resourceOver="stop_png" opacityOver="1.0" colourOver="ffffffff"
               resourceDown="stop_png" opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="record button" id="8ae0819dddbe72e7" memberName="_buttonRecord"
               virtualName="" explicitFocusOrder="0" pos="28 0 24 24" posRelativeX="fb69378d08b1cd59"
               posRelativeY="fb69378d08b1cd59" tooltip="Record" buttonText="Record"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="rec_png" opacityNormal="1.0" colourNormal="ffafafaf"
               resourceOver="rec_png" opacityOver="1.0" colourOver="ffff8b8b"
               resourceDown="rec_png" opacityDown="1.0" colourDown="ffff0000"/>
  <IMAGEBUTTON name="skip back button" id="19b466ef418e20ec" memberName="_buttonSkipBack"
               virtualName="" explicitFocusOrder="0" pos="28 0 24 24" posRelativeX="52d115beaa7d3ac9"
               posRelativeY="52d115beaa7d3ac9" tooltip="Skip back" buttonText="Skip back"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="skip_b_png" opacityNormal="1.0" colourNormal="ffafafaf"
               resourceOver="skip_b_png" opacityOver="1.0" colourOver="ffffffff"
               resourceDown="skip_b_png" opacityDown="1.0" colourDown="ffa45c94"/>
  <IMAGEBUTTON name="skip forward button" id="fb69378d08b1cd59" memberName="_buttonSkipForward"
               virtualName="" explicitFocusOrder="0" pos="28 0 24 24" posRelativeX="19b466ef418e20ec"
               posRelativeY="19b466ef418e20ec" tooltip="Skip forward" buttonText="Skip forward"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="skip_f_png" opacityNormal="1.0" colourNormal="ffafafaf"
               resourceOver="skip_f_png" opacityOver="1.0" colourOver="ffffffff"
               resourceDown="skip_f_png" opacityDown="1.0" colourDown="ffa45c94"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: minus_png, 491, "../Assets/ButtonGraphics/png/minus.png"
static const unsigned char resource_MidiSequenceManagerComponent_minus_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,1,104,73,68,65,84,120,156,237,221,61,74,197,64,20,64,225,59,67,210,10,143,188,34,174,193,229,88,187,53,43,123,23,98,237,10,44,28,36,1,177,13,100,44,252,193,74,139,57,48,68,206,87,165,8,151,203,129,
105,66,96,210,178,44,53,212,36,247,94,224,63,24,190,30,82,74,87,219,182,45,61,151,57,146,113,28,207,181,214,199,136,31,17,183,109,91,230,121,126,233,183,214,177,148,82,98,24,62,242,121,156,1,70,4,24,17,
96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,192,240,247,43,191,91,215,245,34,34,174,
129,93,186,200,57,223,159,78,167,215,150,25,205,17,247,125,191,76,41,221,182,206,233,165,214,250,16,17,77,17,61,206,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,
2,154,63,133,229,156,159,107,173,55,196,50,157,60,181,14,104,142,56,77,211,91,68,220,181,206,57,50,143,51,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,
2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,248,254,161,105,28,199,115,41,165,231,46,135,242,121,247,64,68,68,36,175,18,105,231,113,6,188,3,71,179,50,104,104,
190,167,228,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::minus_png = (const char*) resource_MidiSequenceManagerComponent_minus_png;
const int MidiSequenceManagerComponent::minus_pngSize = 491;

// JUCER_RESOURCE: plus_png, 625, "../Assets/ButtonGraphics/png/plus.png"
static const unsigned char resource_MidiSequenceManagerComponent_plus_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,1,238,73,68,65,84,120,156,237,221,49,106,27,65,20,135,241,55,195,142,170,96,16,90,9,229,12,185,128,193,228,20,73,233,180,169,114,29,183,14,129,148,1,95,32,133,123,215,62,129,139,44,98,22,66,98,210,
204,178,47,133,19,147,46,120,230,11,139,194,255,87,169,208,91,61,62,152,102,89,177,33,231,236,38,77,226,210,11,252,15,186,223,31,66,8,47,74,41,121,201,101,142,73,74,169,119,247,91,179,63,34,150,82,242,
126,191,63,44,183,214,113,25,134,193,186,238,33,159,142,51,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,64,247,247,175,252,91,135,195,225,217,106,181,218,214,206,151,82,
242,118,187,253,78,238,244,84,139,71,140,49,190,158,166,233,125,237,124,8,225,157,153,93,128,43,61,153,142,51,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,
208,124,43,108,28,199,19,51,123,213,112,137,51,247,166,71,36,79,199,113,252,81,59,28,99,188,90,175,215,95,91,22,104,142,56,207,243,243,16,194,101,235,117,26,156,187,251,121,237,176,187,223,152,89,83,68,
29,103,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,160,249,86,88,140,241,139,187,191,169,157,15,33,188,116,247,183,13,43,124,48,179,207,13,243,119,13,179,
102,6,68,220,108,54,223,204,236,99,237,124,206,185,51,179,150,136,55,125,223,87,255,62,65,199,25,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,88,252,175,186,
243,60,127,74,41,93,215,206,79,211,52,130,235,84,89,60,226,110,183,187,55,179,251,165,247,104,161,227,12,80,68,128,34,2,20,17,160,136,0,69,4,40,34,64,17,1,138,8,80,68,128,34,2,20,17,240,120,3,34,165,212,
15,195,176,228,46,71,229,215,187,7,204,204,44,232,85,34,237,116,156,1,63,1,143,238,94,156,25,149,32,227,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::plus_png = (const char*) resource_MidiSequenceManagerComponent_plus_png;
const int MidiSequenceManagerComponent::plus_pngSize = 625;

// JUCER_RESOURCE: down_png, 1103, "../Assets/ButtonGraphics/png/down.png"
static const unsigned char resource_MidiSequenceManagerComponent_down_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,3,204,73,68,65,84,120,156,237,221,63,111,28,69,24,128,241,103,44,159,201,90,218,194,220,172,228,175,16,209,66,21,68,151,179,80,32,136,228,3,240,21,130,18,16,32,209,33,1,130,32,193,7,160,5,5,200,159,
46,162,15,149,41,169,28,201,133,155,83,60,107,185,63,203,47,133,119,144,137,204,221,238,206,59,187,99,52,79,101,217,123,239,141,126,186,211,173,111,199,62,227,156,19,114,65,173,141,189,128,255,67,235,
254,11,99,204,107,139,197,194,141,185,152,203,212,100,50,177,34,242,23,156,67,92,44,22,110,123,123,251,197,120,203,186,92,205,231,115,214,215,207,248,242,211,89,161,140,168,80,70,84,40,35,42,148,17,21,
202,136,10,101,68,133,50,162,66,25,81,161,140,168,80,70,84,40,35,42,148,17,21,202,136,10,169,32,30,30,30,222,112,206,61,217,223,223,191,162,49,47,118,34,178,225,156,123,232,156,251,64,99,94,48,162,115,
238,150,49,230,17,112,179,44,203,199,169,67,138,200,70,93,215,15,128,247,129,31,53,32,131,16,157,115,183,128,159,129,73,243,173,157,178,44,147,125,68,54,128,191,0,239,53,223,90,67,1,178,55,226,5,128,190,
89,138,144,231,0,111,190,244,163,96,200,94,136,75,0,125,73,65,46,1,244,5,65,118,70,108,1,232,155,149,101,249,228,224,224,160,232,179,48,173,90,0,250,122,67,118,66,236,0,232,155,21,69,241,120,44,200,14,
128,190,94,144,173,17,123,0,250,70,129,236,1,232,235,12,217,10,49,0,208,55,40,100,0,160,175,19,228,74,196,186,174,111,19,6,232,27,4,82,1,208,215,26,114,41,98,93,215,183,69,228,39,194,1,125,81,33,21,1,
125,173,32,151,34,158,158,158,94,67,15,208,55,43,138,226,145,246,233,207,222,222,222,43,71,71,71,15,209,3,244,173,1,87,87,29,240,159,89,107,239,2,63,104,174,168,105,71,243,244,71,68,54,182,182,182,30,
136,200,13,141,121,47,205,254,206,90,251,201,178,99,150,34,26,99,100,58,157,222,1,190,87,93,217,89,179,162,40,130,33,155,167,240,175,232,63,2,49,198,220,175,170,234,238,170,227,86,190,176,52,144,31,18,
7,242,122,8,228,57,192,119,149,215,133,49,230,254,116,58,189,215,230,216,86,167,56,41,66,166,2,8,29,78,182,83,130,76,9,16,58,254,218,151,2,100,106,128,208,227,13,8,99,140,88,107,239,0,95,119,189,109,139,
150,66,166,8,8,1,239,39,54,47,251,131,65,166,10,8,129,239,108,15,5,153,50,32,40,92,99,105,32,191,10,157,115,65,215,55,55,55,159,30,31,31,111,213,117,253,27,113,0,191,13,5,4,165,171,125,214,218,79,137,
0,41,34,111,157,156,156,60,7,222,209,158,221,0,126,164,49,75,237,186,115,44,72,224,85,237,129,154,128,160,124,241,62,34,164,90,218,128,16,97,7,68,202,144,49,0,33,210,54,146,20,33,99,1,66,196,189,56,41,
65,198,4,132,200,27,154,82,128,140,13,8,3,236,10,107,32,191,140,125,63,23,101,140,249,38,54,32,12,180,181,206,90,251,25,3,67,54,128,31,15,113,95,131,237,79,28,18,114,72,64,24,120,147,231,16,144,67,3,194,
8,59,101,27,200,223,99,204,22,145,167,67,3,194,72,219,141,173,181,59,192,31,154,51,69,228,207,170,170,222,214,156,217,182,209,246,108,91,107,175,161,4,217,0,190,174,49,171,79,163,110,124,87,130,220,29,
19,16,18,248,235,129,64,200,93,107,237,27,154,235,233,211,232,136,112,6,41,34,207,186,220,70,68,146,0,132,68,16,1,170,170,122,179,45,164,136,236,86,85,149,4,32,36,132,8,237,32,83,3,132,196,16,97,57,100,
138,128,144,32,34,92,12,153,42,32,36,138,8,255,134,76,25,16,18,70,132,51,72,224,243,148,1,33,113,68,0,107,237,23,99,175,97,85,201,35,94,134,50,162,66,25,81,161,140,168,80,70,84,40,35,42,148,17,21,202,
136,10,101,68,133,50,162,66,25,81,161,140,168,80,70,84,40,35,42,244,207,191,205,159,76,38,118,62,159,143,185,150,75,85,243,217,3,0,152,252,81,34,225,229,167,179,66,127,3,46,154,236,10,172,216,103,65,0,
0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::down_png = (const char*) resource_MidiSequenceManagerComponent_down_png;
const int MidiSequenceManagerComponent::down_pngSize = 1103;

// JUCER_RESOURCE: up_png, 1071, "../Assets/ButtonGraphics/png/up.png"
static const unsigned char resource_MidiSequenceManagerComponent_up_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,3,172,73,68,65,84,120,156,237,221,203,110,211,64,20,128,225,51,227,102,199,166,158,154,118,69,97,135,84,158,161,108,184,20,137,75,17,151,37,226,81,64,226,1,120,3,214,236,184,74,220,82,88,64,42,216,243,
14,81,236,218,64,23,180,77,226,195,130,156,42,170,136,227,203,25,207,41,154,127,85,169,206,153,209,167,186,78,28,181,81,73,146,32,248,26,165,93,111,224,127,104,129,190,80,74,173,13,135,195,196,229,102,
142,83,157,78,103,9,17,191,3,76,33,14,135,195,100,101,101,101,224,110,91,199,171,126,191,15,11,11,127,249,252,233,204,144,71,100,200,35,50,228,17,25,242,136,12,121,68,134,60,34,67,30,145,33,143,200,144,
71,100,200,35,50,228,17,25,242,136,12,121,68,134,68,35,14,6,131,245,36,73,118,211,52,189,234,122,47,69,137,69,28,12,6,235,65,16,116,1,224,68,158,231,207,37,67,138,68,140,227,248,124,16,4,93,68,164,155,
198,90,50,164,56,196,56,142,207,107,173,63,76,1,82,98,33,69,33,22,0,82,34,33,197,32,150,0,164,196,65,138,64,172,0,72,137,130,116,142,88,3,144,18,3,233,20,177,1,32,37,2,210,25,34,3,32,69,144,215,88,54,
86,103,3,46,22,101,4,164,116,158,231,207,226,56,190,206,52,175,218,226,109,47,152,101,217,105,165,212,83,70,64,74,107,173,159,36,73,114,150,121,238,252,133,219,92,44,77,211,83,163,209,104,11,0,150,109,
204,71,196,16,0,62,237,236,236,172,217,152,63,171,214,16,211,52,61,53,30,143,63,41,165,206,88,94,106,25,17,187,109,66,182,130,216,34,32,213,42,164,117,68,7,128,212,50,34,110,181,1,105,21,209,33,32,117,
178,13,72,107,136,2,0,41,235,144,86,16,5,1,82,86,33,217,17,5,2,82,214,32,89,17,5,3,82,86,32,217,16,179,44,91,21,14,72,177,67,178,32,102,89,182,58,26,141,62,90,0,60,80,74,61,0,128,61,230,185,39,17,113,
43,77,211,115,28,195,26,35,218,4,68,196,59,198,152,135,74,169,77,176,0,153,231,121,151,3,178,17,162,109,192,40,138,94,0,0,24,99,222,74,134,172,141,104,25,240,54,1,82,146,33,107,33,182,0,248,242,95,223,
148,10,89,25,209,21,32,37,17,178,18,162,107,64,74,26,100,105,68,41,128,148,36,200,82,136,210,0,169,9,228,13,112,12,57,23,81,42,32,101,140,121,231,26,178,16,209,226,75,57,22,64,202,53,100,33,226,120,60,
126,12,0,167,57,119,5,0,123,74,169,27,92,128,212,4,242,38,216,129,124,84,116,64,33,162,214,250,62,0,124,99,220,208,1,34,222,53,198,188,97,156,121,152,49,230,141,133,159,200,109,165,212,189,162,3,10,17,
195,48,252,169,181,190,4,60,144,172,167,240,172,152,79,237,109,165,212,134,49,230,87,209,65,115,47,44,76,144,7,136,120,203,54,32,197,4,217,43,3,8,80,242,41,78,67,72,2,124,85,227,177,181,107,8,217,83,74,
93,41,3,8,80,225,201,246,20,228,215,10,155,217,119,1,72,77,65,254,174,240,176,74,128,0,21,95,246,77,32,47,67,57,200,253,201,239,64,39,128,212,4,114,19,202,65,86,6,4,168,113,3,162,36,164,8,64,170,36,100,
45,64,128,154,183,194,230,64,138,2,164,230,64,214,6,4,104,112,83,118,6,164,72,64,106,6,100,15,17,75,93,133,103,213,232,237,129,35,144,78,47,34,101,59,114,177,233,33,226,70,20,69,187,77,102,54,126,163,
42,12,195,159,65,16,108,104,173,47,68,81,244,186,233,188,54,50,198,188,215,90,95,228,0,4,152,250,95,97,77,90,92,92,252,1,0,159,57,102,181,85,24,134,95,184,102,57,255,19,140,255,33,143,200,144,71,100,200,
35,50,228,17,25,242,136,12,121,68,134,60,34,67,30,145,33,143,200,144,71,100,200,35,50,228,17,25,242,136,12,29,222,10,235,116,58,75,253,126,223,229,94,142,85,147,207,30,0,0,0,229,63,74,164,121,254,116,
102,232,15,236,125,176,179,12,37,238,3,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::up_png = (const char*) resource_MidiSequenceManagerComponent_up_png;
const int MidiSequenceManagerComponent::up_pngSize = 1071;

// JUCER_RESOURCE: play_png, 649, "../Assets/ButtonGraphics/png/play.png"
static const unsigned char resource_MidiSequenceManagerComponent_play_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,2,6,73,68,65,84,120,156,237,221,49,78,228,64,16,133,225,174,149,125,129,145,131,201,17,17,210,222,102,67,226,189,10,167,32,36,224,52,36,196,147,90,168,103,14,128,119,85,4,240,16,17,4,126,118,87,85,
215,31,77,50,163,210,55,106,187,109,7,150,90,171,150,108,85,191,90,15,16,161,1,31,68,228,102,89,150,218,114,24,79,141,227,56,169,234,115,41,95,16,151,101,169,199,227,241,165,221,88,190,154,231,185,12,
195,59,95,46,103,66,137,72,40,17,9,37,34,161,68,36,148,136,132,18,145,80,34,18,74,68,66,137,72,40,17,9,37,34,161,213,136,170,58,168,170,48,134,241,218,106,196,90,235,85,173,245,233,124,62,255,233,21,147,
178,156,69,228,183,170,62,246,138,73,61,38,246,138,185,201,137,165,55,204,77,207,206,189,96,238,178,197,137,142,185,235,62,49,42,102,147,205,118,52,204,166,87,44,81,48,77,92,246,121,199,52,129,136,188,
98,154,66,68,222,48,77,34,34,47,152,166,17,145,117,76,23,136,200,42,166,43,68,100,13,211,37,34,178,130,233,26,17,181,198,12,129,136,90,97,134,66,68,123,99,134,68,68,123,97,134,70,68,91,99,118,129,136,
182,194,236,10,17,1,243,114,185,60,168,234,240,243,55,190,175,75,68,85,61,169,234,223,195,225,112,43,34,255,214,254,222,234,127,193,83,170,122,42,165,220,77,211,116,207,192,67,93,32,110,133,135,66,35,
110,141,135,66,34,238,133,135,66,33,238,141,135,66,32,182,194,67,174,17,91,227,33,151,136,86,240,144,43,68,107,120,200,5,162,85,60,100,26,209,58,30,50,137,232,5,15,153,66,244,134,135,76,32,122,197,67,
77,17,189,227,161,38,136,81,240,208,174,136,209,240,208,46,136,81,241,208,166,136,209,241,208,38,136,189,224,33,42,98,111,120,136,130,216,43,30,90,141,56,77,211,169,148,114,45,34,255,9,243,184,108,53,
162,136,188,50,6,241,92,151,15,239,217,37,34,161,68,36,148,136,132,18,145,80,34,18,74,68,66,137,72,40,17,9,37,34,161,68,36,148,136,132,62,111,64,140,227,56,205,243,220,114,22,87,125,188,123,160,148,82,
138,228,171,68,214,151,203,153,208,27,52,114,249,232,172,17,69,155,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::play_png = (const char*) resource_MidiSequenceManagerComponent_play_png;
const int MidiSequenceManagerComponent::play_pngSize = 649;

// JUCER_RESOURCE: stop_png, 492, "../Assets/ButtonGraphics/png/stop.png"
static const unsigned char resource_MidiSequenceManagerComponent_stop_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,1,105,73,68,65,84,120,156,237,221,189,74,196,64,20,64,225,123,37,83,239,22,41,182,176,209,86,124,255,23,81,176,17,44,20,130,12,236,110,61,66,44,252,193,74,139,57,48,68,206,87,165,8,151,203,129,105,
2,97,178,214,186,134,186,92,140,94,224,63,152,190,30,50,243,166,181,86,71,46,179,37,165,148,121,93,215,251,136,31,17,91,107,245,112,56,188,142,91,107,91,150,101,137,105,250,200,231,113,6,24,17,96,68,128,
17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,211,223,175,252,110,93,215,114,62,159,47,137,101,70,216,237,118,207,153,217,122,102,116,71,172,181,94,103,230,67,239,156,81,142,199,227,109,68,
220,245,204,240,56,3,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,
0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,232,254,85,119,158,231,199,211,233,116,69,44,51,194,126,191,127,233,157,209,29,
49,51,223,34,226,169,119,206,150,121,156,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,192,247,7,136,82,202,188,44,203,200,93,54,229,243,238,129,136,136,72,175,18,233,231,113,
6,188,3,229,194,52,144,182,227,223,99,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::stop_png = (const char*) resource_MidiSequenceManagerComponent_stop_png;
const int MidiSequenceManagerComponent::stop_pngSize = 492;

// JUCER_RESOURCE: rec_png, 1471, "../Assets/ButtonGraphics/png/rec.png"
static const unsigned char resource_MidiSequenceManagerComponent_rec_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,5,60,73,68,65,84,120,156,237,157,63,108,27,85,28,199,191,191,179,29,26,5,199,193,207,118,29,33,1,25,210,34,40,41,12,221,90,154,80,169,165,108,208,5,150,176,85,4,33,24,80,17,91,25,144,248,35,22,24,
66,37,6,68,6,254,84,128,96,66,16,32,137,144,96,139,82,42,80,75,36,172,74,136,56,246,123,118,156,18,5,108,231,126,12,189,162,74,132,36,248,126,239,206,169,222,71,178,148,193,249,188,231,143,238,236,243,
187,187,132,180,214,12,71,40,188,184,39,112,51,144,188,254,3,17,221,219,106,181,116,156,147,217,77,164,82,169,28,51,255,4,220,16,177,213,106,233,98,177,88,137,111,90,187,139,114,185,140,100,242,90,62,
183,59,11,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,224,34,10,144,220,254,41,241,80,42,149,246,40,165,250,214,215,215,51,189,189,189,13,99,204,
218,208,208,208,159,113,207,107,51,186,34,226,210,210,82,190,167,167,103,140,153,71,1,28,4,176,31,128,106,54,155,72,36,18,104,54,155,72,167,211,208,90,27,0,151,1,92,32,162,217,102,179,57,51,56,56,88,141,
115,238,0,64,215,87,182,219,237,246,222,40,151,194,152,57,165,181,62,5,96,156,136,142,3,72,116,160,217,96,230,105,0,83,185,92,238,99,34,106,201,206,242,191,41,151,203,133,100,50,185,12,196,240,158,200,
204,73,173,245,132,49,230,23,34,250,128,136,78,162,179,128,0,144,32,162,135,137,232,125,99,204,162,214,122,130,153,83,146,243,221,9,145,70,172,213,106,135,141,49,243,0,38,1,220,37,172,191,19,192,164,49,
102,190,82,169,28,17,118,111,73,36,17,153,57,81,173,86,95,242,125,127,14,192,125,150,135,59,224,121,222,156,214,250,205,168,182,74,235,17,107,181,90,198,24,51,77,68,103,163,24,47,128,0,60,107,140,249,
170,94,175,15,216,30,204,234,139,90,94,94,222,203,204,179,0,198,108,142,179,5,163,237,118,123,174,82,169,20,109,14,98,45,162,49,166,63,145,72,124,193,204,247,219,26,99,39,16,209,136,231,121,211,43,43,
43,183,217,26,195,74,68,102,78,50,243,231,0,30,176,225,239,128,3,27,27,27,159,217,122,143,180,18,209,24,243,50,128,81,27,238,78,97,230,7,131,121,137,35,30,177,90,173,30,5,112,70,218,43,196,25,173,245,
67,210,82,209,136,204,220,67,68,147,210,94,65,8,192,219,139,139,139,183,72,74,69,95,172,49,230,41,0,247,72,58,45,176,47,155,205,78,72,10,197,34,6,111,218,207,75,249,108,194,204,47,148,74,165,61,82,62,
177,136,198,152,39,0,220,33,229,179,204,96,58,157,126,92,74,38,185,59,63,41,232,138,130,113,41,145,72,196,106,181,58,136,46,59,164,217,1,71,181,214,183,75,136,68,34,18,209,49,41,87,132,120,0,142,73,137,
66,19,172,72,239,70,68,190,211,75,109,137,7,37,60,49,48,34,33,145,218,5,247,9,121,162,102,63,51,83,88,73,232,136,198,152,126,0,253,97,61,49,209,215,104,52,66,175,55,134,142,200,204,233,176,142,56,241,
125,63,244,252,67,71,244,125,191,55,172,35,78,124,223,239,11,235,8,29,209,243,188,245,176,142,56,241,60,111,45,180,35,172,128,136,174,134,117,196,137,231,121,161,231,31,58,162,82,106,21,192,106,88,79,
76,172,101,50,153,149,176,18,169,67,156,203,66,158,168,185,68,68,161,239,109,148,250,198,114,65,194,19,3,63,74,72,164,182,196,89,33,79,212,204,72,72,164,182,196,111,0,248,18,174,8,241,131,121,135,70,36,
98,161,80,40,3,248,86,194,21,33,179,249,124,254,119,9,145,228,242,213,123,130,174,40,152,146,18,137,69,84,74,125,4,224,138,148,207,50,191,213,235,245,15,165,100,98,17,131,11,44,223,144,242,89,230,245,
225,225,225,191,164,100,162,171,209,74,169,115,204,44,114,216,96,145,159,149,82,231,36,133,162,17,137,168,205,204,207,160,123,63,169,125,102,126,90,250,178,100,241,243,34,133,66,225,59,0,175,72,123,133,
120,53,159,207,207,73,75,173,156,92,82,74,157,5,32,114,12,38,200,76,48,47,113,172,68,36,162,13,102,126,20,192,188,13,127,7,92,76,38,147,167,136,168,109,67,110,237,52,103,62,159,191,218,110,183,79,34,230,
144,68,180,224,251,254,241,129,129,129,186,173,49,172,158,43,46,22,139,21,34,26,3,48,109,115,156,45,248,154,136,70,131,111,84,214,176,126,194,93,41,181,170,148,58,1,224,69,0,27,182,199,11,96,0,111,41,
165,30,201,102,179,13,219,131,69,114,213,2,17,113,46,151,123,141,136,142,16,209,130,229,177,22,136,232,112,46,151,123,46,170,59,172,34,189,244,67,41,245,67,54,155,61,196,204,167,137,232,87,73,55,51,151,
152,249,116,54,155,61,164,148,250,94,210,189,29,145,223,32,25,124,66,190,195,204,239,214,106,181,199,0,140,51,243,137,14,231,210,38,162,47,1,76,41,165,62,181,245,233,187,29,177,221,101,26,188,224,243,
0,206,175,174,174,170,86,171,53,202,204,163,68,52,194,204,119,3,40,108,242,107,21,34,186,196,204,23,137,104,38,149,74,205,246,247,247,155,104,103,254,111,186,226,86,221,32,196,39,193,3,192,181,43,111,
27,141,198,173,0,6,0,172,100,50,153,63,162,188,139,244,255,208,21,17,55,35,8,86,15,30,93,205,110,187,166,176,43,113,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,5,112,17,
5,112,17,5,248,103,1,34,149,74,229,202,101,171,167,34,110,42,130,255,61,0,224,134,63,184,230,232,28,183,59,11,240,55,204,84,180,253,167,66,187,104,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::rec_png = (const char*) resource_MidiSequenceManagerComponent_rec_png;
const int MidiSequenceManagerComponent::rec_pngSize = 1471;

// JUCER_RESOURCE: skip_b_png, 739, "../Assets/ButtonGraphics/png/skip_b.png"
static const unsigned char resource_MidiSequenceManagerComponent_skip_b_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,2,96,73,68,65,84,120,156,237,221,49,171,19,65,16,192,241,153,120,23,176,48,41,238,21,105,131,68,132,87,217,248,9,222,103,240,27,249,105,30,126,14,121,157,141,240,138,20,175,203,33,3,73,163,120,156,
222,90,152,17,43,45,118,118,119,102,119,254,16,200,65,24,150,31,119,77,50,16,36,162,0,94,84,171,210,7,168,161,142,223,32,226,237,60,207,84,242,48,150,234,251,254,38,132,240,25,224,47,196,121,158,105,183,
219,125,41,119,44,91,141,227,8,93,247,155,207,31,103,129,28,81,32,71,20,200,17,5,114,68,129,28,81,32,71,20,200,17,5,114,68,129,28,81,32,71,20,200,17,5,234,254,255,145,127,23,66,192,211,233,244,156,175,
167,105,90,246,251,253,247,216,185,185,10,33,116,136,248,35,102,70,244,157,72,68,175,214,235,245,87,126,109,54,155,143,177,51,115,68,68,119,68,244,112,62,159,95,199,206,138,190,19,173,69,68,119,0,240,
30,0,222,74,205,108,6,49,5,30,87,61,98,74,60,174,90,196,28,120,92,117,136,57,241,184,106,16,75,224,113,230,17,75,226,113,102,17,53,224,113,230,16,53,225,113,102,16,53,226,113,234,17,53,227,113,106,17,
45,224,113,234,16,45,225,113,106,16,45,226,113,197,17,45,227,113,197,16,107,192,227,178,35,214,132,199,101,67,172,17,143,75,142,88,51,30,151,12,177,5,60,78,28,49,132,240,130,136,30,160,1,60,46,197,157,
248,242,250,106,166,232,159,76,87,171,213,51,137,131,88,46,26,113,89,150,159,18,7,177,156,248,26,9,34,62,1,192,163,244,92,205,165,216,197,185,12,195,112,139,136,239,160,17,204,36,11,77,136,184,12,195,
112,223,10,102,210,173,176,86,48,179,172,214,213,142,153,117,63,177,86,204,34,75,158,181,97,22,221,148,173,5,83,197,186,177,117,76,21,136,156,85,76,85,136,156,53,76,149,136,156,21,76,213,136,156,118,76,
19,136,156,86,76,83,136,156,54,76,147,136,156,22,76,211,136,92,105,204,42,16,185,82,152,85,33,114,185,49,171,68,228,114,97,86,141,200,165,198,108,2,145,75,133,25,253,227,253,229,114,121,218,110,183,111,
248,26,17,191,197,206,76,29,34,46,0,112,31,66,248,112,60,30,251,216,121,209,136,135,195,97,2,128,79,177,115,74,116,197,156,98,231,52,245,56,167,202,17,5,114,68,129,28,81,32,71,20,200,17,5,114,68,129,28,
81,32,71,20,200,17,5,114,68,129,28,81,160,63,95,64,244,125,127,51,142,99,201,179,152,234,250,223,3,0,0,128,254,87,34,241,249,227,44,208,47,98,34,238,230,230,89,107,185,0,0,0,0,73,69,78,68,174,66,96,130,
0,0};

const char* MidiSequenceManagerComponent::skip_b_png = (const char*) resource_MidiSequenceManagerComponent_skip_b_png;
const int MidiSequenceManagerComponent::skip_b_pngSize = 739;

// JUCER_RESOURCE: skip_f_png, 742, "../Assets/ButtonGraphics/png/skip_f.png"
static const unsigned char resource_MidiSequenceManagerComponent_skip_f_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,2,99,73,68,65,84,120,156,237,221,193,138,19,65,16,198,241,250,116,58,30,132,132,64,31,130,87,81,15,194,62,199,190,128,207,224,171,248,20,62,128,55,223,68,4,175,134,133,61,12,166,67,206,217,201,82,
30,220,146,61,136,10,93,51,221,213,93,127,8,100,32,20,195,143,153,204,76,134,48,72,41,49,121,89,61,41,189,2,45,52,200,27,0,111,167,105,74,37,87,198,82,33,132,200,204,223,136,30,33,78,211,148,118,187,221,
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

const char* MidiSequenceManagerComponent::skip_f_png = (const char*) resource_MidiSequenceManagerComponent_skip_f_png;
const int MidiSequenceManagerComponent::skip_f_pngSize = 742;

// JUCER_RESOURCE: pause_png, 560, "../Assets/ButtonGraphics/png/pause.png"
static const unsigned char resource_MidiSequenceManagerComponent_pause_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,81,0,0,0,81,8,6,0,0,0,170,143,74,54,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,30,194,0,0,30,194,1,110,208,117,62,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,
0,0,1,173,73,68,65,84,120,156,237,221,189,74,195,80,24,128,225,239,180,205,218,210,214,161,131,139,131,147,120,79,206,222,129,171,120,35,222,147,78,46,14,14,65,67,127,162,83,3,137,131,63,56,41,156,188,
16,42,239,51,117,232,151,115,120,225,44,7,66,82,85,85,93,168,151,209,208,27,248,15,38,95,63,82,74,103,77,211,84,67,110,230,144,20,69,113,212,117,221,125,196,143,136,77,211,84,171,213,234,121,184,109,29,
150,178,44,99,50,249,200,231,113,6,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,147,191,255,242,187,174,235,138,221,110,119,156,59,63,26,141,94,167,211,105,246,237,81,93,215,
203,182,109,167,185,243,179,217,236,41,165,212,228,206,71,0,17,215,235,245,233,215,149,80,166,219,136,184,200,29,222,239,247,215,17,113,153,59,191,217,108,206,35,226,46,119,62,194,227,140,48,34,192,136,
0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,
8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,192,136,0,35,2,140,8,48,34,160,247,171,186,139,197,226,97,187,221,158,228,206,143,199,227,183,62,235,167,148,174,218,182,189,201,157,159,207,
231,47,125,214,143,0,34,126,190,112,253,216,247,57,185,150,203,101,29,17,245,80,235,71,120,156,17,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,128,17,1,70,4,24,17,96,68,192,247,5,68,81,20,71,101,89,14,185,
151,131,242,249,237,129,136,136,72,126,74,164,63,143,51,224,29,147,60,75,127,166,232,235,154,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MidiSequenceManagerComponent::pause_png = (const char*) resource_MidiSequenceManagerComponent_pause_png;
const int MidiSequenceManagerComponent::pause_pngSize = 560;


//[EndFile] You can add extra defines here...
//[/EndFile]

