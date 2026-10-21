#include <IRremote.h>

#define ir_receiver 12

#define ir_button_1 12
#define ir_button_2 24
#define ir_button_3 94
#define ir_button_4 8
#define ir_button_5 28
#define ir_button_6 90

#define red_led 11
#define yellow_led 10
#define green_led 9

void setup(){
  Serial.begin(115200);
  IrReceiver.begin(ir_receiver);

  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);

  digitalWrite(red_led, LOW);
  digitalWrite(yellow_led, LOW);
  digitalWrite(green_led, LOW);
}

void loop(){
  if(IrReceiver.decode()){
    // read the command before resuming, so the data isn't overwritten
    int command = IrReceiver.decodedIRData.command;
    IrReceiver.resume();

    Serial.print("Received command: ");
    Serial.println(command);

    switch(command){
      case ir_button_1: digitalWrite(red_led, HIGH);    break;
      case ir_button_2: digitalWrite(yellow_led, HIGH); break;
      case ir_button_3: digitalWrite(green_led, HIGH);  break;
      case ir_button_4: digitalWrite(red_led, LOW);     break;
      case ir_button_5: digitalWrite(yellow_led, LOW);  break;
      case ir_button_6: digitalWrite(green_led, LOW);   break;
    }
  }
}
    if(command == ir_button_1)
      digitalWrite(red_led, HIGH);

    if(command == ir_button_2)
      digitalWrite(yellow_led, HIGH);

    if(command == ir_button_3)
      digitalWrite(green_led, HIGH);

    if(command == ir_button_4)
      digitalWrite(red_led, LOW);

    if(command == ir_button_5)
      digitalWrite(yellow_led, LOW);

    if(command == ir_button_6)
      digitalWrite(green_led, LOW);
  }
}
