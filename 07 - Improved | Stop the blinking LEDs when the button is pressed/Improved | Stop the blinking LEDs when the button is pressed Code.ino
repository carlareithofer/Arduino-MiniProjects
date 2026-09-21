<\> C++

#define red_led_pin 11
#define yellow_led_pin 10
#define green_led_pin 9

#define button_pin 2

#define led_pin_array_size 3

int pattern = 1;

byte ledpin[led_pin_array_size] = 
          {red_led_pin, yellow_led_pin, green_led_pin};

void ledpinmode(){
  for(int i = 1; i <= 3; i++)
    pinMode(ledpin[i], OUTPUT);
}

void ledpinstate(){
  for(int i = 1; i <= 3; i++)
    digitalWrite(ledpin[i], LOW);
}

void setpattern(){
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
      digitalWrite(green_led_pin, HIGH);
      digitalWrite(yellow_led_pin, LOW);
      digitalWrite(red_led_pin, HIGH);
      pattern = 1;
    }
}

void setup() {
  pinMode(button_pin, INPUT);

  ledpinmode();

  ledpinstate();
}

void loop() {
  if(digitalRead(button_pin)==LOW){

    setpattern();
    delay(300);
  }
}
