#pragma once
#include "ControllableElement.h"
#include <Servo.h>

class SteeringController : public ControllableElement {

private:
	int servoSignalPin;
	int steeringInputChannel;
    Servo steeringServo;

public:
	SteeringController(int servoSignalPin, int steeringInputChannel, ControllerInput* controller);
	void update() override;
};