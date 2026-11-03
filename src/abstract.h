
/*
This file holds the abstract command class definition
*/
#include <iostream>
using namespace std;

class Command {
    private:
     int id;
     string description;
     int timeStep;
    public:
     int priority;
     Command(int i, string d, int p) : id(i), description(d), priority(p){};
     int get_id();
     string get_description();
     int get_timestep();
     friend ostream& operator<<(ostream&, Command);
};
