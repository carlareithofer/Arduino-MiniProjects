#include <LiquidCrystal.h>
#include <IRremote.h>

// ---------- pins ----------
#define red_led 5        // moved from 11: IRremote uses Timer2, which controls PWM on pin 11
#define yellow_led 10
#define green_led 9

#define button 2
#define echo_pin 3
#define trigger_pin 4
#define ir_receiver 12
#define photoresistor A0
#define potentiometer A2

#define lcd_rs A5
#define lcd_e A4
#define lcd_d4 11        // moved from 5: the LCD only needs a digital pin
#define lcd_d5 6
#define lcd_d6 7
#define lcd_d7 8

// ---------- remote control codes (check them in the Serial Monitor) ----------
#define ir_button_1 12
#define ir_button_2 24
#define ir_button_3 94

// ---------- settings ----------
#define dark_threshold 300    // mode 2
#define lcd_refresh 200      
#define trigger_delay 60     
#define debounce_delay 50    

LiquidCrystal lcd(lcd_rs, lcd_e, lcd_d4, lcd_d5, lcd_d6, lcd_d7);

byte ledpin[3] = {red_led, yellow_led, green_led};
const char* ledname[3] = {"Red", "Yellow", "Green"};

int mode = 0;                     // 0 = no mode selected yet
unsigned long lastlcdupdate = 0;

// ---------- mode 1: parking sensor ----------
unsigned long lasttrigger = 0;
volatile unsigned long pulseinbegin;
volatile unsigned long pulseinend;
volatile bool newdistance = false;
double distance = -1;             // -1 = out of range

// ---------- mode 3: LED dimmer ----------
volatile bool buttonpressed = false;
volatile unsigned long lastpressed = 0;
int selectedled = -1;             // -1 = no LED selected yet
byte brightness[3] = {0, 0, 0};   // remembered brightness of each LED

// ================= interrupts =================

void echopinint(){
  if(digitalRead(echo_pin) == HIGH) pulseinbegin = micros();
  else{
    pulseinend = micros();
    newdistance = true;
  }
}

void buttonpressedint(){
  unsigned long currenttime = millis();
  if(currenttime - lastpressed > debounce_delay){
    lastpressed = currenttime;
    buttonpressed = true;
  }
}

// ================= helper functions =================

void printline(int row, String text){
  lcd.setCursor(0, row);
  lcd.print(text);
  for(int i = text.length(); i < 16; i++)
    lcd.print(" ");
}

void setleds(byte red, byte yellow, byte green){ 
  digitalWrite(red_led, red);
  digitalWrite(yellow_led, yellow);
  digitalWrite(green_led, green);
}

void trigger(){
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
}

void setmode(int newmode){
  mode = newmode;
  setleds(LOW, LOW, LOW);   
  lcd.clear();
  lastlcdupdate = 0;

  if(mode == 1){
    printline(0, "1: Parking");
    distance = -1;
  }
  else if(mode == 2){
    printline(0, "2: Night light");
  }
  else if(mode == 3){
    selectedled = -1;
    buttonpressed = false;
    for(int i = 0; i < 3; i++)
      analogWrite(ledpin[i], brightness[i]);
    printline(0, "3: LED dimmer");
    printline(1, "Press button");
  }
}

// ================= modes =================

void parkingmode(){
  unsigned long timenow = millis();

  if(timenow - lasttrigger >= trigger_delay){
    lasttrigger = timenow;
    trigger();
  }

  if(newdistance){
    newdistance = false;

    noInterrupts();
    unsigned long duration = pulseinend - pulseinbegin;
    interrupts();

    double d = duration / 58.0;
    distance = (d > 400) ? -1 : d;

    if(distance < 0)           setleds(LOW, LOW, LOW);    
    else if(distance < 30)     setleds(HIGH, LOW, LOW);   
    else if(distance < 150)    setleds(LOW, HIGH, LOW);   
    else                       setleds(LOW, LOW, HIGH);   
  }

  if(timenow - lastlcdupdate >= lcd_refresh){
    lastlcdupdate = timenow;
    if(distance < 0) printline(1, "Out of range");
    else             printline(1, "Dist: " + String(distance, 1) + " cm");
  }
}

void nightlightmode(){
  int light = analogRead(photoresistor);

  if(light < dark_threshold) digitalWrite(yellow_led, HIGH);
  else digitalWrite(yellow_led, LOW);

  if(millis() - lastlcdupdate >= lcd_refresh){
    lastlcdupdate = millis();
    printline(1, "Light: " + String(light));
  }
}

void dimmermode(){
  if(buttonpressed){
    buttonpressed = false;
    selectedled = (selectedled + 1) % 3;
    printline(0, "LED: " + String(ledname[selectedled]));
    lastlcdupdate = 0;
  }

  if(selectedled < 0) return;

  brightness[selectedled] = analogRead(potentiometer) / 4;
  analogWrite(ledpin[selectedled], brightness[selectedled]);

  if(millis() - lastlcdupdate >= lcd_refresh){
    lastlcdupdate = millis();
    printline(1, "Brightness: " + String(brightness[selectedled] * 100 / 255) + "%");
  }
}

// ================= setup & loop =================

void setup(){
  Serial.begin(115200);
  IrReceiver.begin(ir_receiver);

  for(int i = 0; i < 3; i++)
    pinMode(ledpin[i], OUTPUT);

  pinMode(button, INPUT);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(echo_pin), echopinint, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button), buttonpressedint, RISING);

  lcd.begin(16, 2);
  printline(0, "Smart Desk");
  printline(1, "Select mode 1-3");
}

void loop(){
  // ----- remote control: choose the mode -----
  if(IrReceiver.decode()){
    int command = IrReceiver.decodedIRData.command;
    bool isrepeat = IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT;
    IrReceiver.resume();

    if(!isrepeat){   
      if(command == ir_button_1) setmode(1);
      else if(command == ir_button_2) setmode(2);
      else if(command == ir_button_3) setmode(3);
    }
  }

  // ----- run the current mode -----
  if(mode == 1) parkingmode();
  else if(mode == 2) nightlightmode();
  else if(mode == 3) dimmermode();
  else buttonpressed = false;   
}
