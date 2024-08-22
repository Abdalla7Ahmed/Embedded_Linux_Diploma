#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/*
size_t strcspn(const char *s, const char *reject);
The strcspn() function returns the number of bytes in the initial segment of s which  are  not  in the string reject.
*/
#define MAX_INPUT_SIZE 100
char input[MAX_INPUT_SIZE];
int main(int argc, char **argv)
{
    while(1)
    {
        printf("SimpleShell:$ ");
        fgets(input, MAX_INPUT_SIZE,stdin);
        if(input[0] == '\n')
        {
            continue;
        }
        input[strcspn(input,"\n")] = '\0';
        if (strcmp(input,"exit") == 0 || strcmp(input,"quit") == 0 )
        {
            printf("Exiting shell ........\n");
            break;
        }

        pid_t  child_pid;
        child_pid = fork();
        if(child_pid < 0 )
        {
            fprintf(stderr,"Fork failed: \n");
            exit(EXIT_FAILURE);
        } 
        else if (child_pid == 0)
        {
            char *argc[] = {NULL};
            execvp(input,argc);
            perror("execution failed");
            exit(EXIT_FAILURE);
        }
        else
        {
            int status;
            waitpid(child_pid,&status,0);
        }

    }

    return 0;
}