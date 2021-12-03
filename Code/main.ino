#include "DriveshaftController.h"
#include "LightController.h"
#include "Rover.h"
#include "SteeringController.h"

Rover* rover;
ControllerInput* input;

void setup() {

	// Create the input handler and rover handler
	input = new ControllerInput();
	rover = new Rover(input, 6);

	rover->addController(new DriveshaftController(5, 2, input));
	rover->addController(new LightController(4, 5, input));
	rover->addController(new SteeringController(3, 1, input)); 

	Serial.begin(9600);  
}

void loop() {
	// Update all aspects of the rover
	rover->update();
}