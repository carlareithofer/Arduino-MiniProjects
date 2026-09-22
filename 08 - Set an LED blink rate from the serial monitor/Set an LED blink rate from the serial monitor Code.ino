</> C++

#define led_pin 12

int sec = 500;
int led_state = LOW; 
void setup(){
  Serial.begin(115200);
  Serial.setTimeout(10);

  pinMode(led_pin, OUTPUT);
}

void loop(){
  if(Serial.available()){
    int data = Serial.parseInt();
    if(data >= 100 && data <= 1000)
      sec = data;
  }
    
  if(led_state == LOW) led_state = HIGH;
  else led_state = LOW;
  
  digitalWrite(led_pin, led_state);
  delay(sec);
  
}
