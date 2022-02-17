/**
 **************************************************
 *
 * @file        easyC.h
 * @brief       Basic funtions for easyC libraries
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors     Goran Juric @ soldered.com
 ***************************************************/

#ifndef __ANALOG_HALL_EFFECT__
#define __ANALOG_HALL_EFFECT__

#include "Arduino.h"
#include "Wire.h"

#define ANALOG_READ_REG  0
#define DIGITAL_READ_REG 1

namespace ANALOG_HALL_EFFECT_SENSOR_EASYC
{

class EasyC
{
  public:
    EasyC();

    void begin();
    void begin(uint8_t _address);

  protected:
    int native = 0;
    bool beginDone = 0;

    virtual void initializeNative() = 0;

    int err;

    char address;
    const char defaultAddress = 0x30;

    int sendAddress(char regAddr);
    int readData(char a[], int n);
    int sendData(const uint8_t *a, int n);
    int readRegister(char regAddr, char a[], size_t n);
};

} // namespace ANALOG_HALL_EFFECT_SENSOR_EASYC

#endif
