#include <Arduino.h>

#define DECALAGE 20

void setup();
void loop();

void setup() {
	Serial.begin(9600);
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
				Serial.print("#s!");
				break;
		}
	}

}
