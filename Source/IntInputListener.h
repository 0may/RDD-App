/*
  ==============================================================================

    IntInputConstraint.h
    Created: 8 Feb 2021 11:03:09am
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace rdd {

    class IntInputListener : public TextEditor::Listener {

    public:
        IntInputListener(int numDigits = -1, int upperLimit = -1, bool padZeros = false);

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
        void setColours(Colour normalColour, Colour alertColour = Colour(0xffff0000));

    protected:

        int _numDigits;
        int _upperLimit;
        bool _padZeros;

        Colour _normalColour;
        Colour _alertColour;
    };
};