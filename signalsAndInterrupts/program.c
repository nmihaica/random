#include <stdio.h>
#include <signal.h>

#define N 6 /*interrupt levels*/ 
int waitingFlag[N];
int priority[N];
int currentPriority;

int sig[] ={ SIGUSR1, SIGUSR2, SIGINT };

void disableInterrupt(){
  int i;
  for(i=0; i<5; i++)
    sighold(sig[i]);
}

void enableInterrupt(){
  int i;
  for(i=0; i<5; i++)
    sigrelse(sig[i]);
}

void processInterrupt(){
  /*Simulate by wasting time, print statement every second*/
}

void subroutine(int sig){
  int n=1;
  disableInterrupt();
  
  switch(sig){
    case SIGUSR1:
      n=1;
      printf(" - X - - - -\n");
      break;
    case SIGUSR2:
      n=2;
      printf(" - - X - - -\n");
      break
    case SIGINT:
      n=3;
      printf(" - - - X - -\n");
      break;
  }

  waitingFlag[N]=1;
  //...
  enableInterrupt();
}

int main(void){
  sigset(SIGUSR1, subroutine);
  sigset(SIGINT, subroutin);
  printf("Processing interrupts, PID = %d\n", getpid());
  /*time so that it can actually interrupt*/
  printf("Finished program.c\n");
  return 0;
}
