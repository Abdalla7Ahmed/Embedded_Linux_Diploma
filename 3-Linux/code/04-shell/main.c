#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <libgen.h>

// task ==========================
// handle signals
//==========================
// Define macros for text color
#define ANSI_COLOR_BLACK     "\x1b[30m"
#define ANSI_COLOR_RED       "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_YELLOW    "\x1b[33m"
#define ANSI_COLOR_BLUE      "\x1b[34m"
#define ANSI_COLOR_MAGENTA   "\x1b[35m"
#define ANSI_COLOR_CYAN      "\x1b[36m"
#define ANSI_COLOR_WHITE     "\x1b[37m"

// Define macros for background color
#define ANSI_BG_BLACK     "\x1b[40m"
#define ANSI_BG_RED       "\x1b[41m"
#define ANSI_BG_GREEN     "\x1b[42m"
#define ANSI_BG_YELLOW    "\x1b[43m"
#define ANSI_BG_BLUE      "\x1b[44m"
#define ANSI_BG_MAGENTA   "\x1b[45m"
#define ANSI_BG_CYAN      "\x1b[46m"
#define ANSI_BG_WHITE     "\x1b[47m"

// Define macro to reset colors
#define ANSI_COLOR_RESET   "\x1b[0m"



#define MAX_INPUT_SIZE 100
char input[MAX_INPUT_SIZE];


void replaceHomeWithTilde(char *path) {
    char *home = "/home/abdallah";
    char *ptr = strstr(path, home);
    if (ptr != NULL) {
        // Replace /home/abdallah with ~
        strcpy(ptr, "~");
        strcat(ptr, ptr + strlen(home));
    }
}

#define SHORT 1
#define LONG 2

int main(int argc, char **argv)
{
    int flag = LONG;
    char cwd[1024];
    char *Basename; 
    while(1)
    {
        getcwd(cwd, sizeof(cwd)); 
        Basename = basename(cwd);
        // printf("%s",Dirname);
        replaceHomeWithTilde(cwd);
        if(flag == LONG)
        {
            printf(ANSI_COLOR_GREEN "SimpleShell:" ANSI_COLOR_CYAN "%s" ANSI_COLOR_RED ":$ " ANSI_COLOR_RESET , cwd);
        }
        else if(flag == SHORT)
        {
            printf(ANSI_COLOR_GREEN "SimpleShell:" ANSI_COLOR_CYAN "%s" ANSI_COLOR_RED ":$ " ANSI_COLOR_RESET , Basename);
        }
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
        else if (strcmp(input,"short") == 0)
        {
            flag = SHORT;
            continue;
        }
        else if (strcmp(input,"long") == 0)
        {
            flag = LONG;
            continue;
        }


        char *command = strtok(input, " "); // command only
        char *args[MAX_INPUT_SIZE]; 
        int args_count = 0;
        while(command != NULL)
        {
            args[args_count++] = command;
            command = strtok(NULL," ");
        }
        args[args_count] = NULL;


        pid_t  child_pid;
        child_pid = fork();
        if(child_pid < 0 )
        {
            fprintf(stderr,"Fork failed: \n");
            exit(EXIT_FAILURE);
        } 
        else if (child_pid == 0)
        {

            execvp(args[0],args);
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


