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

class Camera {
    private:
        CameraMode mode;
    public:
        Camera(){
            mode = CameraMode::OFF;
        }
};

#endif