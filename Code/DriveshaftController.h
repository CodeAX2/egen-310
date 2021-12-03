#pragma once

#include "ControllableElement.h"
#include <Servo.h>

// Represents the controller for the Driveshaft of the rover
class DriveshaftController : public ControllableElement {

private:
	// Output pin for writing to the esc
	int escSignalPin;

	// Channel to read for input on the driveshaft
	int driveshaftInputChannel;

	// The actual esc controller
	Servo esc;

	// Represents the mid value of an ESC
	static int MID_VALUE;

	// Represents the range to use for an esc
	static int RANGE_VALUE;

	// Represents the cutoff value that determines what values just clamp back to MID_VALUE
	static int CUTOFF_VALUE;

	// The minimum value that can be sent to an esc
	static int MIN_VALUE;

	// The maximum value that can be sent to an esc
	static int MAX_VALUE;

public:
	// Creates a new driveshaft controller that reads in data 
	// from the input channel on the given input, and writes to the specified esc pin
	DriveshaftController(int escSignalPin, int driveshaftInputChannel, ControllerInput* input);

	// Called every tick to update the controller
	void update() override;
};