#include "CameraController.h"

CameraController::CameraController(int cameraPin, ControllerInput* controller) :
	ControllableElement(controller) {

	this->cameraPin = cameraPin;
	recording = true;

	pinMode(cameraPin, OUTPUT);
}

void CameraController::update() {
}

void CameraController::onDriveModeChange(Rover::DriveMode prevMode, Rover::DriveMode newMode) {
	if (newMode == Rover::DriveMode::IDLE_MODE && recording) {
		recording = false;
		digitalWrite(cameraPin, HIGH);
		delay(500);
		digitalWrite(cameraPin, LOW);
	} else if (newMode == Rover::DriveMode::DRIVING_MODE && prevMode == Rover::IDLE_MODE && !recording) {
		recording = true;
		digitalWrite(cameraPin, HIGH);
		delay(500);
		digitalWrite(cameraPin, LOW);
	}
}

bool CameraController::isRecording() {
	return recording;
}