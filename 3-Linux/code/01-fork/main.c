#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    // fork()  creates  a new process by duplicating the calling process.
    // The child has its own unique process ID,
    pid_t  child_pid;
    child_pid = fork();
    if(child_pid < 0 )
    {
        // Error occurred while creating child process
        fprintf(stderr,"Fork failed: \n");
        exit(EXIT_FAILURE);
    } 
    else if (child_pid == 0)
    {
        // this code is executed by the child process
        while(1)
        {
            printf("Child process:PID=%d , PPID=%d , GPID=%d\n", getpid(),getppid(),getgid() );
            sleep(5);
        }
    }
    else
    {
        // this code is executed by the parent process
        while(1)
        {
            printf("Parent process:PID=%d , PPID=%d , GPID=%d , ChildID=%d\n", getpid(),getppid(),getgid(),child_pid );  
            printf("==================================\n");

            sleep(5);

        }
    }
    return 0;
}