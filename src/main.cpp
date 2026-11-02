/*
This is the main file that will be called
*/
#include "abstract.h"
#include <vector>
#include <thread>

bool shouldEnd = false;

void schedule_loop() {
    while (true) {
        
    }
}

void display_loop() {
    while (true) {
        
    }
}

int main() {
    vector<thread> threads;
    threads.push_back(thread(schedule_loop));
    threads.push_back(thread(display_loop)); // We could do this in this main but it might be easier in it's own function

    // shouldEnd can change when a end command is input.
    while (!shouldEnd) {
    }
    // After end attach all threads back to main
    for (auto& thread : threads) {
        thread.join();
    }
    // After end
}