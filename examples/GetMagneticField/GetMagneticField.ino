/**
 **************************************************
 *
 * @file        Read_value.ino
 * @brief       Example for using the analog read functions for analog hall sensor with easyC
 *
 *
 *	product: www.solde.red/333018
 *
 * @authors     Goran Juric for Soldered.com
 ***************************************************/

#include "Analog-Hall-effect-sensor-Soldered.h"

// Declare the sensor object for analog use with easyC
Analog_Hall_Sensor hallE;

// Declare the sensor object for analog use without easyC
Analog_Hall_Sensor hall(A0); //Parameter is pin on which is connected devices analog pin


void setup()
{
    // Initialize the serial communication via UART
    Serial.begin(115200);

    // Initialize the sensor
    hall.begin();
    hallE.begin();
}

void loop()
{
  if(hallE.Available())
  {
    Serial.print("Raw value of hall effect sensor with easyC: "); //Print information message
    Serial.println(hallE.getValue()); //Prints raw value of slider potentiometer
    Serial.print("Hall effect sensor with easyC reading: "); //Print information message
    Serial.print(hallE.getMiliTeslas()); //Prints value of hall sensor with easyC in militeslas
    Serial.println(" mT"); 
  }
  Serial.print("Raw value of hall effect sensor: "); //Print information message
  Serial.println(hall.getValue()); //Prints raw value of slider potentiometer
  Serial.print("Hall effect sensor reading: "); //Print information message
  Serial.print(hall.getMiliTeslas()); //Prints value of hall sensor without easyC in militeslas
  Serial.println(" mT"); 
  delay(1000);
}
