/*
* LCD pins- Arduino pins
vss-gnd
vdd-5v
vo-6
rs-12
rw-gnd
e-11
d4-5
d5-4
d6-3
d7-2
A-5v
K-gnd

*/
#include <LiquidCrystal.h>
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define ARRAYSIZE 11

String pickupLines[ARRAYSIZE] = {
  "This is a test string 1",
  "This is a test string 2",
  "This is a test string 3",
  "This is a test string 4",
  "This is a test string 5",
  "This is a test string 6",
  "This is a test string 7",
  "This is a test string 8",
  "This is a test string 9",
  "This is a test string 10",
 };

void setup()
{
analogWrite(6,Contrast);
lcd.begin(16, 2);
}
void loop()
{
   for (int i = 0; i <= ARRAYSIZE; i++) {
    if(pickupLines[i].length() <= 16){
      lcd.setCursor(0,0);
      lcd.println(pickupLines[i]); 
    } else if (pickupLines[i].length() > 32){
      // do nothing
    } else {
      lcd.setCursor(0,0);
      lcd.println(pickupLines[i].substring(0,16));

      lcd.setCursor(0,1);
      lcd.println(pickupLines[i].substring(16, pickupLines[i].length()));
    }
    delay(3000);
    lcd.clear();
   }
}
