/*
This is where all of the functions for the commands will be implemented
*/

#include "rotors.h"
#include "actions.h"
#include "camera.h"
#include "abstract.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*----------Rotor Commands------------*/
RotorCommand::RotorCommand() : Command() {
    string inTemp;
    cout << "(1) Rotor 1\n(2) Rotor 2\n(3) Rotor 3\n(4) Rotor 4\n(5) All Rotors\n" << "Which Rotor is this command for: \n";
    cin >> inTemp;
    if (stoi(inTemp) - 1 <= 4 && stoi(inTemp) - 1 >= 0) {
        rotorID = static_cast<Rotor>(stoi(inTemp) - 1);
    }
}
void RotorCommand::update_rotorID(Rotor rotorID) {
    this->rotorID = rotorID;
}

/*----------Action Commands------------*/
ActionCommand::ActionCommand() : Command(){
    string inTemp;
    cout << "(1) Take Off\n(2) Land\n(3) Flip\n(4) Spin 360\n(5) Spin 180\n" << "What action would you like to use: \n";
    cin >> inTemp;
    if (stoi(inTemp) - 1 <= 4 && stoi(inTemp) - 1 >= 0) {
        actionType = static_cast<Action>(stoi(inTemp) - 1);
    }
}

void ActionCommand::update_action(Action a) {
    actionType = a;
}

/*----------Camera Commands------------*/
CameraCommand::CameraCommand() : Command() {
    string inTemp;
    cout << "(1) Turn On\n(2) Infrared Mode\n(3) RGB Mode\n(4) Grayscale Mode\n(5) Turn Off\n" << "What Camera function would you like to use: \n";
    cin >> inTemp;
    if (stoi(inTemp) - 1 <= 4 && stoi(inTemp) - 1 >= 0) {
        mode = static_cast<CameraMode>(stoi(inTemp) - 1);
    }
}
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

Command::Command() {
    cout << "Describe the Command in 1-2 words (e.g. Initialize Camera): \n";
        cin >> description;
        
        cout << "Now set the priority 1-10 (1 being most important): \n";
        cin >> priority;
        if (!cin) {
            cin.ignore(INT_MAX, '\n');
            cin.clear();
            throw(string("Invalid Priority"));
        }

        cout << "How long will this take (estimate in seconds): \n";
        cin >> timeStep;
        if (!cin) {
            cin.ignore(INT_MAX, '\n');
            cin.clear();
            throw(string("Invalid Timestep"));
        }
}


/*------------General Functions------------*/
void create(vector<Command>& cmdHeap) {
    string userIn;
    cout << "(1) General\n(2) Rotor\n(3) Action\n(4) Camera\n Which Command Type: ";
    cin >> userIn;
    if (stoi(userIn) == 1){
        cmdHeap.push_back(Command());
    } else if (stoi(userIn) == 2) {
        cmdHeap.push_back(RotorCommand());
    } else if(stoi(userIn) == 3) {
        cmdHeap.push_back(ActionCommand());
    } else if (stoi(userIn) == 4) {
        cmdHeap.push_back(CameraCommand());
    } else {
        throw(string("Invalid Command Type"));
    }
    push_heap(cmdHeap.begin(), cmdHeap.end()); //O(logn)

}

void send(vector<Command>& cmdHeap, Command cmd) {
    cmdHeap.push_back(cmd);
    push_heap(cmdHeap.begin(), cmdHeap.end()); //time complexity of O(logn)
}