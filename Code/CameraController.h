#pragma once
#include "ControllableElement.h"
#include "RoverListener.h"

class CameraController : public ControllableElement, public RoverListener {

private:
	int cameraPin;
	bool recording;

public:
	CameraController(int cameraPin, ControllerInput* controller);
	void update() override;
    bool isRecording();
    void onDriveModeChange(Rover::DriveMode prevMode, Rover::DriveMode newMode) override;
};