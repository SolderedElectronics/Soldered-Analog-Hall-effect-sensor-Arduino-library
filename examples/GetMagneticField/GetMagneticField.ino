/**
 **************************************************
 *
 * @file        Read_value.ino
 * @brief       Example for using the analog read functions for Slider potentiometer with easyC
 *
 *
 *	product: www.solde.red/333131
 *
 * @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "Analog-Hall-effect-sensor-Soldered.h"

// Declare the sensor object
Hall_Sensor hall;

void setup()
{
    // Initialize the serial communication via UART
    Serial.begin(115200);

    // Initialize the sensor
    hall.begin();
}

void loop()
{
  if(hall.Available())
  {
    Serial.print("Raw value of slider hall effect sensor: "); //Print information message
    Serial.println(hall.getValue()); //Prints raw value of slider potentiometer
    Serial.print("Hall effect sensor: "); //Print information message
    Serial.print(hall.getMiliTeslas()); //Prints raw value of slider potentiometer
    Serial.println(" mT"); //Prints raw value of slider potentiometer
    delay(1000);
  }
}
