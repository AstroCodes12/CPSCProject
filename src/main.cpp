/*
This is the main file that will be called
*/
#include "abstract.h"
#include "rotors.h"
#include "command_functions.cpp"

#include <vector>
#include <thread>
#include <algorithm>

bool shouldEnd = false;


/* TODO:
* Command Page Function
*   Prints all the commands in the schedule loop
*   Prompts to enter create or send (explain how to enter correctly)

* Add New Command Function(?)
*   Adds to both scheduler and display heaps

* Terminate Function(?)
*   ends loop and closes threading

* Run Command Function (add to log)
*   Adds command to log
*   sleeps thread for timeStep % 10
*   Removes command from heap

* Create Command function
*   Walks user thru making a command (what type (child) of command, enter all variables)
*   Adds command to available command table

* Send Command Function
*   Allows user to send existing Command with command name
*   Searches available commands
*   Adds command to new command heap
*   runs heap sort
*/

void display_loop() {
    while (true) {
        /*
        * 
        * print command page (make function to do this)
        * prompt to enter create or send (make function to do this)
        *   if create:
        *       run create
        *   if send:
        *       run send
        *   Note: enter command function waits for user so its not printing infinitly
        * 
        * return to top

        /*
        * Notes: 
        */
    }
}

vector<Command> queue = {};
vector<Command> join_queue = {};

    //-------Data Structures----------------------------------
    /* Available Command Hash Table
    *  Table of all available commands. Vector index is used as command ID
    */
namespace data {
    Command* cmd[] = {
        new Command("Terminate", 1),
        new Command("Initialize", 1),
        new RotorCommand("Init_Rotors", 2, Rotor::All),
        new ActionCommand("Takeoff", 2, Action::TAKE_OFF), 
        new CameraCommand("Camera_Init" ,2, CameraMode::ON)
    };

    /* Command Heap (main structure)
    *   min heap for scheduler thread
    *   root node will run. Schedule Thread will add all new commands from newCmdHeap to this
    */
    vector<Command> cmdHeap;
    
    /* New Command Heap
    *   min Heap for interface thread
    *   queues commands while schedule thread is running
    *   Allows each thread to run asynchronously
    */
    vector<Command> newCmdHeap = {*cmd[1], *cmd[2], *cmd[3], *cmd[4]};
}
// This function will be used to combine both heaps into one
void combine_heaps() {

}

// Logs the command that gets sent
const string LOG_FILE = "log.txt"; // we could change this based on an arg sent to main when run
void logCommand(Command sent) {

}

void sendCommand(Command toSend) {
    // Command Sent!
}

void schedule_loop() {
    while (true) {
        /*
        * If heap is empty:
        *   If new commands:
        *       add all new commands to schedule heap
        *       run heap sort
        *   return to top
        *
        * If heap is not empty:
        *   If is terminate
        *      terminate
        *   else
        *      add to logs
        *      sleep for timeStep % 10
        * 
        *  If new Commands:
        *       add all new commands to schedule heap
        *       run heap sort
        *  return to top
        */
        // check if there is/are new commands to be added
        if (!join_queue.empty()) {
            combine_heaps();
        }
        // if there are no commands restart the loop
        if (queue.empty()) {
            continue;
        }
        
        // Get and pop from the heap/queue
        Command toSend = queue.front();
        pop_heap(queue.begin(), queue.end());
        
        logCommand(toSend);
        if (toSend.get_id() == 0) { // 0 = terminate
            shouldEnd = true;
            break;
        }
        sendCommand(toSend);
        _sleep(toSend.get_timestep() / 10); // from stdlib.h
    }
}

struct priority{
    bool operator()(const Command& c1,const Command& c2) const{
        return c1.priority>c2.priority;
    }
};


int main() {
    //Threading
    vector<thread> threads;
    threads.push_back(thread(schedule_loop));
    threads.push_back(thread(display_loop)); // We could do this in this main but it might be easier in it's own function

    //-------Data Structures----------------------------------
    /* Command Heap (main structure)*/
    make_heap(data::cmdHeap.begin(), data::cmdHeap.end(), priority());
    
    /* New Command Heap*/
    make_heap(data::newCmdHeap.begin(), data::newCmdHeap.end(), priority());

    // shouldEnd can change when a end command is input.
    while (!shouldEnd) {
    }
    // After end attach all threads back to main
    for (auto& thread : threads) {
        thread.join();
    }
    // After end
}