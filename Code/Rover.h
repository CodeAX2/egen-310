#pragma once

#include "ControllerInput.h"

class ControllableElement;
class RoverListener;

class Rover {

public:
	const static int MAX_CONTROLLERS = 10;
	const static int MAX_LISTENERS = 10;

	enum DriveMode {
		IDLE_MODE,
		DRIVING_MODE,
		WINCH_MODE
	};

private:
	ControllableElement* controllers[MAX_CONTROLLERS];
    int numControllers;
	RoverListener* listeners[MAX_LISTENERS];
    int numListeners;

	DriveMode mode;
	ControllerInput* input;
	int modeInputChannel;

public:
	Rover(ControllerInput* input, int modeInputChannel);

    void update();

    DriveMode getCurrentDriveMode();

    void registerListener(RoverListener* listener);
    void deregisterListener(RoverListener* listener);

    void addController(ControllableElement* controller);

};