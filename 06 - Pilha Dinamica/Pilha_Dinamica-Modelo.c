#include <stdio.h>
#include <stdlib.h>

typedef struct sStack{
    int data;
    struct sStack *next;
} Stack;

