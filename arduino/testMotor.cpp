#include <Arduino.h>
#include <Wire.h>


void setup();
void loop();

int rightMotor = 6;
int leftMotor = 7;

void setup() {
        pinMode(leftMotor, OUTPUT);
        pinMode(rightMotor, OUTPUT);
}

void loop() {
        digitalWrite(leftMotor, HIGH);
        digitalWrite(rightMotor, HIGH);
        delay(100);
        digitalWrite(rightMotor, LOW);
        delay(100);
}
