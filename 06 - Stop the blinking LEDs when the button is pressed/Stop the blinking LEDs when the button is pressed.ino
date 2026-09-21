</> C++

#define red_led_pin 11
#define yellow_led_pin 10
#define green_led_pin 9
#define button_pin 2
int pattern = 1;

void setup() {
  pinMode(red_led_pin, OUTPUT);
  pinMode(yellow_led_pin, OUTPUT);
  pinMode(green_led_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  digitalWrite(green_led_pin, LOW);
  digitalWrite(yellow_led_pin, LOW);
  digitalWrite(red_led_pin, LOW);
}

void loop() {
  if(digitalRead(button_pin)==LOW){

    if(pattern == 1){
      digitalWrite(green_led_pin, HIGH);
      digitalWrite(yellow_led_pin, HIGH);
      digitalWrite(red_led_pin, LOW);
      pattern = 2;
    }
    else if(pattern == 2){
      digitalWrite(green_led_pin, LOW);
      digitalWrite(yellow_led_pin, HIGH);
      digitalWrite(red_led_pin, LOW);
      pattern = 3;
    }
    else if(pattern == 3){
      digitalWrite(green_led_pin, LOW);
      digitalWrite(yellow_led_pin, HIGH);
      digitalWrite(red_led_pin, LOW);
      pattern = 1;
    }
    delay(300);
  }
}

