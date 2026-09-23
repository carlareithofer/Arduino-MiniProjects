</> C++

#include <LiquidCrystal.h>

#define echo_pin 3
#define trigger_pin 4

#define lcd_rs A5
#define lcd_e A4

#define lcd_d4 5
#define lcd_d5 6
#define lcd_d6 7
#define lcd_d7 8

unsigned long lasttrigger = millis();
unsigned long triggerdelay = 60;

volatile unsigned long pulseinbegin;
volatile unsigned long pulseinend;
volatile bool newdistance = false;

double lastdistance = 400.0;

LiquidCrystal lcd(lcd_rs, lcd_e, lcd_d4, lcd_d5, lcd_d6, lcd_d7);

int cursorLine = 0;

void trigger(){
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
}

double getdistance(){
  double duration = pulseinend - pulseinbegin;
  double distance = duration/58.0;
  if(distance > 400.0)
    return lastdistance;
  lastdistance = distance;
  return distance;
}

void echopinint(){
  if(digitalRead(echo_pin) == HIGH) pulseinbegin = micros();
  else{
    pulseinend = micros();
    newdistance = true;
  }
}

void printdistance(double distance){
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
}

void setup(){
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Rate: ");
  lcd.print(triggerdelay);
  lcd.print(" ms.");

  attachInterrupt(digitalPinToInterrupt(echo_pin), echopinint, CHANGE);
}

void loop(){
  unsigned long timenow = millis();

  if(timenow - lasttrigger > triggerdelay){
    lasttrigger += triggerdelay;
    trigger();
  }

  if(newdistance){
    newdistance = false;
    double distance = getdistance();
    printdistance(distance);
  }
}
