</> C++

#define photoresistor A0
#define led 10

void setup(){
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop(){
  int light = analogRead(photoresistor);

  if(light <300) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);

}
