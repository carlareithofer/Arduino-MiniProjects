</> C++

#define echo_pin 3
#define trigger_pin 4

#define red_led 11
#define yellow_led 10
#define green_led 9

unsigned long lasttrigger = millis();
unsigned long triggerdelay = 100;

volatile unsigned long pulseinbegin;
volatile unsigned long pulseinend;
volatile bool newdistance = false;

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
  return distance;
}

void echopinint(){
  if(digitalRead(echo_pin) == HIGH) pulseinbegin = micros();
  else{ 
    pulseinend = micros(); 
    newdistance = true;
  }
}
void setup(){
  Serial.begin(115200);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);

  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);

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
    Serial.println(distance);

    if(distance >= 0 && distance < 50){
      digitalWrite(red_led, HIGH);
      digitalWrite(yellow_led, LOW);
      digitalWrite(green_led, LOW);
    }

    if(distance >= 50 && distance < 150){
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, HIGH);
      digitalWrite(green_led, LOW);
    }

    if(distance >= 150 && distance <= 400){
      digitalWrite(red_led, LOW);
      digitalWrite(yellow_led, LOW);
      digitalWrite(green_led, HIGH);
    }
  }
}
