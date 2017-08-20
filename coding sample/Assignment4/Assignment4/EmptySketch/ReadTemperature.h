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


#ifndef READTEMPERATURE_H_H
#define READTEMPERATURE_H_H

double ReadingTemp(); 

#endif