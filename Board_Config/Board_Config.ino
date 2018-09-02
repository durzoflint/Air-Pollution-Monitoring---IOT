#include "MQ135.h"
#include <LiquidCrystal.h>

const int sensorPin= 0;
int air_quality;

LiquidCrystal lcd(13,12, 6, 5, 4, 3);

void setup() {
  
  pinMode(8, OUTPUT);
  
  lcd.begin(16,2);
  lcd.setCursor (0,0);
  lcd.print ("Air Quality");
  lcd.setCursor (0,1);
  lcd.print ("Sensor Warming");
  
  delay(1000);
  
  Serial.begin(115200);
  
  pinMode(sensorPin, INPUT);
  
  lcd.clear();
}

void loop() {

  MQ135 gasSensor = MQ135(A0);
  float air_quality = gasSensor.getPPM();
  
  Serial.print (air_quality);
  Serial.print (" PPM\n");

  lcd.setCursor (0,1);
  lcd.print (air_quality);
  lcd.print (" PPM");
  
  if (air_quality<=1000)
  {
    lcd.setCursor (0,0);
    lcd.print ("Air Quality-Good");
    digitalWrite(8, LOW);
  }
  else if( air_quality>1000 && air_quality<2000 )
  {
    lcd.setCursor (0,0);
    lcd.print ("Air Quality-Poor");
    digitalWrite(8, HIGH );
  }
  else if (air_quality>=2000 )
  {
    lcd.setCursor (0,0);
    lcd.print ("Air Quality-Bad");
    digitalWrite(8, HIGH);
  }
  
  delay(5000);
}
