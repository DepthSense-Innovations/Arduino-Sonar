#include <LiquidCrystal.h>
#include "Servo.h"

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
Servo myServo;

#define refreshDelay 30

#define servoPin 12
#define servoAngleIncrement 1
#define servoMinAngle 480 //min servo angle in microseconds
#define servoMaxAngle 2500 //max servo angle in microseconds
int servoAngle = 10;

#define trigPin 9
#define echoPin 10
long duration;
int distance;
int direction = 1;

void setup() {
  myServo.attach(servoPin, servoMinAngle, servoMaxAngle);
  
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  myServo.write(servoAngle);
  servoAngle += servoAngleIncrement * direction;
  if(servoAngle <= 10 || servoAngle >= 170) direction *= -1;
  delay (refreshDelay);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
}
