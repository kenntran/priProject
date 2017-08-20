/*
Exercise 4 - Assignment 4
In this Assignment, we will combine those files to make a program which shall read temperature from the environment
And display on 7-segment display.


Authors:
Nhut Tran
Duy Le Nguyen
	
*/
#include <Arduino.h>
#include "Assignment4.h"
#include "WriteDisplay.h"

int firstNumber, secondNumber;

// This function will receive the temperature value from ReadTemperature function and display those value on 7-segment.

void DisplayTemperature(double TemperatureC){
	//tempC
	//extern float TempC;
	int a = TemperatureC;
	firstNumber = a/10;						// The tens - Separate a two-digit number to two one-digit numbers  
	secondNumber = a%10;					// The unit number - Separate a two-digit number to two one-digit numbers  

	DisplayFirstNumber(firstNumber);
	DisplaySecondNumber(secondNumber);

	delay(1000);
}

void DisplayFirstNumber(int firstNumber){
	DisplayNumber(numbers[firstNumber]);
	//Serial.print(firstNumber);
	delay(1000);
	for (int x = 0;x<7;x++){
		digitalWrite(pin1[x], HIGH);
	}
	delay(500);
}

void DisplaySecondNumber(int secondNumber){
	DisplayNumber(numbers[secondNumber]);
	delay(1000);
	for (int x = 0;x<7;x++){
		digitalWrite(pin1[x], HIGH);
	}
	delay(500);
}
