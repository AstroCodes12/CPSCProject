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

class Lens {
    private:
     int focalLength;
     float aperature;
    public: 
     Lens(int fl = 18, float ap = 1.2) : focalLength(fl), aperature(ap){};
     ~Lens() {
        cout << "Lens removed\n";
     }
};

class CameraCommand : public Command {
    private:
        CameraMode mode;
        Lens* camlens;
    public:
        CameraCommand(string d, int t, int p, CameraMode c) : Command(d, t, p), mode(c){};
        CameraCommand();
};


#endif