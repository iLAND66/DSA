#ifndef STACK_H
#define STACK_H

#define size 8

typedef int element;

typedef struct Stack {
    int top;
    element Stack[size];
} Stack;


int create(struct Stack *s);
int isFull(struct Stack s);
int isEmpty(struct Stack s);
int push(struct Stack *s, element e);
int pop(struct Stack *s);

#endif