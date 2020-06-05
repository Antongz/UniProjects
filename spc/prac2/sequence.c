#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>

#define LINENUMBER 100
#define CHARNUMBER 256
#define ARGNUMBER 10

void exec(char * line)
{
    char A[CHARNUMBER];
    strcpy(A,line);
    
    char trans[4]=" \t\n";
    char* commands[CHARNUMBER];
    char* tmp;
    tmp =strtok(A,trans);
    int counter =0;
    while (tmp != NULL)
    {
        commands[counter]= tmp;
        tmp =strtok(NULL,trans);
        counter++;
    }
    
    commands[counter]=NULL;
    
    int forked;
    int waited;
    int exitC;
    
    forked = fork();
    if(forked==0)
    {
        if(execvp(*commands, commands)<0)
        {
            exit(1);
        }
    }else{
        
        waited= wait(&exitC);
        return;
    }
}

int main(){

    char str[LINENUMBER+1];

    char * line = NULL;
    
    while(fgets(str, LINENUMBER, stdin) != NULL){
     
        line=strdup(str);
         exec(line);
     
    }

 
    return 0;
    
    
}

