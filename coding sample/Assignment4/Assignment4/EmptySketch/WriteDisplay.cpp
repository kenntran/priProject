/*
Assignment 2 for Exercise 4 Embedded SW.
In this assignment we will display number with 7-segment display.

Authors:
Duy Nguyen Le
Nhut Tran
*/

#include <Arduino.h>
#include "WriteDisplay.h"


void DisplayNumber(int number){
	for (int x=0;x<7;x++){
		int value = bitRead(number, x);
		digitalWrite(pin1[x], value);
	}
}

void CountUp(){
	int j = 0;
	while(j < 10){
		DisplayNumber(numbers[j]);
		delay(1000);
		j++;
		for (int x = 0;x<7;x++){
			digitalWrite(pin1[x], HIGH);
		}
		delay(500);
	}
}

void CountDown(){
	int k = 9;
	while(k > -1){
		DisplayNumber(numbers[k]);
		delay(1000);
		k--;
		for (int x = 0;x<7;x++){
			digitalWrite(pin1[x], HIGH);
		}
		delay(500);
	}
}

