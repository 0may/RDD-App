/*
  ==============================================================================

    Time.h
    Created: 8 Feb 2021 1:03:29pm
    Author:  omay

  ==============================================================================
*/

#pragma once

#include <math.h>
#include <JuceHeader.h>

namespace rdd {

    class Time {


    public:

        Time() {
            _hours = 0;
            _mins = 0;
            _secs = 0;
            _millis = 0;
        }


        void setTime(double seconds) {
            seconds = fabs(seconds);

            unsigned long d = (unsigned long)seconds;

            _millis= (unsigned short)((seconds - d)*1000.0 + 0.5);

            _hours = (unsigned int)(d / 3600);
            d -= _hours * 3600;

            _mins = (unsigned char)(d / 60);
            d -= _mins * 60;

            _secs = (unsigned char)d;
        }

        void setTime(unsigned int hours, unsigned char mins, unsigned char secs, unsigned short millis) {
            _hours = hours;
            _mins = mins;
            _secs = secs;
            _millis = millis;
        }

        void getTime(unsigned int& hours, unsigned char& mins, unsigned char& secs, unsigned short& millis) {
            hours = _hours;
            mins = _mins;
            secs = _secs;
            millis = _millis;
        }

        unsigned int getHours() { return _hours; }
        unsigned char getMins() { return _mins; }
        unsigned char getSecs() { return _secs; }
        unsigned short getMillis() { return _millis; }

        void setHours(unsigned int hours) { _hours = hours;  }
        void setMins(unsigned char mins) { _mins = mins; }
        void setSecs(unsigned char secs) { _secs = secs; }
        void setMillis(unsigned short millis) { _millis = millis; }

        double seconds() {
            return _hours * 3600.0 + _mins * 60.0 + (double)_secs + _millis * 0.001;
        }

        String toString() {
            return String(_hours) + String(":") + String(_mins).paddedLeft('0',2) + String(":") + String(_secs).paddedLeft('0',2) + String(".") + String(_millis).paddedLeft('0',3);
        }



    protected:
        unsigned int _hours;
        unsigned char _mins;
        unsigned char _secs;
        unsigned short _millis;
    };




};
