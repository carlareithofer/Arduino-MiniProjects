</> C++

#include <LiquidCrystal.h>

#define lcd_rs A5
#define lcd_e A4

#define lcd_d4 5
#define lcd_d5 6
#define lcd_d6 7
#define lcd_d7 8

LiquidCrystal lcd(lcd_rs, lcd_e, lcd_d4, lcd_d5, lcd_d6, lcd_d7);

int cursorLine = 0;

void printtextlcd(String text){
  if(text.length() > 16) 
    text = "Text too long";

  lcd.setCursor(0, cursorLine);
  lcd.print("                ");
  
  lcd.setCursor(0, cursorLine);
  lcd.print(text);
  
  if(cursorLine == 0)
    cursorLine = 1;
  else cursorLine = 0;
}

void setup(){
  Serial.begin(115200);
  Serial.setTimeout(10);

  lcd.begin(16, 2);
}

void loop(){
  if(Serial.available() > 0){
    String text = Serial.readString();
    printtextlcd(text);
  }
}
