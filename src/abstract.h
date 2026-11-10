/*
This file holds the abstract command class definition
*/
#ifndef ABSTRACT_H
#define ABSTRACT_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Command {
    private:
     string description;
     int timeStep;
    public:
     int priority;
     Command(string d, int t, int p) : description(d), timeStep(t), priority(p){};
     Command();
     
     string get_description();
     int get_timestep();
     friend ostream& operator<<(ostream&, const Command&);
     friend bool operator==(const Command&, const Command&);
};

void create(vector<Command>&);
void send(vector<Command>&, const Command&);

struct priority{
    bool operator()(const Command& c1,const Command& c2)const;
};

#endif