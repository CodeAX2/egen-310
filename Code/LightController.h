#pragma once
#include "ControllableElement.h"

// Represents a controller for turning on and off lights
class LightController : public ControllableElement {

private:
	int ledPin;
	int lightInputChannel;

public:
	// Creates a new light controller that recieves input from a controller on 
	// the specified channel, and writes to a given output pin 
	LightController(int ledPin, int lightInputChannel, ControllerInput* controller);

	// Updates the controller every tick
	void update() override;
};