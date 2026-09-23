</> C++

#define echo_pin 3
#define trigger_pin 4

unsigned long lasttrigger = millis();
unsigned long triggerdelay = 100;

void trigger(){
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
}

double getdistance(){
  unsigned long begin = micros();
  double duration = pulseIn(echo_pin, HIGH);
  unsigned long end = micros();

  unsigned long codeduration = end - begin;

  Serial.print("Duration : ");
  Serial.println(codeduration);

  double distance = duration/58.0;
  return distance;
}
void setup(){
  Serial.begin(115200);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);
}

void loop(){
  unsigned long timenow = millis();

  if(timenow - lasttrigger > triggerdelay){
    lasttrigger += triggerdelay;
    trigger();
    Serial.println(getdistance());
  }
}
