#include <iostream>
#include <csignal>
#include <cstdlib>

// Signal handler function
void signalHandler(int signal) {
    if (signal == SIGINT) {
        std::cout << " ==> Signal " << signal << " received: Ctrl+C" << std::endl;
    } else if (signal == SIGTSTP) {
        std::cout << " ==> Signal " << signal << " received: Ctrl+Z" << std::endl;
    } else if (signal == SIGQUIT) {
        std::cout << " ==> Signal " << signal << " received: Ctrl+\\" << std::endl;
    }

    // Terminate the program
    exit(signal);
}

int main() {
    // Set up signal handlers for specific hotkey signals
    std::signal(SIGINT, signalHandler);  // Ctrl+C - SIGINT
    std::signal(SIGTSTP, signalHandler); // Ctrl+Z - SIGTSTP
    std::signal(SIGQUIT, signalHandler); // Ctrl+\ - SIGQUIT

    std::cout << "Running. PID: " << getpid() << std::endl;
    std::cout << "Press Ctrl+C, Ctrl+Z, or Ctrl+\\ to send signals to this process." << std::endl;


    // Infinite loop to keep the program running
    while (true) {
        // Do some work or just wait here
    }

    return 0;
}
