</> C++

#define photoresistor A0

int lightsamples[100] = { 0 };
int cnt = 0;

unsigned long lastread = millis();
unsigned long lightdelay = 50;

void setup(){
  Serial.begin(115200);
}

void loop(){
  unsigned long currentread = millis();

  if(currentread - lastread > lightdelay){
    lastread += lightdelay;
    if(cnt == 100){
      cnt =0;
      long sum = 0;
      for(int i = 0; i < 100; i++)
        sum += lightsamples[i];

      int averagelight = sum/100;

      Serial.print("Average luminosity for 100 samples: ");
      Serial.println(averagelight);
    }

    lightsamples[cnt] = analogRead(photoresistor);
    cnt++;
  }
  

}
