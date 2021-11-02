#include "DriveshaftController.h"

DriveshaftController::DriveshaftController(int escSignalPin, int driveshaftInputChannel, ControllerInput* input) :
	ControllableElement(input) {
	this->escSignalPin = escSignalPin;
	this->driveshaftInputChannel = driveshaftInputChannel;

	esc.attach(escSignalPin);
}

void DriveshaftController::update() {
	//Serial.println(input->getChannel(driveshaftInputChannel));
	if (rover->getCurrentDriveMode() == Rover::DriveMode::DRIVING_MODE) {
		esc.writeMicroseconds(input->getChannel(driveshaftInputChannel));
	}
}