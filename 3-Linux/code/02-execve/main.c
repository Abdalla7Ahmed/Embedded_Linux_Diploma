#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
//int execve(const char *pathname, char *const argv[],char *const envp[]);
//execve() executes the program referred to by pathname.
//pathname must be either a binary executable,
/*
        argv  is  an  array of pointers to strings passed to the new program as
       its command-line arguments.  By convention, the first of these  strings
       (i.e.,  argv[0])  should  contain the filename associated with the file
       being executed.  The argv array must be terminated by a  NULL  pointer.
       (Thus, in the new program, argv[argc] will be NULL.)
*/

/*
        envp  is  an  array  of pointers to strings, conventionally of the form
       key=value, which are passed as the environment of the new program.  The
       envp array must be terminated by a NULL pointer.
*/

int main(int argc, char **argv)
{

    char *cmd = "/usr/bin/sleep";  //pathname
    char *args[] = {cmd,"2000",NULL}; //command-line arguments
    char *envp[] = {NULL}; // the environment of the new program (optional)

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
        printf("Child process:PID=%d , PPID=%d , GPID=%d\n", getpid(),getppid(),getgid() );
        execve(cmd,args,envp);
        //execve() does not return on success,
        perror("execution failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Parent process:PID=%d , PPID=%d , GPID=%d , ChildID=%d\n", getpid(),getppid(),getgid(),child_pid );  
        // this code is executed by the parent process
        int status;
        waitpid(child_pid,&status,0);
        printf("the status is %d\n",status);
    }
    return 0;
}