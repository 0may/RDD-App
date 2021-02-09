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

    /**
    * 
    */
    class Time {


    public:

        Time();

        void setTime(double seconds);

        void setTime(unsigned int hours, unsigned char mins, unsigned char secs, unsigned short millis);

        void getTime(unsigned int& hours, unsigned char& mins, unsigned char& secs, unsigned short& millis);

        inline unsigned int getHours() { return _hours; }
        inline unsigned char getMins() { return _mins; }
        inline unsigned char getSecs() { return _secs; }
        inline unsigned short getMillis() { return _millis; }

        inline void setHours(unsigned int hours) { _hours = hours; }
        inline void setMins(unsigned char mins) { _mins = (mins <= 59) ? mins : 59; }
        inline void setSecs(unsigned char secs) { _secs = (secs <= 59) ? secs : 59; }
        inline void setMillis(unsigned short millis) { _millis = (millis < 999) ? millis : 999; }

        inline double seconds() {
            return _hours * 3600.0 + _mins * 60.0 + (double)_secs + _millis * 0.001;
        }

        String toString();



    protected:
        unsigned int _hours;
        unsigned char _mins;
        unsigned char _secs;
        unsigned short _millis;
    };




};
