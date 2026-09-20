</> C++

#define led_pin 11
#define potentiometer_pin A2

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(potentiometer_pin, INPUT);
}

void loop() {
  analogWrite(led_pin, analogRead(potentiometer_pin)/4);
}

