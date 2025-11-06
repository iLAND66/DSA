#ifndef QUEUE_H
#define QUEUE_H

#define n 10

typedef char element;

typedef struct squeue{
    element SQ[n];
    int head;
    int tail;
} squeue;

void createQueue(squeue *Q);
int isEmptyQueue(squeue Q);
int isFullQueue(squeue Q);
int next(int i);
void enqueue(squeue *Q, element a);
element dequeue(squeue *Q);
void deleteQueue(squeue *Q);
void imprimir(squeue Q);

typedef struct stack{
    int top;
    element stack[n];
} stack;

void createStack(struct stack *s);
int isEmptyStack(struct stack s);
int isFullStack(struct stack s);
void push(struct stack *s, element a);
element pop(struct stack *s);

#endif