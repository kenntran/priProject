/*
Assignment 3, Exercise 4
In this assignment, we will code and build a circuit to read temperature from the environment 
and convert it to Celsius degree and Fahrenheit degree by using Analog input of Arduino.

We have found the equation below on the Internet which help to minimize the memory better than using ADC library.
T = 1 / {A + B[ln(R)] + C[ln(R)]^3}
A = 0.001129148
B = 0.000234125
C = 8.76741E-08
The coefficients A, B, and C are constant factors of the individual thermistor.

Sources:
https://learn.adafruit.com/thermistor/using-a-thermistor
http://playground.arduino.cc/ComponentLib/Thermistor2

Authors:
Duy Le Nguyen
Nhut Tran

Date: 27/10/2016

*/

#include <Arduino.h>

double Temp, TempC, TempF;

double ReadingTemp() {
	
	int adc = analogRead(0);

	Temp = log(10000.0*((1024.0/adc-1)));												// ln(R) and (1024.0/adc-1) means it was caculated from this equation ADC value = R / (R + 10K) * 1023
	Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );	// T = 1 / {A + B[ln(R)] + C[ln(R)]^3}
	TempC = Temp - 273.15;																// Convert temperature from Kevin degree to Celsius degree
	Serial.print("Temperature C = ");
	Serial.print(TempC);
	Serial.print(" C. ");
	
	TempF = (TempC * 9.0)/ 5.0 + 32.0;		// Convert F degree to C degree
	Serial.print("Temperature F = ");
	Serial.print(TempF);
	Serial.println(" F.");
	delay(1000);
	return TempC;
	
}