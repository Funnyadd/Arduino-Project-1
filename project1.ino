#include <LiquidCrystal.h>

#define echoPin A1
#define triggerPin A0

long duration;
long distance;

int minRange = 5;
int maxRange = 200;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
pinMode(triggerPin, OUTPUT);
pinMode(echoPin, INPUT);
  
lcd.begin(16, 2);
}

void loop() {
  getDistance();
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(0,1);
}

void getDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //calculated distance in cm
  distance = duration/58.2;

  
  if(distance >= maxRange || distance <= minRange) {
    lcd.print("Out of Range");
  } else {
    lcd.print(distance);
    lcd.print(" cm");
  }
}
