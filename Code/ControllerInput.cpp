#include "ControllerInput.h"

ControllerInput::ControllerInput() {

	// Uses pins 6,9,10,11 for input
	pinMode(9, INPUT);
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(6, INPUT);
}

int ControllerInput::getChannel(int channelID) {

	// Get the value for a given channel

	switch (channelID) {
	case 1:
		return pulseIn(6, HIGH);
	case 2:
		return pulseIn(9, HIGH);
	case 5:
		return pulseIn(10, HIGH);
	case 6:
		return pulseIn(11, HIGH);
	}

	return 0;
}