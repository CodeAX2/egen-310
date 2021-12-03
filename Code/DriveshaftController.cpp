#include "DriveshaftController.h"

int DriveshaftController::MID_VALUE = 1480;
int DriveshaftController::RANGE_VALUE = 100;
int DriveshaftController::CUTOFF_VALUE = 25;
int DriveshaftController::MIN_VALUE = 1000;
int DriveshaftController::MAX_VALUE = 2000;

DriveshaftController::DriveshaftController(int escSignalPin, int driveshaftInputChannel, ControllerInput* input) :
	ControllableElement(input) {
	this->escSignalPin = escSignalPin;
	this->driveshaftInputChannel = driveshaftInputChannel;

	// Initialize the esc
	esc.attach(escSignalPin, MIN_VALUE, MAX_VALUE);

	// Write the MID_VALUE to arm the esc (assuming bi-directional)
	esc.writeMicroseconds(MID_VALUE);
}

void DriveshaftController::update() {
	if (rover->getCurrentDriveMode() == Rover::DriveMode::DRIVING_MODE) {
		int inputVal = input->getChannel(driveshaftInputChannel);

		// Clamp to mid value if within cutoff
		if (abs(inputVal - MID_VALUE) <= CUTOFF_VALUE) inputVal = MID_VALUE;

		// Avoid sudden jump when leaving cutoff
		if (inputVal < MID_VALUE - CUTOFF_VALUE) {
			inputVal += CUTOFF_VALUE;
		} else if (inputVal > MID_VALUE + CUTOFF_VALUE) {
			inputVal -= CUTOFF_VALUE;
		}

		// Scale the max
		if (inputVal > MID_VALUE)
			inputVal = (inputVal - MID_VALUE) / (((double)MAX_VALUE - MID_VALUE) / RANGE_VALUE) + MID_VALUE;
		else
			inputVal = MID_VALUE - (MID_VALUE - inputVal) / (((double)MAX_VALUE - MID_VALUE) / RANGE_VALUE);

		esc.writeMicroseconds(inputVal);
	} else {
		// Not in drive mode, so just write MID_VALUE
		esc.writeMicroseconds(MID_VALUE);
	}
}