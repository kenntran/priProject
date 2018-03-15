/***********************************************************************************************************************
 * Black Jack game
 * Names: Jorge
 *        Nhut Tran
 * Playing Black Jack with Arduino 
 * It still have bugs, particullary for LCD display - sometime it does not work properly on the first round after plugin
 * However, when simulate it on Autodesk Circuit website, it works properly
*************************************************************************************************************************/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buttonPlay = 0;
int buttonStop = 0;
int count = 0, number, dealerNumber, totalValue, dealerTotal;
int value[5], dealerValue[5];
const char* names[5] = {"ace","K","Q","J","N."};
int x = 0;

int buttonState, State = LOW;
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 100;    // the debounce time; increase if the output flickers


int calculating();
int calculatingDealer();
int randomNumber();
void line1(int times, int cardNumber, int playerValue);
void line2(int times,int dealerCard, int dealerValue);
boolean debounceButton(int buttonPin);

void Player(int playerNumber, int playerValue);
void Dealer(int dealerNumber, int valueDealer);

void endGame();
void winning();
void losing();
void runningWelcome();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  randomSeed(analogRead(A0));
  
  lcd.begin(16, 2);
}

void loop() {
  //checking button with debounceButtion function
  while(x < 1)
  {
    runningWelcome();
    x++;
  }  
  buttonPlay = debounceButton(6);
  buttonStop = debounceButton(7);
  
  if(buttonPlay == true)
  {    
    if(count < 6 && totalValue <= 21 )     //only allow player to draw card if under 5 cards, totalValue under 21
    { 
      lcd.clear();
      delay(200);                          //delay to avoid the program running so fast
      number = randomNumber();
      value[count] = number;      
      dealerNumber = randomNumber();      
      dealerValue[count] = dealerNumber;
      Player(number, value[count]);
      Dealer(dealerNumber, dealerValue[count]);
         
      totalValue = calculating();
      dealerTotal = calculatingDealer();
      count++;                             //increase the times
    }       
      
  
    if(count > 5 || totalValue > 21 || dealerTotal == 21) //if player cards is overflow || totalValue larger than 21 || dealerTotal = 21 before player 
    {
      losing();                                               //print totalValue and "Lose"
            
    }  
    else if(dealerTotal > 21)                      //checking dealer value and player value value after each round 
    {
      winning();
    }
  }
  
  if(buttonStop == true)                     //when the player want to stop and checking the result of player and dealer 
  {
      while(dealerTotal < 17)                //if the final result of dealer is under 17, get more cards untill it is over 17
      {        
        dealerNumber = randomNumber();      
        dealerValue[count + 1] = dealerNumber;     
        dealerTotal = calculatingDealer();
        count++;
      }
      
      if(totalValue > dealerTotal && totalValue <= 21 )
      {
        winning();
      }
      else if(totalValue > 21 || dealerTotal > totalValue)
      {
        losing();
      }
  }
}

/********************************************************************
 * Player get cards
********************************************************************/
void Player(int playerNumber, int playerValue)      
{
  if(number < 4 )                      //if random number is under 4, get their name
  {
    switch(number)                     //print its order and name  
    {
      case 0:                         //ace
      value[count] = 1;
      line1(count, number, value[count]);          //print its value
      break;
      
      case 1:                         //K
      value[count] = 10;              //set value of card K = 10
      line1(count, number, value[count]);         //print its value
      break;
      
      case 2:                         //Q 
      value[count] = 10;              //set value of card Q = 10
      line1(count, number, value[count]);           //print its value
      break;
      
      case 3:                         //J
      value[count] = 10;              //set value of card J = 10
      line1(count, number, value[count]);            //print its value
      break;
    }
  }
  else if(number > 4)
  {
      line1(count,4,value[count]);                  //if random number is over 4, get "N." symbol           
  }
}


/********************************************************************
 * Dealer get cards
********************************************************************/
void Dealer(int dealerNumber, int valueDealer)
{
  if(dealerNumber < 4)                      //if random number is under 4, get their name
  {
                                            //print its order and name  
    switch(dealerNumber)
    {
      case 0:                         //ace
      dealerValue[count] = 1;      
      line2(count, dealerNumber, dealerValue[count]);          //print its value
      break;
      
      case 1:                         //K
      dealerValue[count] = 10;        //set value of card K = 10           
      line2(count, dealerNumber, dealerValue[count]);            //print its value
      break;
      
      case 2:                         //Q 
      value[count] = 10;              //set value of card Q = 10
      dealerValue[count] = 10;
      line1(count, number, value[count]);           
      line2(count, dealerNumber, dealerValue[count]);            //print its value
      break;
      
      case 3:                         //J
      dealerValue[count] = 10;        //set value of card J = 10                 
      line2(count, dealerNumber, dealerValue[count]);            //print its value
      break;
    }
  }
  
  else if(dealerNumber > 4)
  {
    line2(count,4,dealerValue[count]);              //print its value
  }
}


