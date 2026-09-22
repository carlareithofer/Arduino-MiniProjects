</> C++

#define button 2

int cnt = 0;

volatile bool buttonpressed = false;

unsigned long lastpressed = millis();
unsigned long millisec = 50;

void buttonpressedint(){
  unsigned long currenttime = millis();
  if(currenttime - lastpressed > millisec){
    lastpressed = currenttime;
    buttonpressed = true;
  }
}

void setup(){
  Serial.begin(115200);
  pinMode(button, INPUT);

  attachInterrupt(digitalPinToInterrupt(button), buttonpressedint, RISING);
}

void loop(){
  if(buttonpressed){
    buttonpressed = false;
    cnt++;
    Serial.print("Counter is: ");
    Serial.println(cnt);
  }
}
