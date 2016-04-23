#include <Arduino.h>
#include <AFMotor.h>

void setup();
void loop();

AF_DCMotor motor(2, MOTOR12_2KHZ);
int rightMotor = 6;
int leftMotor = 7;

void setup() {
	Serial.begin(9600);
	motor.setSpeed(200);

}

void loop() {
    motor.run(FORWARD);
	delay(500);
	motor.run(BACKWARD);
}
