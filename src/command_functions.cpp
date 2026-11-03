/*
This is where all of the functions for the commands will be implemented
*/

#include "rotors.h"
#include "actions.h"
#include "camera.h"
#include "abstract.h"
#include <iostream>
using namespace std;


/*----------Rotor Commands------------*/
void RotorCommand::update_rotorID(Rotor rotorID) {
    this->rotorID = rotorID;
}
/*----------Action Commands------------*/

/*----------Camera Commands------------*/

/*----------Abstract Commands------------*/
string Command::get_description(){
    return description;
}

int Command::get_timestep(){
    return timeStep;
}

ostream& operator<<(ostream& os, Command c) {
    os << " | Description: " << c.description << " | TimeStep: " << c.timeStep << " | Priority: " << c.priority << endl;
    return os;
}