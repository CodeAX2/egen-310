#pragma once

#include <PPMReader.h>

class ControllerInput {

private:
	int numChannels;
	int inputPin;
    PPMReader* reader;

public:
	ControllerInput(int numChannels, int inputPin);

	int getChannel(int channelID);
};