</> C++

#define red_led 11
#define yellow_led 10
#define green_led 9

#define button 2

unsigned long lastblink = millis();
unsigned long blinkrate = 1000;

unsigned long lastchanged = millis();
unsigned long milisec = 50;

unsigned long currenttime = millis();

int led_state = LOW; 

int ledpattern = 1;

byte lastbuttonstate = 0;

byte ledpin[3] = {red_led, yellow_led, green_led};

// create function to set all LED pins as outputs
void ledpinmode(){
  for(int i = 0; i < 3; i++)
    pinMode(ledpin[i], OUTPUT);
}

// create function to set the LEDs low
void ledpinstate(){
  for(int i = 0; i < 3; i++)
    digitalWrite(ledpin[i], LOW);
}

void setup(){
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(button, INPUT);

  ledpinmode();
  ledpinstate();
}

void actionled1(){
  if(currenttime - lastblink > 1000){
    if(led_state == LOW) led_state = HIGH;
    else led_state = LOW;
  
    digitalWrite(red_led, led_state);
    lastblink += 1000;
  }
}

void actionleds2and3(){
  if(currenttime - lastchanged > milisec){
    byte buttonstate = digitalRead(button);
    if(buttonstate != lastbuttonstate){

      lastbuttonstate = buttonstate;
      lastchanged = currenttime;

      if(buttonstate == HIGH){
        if(ledpattern == 1){
          digitalWrite(yellow_led, HIGH);
          digitalWrite(green_led, LOW);
          ledpattern = 2;
        }
        else{
          digitalWrite(yellow_led, LOW);
          digitalWrite(green_led, HIGH);
          ledpattern = 1;
        }
      }
    }
  }
}

void loop(){

  currenttime = millis();

  // action for LED 1 (red) - blinkrate 1000ms
  actionled1();

  //  action LEDs 2 and 3 (yellow and green)
  actionleds2and3();

}
