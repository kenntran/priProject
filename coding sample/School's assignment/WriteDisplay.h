/*
Assignment 2 for Exercise 4 Embedded SW.
In this assignment we will display number with 7-segment display.

Authors:
Duy Nguyen Le
Nhut Tran
*/


#ifndef WRITEDISPLAY_H_
#define WRITEDISPLAY_H_

//#define byte uint8_t

#define LED_A1 3
#define LED_B1 4
#define LED_C1 5
#define LED_D1 6
#define LED_E1 7
#define LED_F1 8
#define LED_G1 9
// #define LED_A2 7
// #define LED_B2 8
// #define LED_C2 9
// #define LED_D2 10
// #define LED_E2 11
// #define LED_F2 12
// #define LED_G2 13

const int pin1[7] = { LED_A1,LED_B1, LED_C1,LED_D1,LED_E1,LED_F1,LED_G1 };
/*const int pin2[7] = { LED_A2,LED_B2, LED_C2,LED_D2,LED_E2,LED_F2,LED_G2 };*/

const byte numbers[] = { 0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000 };


void DisplayNumber(int number);
void CountUp();
void CountDown();


#endif