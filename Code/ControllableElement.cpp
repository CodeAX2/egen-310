#include "ControllableElement.h"

ControllableElement::ControllableElement(ControllerInput* input) {
	this->input = input;
}

void ControllableElement::setRover(Rover* rover) {
	this->rover = rover;
}