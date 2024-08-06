#include "SocketHandler.hpp"
#include "execute.hpp"

int main()
{
    execute e;
    SocketHandler handle;

    std::string new_command;

    if (handle.createSocket() != 0)
        return 1;
    handle.Define_server_address();
    if (handle.bindSocket() != 0)
        return 1;
    if (handle.listenSocket() != 0)
        return 1;

    while (1)
    {
        std::string accepted_command = handle.accept_multiple_connections();
        if (accepted_command != new_command)
        {
            e.set_string(accepted_command);
            e.execute_command();
            new_command = accepted_command;
        }
        // pid_t child_pid;
        // child_pid = fork();
        // if (child_pid < 0)
        // {
        //     fprintf(stderr, "Fork failed: \n");
        //     exit(EXIT_FAILURE);
        // }
        // else if (child_pid == 0)
        // {
        //     // Child process
        //     std::string accepted_command = handle.accept_multiple_connections();
        //     if (accepted_command != new_command)
        //     {
        //         e.set_string(accepted_command);
        //         e.execute_command();
        //         new_command = accepted_command;
        //     }
        //     exit(0);
        // }
        // else
        // {
        //     // Parent process
        //     int status;
        //     waitpid(child_pid, &status, 0);
        // }
    }

    return 0;
}