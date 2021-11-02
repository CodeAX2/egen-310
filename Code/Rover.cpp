#include "Rover.h"
#include "ControllableElement.h"
#include "RoverListener.h"

Rover::Rover(ControllerInput* input, int modeInputChannel) {
	numControllers = 0;
	numListeners = 0;

	mode = DriveMode::IDLE_MODE;
	this->input = input;
	this->modeInputChannel = modeInputChannel;
}

void Rover::update() {

	int modeInput = input->getChannel(modeInputChannel);

	DriveMode newMode = DriveMode::IDLE_MODE;

	if (modeInput <= 1300) {
		newMode = DriveMode::IDLE_MODE;
	} else if (modeInput <= 1700) {
		newMode = DriveMode::DRIVING_MODE;
	} else {
		newMode = DriveMode::WINCH_MODE;
	}

	if (newMode != mode) {
		for (int i = 0; i < numListeners; i++) {
			listeners[i]->onDriveModeChange(mode, newMode);
		}
		mode = newMode;
	}

	for (int i = 0; i < numControllers; i++) {
		controllers[i]->update();
	}
}

Rover::DriveMode Rover::getCurrentDriveMode() {
	return mode;
}

void Rover::registerListener(RoverListener* listener) {
	if (numListeners < MAX_LISTENERS) {
		listeners[numListeners] = listener;
		numListeners++;
	}
}

void Rover::deregisterListener(RoverListener* listener) {

	bool removedItem = false;
	for (int i = 0; i < numListeners; i++) {
		if (removedItem && i < numListeners - 1) {
			listeners[i] = listeners[i + 1];
		} else if (listeners[i] == listener) {
			listeners[i] = nullptr;
			removedItem = true;
		}
	}
	numListeners--;
}

void Rover::addController(ControllableElement* controller) {
	if (numControllers < MAX_CONTROLLERS) {
		controllers[numControllers] = controller;
		controller->setRover(this);
		numControllers++;
	}
}