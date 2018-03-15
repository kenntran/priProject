# FAN's project - Cooling-system project
  04/2017

Descriptions
----------
 	- Due to the demand of users, the FAN will be automated accordingly to the temperature of ambient environment
 	- The speed of FAN will be changed accordingly to the signal which will be read by thermal sensor LM35
 	- The sensor will read the temperature data from environment each 4ms by using Interrupt routine 
 	- Using Interrtupt rountine to read the temperature data to avoid the time jitter or delay in main loop to increase the accuracy of the system

Platform
--------
* This project had been developed by using Arduino and Arduino IDE 

Demo video
----------
* You can watch the demo video from ***[here](https://www.youtube.com/watch?v=10znzdELKZs)***

Note
----
### Interrupt function
* This project control the reading function by using Interrupt function of Arduino 
```
ISR(TIMER1_COMPA_vect) 
{  
  sensorVal = analogRead(A5);
}
```

* To eanble Arduino to switch into Interrup function, you need define which TIMER and prescaler. For example, in this project, We have used TIMER1 of Arduino: 
Further information, you can see ***[here](http://www.instructables.com/id/Arduino-Timer-Interrupts/)***
```
// Setting Timer Counter Control Registers A and B to zero
  TCCR1A = 0;
  TCCR1B = 0;

  OCR1A = 23471; // Output Compare Register set to correct timer count  -- set 2/3hz -- 1.5s 

  TCCR1B |= (1 << WGM12); // Waveform Generation Mode
  TCCR1B |= (1 << CS10); // Clock select
  TCCR1B |= (1 << CS12); // Clock select

  TIMSK1 |= (1 << OCIE1A); // Timer/Counter Interrupt Mask Register
```

* The problem while using TIMER of Arduino.
You can encounter the problem with analogWrite() function while using TIMER of Arduino because that each TIMER will have its different pins.
For example, we could not write analog signal on pins 9 and 10. You can see more ***[here](https://arduino-info.wikispaces.com/Timers-Arduino)***

* Noting on the changing value of `sensorVal`
We have used `volatile` keywork to notify to complier that always check the value of `sensorVal`. It might be changed frequenlty after each Interrup Route:
```
volatile int sensorVal = 0;
```  

### runningFan function
* In this project, we have used `map()` function of Arduino to compare the value of `convertTemperature` value and limited analog value to control the FAN's speed
```
fanSpeed = map(convertTemperature,10,60,0,255);
```

* This function is quite similar with PID (proportional–integral–derivative) controller. Because lack of time, we have to use `map()` function instead embedded PID algorithms to control the FAN's speed according the temperature data. 

Authors
-------
Created by `Nhut Tran` and `Duy Le` 