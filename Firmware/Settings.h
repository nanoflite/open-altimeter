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

#ifndef SETTINGS_H
#define SETTINGS_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif

#include "config.h"

#define SETTINGS_SIZE sizeof(Settings)

enum BatteryType { BATTERY_TYPE_NIMH = 0, BATTERY_TYPE_LIPO = 1, BATTERY_TYPE_NONE = 2 };
enum Action { DO_NOTHING = 0, OUTPUT_MAX_HEIGHT = 1, OUTPUT_MAX_LAUNCH_HEIGHT = 2, OUTPUT_LAUNCH_WINDOW_END_HEIGHT = 3, OUTPUT_BATTERY_VOLTAGE = 4 };

class Settings
{
  public:
    uint16_t logIntervalMS;
    float heightUnits;
    BatteryType batteryType;
    // if the battery type is NIMH, then this is the threshold, for LIPO it's the per cell threshold
    float lowVoltageThreshold;
    float batteryMonitorCalibration;
    bool logServo;
    Action midPositionAction;
    Action onPositionAction;
    
    void print();
};

class SettingsStore
{
  public:
    static void save(Settings* settings);
    static void load(Settings* settings);
    static void erase();
    static void test();
};


#endif /*SETTINGS_H*/
