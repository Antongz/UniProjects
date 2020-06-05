/**  smsh1.c  small-shell version 1
 **        first really useful version after prompting shell
 **        this one parses the command line into strings
 **        uses fork, exec, wait, and ignores signals
 **/

#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <signal.h>
#include    "smsh.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

#define    DFL_PROMPT    "> "
#define MAX 100
#define LEN 100

struct cmd_list{
    int argc;
    char *argv[MAX];
};

struct cmd_list *cmdv[MAX];
int num;
int flagdo;

void split_cmd(char *line)
{

     struct cmd_list * cmd = (struct cmd_list *)malloc(sizeof(struct cmd_list));
     cmdv[num++] = cmd;
     cmd->argc = 0;
     char *save;

     char *arg = strtok_r(line," \0", &save);

     while (arg)
     {

        cmd->argv[cmd->argc] = arg;
        arg = strtok_r(NULL," \0", &save);
        cmd->argc++;
     }

     cmd->argv[cmd->argc] = NULL;
}

void split_pipe(char *line)
{

    char *save;
    char * cmd = strtok_r(line, "|", &save);
    while (cmd) {
    
        split_cmd(cmd);
        cmd = strtok_r(NULL, "|", &save);
    }
}
void piping(int index)
{
    if (index == num - 1)
        execute(cmdv[index]->argv);
    int fd[2];
    pipe(fd);
    if (fork() == 0)
    {
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        execute(cmdv[index]->argv);
         wait(0);
    }
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);
    piping(index + 1);
     wait(0);
}


int main()
{
    char    *cmdline, *prompt, **arglist;
    int    result;
     int i,pid;
    char buf[LEN],p[LEN];
    void    setup();

    prompt = DFL_PROMPT ;
    setup();

    while ((cmdline = next_cmd(prompt, stdin)) != NULL ){
         pid=fork();
         if (pid==0)
        {
        split_pipe(cmdline);
        piping(0);
       result=execute(cmdv[0]->argv);
        }
   wait(0);
    }
                free(cmdline);
        
    return 0;
}

void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
    signal(SIGINT,  SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
    fprintf(stderr,"Error: %s,%s\n", s1, s2);
    exit(n);
}

