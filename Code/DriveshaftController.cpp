#include "DriveshaftController.h"

DriveshaftController::DriveshaftController(int escSignalPin, int driveshaftInputChannel, ControllerInput* input) :
	ControllableElement(input) {
	this->escSignalPin = escSignalPin;
	this->driveshaftInputChannel = driveshaftInputChannel;

	esc.attach(escSignalPin);
}

void DriveshaftController::update() {
	if (rover->getCurrentDriveMode() == Rover::DriveMode::DRIVING_MODE) {
		int inputVal = input->getChannel(driveshaftInputChannel);
		if (abs(inputVal - 1500) <= 30) inputVal = 1500;
		esc.writeMicroseconds(input->getChannel(driveshaftInputChannel));
	}
}