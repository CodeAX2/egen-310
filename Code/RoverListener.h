#pragma once
#include "Rover.h"

// Represents an object that listens to a Rover
class RoverListener {

public:
    // Called whenever the drive mode of the rover changes
    virtual void onDriveModeChange(Rover::DriveMode prevMode, Rover::DriveMode newMode);

};