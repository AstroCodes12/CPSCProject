#include "command_functions.cpp"

#include <vector>


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


int main() {
        //-------Data Structures----------------------------------
    /* Command Heap (main structure)*/
    make_heap(data::cmdHeap.begin(), data::cmdHeap.end(), priority());
    
    /* New Command Heap*/
    make_heap(data::newCmdHeap.begin(), data::newCmdHeap.end(), priority());
    
    int index;
    create(data::newCmdHeap);
    cout << "Index: ";
    cin >> index;
    send(data::newCmdHeap, *data::cmd[1]);
    
}