#pragma once

#include <PPMReader.h>

// Interfaces with PWM input from an RC Reciever
class ControllerInput {

public:
	//  Initializes a reciever
	ControllerInput();

	// Gets the last value of a given channel
	int getChannel(int channelID);
};