#pragma once

#include "ControllerInput.h"

class ControllableElement;
class RoverListener;

// Represents the Rover and all of its components
class Rover {

public:
	// Represents the maximum number of controllable elements, 
	// and the maximum number of listeners
	const static int MAX_CONTROLLERS = 10;
	const static int MAX_LISTENERS = 10;

	// Represents the possible drive modes of the rover
	enum DriveMode {
		IDLE_MODE,
		DRIVING_MODE,
		WINCH_MODE
	};

private:
	// Keeps track of the controllable elements of the rover
	ControllableElement* controllers[MAX_CONTROLLERS];
    int numControllers;

	// Keeps track of the objects to notify on rover changes
	RoverListener* listeners[MAX_LISTENERS];
    int numListeners;

	// The current drive mode of the rover
	DriveMode mode;

	// The reciever input the rover is listening to
	ControllerInput* input;
	int modeInputChannel;

public:
	// Creates a new rover that listens to a reciever, 
	// and changes the drive mode based on the modeInputChannel
	Rover(ControllerInput* input, int modeInputChannel);

	// Updates the rover and all of its controllable elements
    void update();

	// Returns the current drive mode of the rover
    DriveMode getCurrentDriveMode();

	// Register a listener to be notified on a change of Drive Mode
    void registerListener(RoverListener* listener);

	// Deregister a registered listener
    void deregisterListener(RoverListener* listener);

	// Adds a controllable element to the rover
    void addController(ControllableElement* controller);

};