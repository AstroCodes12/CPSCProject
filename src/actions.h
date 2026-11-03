/*
this file holds the definitions of the actions command class
*/
#ifndef ACTIONS_H
#define ACTIONS_H
#include "abstract.h"


enum class Action {
    TAKE_OFF,
    LAND,
    FLIP,
    SPIN_360,
    TURN_AROUND
};

class ActionCommand : public Command {
private:
    Action actionType;
public:
    ActionCommand(string d, int p, Action a) : Command(d, p), actionType(a){};
    ActionCommand();
    void update_action(Action);
};
#endif