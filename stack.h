#ifndef STACK_H
#define STACK_H

typedef int element;

typedef struct node {
    element e;
    struct node *next;
} node;

void createDS(node **t);
element isEmpyDS(node *t);
element pushDS(node **t, element a);
element popDS(node **s);
void liberarPila(node **s);
//#include "stack.c"
#endif
