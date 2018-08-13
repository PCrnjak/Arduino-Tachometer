/*
 /////////////////////////////STEPPER SPEED TEST//////////////////////
 
 This sketch is used as test for my 3d printed tachometer , but it can also be used for anyone
 that wants to control speed of stepper with press of a button.It works like this:
 when you start your arduino and have everything hooked up , your motor should spin at 93 RPM if
 you used parametars i used for microstepping and pulse widht. RPM is calculated by this formula:
(60/(200*(1/microstepping)*2*pulse_widht*0.000001)).You should see those 93 RPM on your LCD display.
After every button press pulse widht is reduced by 20 microseconds, and new speed is calculated and
displayed on LCD.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 8
 * LCD D7 pin to digital pin 9
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 
 * Our switch will be used with pull-down resistor like this:
 * one end of switch goes to the 220 ohm resistor and D2 on arduino
 * another end of switch goes to 5V ,and unconnected lead of resistor goes to the GND.
 * 
 * There are alot of different stepper drivers but they all have STEP/PULS pin and DIR pin
 * STEP/PULS pin of stepper driver goes to the D6 on arduino
 * DIR pin of stepper driver goes to the D7 on arduino


Written by Petar Crnjak https://github.com/PCrnjak
*/

// include the library code:
#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Define what kind of microstepping you are using ,default is 0.5 ( or half stepping )
// 1/4 stepping would be 0.25 ,1/8 would be 0.125 and so on ....
#define microstepping 0.5

// Pulse_widht that will be decreased by pressing button
volatile int pulse_widht=1000; /// 1000 microseconds
byte state=LOW;  
int RPM=0;

unsigned long previousMillis=0;

volatile byte control_state=LOW;


const int stepPin = 6; // this pin goes to the PULS pin on stepper driver
const int dirPin = 7;  // Direction pin on stepper controller

void setup() {
//Define pins that go in stepper driver as outputs
pinMode(stepPin,OUTPUT); 
pinMode(dirPin,OUTPUT);

//Define LCD's number of colums and rows
lcd.begin(16, 2);
lcd.print("RPM:"); // Print out rpm 
digitalWrite(dirPin,HIGH); // Here you can change direction by changing HIGH to LOW
attachInterrupt(0,increment,RISING); // Attaching interrupt to pin 2 of arduino
/////Here we precalculate RPM for default pulse_widht of 1000 microseconds
//// Because we want to display RPM even if we never pressed button to increment it
 lcd.setCursor(0, 1);   
 RPM=(60/(200*(1/microstepping)*2*pulse_widht*0.000001));   ///(60/(0.0008*pulse_widht));
 lcd.print(RPM);

}

void loop(){
  unsigned long currentMillis=micros();
 ////// state is used to prevent triggering of this if statement twice in row 
 ///// same goes for second one , this secures perfect square wave form
  if(currentMillis-previousMillis>=pulse_widht and state==LOW){
    previousMillis=currentMillis;
    digitalWrite(stepPin,HIGH);
    state=HIGH;
    
  }
  if(currentMillis-previousMillis>=(pulse_widht) and state==HIGH) {
    previousMillis=currentMillis;
    digitalWrite(stepPin,LOW);
    state=LOW;
    
  }
  ///// This if statement triggers every time button is pressed and it prints new RPM value
  if(control_state==HIGH){
    lcd.setCursor(0, 1);   
    RPM=(60/(200*(1/microstepping)*2*pulse_widht*0.000001)); 
    lcd.print(RPM);
    control_state=LOW;
  }

}

void increment(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
   // If interrupts come faster than 250ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 250) {
          //////// Here we decease pulse_widht wich in turn increases RPM
          pulse_widht=pulse_widht - 20;
          control_state=HIGH;
    }else{
         control_state=LOW;     
   }   
last_interrupt_time = interrupt_time;
}

