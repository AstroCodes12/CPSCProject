/*
This is the main file that will be called
*/
#include "abstract.h"
#include "command_functions.cpp"
#include <vector>
#include <thread>

bool shouldEnd = false;

void display_loop() {
    while (true) {
        /*
        * If commands in heap: 
        *   print command page (make function to do this)
        * If no commands in heap: 
        *   prompt to enter command (make function to do this)
        *   Note: enter command waits for user so its not printing infinitly
        *   put user input into new Command queue
        * 
        * If is terminate command
        *   terminate
        * If is not terminate
        *    display command page
        *    prompt to enter command
        */

        /*
        * Notes: 
        */
    }
}

void schedule_loop() {
    while (true) {
        /*
        * If heap is empty:
        *  If new command:
        *      insert into heap
        *      run Heap sort function (might be built into c++ std lib)
        *      return to top
        *  If no new command, return to top
        */

        /*If heap is not empty:
        *  Run command on top of heap
        *  If is terminate
        *      terminate
        *  else
        *      add to logs.
        *  
        *  If new command:
        *      add to heap
        *      run heap sort
        *       return to top
        *  else:
        *      return to top
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
    * New Command heap:
    *   Should be priority heap too
    *   allows multiple new commands to be entered 
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