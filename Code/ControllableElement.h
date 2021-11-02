#pragma once

#include "ControllerInput.h"
#include "Rover.h"

class ControllableElement {
	
protected:
	ControllerInput* input;
	Rover* rover;

public:
	virtual void update();

	ControllableElement(ControllerInput* input);
	void setRover(Rover* rover);
};