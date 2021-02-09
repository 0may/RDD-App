/*
  ==============================================================================

    TimeInputListener.h
    Created: 8 Feb 2021 1:59:07pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Time.h"

namespace rdd {

    class TimeInputListener : public TextEditor::Listener, public ChangeBroadcaster {

    public:
        TimeInputListener(rdd::Time* time);

        /** Called when the user changes the text in some way. */
        void textEditorTextChanged(TextEditor& e) override;

        /** Called when the user presses the return key. */
        void textEditorReturnKeyPressed(TextEditor& e) override;

        /** Called when the user presses the escape key. */
        void textEditorEscapeKeyPressed(TextEditor& e) override;

        /** Called when the text editor loses focus. */
        void textEditorFocusLost(TextEditor& e) override;

        /** Set colours for normal and alert display, only required when upper limit is specified
        */
        void setColours(Colour normalColour, Colour editColour = Colour(0xffffff88), Colour alertColour = Colour(0xffff0000));

        void setTimeObject(rdd::Time* time);

    protected:
        Colour _normalColour;
        Colour _editColour;
        Colour _alertColour;

        rdd::Time* _time;
    };
};