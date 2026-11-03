/*
This file holds the abstract command class definition
*/
#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <iostream>
using namespace std;

class Command {
    private:
     string description;
     int timeStep;
    public:
     int priority;
     Command(string d, int p) : description(d), priority(p){};
     Command();
     
     string get_description();
     int get_timestep();
     friend ostream& operator<<(ostream&, Command);
};

#endif