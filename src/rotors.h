/*
This file holds the definitions for the rotor commands
*/
#ifndef ROTORS_H
#define ROTORS_H
#include "abstract.h"

//Rotor Enum
enum class Rotor{
    //By default, the underlying type is int
    Rotor1, //0
    Rotor2, //1
    Rotor3, //2
    Rotor4, //3
    All
};

//Rotor Child Class
// Child of Command Class
class RotorCommand : public Command {
    private:
     Rotor rotorID;
    public:
     RotorCommand(string d, int p, Rotor r) : Command(d, p), rotorID(r){};
     RotorCommand();
     void update_rotorID(Rotor rotorID);
};



#endif