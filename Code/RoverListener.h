#pragma once
#include "Rover.h"

class RoverListener {

public:
    virtual void onDriveModeChange(Rover::DriveMode prevMode, Rover::DriveMode newMode);

};