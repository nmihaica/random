#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int pid=0;

void subroutine(int sig){
  /* send SIGKILL to a pid process */
  exit(0);
}

int main(int argc, char **argv){
  pid = atoi(argv[1]);
  sigset(SIGINT, subroutine);

  while(1){
    /* sleep for a 3-7 seconds
     * randomly choose one signal from 4
     * send signal to a process with 'kill' */

  }
  return 0;
}
