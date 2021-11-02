#include "LightController.h"

LightController::LightController(int ledPin, int lightInputChannel, ControllerInput* controller) :
	ControllableElement(controller) {

	this->ledPin = ledPin;
	this->lightInputChannel = lightInputChannel;

	pinMode(ledPin, OUTPUT);

}

void LightController::update() {
	int value = input->getChannel(lightInputChannel);
	if (value >= 1500) {
		digitalWrite(ledPin, HIGH);
	} else {
		digitalWrite(ledPin, LOW);
	}
}