/********************************************************************
 * "Black Jack" welcome words
********************************************************************/
void runningWelcome()
{
  lcd.setCursor(16, 0);
    lcd.print("BLACK JACK!");
    delay(1000);    
    for (int positionCounter = 0; positionCounter < 27; positionCounter++) {
      // scroll one position left:      
      lcd.scrollDisplayLeft();
      // wait a bit:
      delay(150);
    }
    lcd.clear();       
}


/********************************************************************
 * Winning function
 * Display the final result cards of Player and Dealer
 * Player WIN
********************************************************************/

void winning()                                    //print "winning" and show their final result 
{
  // Using Serial monitor to check the value
  
  /*******************************
  * Using those code for checking result through Serial monitor of Arduino
  *Serial.print("Player value: ");
  *Serial.println(totalValue);
  *Serial.print("Dealer value: ");
  *Serial.println(dealerTotal);
  *Serial.println("Player WIN");
  *********************************/
    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Player: ");
  lcd.setCursor(9,0);
  lcd.print(totalValue);
  lcd.setCursor(0,1);
  lcd.print("Dealer: ");
  lcd.print(dealerTotal);
  delay(3000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Player WIN!!!");
  lcd.setCursor(2,1);
  lcd.print("Dealer LOSE");
  delay(1500);
  lcd.clear();
  
  
  for(int x = 0; x < 5; x++)
  {
    value[x] = 0;
  }
  for(int x = 0; x < 5; x++)
  {
    dealerValue[x] = 0;
  }
  
  count = 0;
  number = 0;    
  totalValue = 0;
  dealerTotal = 0;
  delay(500);
  x = 0;
}


/********************************************************************
 * Losing function
 * Display the final result cards of Player and Dealer
 * Player LOSE
********************************************************************/
void losing()                                     // print "lose" and show their final result
{

  /*******************************
  * Using those code for checking result through Serial monitor of Arduino
  *Serial.print("Player value: ");
  *Serial.println(totalValue);
  *Serial.print("Dealer value: ");
  *Serial.println(dealerTotal);
  *Serial.println("Player LOSE");
  *********************************/
  
  lcd.clear(); 
  lcd.setCursor(0,0);
  lcd.print("Player: ");
  lcd.setCursor(9,0);
  lcd.print(totalValue);
  lcd.setCursor(0,1);
  lcd.print("Dealer: ");
  lcd.print(dealerTotal);
  delay(3000);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Dealer WIN!!!");
  lcd.setCursor(2,1);
  lcd.print("Player LOSE");
  delay(1500);
  lcd.clear();
  
  for(int x = 0; x < 5; x++)
  {
    value[x] = 0;
  }
  for(int x = 0; x < 5; x++)
  {
    dealerValue[x] = 0;
  }  
  count = 0;
  number = 0;    
  totalValue = 0;
  dealerTotal = 0;
  delay(500);
  x = 0;
}


/********************************************************************
 * Display cards of Player
********************************************************************/
void line1(int times, int cardNumber, int playerValue)               // print the result to Serial monitor
{
  const char *cardName = names[cardNumber];
  
  // Using Serial monitor to check the value
  /*
  Serial.print(times);  
  Serial.print(" Player: ");
  Serial.print(cardName);
  Serial.print(" ");
  Serial.println(playerValue);
  */
  
  lcd.setCursor(0,0);
  lcd.print(times);
  lcd.print(" Player:");
  lcd.print(cardName);
  lcd.setCursor(13,0);
  lcd.print(playerValue);  
  delay(1500); 
  
  
}


/********************************************************************
 * Display cards of Dealer
********************************************************************/
void line2(int times,int dealerCard, int dealerValue)
{
  const char *dealerCardName = names[dealerCard];
  
  // Using Serial monitor to check the value
  /*
  Serial.print(times);  
  Serial.print(" Dealer: ");
  Serial.print(dealerCardName);
  Serial.print(" ");
  Serial.println(dealerValue); 
  */
  
  lcd.setCursor(0,1);
  lcd.print(times);
  lcd.print(" Dealer:");
  lcd.print(dealerCardName);
  lcd.setCursor(13,1);
  lcd.print(dealerValue);
  delay(1500); 
}


/********************************************************************
 * Get a random number by using random function in Arduino 
********************************************************************/
int randomNumber()                                      
{
  int randomNumber = random(12);
  return randomNumber;
}


/********************************************************************
 * calculating the total card's value of player
********************************************************************/
int calculating()                                     
{
  int finalValue = 0;
  for(int a = 0; a < 5; a++)
  {
    finalValue += value[a];
  }
  return finalValue;       
}

/********************************************************************
 * Calculating the total card's values of dealer
********************************************************************/
int calculatingDealer()                               
{
  int finalDealer = 0;
  for(int a = 0; a < 5; a++)
  {
    finalDealer += dealerValue[a];
  }
  return finalDealer;       
}

/********************************************************************
 * Checking button function - only change the current's state when button is pressed over 50ms
 * Return the current's state to start getting cards
********************************************************************/
boolean debounceButton(int buttonPin)                   
{
  boolean current = digitalRead(buttonPin);
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
