/*
Task:
Create C program in which you create M simultaneous processes.
You will receive M from the command line.
In one you need to calculate surface area and in the other
you need to calculate circumference of the depending regular polygon.
Also you need to print the result on the screen.
5 is the maximum number of allowed processes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include "input.h"
#include "process.h"
#define MAX_POLY 5

int main( int argc, char **argv){
    if(argc==1 || argc >2){
        perror("No arguments\n");
        exit(0);
    }
    int process;
    int i=0;
    process = (int)atoi(argv[1]);
    polygon *list;
    list = (polygon*) malloc (sizeof(polygon) * process );

    if(process > MAX_POLY){
        perror("Not allowed to create that many processes");
        exit(0);
    }
    for(i; i<process; i++){
        inputData(list+i);
    }

    i=0;
    for(i; i<process; i++){
        switch ( fork() ){
            case 0:
                __processJob(list+i,2);
                exit(0);
            case -1:
            default:
                __processJob(list+i,1);
                /*wait(NULL) to avoid <defunct> proces*/
                break;
        }
    }
    while(i--)  wait(NULL);
    free(list);
    return 0;
}
