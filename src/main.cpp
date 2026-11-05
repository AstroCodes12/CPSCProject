/*
This is the main file that will be called
*/
#include "abstract.h"
#include "rotors.h"
#include "command_functions.cpp"


#include <thread>
#include <fstream>

bool shouldEnd = false; // This bool will be used to signal the threads to end when a terminate command is sent

    //-------Data Structures----------------------------------
    /* Available Command Hash Table
    *  Table of all available commands. Vector index is used as command ID
    */
namespace data {
    
        Command Terminate = Command("Terminate", 1, 1);
        Command INIT = Command("Initialize", 1, 1);
        Command RotorINIT = RotorCommand("Init_Rotors", 2, 10, Rotor::All);
        Command ActionINIT = ActionCommand("Takeoff", 2, 10, Action::TAKE_OFF); 
        Command camINIT = CameraCommand("Camera_Init", 2, 10, CameraMode::ON);

    /* Command List*/
    vector<Command> commandList = {Terminate, INIT, RotorINIT, ActionINIT, camINIT};

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
    vector<Command> newCmdHeap = {commandList[1], commandList[2], commandList[3], commandList[4]};
}

/* TODO:
* Command Page Function
*   Prints all the commands in the schedule loop
*   Prompts to enter create or send (explain how to enter correctly)
*
* Terminate Function(?)
*   ends loop and closes threading
*/
void term_program() {
    cout << "Terminating program..." << endl;
    cout << "Program terminated." << endl;
    shouldEnd = true;
}

void cmd_page(const vector<Command> temp) {
    cout << "\n********** COMMAND DASHBOARD **********\n" << endl;
    cout << "\nCurrent Command Queue: \n" << endl;

    if (temp.empty()) {
        cout << "No commands in queue." << endl;
    } else {
        for (int i = 0; i < temp.size(); i++) {
            cout << i << " " << temp[i];
        }
    }

    cout << "\n************************************\n";

    cout << "1. Create Command\n";
    cout << "2. Send Command\n";
    cout << "3. Terminate Program\n";
    cout << "\nPlease enter your choice: ";

    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            // Call create command function
            create(data::commandList);
            break;
        case 2:
            int cmdChoice;
            // Call send command function
            cout << "\nAvailable Commands: \n";

            for (int i = 0; i < data::commandList.size(); i++) {
                cout << i << " " << data::commandList[i];
            }
            cout << "which command would you like to send: \n";
            cin >> cmdChoice;
            send(data::cmdHeap, data::commandList[cmdChoice]);
            break;
        case 3:
            term_program();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}


/*
* Add New Command Function(?)
*   Adds to both scheduler and display heaps
*/

/*
* Run Command Function (add to log)
*   Adds command to log
*   sleeps thread for timeStep % 10
*   Removes command from heap

* Create Command function
*   Walks user thru making a command (what type (child) of command, enter all variables)
*   Adds command to available command table
*/
void create_cmd() {
    
}

/*
* Send Command Function
*   Allows user to send existing Command with command name
*   Searches available commands
*   Adds command to new command heap
*   runs heap sort
*/

void send_cmd() {
    
}

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

        cmd_page(data::cmdHeap);

    }
}

// Logs the command that gets sent
const string LOG_FILE = "log.txt"; // we could change this based on an arg sent to main when run
// Logs the command that gets sent
void logCommand(Command sent) {
    ofstream log(LOG_FILE, ios::app);
    log << sent;
    log.close();
}

// This function will be used to combine both heaps into one
void combine_heaps() {
    for (int i = 0; i < data::newCmdHeap.size(); i++) {
        data::cmdHeap.push_back(data::newCmdHeap[i]);
    }
    make_heap(data::cmdHeap.begin(), data::cmdHeap.end(), priority());
}

void schedule_loop(vector<Command> &queue, vector<Command> &join_queue) {
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
        pop_heap(queue.begin(), queue.end(), priority());
        
        logCommand(toSend);
        if (toSend == data::Terminate) { // 0 = terminate
            shouldEnd = true;
            break;
        }
        send(data::newCmdHeap, toSend);
        _sleep(toSend.get_timestep() / 10); // from stdlib.h
    }
}



int main() {
    //Threading
    vector<thread> threads;
    threads.push_back(thread(schedule_loop));
    threads.push_back(thread(display_loop)); // We could do this in this main but it might be easier in it's own function

    //-------Data Structures----------------------------------
    //Command Heap (main structure)
    make_heap(data::cmdHeap.begin(), data::cmdHeap.end(), priority());
    
    //New Command Heap
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
