/*
  ==============================================================================

    IntInputConstraint.cpp
    Created: 8 Feb 2021 11:03:09am
    Author:  omay

  ==============================================================================
*/

#include "IntInputListener.h"

using namespace rdd;

IntInputListener::IntInputListener(int numDigits, int upperLimit, bool padZeros)
    : _numDigits(numDigits),
    _upperLimit(upperLimit),
    _padZeros(padZeros)
{
    setColours(Colour(0xffffffff), Colour(0xffff0000));

    
}


/** Called when the user changes the text in some way. */
void IntInputListener::textEditorTextChanged(TextEditor& e) {


    if (_upperLimit >= 0) {

        if (atoi(e.getText().toStdString().c_str()) > _upperLimit) {
            e.applyColourToAllText(_alertColour, true);
        }
        else {
            e.applyColourToAllText(_normalColour, true);
        }
    }

}

/** Called when the user presses the return key. */
void IntInputListener::textEditorReturnKeyPressed(TextEditor& e) {

    String s = e.getText();

    if (s.isEmpty()) {
        s = String("0");
    }
    else if (_upperLimit >= 0 && atoi(s.toStdString().c_str()) > _upperLimit) {
        s = String(_upperLimit);
    }

    if (_padZeros) 
        s = s.paddedLeft('0', _numDigits);

    e.setText(s);
}

/** Called when the user presses the escape key. */
void IntInputListener::textEditorEscapeKeyPressed(TextEditor& e) {

}

/** Called when the text editor loses focus. */
void IntInputListener::textEditorFocusLost(TextEditor& e) {
    textEditorReturnKeyPressed(e);
}


void IntInputListener::setColours(Colour normalColour, Colour alertColour) {
    _normalColour = normalColour;
    _alertColour = alertColour;
}