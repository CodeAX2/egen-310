#include "ControllerInput.h"

ControllerInput::ControllerInput(int numChannels, int inputPin) {

	this->numChannels = numChannels;
	this->inputPin = inputPin;

	this->reader = new PPMReader(inputPin, numChannels);

	pinMode(9, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
}

int ControllerInput::getChannel(int channelID) {
	switch (channelID) {
	case 2:
		return pulseIn(9, HIGH);
	case 5:
		return pulseIn(10, HIGH);
	case 6:
		return pulseIn(11, HIGH);
	}
	//reader->rawChannelValue(channelID);
	// TODO: Change to work with PPM
	return 0;
}