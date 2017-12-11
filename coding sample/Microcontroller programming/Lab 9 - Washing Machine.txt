/******************************************************************************
*Lab 9 - Embedded Electronics: Washing Machine
*Names:	Jorge
*	Nhut Tran
******************************************************************************/


#define LED_A1 2
#define LED_B1 3
#define LED_C1 4
#define LED_D1 5
#define LED_E1 6
#define LED_F1 7
#define LED_G1 8

#define Motor 9
#define Pump 10
#define Relay 11
#define LED 12

volatile byte State = LOW;

int run = 0;
int buttonStart = 0, x =0;
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

int Step = 0;
// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

int Switch2 = 0;
int Switch3 = 0;
const int pin1[7] = { LED_A1,LED_B1, LED_C1,LED_D1,LED_E1,LED_F1,LED_G1 };

const byte numbers[] = { 0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000 };

void DisplayNumber(int number);
void CountUp(int Time);
void State1(int roatingTime);
void State2(int roatingTime);
void State3(int roatingTime);
void State4(int roatingTime);
void State5(int roatingTime);
void State6(int roatingTime);
void State7(int roatingTime);
int debounceButton(int buttonPin);
void StateEnd();

void setup() {
  for(int i = 2; i < 12; i++)
    {
      pinMode(i, OUTPUT);
    }
  Serial.begin(9600);
}

void loop() {
  
  Switch2 = analogRead(A0);
  Switch3 = analogRead(A1);  
  buttonStart = debounceButton(13);   //ON/OFF Button is Pin13

  
  if(buttonStart == HIGH)       //This function will ON/OFF the washing machine
  {
    if(run == 0)
    {
      run = 255;
    }
    else
    {
      run = 0;      
      Step = 0;
    }
  }

  
  if(run > 0)
  {
   switch(Step)
   {
      case 0:                 //State1: Taking water
        State1(3);
        Step++;
        break;

      case 1:                 //State2: Washing
        if(Switch2 > 700)
        {
          State2(9);
          Step++;
        }        
        break;

       case 2:                //State3: Pump Out
        if(Switch3 > 700)
        {
          State3(3);
          Step++;
        }        
        break;

       case 3:                 //State4: Taking Water
        State4(3);
        Step++;
        break;

       case 4:                 //State5: Rinsing
        if(Switch2 > 700)
        {
          State5(5);
          Step++;
        }        
        break;

       case 5:                  //State6: Pump Out
        if(Switch3 > 700)
        {
          State6(3);
          Step++;
        }          
        break;

       case 6:                //State7: Centrifuging and Finishing 
        State7(5);
        BlinkingLed();
        delay(500);          
        run = 0;   
        break;    
    }   
  }
}



/********************************************************************
 * Displaying the time of process
********************************************************************/
void DisplayNumber(int number){
  for (int x=0;x<7;x++){
    int value = bitRead(number, x);
    digitalWrite(pin1[x], value);
  }
}

/********************************************************************
 * Count up from 0 to the time of process
********************************************************************/
void CountUp(int Time){
  int j = 0;
  while(j <= Time){
    DisplayNumber(numbers[j]);
    delay(500);
    j++;
    for (int x = 0;x<7;x++){
      digitalWrite(pin1[x], HIGH);
    }
    delay(500);
  }
  //delay(500);
}

/********************************************************************
 * Blinking LED to announce the program is ready for finish
********************************************************************/
void BlinkingLed()
{
  for(int x = 0; x < 3; x++)
  {
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(1000);
  }
}

/********************************************************************
 * State 1: Washing machine takes water about 3 s.
********************************************************************/
void State1(int rotatingTime)
{
  digitalWrite(Relay, HIGH);
  CountUp(rotatingTime);
  digitalWrite(Relay,LOW);
}

/********************************************************************
 * State 2:Washing machine is washing 9 s. (The speed of the motor should be moderate)
 * The speed of motor is medium
********************************************************************/
void State2(int rotatingTime)
{
  analogWrite(Motor, 128);
  CountUp(rotatingTime);
  analogWrite(Motor, 0);
}

/********************************************************************
 * State 3:Dirty water is pumped out of the machine about 3 s.
********************************************************************/
void State3(int rotatingTime)
{
  digitalWrite(Pump, HIGH);
  CountUp(rotatingTime);
  digitalWrite(Pump,LOW);
}

/********************************************************************
 * State 4:Washing machine takes water about 3 s.
********************************************************************/
void State4(int rotatingTime)
{
  digitalWrite(Relay, HIGH);
  CountUp(rotatingTime);
  digitalWrite(Relay,LOW);
}

/********************************************************************
 * State 5:Washing machine is rinsing 5 s
 * The speed of motor is low
********************************************************************/
void State5(int rotatingTime)
{
  analogWrite(Motor,70);
  CountUp(rotatingTime);
  analogWrite(Motor,0);
}

/********************************************************************
 * State 6:Rinsing water is pumped out of the machine about 3 s
********************************************************************/
void State6(int rotatingTime)
{
  digitalWrite(Pump, HIGH);
  CountUp(rotatingTime);
  digitalWrite(Pump,LOW);
}

/********************************************************************
 * State 7:Washing machine is centrifuging 5 s. (The speed of the motor should be high) 
 * The speed of motor is fastest
********************************************************************/
void State7(int rotatingTime)
{
  analogWrite(Motor, 255);
  CountUp(rotatingTime);
  analogWrite(Motor, 0);
}


/********************************************************************
 * Checking button function - only change the current's state when button is pressed over 50ms
 * Return the current's state to start getting cards
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
