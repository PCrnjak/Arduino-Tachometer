
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


unsigned int rpm;
unsigned int prevmillis=0;
volatile byte state;
unsigned int duration;
unsigned int prevTime = 0; 
#define updateTime 350

void setup() {
attachInterrupt(1,interrupt,RISING); 
 Serial.begin(9600);
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.clearDisplay();
}

void loop() {
 
if(state==true){
  detachInterrupt(1);
  duration = ( millis() - prevmillis );
  prevmillis = millis();
  
 
  if(millis() - prevTime >= updateTime) {
     prevTime = millis(); 
      ///Serial.print("\t RPM:  ");
     // Serial.println(rpm);
     rpm = (60000/duration)/1;   
     display.clearDisplay();
     display.setTextSize(2);
     display.setTextColor(WHITE);
     display.setCursor(3,9);
     display.println("RPM:");
     display.setCursor(60,9);
     display.println(rpm);  
     display.display();   
  }
  state=false;
  attachInterrupt(1,interrupt,RISING); 
  
  }
}


void interrupt(){
 state=true;

}


