#### Summary
C program which creates ```n``` processes using ```POSIX``` system calls .
Calculates surface area and circumference of the corresponding regular polygon.

###### OS Assignment:
Create C program in which you create *n* simultaneous processes.
You will receive *n* from the command line.
In one you need to calculate surface area and in the other
you need to calculate circumference of the depending regular polygon.
Also you need to print the result on the screen.
**5** is the maximum number of allowed processes.

#### Compile, build and run
```make``` compile and build executable .

```make clean``` clean the executable .

```./forking``` run .

#### Info  
Place following command into ```main.c``` file to enable parent process to
wait until execution of child process is done. This will prevent [defunct](https://en.wikipedia.org/wiki/Zombie_process) processes.

```c
wait(NULL);
```
