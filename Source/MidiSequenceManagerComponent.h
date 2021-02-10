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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "MidiSequenceTableComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MidiSequenceManagerComponent  : public juce::Component,
                                      public juce::Button::Listener
{
public:
    //==============================================================================
    MidiSequenceManagerComponent ();
    ~MidiSequenceManagerComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* minus_png;
    static const int minus_pngSize;
    static const char* plus_png;
    static const int plus_pngSize;
    static const char* down_png;
    static const int down_pngSize;
    static const char* up_png;
    static const int up_pngSize;
    static const char* play_png;
    static const int play_pngSize;
    static const char* stop_png;
    static const int stop_pngSize;
    static const char* rec_png;
    static const int rec_pngSize;
    static const char* skip_b_png;
    static const int skip_b_pngSize;
    static const char* skip_f_png;
    static const int skip_f_pngSize;
    static const char* pause_png;
    static const int pause_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> _labelSequence;
    std::unique_ptr<MidiSequenceTableComponent> _tableComponent;
    std::unique_ptr<juce::ImageButton> _buttonDelete;
    std::unique_ptr<juce::TextButton> _buttonExport;
    std::unique_ptr<juce::TextButton> _buttonImport;
    std::unique_ptr<juce::ImageButton> _buttonAdd;
    std::unique_ptr<juce::ImageButton> _buttonMoveDown;
    std::unique_ptr<juce::ImageButton> _buttonMoveUp;
    std::unique_ptr<juce::ImageButton> _buttonPlay;
    std::unique_ptr<juce::ImageButton> _buttonStop;
    std::unique_ptr<juce::ImageButton> _buttonRecord;
    std::unique_ptr<juce::ImageButton> _buttonSkipBack;
    std::unique_ptr<juce::ImageButton> _buttonSkipForward;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiSequenceManagerComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

