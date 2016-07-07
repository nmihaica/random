#ifndef INPUT_H
#define INPUT_H
#include <stdio.h>
#include "polygon.h"

void inputData(polygon *a){
    int n;
    float s;
    printf("Number of pages: \n");
    scanf("%d",&n);
    printf("Length of a page: \n");
    scanf("%f",&s);
    a->numberOfPages = n;
    a->length = s;
}
#endif
