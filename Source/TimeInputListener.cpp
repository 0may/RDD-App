/*
  ==============================================================================

    TimeInputListener.cpp
    Created: 8 Feb 2021 1:59:07pm
    Author:  omay

  ==============================================================================
*/

#include "TimeInputListener.h"


using namespace rdd;

TimeInputListener::TimeInputListener(rdd::Time* time)
    : _time(time)
{

    setColours(Colour(0xffffffff), Colour(0xffffff88), Colour(0xffff0000));

}


/** Called when the user changes the text in some way. */
void TimeInputListener::textEditorTextChanged(TextEditor& e) {


    if (e.getName().compare("hours text editor") == 0) {

        e.applyColourToAllText(_editColour, true);

    }
    else if (e.getName().compare("mins text editor") == 0) {

        if (atoi(e.getText().toStdString().c_str()) > 59) {
            e.applyColourToAllText(_alertColour, true);
        }
        else {
            e.applyColourToAllText(_editColour, true);
        }

    }
    else if (e.getName().compare("secs text editor") == 0) {

        if (atoi(e.getText().toStdString().c_str()) > 59) {
            e.applyColourToAllText(_alertColour, true);
        }
        else {
            e.applyColourToAllText(_editColour, true);
        }
    }
    else if (e.getName().compare("millis text editor") == 0) {


        e.applyColourToAllText(_editColour, true);
    }

}

/** Called when the user presses the return key. */
void TimeInputListener::textEditorReturnKeyPressed(TextEditor& e) {

    String s = e.getText();

    if (s.isEmpty()) {
        s = String("0");
    }


    if (e.getName().compare("hours text editor") == 0) {
        _time->setHours((unsigned int)atoi(s.toStdString().c_str()));
        s = s.paddedLeft('0', 3);
    }
    else if (e.getName().compare("mins text editor") == 0) {

        if (atoi(s.toStdString().c_str()) > 59) {
            s = String(59);
        }

        _time->setMins((unsigned char)atoi(s.toStdString().c_str()));
        s = s.paddedLeft('0', 2);
    }
    else if (e.getName().compare("secs text editor") == 0) {

        if (atoi(s.toStdString().c_str()) > 59) {
            s = String(59);
        }

        _time->setSecs((unsigned char)atoi(s.toStdString().c_str()));
        s = s.paddedLeft('0', 2);
    }
    else if (e.getName().compare("millis text editor") == 0) {

        _time->setMillis((unsigned short)atoi(s.toStdString().c_str()));
        s = s.paddedLeft('0', 3);
    }


    e.setText(s);
    e.repaint();

    e.applyColourToAllText(_normalColour, true);
}

/** Called when the user presses the escape key. */
void TimeInputListener::textEditorEscapeKeyPressed(TextEditor& e) {
    if (e.getName().compare("hours text editor") == 0) {
        e.setText(String(_time->getHours()));
    }
    else if (e.getName().compare("mins text editor") == 0) {
        e.setText(String(_time->getMins()));
    }
    else if (e.getName().compare("secs text editor") == 0) {
        e.setText(String(_time->getSecs()));
    }
    else if (e.getName().compare("millis text editor") == 0) {
        e.setText(String(_time->getMillis()));
    }
    e.applyColourToAllText(_normalColour, true);
}

/** Called when the text editor loses focus. */
void TimeInputListener::textEditorFocusLost(TextEditor& e) {
    textEditorReturnKeyPressed(e);
}


void TimeInputListener::setColours(Colour normalColour, Colour editColour, Colour alertColour) {
    _normalColour = normalColour;
    _editColour = editColour;
    _alertColour = alertColour;
}