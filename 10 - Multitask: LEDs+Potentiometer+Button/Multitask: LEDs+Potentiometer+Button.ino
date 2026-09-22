</> C++

#define red_led 11
#define yellow_led 10
#define green_led 9

#define button 2
#define potentiometer A2

unsigned long lastblink = millis();
unsigned long sec = 500;

int led_state = LOW; 

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

  pinMode(potentiometer, INPUT);
  pinMode(button, INPUT);

  ledpinmode();
  ledpinstate();
}

void actionled1(){
  if(Serial.available()){
    int data = Serial.parseInt();
    if(data >= 100 && data <= 4000)
      sec = data;
  }
  
  unsigned long currenttime = millis();
  if(currenttime - lastblink > sec){
    if(led_state == LOW) led_state = HIGH;
    else led_state = LOW;
  
    digitalWrite(red_led, led_state);
    lastblink += sec;
  }
}

void actionled2(){
  int potentiometerlevel = analogRead(potentiometer);
  analogWrite(yellow_led, potentiometerlevel/4);
  Serial.println(potentiometerlevel);
  delay(100);
}

void actionled3(){
  if(digitalRead(button) == HIGH)
    digitalWrite(green_led, HIGH);
  else digitalWrite(green_led, LOW);
}

void loop(){

  // action for LED 1 (red)
  actionled1();

  //  action LED 2 (yellow)
  actionled2();

  // action LED 3 (green)
  actionled3();
}
