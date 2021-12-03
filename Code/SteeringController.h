#pragma once
#include "ControllableElement.h"
#include <Servo.h>

// Represents the steering of a rover
class SteeringController : public ControllableElement {

private:
	// The pin to write the steering to
	int servoSignalPin;

	// The channel to listen for steering input on
	int steeringInputChannel;

	// The actual servo connection to write to
    Servo steeringServo;

public:
	// Creates a new steering controller that listens on a given input channel for
	// a controller, and updates the servo connected to the output signal pin
	SteeringController(int servoSignalPin, int steeringInputChannel, ControllerInput* controller);
	
	// Updates the steering, called every tick
	void update() override;
};