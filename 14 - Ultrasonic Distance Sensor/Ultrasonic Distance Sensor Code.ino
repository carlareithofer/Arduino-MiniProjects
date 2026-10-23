#define echo_pin 3
#define trigger_pin 4

unsigned long lasttrigger = 0;
unsigned long triggerdelay = 100;

void trigger(){
  digitalWrite(trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);
}

double getdistance(){
  unsigned long duration = pulseIn(echo_pin, HIGH, 25000);
  if(duration == 0) return -1;   

  return duration / 58.0;
}

void setup(){
  Serial.begin(115200);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);
}

void loop(){
  unsigned long timenow = millis();

  if(timenow - lasttrigger > triggerdelay){
    lasttrigger = timenow;
    trigger();

    double distance = getdistance();
    if(distance < 0)
      Serial.println("Out of range");
    else{
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  }
}  
