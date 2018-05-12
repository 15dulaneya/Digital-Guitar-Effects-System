// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(8,INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
 // lcd.print("hello, world!");
 Serial.begin(9600);
 
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  Serial.print(digitalRead(8));
  if (digitalRead(8)==1) {
    lcd.setCursor(0,0);
    lcd.print("Distortion      ");
    lcd.setCursor(0,1);
    lcd.print("       ");
  }
  else if (digitalRead(7)==1) {
    lcd.setCursor(0,0);
    lcd.print("Tremolo         ");
    lcd.setCursor(0,1);
    lcd.print("       ");
  }
  else if (digitalRead(6)==1) {
    lcd.setCursor(0,0);
    lcd.print("Distorted Delay ");
    lcd.setCursor(0,1);
    lcd.print("       ");
  }
  else {
    lcd.setCursor(0,0);
    lcd.print("No Effect       ");
    lcd.setCursor(0,1);
    lcd.print("Enabled");
  //  lcd.display();
  }
}
