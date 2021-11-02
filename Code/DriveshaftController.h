#pragma once

#include "ControllableElement.h"
#include <Servo.h>

class DriveshaftController : public ControllableElement {

private:
	int escSignalPin;
	int driveshaftInputChannel;
    Servo esc;

public:
	DriveshaftController(int escSignalPin, int driveshaftInputChannel, ControllerInput* input);

	void update() override;
};