/*
 Demo video link: https://www.youtube.com/watch?v=10znzdELKZs 

 LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
 the text.

  The circuit:
 * LCD RS pin to digital pin 12y
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5 q
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalScroll

 */

/*********************************************************************************************************
 * Automated FAN project
 * Authors: Duy Le Nguyen
 *          Nhut Tran
 * Description:
 * Due to the demand of users, the FAN will be automated accordingly to the temperature of ambient environment
 * The speed of FAN will be changed accordingly to the signal which will be read by thermal sensor LM35
 * The sensor will read the temperature data from environment each 4ms by using Interrupt routine 
 * Using Interrtupt rountine to read the temperature data to avoid the time jitter or delay in main loop to increase the accuracy of the system
 * 
 **********************************************************************************************************/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int stepp = 0;
volatile int count = 10;
volatile int fanSpeed = 0, displaySpeed =0;
int INA = 7; 
int INB = 6;

volatile int sensorVal = 0;
float convertTemperature; 

int buttonReset = 0;
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void runningWelcome();
void showingWords();
void displayTemperature();
void runningFan();

void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(INA,OUTPUT); 
  pinMode(INB,OUTPUT);
   
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  

  cli(); // Disable global interrupts

  // Setting Timer Counter Control Registers A and B to zero
  TCCR1A = 0;
  TCCR1B = 0;

  OCR1A = 23471; // Output Compare Register set to correct timer count  -- set 2/3hz -- 1.5s 

  TCCR1B |= (1 << WGM12); // Waveform Generation Mode
  TCCR1B |= (1 << CS10); // Clock select
  TCCR1B |= (1 << CS12); // Clock select

  TIMSK1 |= (1 << OCIE1A); // Timer/Counter Interrupt Mask Register

  sei(); // Enable global interrupts

}

/*************************************************************************************
 * Main program
 **************************************************************************************/
void loop() {
  buttonReset = debounceButton(8);
  switch(stepp)
  {
    case 0:
    runningWelcome();
    delay(1000);
    lcd.clear();
    break;

    case 1:
    showingWords();
    break;

    case 2:
    displayTemperature();
    runningFan(); 
    break;    
  } 

  if(buttonReset == 1)
  {
    stepp = 0;
    fanSpeed = 0;
    convertTemperature = 0;
    
  }
}
/*************************************************************************************
 * Running Welcome Words function
 * This function will display welcome words 
 * Those words will run from Right to Left on LCD display and disappeard
 **************************************************************************************/

void runningWelcome()
{
  lcd.setCursor(16, 0);
    lcd.print("FAN Project");
    delay(1000);    
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
      // scroll one position left:      
      lcd.scrollDisplayLeft();
      // wait a bit:
      delay(150);
    }        
    stepp++;
}

/*************************************************************************************
 * Showing Data
 * This function will show the position of data which will be display in a minute late
 * 
 **************************************************************************************/
void showingWords()
{
  lcd.setCursor(16, 0);
  lcd.print("Temperature: 0");
  lcd.setCursor(16,1);
  lcd.print("FAN's Speed: 0");
  delay(1000);    
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:      
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  delay(2000);
  lcd.clear();
  stepp++;
}

void displayTemperature()
{     
  float voltage = (sensorVal/1024.0) * 5;
  convertTemperature = (voltage - .5) *100;
    
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.print((int)convertTemperature);
  lcd.print((char)223);  
  lcd.print("C");  
  lcd.setCursor(0,1);
  lcd.print("FAN's Speed:");
  lcd.print(displaySpeed);
  lcd.print((char)37);
  delay(1000);
  lcd.clear(); 
}

/******************************************************
 * RunningFan function will map the value of sensor to the voltage to provide for FAN
 * The range of temperature for this system is from 10*C to 45*C 
 * The Fan will run from 0% to 100% accordingly to the temperature of environment
 ******************************************************/
void runningFan()
{    
  fanSpeed = map(convertTemperature,10,60,0,255);
  displaySpeed = map(fanSpeed,0,255,0,100);
  digitalWrite(INA,LOW);
  analogWrite(INB,fanSpeed);  
}

/**********************************************************************
* Interrupt function
* Used for reading temperature data from sensor
* This function also used to protect temperatre data from data stream
**********************************************************************/
ISR(TIMER1_COMPA_vect) {  
  sensorVal = analogRead(A5);
}

/********************************************************************
 * Checking button function - only change the current's state when button is pressed over 50ms
********************************************************************/
int debounceButton(int buttonPin)                   
{
  int current = digitalRead(buttonPin);
  if (current != lastButtonState) {
    lastDebounceTime = millis();  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (current != buttonState) {
      buttonState = current;
    }
  } 
  return current;                                         
}