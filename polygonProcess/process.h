#ifndef PROCESS_H
#define PROCESS_H
#include <stdio.h>
#include <math.h>
#include "polygon.h"
void _surface(int num, float len){
    printf("N: %d A: %f P: %f \n", num, len,
    (float) (
        (1./4) * (float)num
        * (float)len
        * len
        / (tan(M_PI/num)
        )
    ));
}
void _circumference(int num, float len){
    printf("N: %d A: %f O: %f \n",
    num,
    len,
    num*len);
}

/*
op == 1 -> surface
op == 2 -> circumference
*/
void __processJob(polygon *b, int op){
    if(op == 1){
        _surface(
            b->numberOfPages,
            b->length
        );
    }
    if(op == 2){
        _circumference(
            b->numberOfPages,
            b->length
        );
    }
}
#endif
