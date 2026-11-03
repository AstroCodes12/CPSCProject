/*
This is the main file that will be called
*/
#include "abstract.h"
#include "command_functions.cpp"
#include <vector>
#include <thread>

bool shouldEnd = false;


/* TODO:
* Command Page Function
*   Prints all the commands in the schedule loop
*   Prompts to enter create or send (explain how to enter correctly)
*/

void cmd_page() {
    cout << "********** COMMAND DASHBOARD **********" << endl;
    cout << endl;
    cout << "Clock: " << clock() << endl;
    cout << "Command Queue:" << endl;
    
}

/*
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
    }
}


int main() {
    //Threading
    vector<thread> threads;
    threads.push_back(thread(schedule_loop));
    threads.push_back(thread(display_loop)); // We could do this in this main but it might be easier in it's own function

    // Data Structures
    //C++ has some standard libs for heaps (std::priority_queue)

    /* 
    * Command Heap (main strucutre)
    *   Should be a priority queue heap
    * 
    * New Command Heap
    *   Priority Queue Heap
    *   Allows each thread to run asynchronously
    * 
    * Available Command Hash Table
    *   Table of all available commands. Organized by ID
    * 
    * 
    */

    /*
    * Note:
    *   Could be reduced to one heap if display loop is responsible for insterting and sorting
    *   however this could cause issues with schedule loop because they are asynchronous
    */

    // shouldEnd can change when a end command is input.
    while (!shouldEnd) {
    }
    // After end attach all threads back to main
    for (auto& thread : threads) {
        thread.join();
    }
    // After end
}