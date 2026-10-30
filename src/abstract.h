
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
     string priority;
     string get_id();
     string get_description();
     friend ostream& operator<<(ostream&, Command);
};
