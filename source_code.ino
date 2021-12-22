
#include<LiquidCrystal.h>
#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"
int contrast=120;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
FPS_GT511C3 fps(8,9);
int id;
int match;
void setup()
{
  analogWrite(6,contrast);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("WELCOME”");
  delay(2500);
  lcd.clear();
fps.Open();
  fps.SetLED(true);
}
void loop()
{ 
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    id = fps.Identify1_N();
    if (id <200)
    {
      lcd.print("Verified ID : ");
      lcd.println(id);
    }
    else
    {
      lcd.println("Finger not found");
    }
  }
  else
  {
    lcd.println("Please press ");
    lcd.setCursor(0,1);
    lcd.print("ENROLLED finger");
  }
  delay(100);
}
void unlock()
{
 match=id;
if(match==id)
{
  digitalWrite(13,HIGH);
  delay(6000);
}
else
  {
    digitalWrite(13,LOW);
}
  
}

