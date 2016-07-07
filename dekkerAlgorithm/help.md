#### Summary
Mutual exclusion solution by implementing [Dekker's algorithm](https://en.wikipedia.org/wiki/Dekker%27s_algorithm) which is first known correct solution to the mutual exclusion problem in concurrent programming .

#### Compile, build and run
```make```  
compile and build executable  

```make clean```     
clean the executable

```./dekker```  
run

#### Info  
Mutual exclusion is turned ```off``` by default. To enable it uncomment
following functions in ```__threadJob()``` function .

```c
__enterCritical(i);
```
and
```c
__exitCritical();
```

Pseudocode:
```
variables: turn, flags[0..1]

function
enteringCriticalSection(i,j){
    flag[i] = 1
    while(flag[j]<>0){
        if(turn == j){
            flag[i] = 0;
            while( turn == j){
                //nothing
            }
            flag[i] = 1
        }
    }
}

function
exitingCriticalSection(i,j){
    turn = j
    flag[i] = 0;
}
```
