/*
    openaltimeter -- an open-source altimeter for RC aircraft
    Copyright (C) 2010  Jony Hudson
    http://openaltimeter.org

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BATTERY_H
#define BATTERY_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

#include "config.h"

#include "Settings.h"

class Battery
{
  public:
    Battery(int analogInputPin);
    void setup(BatteryType batteryType, float batteryMonitorCalibration, float threshold);
    float readVoltage();
    boolean isLow();
    int numberOfCells();
    void test();
  private:
    int _analogInputPin;
    int _numberOfCells;
    boolean _isLow;
    float _calibration;
    BatteryType _batteryType;
    float _threshold;
};

#endif /*BATTERY_H*/
