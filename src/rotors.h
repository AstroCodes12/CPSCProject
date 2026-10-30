/*
This file holds the definitions for the rotor commands
*/
#include <iostream>
using namespace std;
#include "abstract.h"

enum class Rotor{
    //By default, the underlying type is int
    Rotor1, //0
    Rotor2, //1
    Rotor3, //2
    Rotor4 //3
};

class RotorCommand : public Command {
    private:
     Rotor rotorID;
    public:
     void update_rotorID(Rotor rotorID);
};