#include <ESP32Servo.h>

const int servoPin = 23;     // Servo signal pin
const int rightButton = 1;   // Move to 180°
const int leftButton = 22;   // Move to 0°
Servo myServo;

int currentAngle = 90;

void setup() {
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  myServo.attach(servoPin);
  myServo.write(currentAngle); // Start at center
}

void loop() {
  if (digitalRead(rightButton) == LOW) {
    currentAngle = 180;
    myServo.write(currentAngle);
    delay(300); // debounce & movement delay
  }

  if (digitalRead(leftButton) == LOW) {
    currentAngle = 0;
    myServo.write(currentAngle);
    delay(300);
  }
}
