/* execute.c - code used by small shell to execute commands */

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <signal.h>
#include    <sys/wait.h>
#include    <fcntl.h>
//
int execute(char *argv[])
/*
 * purpose: run a program passing it arguments
 * returns: status returned via wait, or -1 on error
 *  errors: -1 on fork() or wait() errors

 */
{
   int    child_info = -1;
        execvp(argv[0],argv);
       perror("cannot execute command");
        exit(1);

       return child_info;
}



