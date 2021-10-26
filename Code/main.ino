#include <PPMReader.h>
#include <Servo.h>

Servo servo;

void setup() {
	servo.attach(3);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(8, OUTPUT);
}

void loop() {
	int ch1 = pulseIn(5, HIGH);
	int ch2 = pulseIn(6, HIGH);
	servo.writeMicroseconds(ch1);
	if (ch2 >= 1500) {
		digitalWrite(8, HIGH);
	} else {
		digitalWrite(8, LOW);
	}
}