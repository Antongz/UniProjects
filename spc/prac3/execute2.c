/* execute.c - code used by small shell to execute commands */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<signal.h>
#include	<sys/wait.h>
#include    <fcntl.h>
//
int execute(char *argv[])

{
        int child_info = -1;
        execvp(argv[0],argv);
        perror("cannot execute command");
        exit(1);

       return child_info;
}



