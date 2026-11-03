/*
this file holds the definition of the camera command class
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "abstract.h"
using namespace std;



enum class CameraMode {
    ON,
    INFRARED,
    RGB,
    GRAYSCALE,
    OFF
};

class CameraCommand : public Command {
    private:
        CameraMode mode;
    public:
        CameraCommand(string d, int p, CameraMode c) : Command(d, p), mode(c){};
        CameraCommand();
};

#endif