#include "DriveshaftController.h"
#include "LightController.h"
#include "Rover.h"

Rover* rover;
ControllerInput* input;

void setup() {

	input = new ControllerInput(6, 3);
	rover = new Rover(input, 6);

	rover->addController(new DriveshaftController(5, 2, input));
	rover->addController(new LightController(4, 5, input));
	Serial.begin(9600);
}

void loop() {
	rover->update();
}