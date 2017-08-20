/*
Exercise 4 - Assignment 4
In this Assignment, we will combine those files to make a program which shall read temperature from the environment
And display on 7-segment display.


Authors:
Nhut Tran
Duy Le Nguyen
	
*/

#include <Arduino.h>
#include "ReadTemperature.h"
#include "WriteDisplay.h"
#include "Assignment4.h"

double TemperatureC;

void setup() {
  // put your setup code here, to run once:
	pinMode(LED_A1, OUTPUT);
	pinMode(LED_B1, OUTPUT);
	pinMode(LED_C1, OUTPUT);
	pinMode(LED_D1, OUTPUT);
	pinMode(LED_E1, OUTPUT);
	pinMode(LED_F1, OUTPUT);
	pinMode(LED_G1, OUTPUT);
// 	pinMode(LED_A2, OUTPUT);
// 	pinMode(LED_B2, OUTPUT);
// 	pinMode(LED_C2, OUTPUT);
// 	pinMode(LED_D2, OUTPUT);
// 	pinMode(LED_E2, OUTPUT);
// 	pinMode(LED_F2, OUTPUT);
// 	pinMode(LED_G2, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	//get temp in Celsius  
	ReadingTemp();
	TemperatureC = ReadingTemp();
	//print temp to 7-segment display
	DisplayTemperature(TemperatureC);
	
}
