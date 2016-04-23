#include <Arduino.h>

#define DECALAGE 20

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
	stop();
}

void forward(){
	digitalWrite(rightMotor, HIGH);
	digitalWrite(leftMotor, HIGH);
	delay(DECALAGE);
	digitalWrite(rightMotor, LOW);
	delay(DECALAGE);
	stop();
}

void turnRight(){
	digitalWrite(rightMotor, LOW);
	digitalWrite(leftMotor, HIGH);
	stop();
}

void turnLeft(){
	digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, HIGH);
	stop();
}

void setup() {
	Serial.begin(9600);
    pinMode(leftMotor, OUTPUT);
    pinMode(rightMotor, OUTPUT);
	stop();
}

void loop() {
	if(Serial.available()){
		char data = '\0';
		int i = 0;
		char car = '\0';
		do{
			car = Serial.read();
			if(car != '#' && car != '!'){
				data = car;
			}
		}while(Serial.available() && car != '!');

		switch(data){
			case 'i':
				Serial.write('#m!');
			case 's':
				stop();
				break;
			case 'f':
				forward();
				break;
			case 'r':
				turnRight();
				break;
			case 'l':
				turnLeft();
				break;
		}
	}

}
