<\> C++

#define button_pin 2
#define led_pin 11

void setup() {
  // set button pin to input
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, LOW);
}

void loop() {
  if(digitalRead(button_pin)==HIGH)
    digitalWrite(led_pin, HIGH);
  else digitalWrite(led_pin, LOW);
}

