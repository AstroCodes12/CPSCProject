/*
This is where all of the functions for the commands will be implemented
*/

#include "rotors.h"
#include "actions.h"
#include "camera.h"

#include "abstract.h"



/*----------Rotor Commands------------*/
RotorCommand::RotorCommand() : Command() {
    int inTemp;
    bool pass = false;
    cout << "(1) Rotor 1\n(2) Rotor 2\n(3) Rotor 3\n(4) Rotor 4\n(5) All Rotors\n" << "Which Rotor is this command for: \n";
    while(!pass){
        cin >> inTemp;
        if (!cin) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');\
            inTemp = -1;
        }
        
        if (inTemp - 1 <= 4 && inTemp - 1 >= 0) {
            rotorID = static_cast<Rotor>(inTemp - 1);
            pass = true;
        } else {
            cout << "Invalid Rotor, try 1-5: \n";
        }
    }
}

void RotorCommand::update_rotorID(Rotor rotorID) {
    this->rotorID = rotorID;
}

/*----------Action Commands------------*/
ActionCommand::ActionCommand() : Command(){
    int inTemp;
    bool pass = false;
    cout << "(1) Take Off\n(2) Land\n(3) Flip\n(4) Spin 360\n(5) Spin 180\n" << "What action would you like to use: \n";
    while (!pass){
        cin >> inTemp;
        if (!cin) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');\
            inTemp = -1;
        }
        if (inTemp - 1 <= 4 && inTemp - 1 >= 0) {
            actionType = static_cast<Action>(inTemp - 1);
            pass = true;
        } else {
            cout << "Invalid Action, try 1-5: ";
        }
    }
}

void ActionCommand::update_action(Action a) {
    actionType = a;
}

/*----------Camera Commands------------*/
CameraCommand::CameraCommand() : Command() {
    int inTemp;
    float inAperture;
    bool pass = false;
    cout << "(1) Turn On\n(2) Infrared Mode\n(3) RGB Mode\n(4) Grayscale Mode\n(5) Turn Off\n" << "What Camera function would you like to use: \n";
    while (!pass) {
        cin >> inTemp;
        if (!cin) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');\
            inTemp = -1;
        }
        if (inTemp - 1 <= 4 && inTemp - 1 >= 0) {
            mode = static_cast<CameraMode>(inTemp - 1);
            pass = true;
        } else {
            cout << "Invalid Input, try 1-5: ";
        }
    }

    inTemp = 0;
    cout << "What Focal Length should the lens be at (18-250): ";
    cin >> inTemp;
    while(!cin || inTemp > 250 || inTemp < 18) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Not a valid number, try 18-250: ";
        cin >> inTemp;
    }

    cout << "What Aperature should the lense be set to: (1.2 - 22.0): ";
    cin >> inAperture;
    while(!cin || inAperture < 1.2 || inAperture > 22.0) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid Aperature, try 1.2-22.0: ";
        cin >> inAperture;
    }

    camlens = new Lens(inTemp, inAperture);
}

/*----------Abstract Commands------------*/
string Command::get_description(){
    return description;
}

int Command::get_timestep(){
    return timeStep;
}

ostream& operator<<(ostream& os, const Command& c) {
    os << " | Description: ";
    os.width(18);
    os << left << c.description;
    os << " | TimeStep: ";
    os.width(3);
    os << c.timeStep;
    os << " | Priority: ";
    os.width(2);
    os << c.priority;
    return os;
}

bool operator==(const Command& c1, const Command& c2){
    if (c1.description == c2.description && c1.priority == c2.priority && c1.timeStep == c2.timeStep) {
        return true;
    } else {
        return false;
    }
}

Command::Command() {
    bool pass = false;
    cout << "Describe the Command in 1-2 words (e.g. Initialize Camera): \n";
        cin.ignore(INT_MAX, '\n');
        getline(cin, description);
        
        cout << "Now set the priority 1-10 (1 being most important): \n";

        while(!pass) {
            cin >> priority;
            if (!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                priority = 11;
            }
            if (priority >= 0 && priority <= 10) {
                pass = true;
            } else {
                cout << "Invalid priority, try again 1-10: ";
            }
        }
        pass = false;

        cout << "How long will this take (estimate in seconds > 0): \n";
        while (!pass) {
            cin >> timeStep;
            if (!cin) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                timeStep = -1;
            }
            if (timeStep > 0) {
                pass = true;
            } else {
                cout << "Invalid Time, try again with a value greater than 0: ";
            }
        }
}


/*------------General Functions------------*/

bool priority::operator()(const Command& c1,const Command& c2) const{
    return c1.priority>c2.priority;
}

void create(vector<Command>& cmdHeap) {
    int userIn;
    cout << "(1) General\n(2) Rotor\n(3) Action\n(4) Camera\n Which Command Type: ";
    cin >> userIn;
    while (!cin || userIn < 1 || userIn > 4) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid Command, Try again with number 1-4: ";
        cin >> userIn;
    }
    switch (userIn) {
        case 1:
            cmdHeap.push_back(Command());
            break;
        case 2:
            cmdHeap.push_back(RotorCommand());
            break;
        case 3:
            cmdHeap.push_back(ActionCommand());
            break;
        case 4:
            cmdHeap.push_back(CameraCommand());
            break;
        default:
            cout << "How did this happen";
            exit(1);
    }
    push_heap(cmdHeap.begin(), cmdHeap.end(), priority()); //O(logn)
}

void send(vector<Command>& cmdHeap, const Command& cmd) {
    cmdHeap.push_back(cmd);
    push_heap(cmdHeap.begin(), cmdHeap.end(), priority()); //time complexity of O(logn)
}