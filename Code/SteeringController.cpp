#include "SteeringController.h"

SteeringController::SteeringController(int servoSignalPin, int steeringInputChannel, ControllerInput* controller) :
	ControllableElement(controller) {
	this->servoSignalPin = servoSignalPin;
	this->steeringInputChannel = steeringInputChannel;

	steeringServo.attach(servoSignalPin);
}

void SteeringController::update() {
	// Check that we are in driving mode
	if (rover->getCurrentDriveMode() == Rover::DriveMode::DRIVING_MODE) {
		int inputVal = input->getChannel(steeringInputChannel);
		steeringServo.writeMicroseconds(inputVal);
	}
}