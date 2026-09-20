</> C++

#define red_led_pin 11
#define yellow_led_pin 10
#define green_led_pin 9

void setup() {
  pinMode(red_led_pin, OUTPUT);
  pinMode(yellow_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
}

void loop() {
  digitalWrite(green_led_pin, HIGH);
  delay(2000);
  digitalWrite(green_led_pin, LOW);
  digitalWrite(yellow_led_pin, HIGH);
  delay(1000);
  digitalWrite(yellow_led_pin, LOW);
  digitalWrite(red_led_pin, HIGH);
  delay(2000);
  digitalWrite(red_led_pin, LOW);
}
