</> C++

#include <EEPROM.h>

#define potentiometer A2
#define led 11
#define eeprom_address 350

byte maxbrightness;

void setup(){
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(led, OUTPUT);
  pinMode(potentiometer, INPUT);

  maxbrightness = EEPROM.read(eeprom_address);
  if(maxbrightness == 0) maxbrightness = 255;
}

void loop{
  if(Serial.available()){
    int data = Serial.parseInt();
    if((data >= 0) && (data <= 255)){
     EEPROM.write(eeprom_address, data);
     maxbrightness = data;
    }
  }

  byte ledbrightness = analogRead(potentiometer)/4;

  if(ledbrightness > maxbrightness)
    ledbrightness = maxbrightness;
  analogWrite(led, ledbrightness);
  
}
