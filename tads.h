#ifndef QUEUE_H
#define QUEUE_H

#define n 10

typedef char element;

typedef struct squeue{
    element SQ[n];
    int head;
    int tail;
} squeue;

void create(squeue *Q);
int isEmpty(squeue Q);
int isFull(squeue Q);
int next(int i);
void enqueue(squeue *Q, element a);
element dequeue(squeue *Q);
void deleteQueue(squeue *Q);
void imprimir(squeue Q);

#endif
