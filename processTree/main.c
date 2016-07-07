#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SLEEP_TIME 3
#define LEVELS 3

void about(){
    printf("Currently in %d\n", getpid());
}

void doWork(){
    printf("Spawning process ...\n");
    sleep(5);
}

void exiting(){
    printf("Exiting process ... %d\n", getpid());
    sleep(5);
    exit(0);
}

int createLevels(int n){
    if(n<1)
        return 1;
    about();
    doWork();
    if(fork() == 0)
        return createLevels(--n);
    wait(NULL);
    exiting();
}

int main(){
  puts("Creating Levels ...");
  sleep(SLEEP_TIME);
  createLevels(LEVELS);
  return 0;
}
