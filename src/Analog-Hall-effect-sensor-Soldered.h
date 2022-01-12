/**
 **************************************************
 *
 * @file        Analog-Hall-effect-sensor-Soldered.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     @ soldered.com
 ***************************************************/

#ifndef _easyC_
#define _easyC_

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

class Analog_Hall_Sensor : public ANALOG_HALL_EFFECT_SENSOR_EASYC::EasyC
{
  public:
    Analog_Hall_Sensor();
    Analog_Hall_Sensor(int _pin);
    uint16_t getValue(void);
    float getMiliTeslas(void);
    bool Available(void);

  protected:
    void initializeNative();

  private:
    int pin;
    uint16_t value;
    char raw[2];
    int prescale = 1;
};

#endif
