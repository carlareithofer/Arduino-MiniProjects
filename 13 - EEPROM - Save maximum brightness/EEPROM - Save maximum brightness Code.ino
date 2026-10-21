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
}

void loop(){
  if(Serial.available()){
    String input = Serial.readStringUntil('\n');
    input.trim();

    if(input.length() > 0){
      int data = input.toInt();
      if((data >= 0) && (data <= 255)){
        EEPROM.update(eeprom_address, data);
        maxbrightness = data;
        Serial.print("Maximum brightness saved: ");
        Serial.println(maxbrightness);
      }
    }
  }

  byte ledbrightness = analogRead(potentiometer)/4;

  if(ledbrightness > maxbrightness)
    ledbrightness = maxbrightness;
  analogWrite(led, ledbrightness);
}
