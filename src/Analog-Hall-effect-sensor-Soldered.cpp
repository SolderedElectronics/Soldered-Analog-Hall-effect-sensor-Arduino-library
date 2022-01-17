/**
 **************************************************
 *
 * @file        Analog-Hall-effect-sensor-Soldered.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/


#include "Analog-Hall-effect-sensor-Soldered.h"

Analog_Hall_Sensor::Analog_Hall_Sensor()
{
}

/**
 * @brief                   Sensor specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
Analog_Hall_Sensor::Analog_Hall_Sensor(int _pin)
{
    pin = _pin;
    native = 1;
}

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
void Analog_Hall_Sensor::initializeNative()
{
    pinMode(pin, INPUT);
}

/**
 * @brief                   This function gets raw value of meauserement
 *
 * @return                  Raw value of measurement
 */
uint16_t Analog_Hall_Sensor::getValue()
{
    if (native)
    {
        value = analogRead(pin);
    }
    else
    {
        readRegister(ANALOG_READ_REG, raw, 2 * sizeof(uint8_t));
        value = raw[0] | (raw[1]) << 8;
    }
    return value;
}

/**
 * @brief                   This function calculates value of magnetic flux in militeslas,
 *                          normally you should get about 0.05 mT
 *
 * @return                  Value of magnetic flux in militeslas
 */
float Analog_Hall_Sensor::getMiliTeslas()
{
    value = getValue();
    return 20.47 * (10 * (value / 1023.0) / 5.0 - 1);
}

/**
 * @brief                   Function which checks if I2C device is responding
 *
 * @return                  1 if device is responding, 0 if not
 */
bool Analog_Hall_Sensor::Available()
{
    return !(sendAddress(0X01)); // checking if address is succesfully sent, if not device is not ready to communicate
}
