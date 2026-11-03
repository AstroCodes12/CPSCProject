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

class Actions : public Command {
private:
    Action actionType;
public:
    Actions(string d, int p, Action a) : actionType(a), Command(d, p){};
    void update_action(Action);
};
#endif