#pragma once

#include "ControllerInput.h"
#include "Rover.h"

// Represents an element of the rover that can be controlled and is updated every tick
class ControllableElement {
	
protected:
	ControllerInput* input;
	Rover* rover;

public:
	virtual void update();

	ControllableElement(ControllerInput* input);
	void setRover(Rover* rover);
};