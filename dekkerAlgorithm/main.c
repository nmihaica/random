#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define false 0
#define true 1
typedef int bool;

pthread_t tid[2];
bool flag_i = false;
bool flag_j = false;
int turn = 1;

void* _print(int i, int k, int m){
    printf("Thread: %d, C.S Turn: %d , (%d/5)\n",i,k,m+1);
}


void* thread_i() {
  flag_i = true;
  while(flag_j) {
    if(turn == 2) {
      flag_i = false;
      pthread_yield();
      while(turn != 1) {

      }
      flag_i = true;
    }
  }
}

void* thread_j() {
  flag_j = true;
  while(flag_i) {
    if(turn == 1) {
      flag_j = false;
      pthread_yield();
      while(turn != 2) {

      }
      flag_j = true;
    }
  }
}

void* __enterCritical(pthread_t i){
    if(pthread_equal(i,tid[0])){
      thread_i();
    }
    else if(pthread_equal(i, tid[1])) {
      thread_j();
    }
}

void* __exitCritical(){
    if(flag_i==true && flag_j==false){
        turn = 2;
        flag_i = false;
    }
    if(flag_i==false && flag_j==true){
        turn = 1;
        flag_j = false;
    }
}

void* __threadJob() {
    int k=0;
    int m=0;pthread_t i = pthread_self();
    //__enterCritical(i);              /*ON OFF*/
    /*entering critical section*/
        for(m; m<5; m++){
            sleep(1);
            _print((int)i,turn,m);
      }
    /*exiting critical section*/
    //__exitCritical(); /*ON OFF*/
    pthread_exit(NULL);
}

int main(void) {
  pthread_attr_t atr_thread;
  pthread_attr_init(&atr_thread);

  pthread_create(&(tid[0]), &atr_thread, __threadJob, NULL);
  pthread_create(&(tid[1]), &atr_thread, __threadJob, NULL);

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  return 0;
}
