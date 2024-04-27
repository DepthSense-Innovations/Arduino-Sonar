#include <LiquidCrystal.h>
#include "Servo.h"
 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
Servo myServo;
 
#define refreshDelay 30
 
#define servoPin 12
#define servoAngleIncrement 5
#define servoMinAngle 480 //min servo angle in microseconds
#define servoMaxAngle 2500 //max servo angle in microseconds
int servoAngle = 0;
 
#define trigPin 9
#define echoPin 10
long duration;
int distance;
 
void setup() {
  myServo.attach(servoPin, servoMinAngle, servoMaxAngle);
 
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
   for (int i=10;i<=170;i++) {
    myServo.write(i);
    delay (30);
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
  lcd.print(" cm");// Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  for (int i=170;i>10; i--) {
  myServo.write(i);
  delay (30);
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
 
}
