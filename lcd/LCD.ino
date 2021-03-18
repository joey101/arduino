#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7 );

void setup()
{
  lcd.begin(16,2);
  lcd.print("Hello Instagram");
  lcd.setCursor(0,1);
  lcd.println("I'm Back!!");
}

void loop() {
  
  }
