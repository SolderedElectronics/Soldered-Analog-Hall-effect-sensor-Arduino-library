/**
 **************************************************
 *
 * @file        attiny_firmware for Slider Potentiometer
 * @brief       This sensor sends position of slider on
 *              potentiometer using I2C communication
 *
 *
 *
 * @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;

void setup()
{
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);
}

void loop()
{
}

char lastEvent;

void receiveEvent(int howMany)
{
    while (1 < Wire.available())
    {
        char c = Wire.read();
    }

    lastEvent = Wire.read();
}

void requestEvent()
{
    int c = 0;
    char a[2];
    if (lastEvent==0)
    {
      c = analogRead(PA4);
      a[1] = c >> 8;
      a[0] = c & 0xFF;
      Wire.write(a, 2);
    }
}
