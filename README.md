[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=bugs)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=security_rating)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=reliability_rating)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
[![Technical Debt](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=sqale_index)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=sqale_rating)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
[![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=DepthSense-Innovations_Arduino-Sonar&metric=vulnerabilities)](https://sonarcloud.io/summary/new_code?id=DepthSense-Innovations_Arduino-Sonar)
<a href='https://coveralls.io/github/DepthSense-Innovations/Arduino-Sonar?branch=main'><img src='https://coveralls.io/repos/github/DepthSense-Innovations/Arduino-Sonar/badge.svg?branch=main' alt='Coverage Status' /></a>


### Arduino Sonar 

This project utilizes an Arduino UNO R3 along with various components to create a moving sonar system that displays distance measurements on an LCD screen.

#### Components:
    - 1 x Arduino UNO R3
    - 1 x LCD 16 x 2
    - 1 x Ultrasonic Distance Sensor (4-pin)
    - 1 x Positional Micro Servo
    - 1 x 1 kΩ Potentiometer
    - 1 x >=300Ω Resistor

#### Circuit Diagram:

![image](https://github.com/DepthSense-Innovations/Arduino-Sonar/assets/97468479/b4e9f425-d7c7-4bfa-8e52-a5e539ff7485)

#### Description:
The Arduino Sonar project integrates an ultrasonic distance sensor and a servo motor controlled by an Arduino UNO R3. The ultrasonic sensor measures distances, and the servo motor rotates to provide a sweeping motion for distance detection. The measured distance is displayed on the LCD screen in real-time.

#### Setup:
1. Connect the LCD to the Arduino UNO R3:
   - LCD RS pin to digital pin 1
   - LCD Enable pin to digital pin 2
   - LCD D4 pin to digital pin 4
   - LCD D5 pin to digital pin 5
   - LCD D6 pin to digital pin 6
   - LCD D7 pin to digital pin 7

2. Connect the servo motor to the Arduino UNO R3:
   - Servo control wire to digital pin 12
   - Servo power wire to 5V
   - Servo ground wire to GND

3. Connect the ultrasonic distance sensor to the Arduino UNO R3:
   - VCC to 5V
   - GND to GND
   - Trig pin to digital pin 9
   - Echo pin to digital pin 10

4. Add a 1 kΩ potentiometer between 5V and GND, with the wiper connected to analog pin A0.

5. Place a resistor with a resistance greater than or equal to 300Ω between the LCD backlight positive (+) and GND.

#### Functionality:
- The servo motor rotates incrementally, changing the angle of the ultrasonic sensor.
- The ultrasonic sensor measures the distance to objects in its path.
- The Arduino calculates the distance based on the time taken for the ultrasonic pulse to return.
- Distance measurements are displayed on the LCD screen in centimeters.

#### Note:
Ensure all connections are secure and the components are properly powered before uploading the code to the Arduino UNO R3. Adjustments to the servo motor angle range and LCD pin configuration may be necessary based on the specific components used.

### Deep Explanation:


![image](https://github.com/DepthSense-Innovations/Arduino-Sonar/assets/97468479/dcdc0243-0505-411e-b18a-7911de09a7f2)

 - #include <LiquidCrystal.h>: This line includes the LiquidCrystal library, which provides functions to interface with LCD displays.
 - #include "Servo.h": This line includes the Servo library, which allows control of servo motors.
 - LiquidCrystal lcd(1, 2, 4, 5, 6, 7);: This line initializes an LCD object named lcd with the pin numbers connected to the LCD display.
 - Servo myServo;: This line declares a Servo object named myServo.
 - #define refreshDelay 30: This line defines a constant refreshDelay with a value of 30 milliseconds, which determines the delay between servo angle updates.
 - #define servoPin 12: This line defines a constant servoPin with the value 12, representing the pin connected to the servo motor.
 - #define servoAngleIncrement 1: This line defines a constant servoAngleIncrement with the value 1, representing the increment by which the servo angle changes.
 - #define servoMinAngle 480: This line defines a constant servoMinAngle with the value 480, representing the minimum angle (in microseconds) for the servo motor.
 - #define servoMaxAngle 2500: This line defines a constant servoMaxAngle with the value 2500, representing the maximum angle (in microseconds) for the servo motor.
 - int servoAngle = 10;: This line declares an integer variable servoAngle and initializes it to 10, representing the initial angle of the servo motor.
 - int direction = 1;: This line declares an integer variable direction and initializes it to 1, representing the direction of servo movement.
 - #define trigPin 9: This line defines a constant trigPin with the value 9, representing the pin connected to the ultrasonic sensor's trigger.
 - #define echoPin 10: This line defines a constant echoPin with the value 10, representing the pin connected to the ultrasonic sensor's echo.
 - long duration;: This line declares a long integer variable duration to store the duration of the pulse from the ultrasonic sensor.
 - int distance;: This line declares an integer variable distance to store the calculated distance from the ultrasonic sensor.
 - void setup() { ... }: This function runs once when the Arduino board is powered on or reset. It initializes the servo, LCD, and sets the pin modes.
 - void loop() { ... }: This function runs repeatedly as long as the Arduino is powered on. It controls the servo motor's movement, reads the distance using the ultrasonic sensor, and displays the distance on the LCD.
      
#### The loop() function:

    Sets the servo angle based on the servoAngle variable.
    Increments or decrements the servoAngle based on the direction variable.
    Reverses the direction (direction *= -1) when the servo angle reaches the limits (10 or 170).
    Delays for refreshDelay milliseconds.
    Triggers the ultrasonic sensor to measure distance.
    Calculates the distance using the duration of the pulse.
    Prints the distance on the LCD screen along with the string "Distance: " and the unit "cm".


