/**
 * SHTxx Library
 *
 * Copyright 2012 JAS <qlfecv@gmail.com>
 * Based on previous work by:
 *	  Jonathan Oxer <jon@oxer.com.au> / <www.practicalarduino.com>
 *    Maurice Ribble: <www.glacialwanderer.com/hobbyrobotics/?p=5>
 *    Wayne ?: <ragingreality.blogspot.com/2008/01/ardunio-and-sht15.html>
 *
 * Manages communication with SHTxx series (SHT10, SHT11, SHT15,SHT71)
 * temperature / humidity sensors 
 */
#ifndef SHTxx_h
#define SHTxx_h

#if (ARDUINO >= 100)
#include <Arduino.h>

#endif

class SHTxx
{
  public:
    SHTxx(int dataPin, int clockPin);
    float readHumidity();
    float readTemperatureC();
    float readTemperatureF();
  private:
    int _dataPin;
    int _clockPin;
    int _numBits;
    float readTemperatureRaw();
    int shiftIn(int _dataPin, int _clockPin, int _numBits);
    void sendCommandSHT(int _command, int _dataPin, int _clockPin);
    void waitForResultSHT(int _dataPin);
    int getData16SHT(int _dataPin, int _clockPin);
    void skipCrcSHT(int _dataPin, int _clockPin);
};

#endif
