/**
 **************************************************
 *
 * @file        Read_value.ino
 * @brief       Example for using the analog read functions for analog hall sensor
 *
 *
 *	product: www.solde.red/333018
 *
 * @authors     Goran Juric for Soldered.com
 ***************************************************/

//Connecting diagram
//Breakout      Arduino
//|-------------|
//OUT-----------A0
//GND-----------GND
//VCC-----------5V

#include "Analog-Hall-effect-sensor-Soldered.h"

// Declare the sensor object for analog use without easyC
Analog_Hall_Sensor hall(A0); //Parameter is pin on which is connected devices analog pin

void setup()
{
    // Initialize the serial communication via UART
    Serial.begin(115200);

    // Initialize the sensor
    hall.begin();
}

void loop()
{
  Serial.print("Raw value of hall effect sensor: "); //Print information message
  Serial.println(hall.getValue()); //Prints raw value of slider potentiometer
  Serial.print("Hall effect sensor reading: "); //Print information message
  Serial.print(hall.getMiliTeslas()); //Prints value of hall sensor without easyC in militeslas
  Serial.println(" mT"); 
  delay(1000);
}
