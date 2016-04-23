#include <Arduino.h>

#define DECALAGE 80

void setup();
void loop();

void stop();
void forward();
void turnRight();
void turnLeft();

int rightMotor = 7;
int leftMotor = 6;

void stop(){
	digitalWrite(rightMotor, LOW);
	digitalWrite(leftMotor, LOW);
}

void forward(int time){
	int tempTime = 0;
	while(tempTime < time){
		digitalWrite(rightMotor, HIGH);
		digitalWrite(leftMotor, HIGH);
		delay(DECALAGE);
		digitalWrite(rightMotor, LOW);
		delay(DECALAGE);
		tempTime += 2*DECALAGE;
	}
	stop();
}

void turnRight(int time){
	digitalWrite(rightMotor, LOW);
	digitalWrite(leftMotor, HIGH);
	delay(time);
	stop();
}

void turnLeft(int time){
	digitalWrite(leftMotor, LOW);
        digitalWrite(rightMotor, HIGH);
        delay(time);
        stop();
}

void setup() {
        pinMode(leftMotor, OUTPUT);
        pinMode(rightMotor, OUTPUT);
}

void loop() {
        turnRight(1000);
	delay(500);
	turnLeft(1000);
	delay(500);
}
