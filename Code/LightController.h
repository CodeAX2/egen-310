#pragma once
#include "ControllableElement.h"

class LightController : public ControllableElement {

private:
	int ledPin;
	int lightInputChannel;

public:
	LightController(int ledPin, int lightInputChannel, ControllerInput* controller);
	void update() override;
};