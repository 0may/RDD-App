/*
  ==============================================================================

    Time.cpp
    Created: 9 Feb 2021 10:04:26am
    Author:  omay

  ==============================================================================
*/

#include "Time.h"


rdd::Time::Time() {
    _hours = 0;
    _mins = 0;
    _secs = 0;
    _millis = 0;
}

rdd::Time::Time(double seconds) {
    setTime(seconds);
}


void rdd::Time::setTime(double seconds) {
    seconds = fabs(seconds);

    unsigned long d = (unsigned long)seconds;

    _millis = (unsigned short)((seconds - d) * 1000.0 + 0.5);

    _hours = (unsigned int)(d / 3600);
    d -= _hours * 3600;

    _mins = (unsigned char)(d / 60);
    d -= _mins * 60;

    _secs = (unsigned char)d;
}

void rdd::Time::setTime(unsigned int hours, unsigned char mins, unsigned char secs, unsigned short millis) {
    setHours(hours);
    setMins(mins);
    setSecs(secs);
    setMillis(millis);
}

void rdd::Time::getTime(unsigned int& hours, unsigned char& mins, unsigned char& secs, unsigned short& millis) {
    hours = _hours;
    mins = _mins;
    secs = _secs;
    millis = _millis;
}

String rdd::Time::toString() {
    return String(_hours) + String(":") + String(_mins).paddedLeft('0', 2) + String(":") + String(_secs).paddedLeft('0', 2) + String(".") + String(_millis).paddedLeft('0', 3);
}
