/**
 **************************************************
 *
 * @file        Analog-Hall-effect-sensor-Soldered.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     @ soldered.com
 ***************************************************/


#include "Analog-Hall-effect-sensor-Soldered.h"

Hall_Sensor::Hall_Sensor()
{
}

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
Hall_Sensor::Hall_Sensor(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void Hall_Sensor::initializeNative()
{
    pinMode(pin, INPUT);
}

uint16_t Hall_Sensor::getValue()
{
    readRegister(ANALOG_READ_REG, raw, 2 * sizeof(uint8_t));
    value = raw[0] | (raw[1]) << 8;
    return value;
}

float Hall_Sensor::getMiliTeslas()
{
    value = getValue();
    return 20.47 * (10 * (value / 1023.0) / 5.0 - 1);
}