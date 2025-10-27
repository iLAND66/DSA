#include <stdio.h>
#include "queue.h"

int next(int i) {
    return (i + 1) % N;
}

void create(squeue *Q) {
    Q->head = -1;
    Q->tail = -1;
}

int isEmpty(squeue Q) {
    return Q.head == -1 && Q.tail == -1;
}

int isFull(squeue Q) {
    return next(Q.tail) == Q.head;
}

void enqueue(squeue *Q, element a) {
    if (isFull(*Q)) {
        printf("Error: cola llena.\n");
        return;
    }

    if (isEmpty(*Q)) {
        Q->head = 0;
        Q->tail = 0;
    } else {
        Q->tail = next(Q->tail);
    }

    Q->SQ[Q->tail] = a;
}

element dequeue(squeue *Q) {
    if (isEmpty(*Q)) {
        printf("Error: cola vacía.\n");
        return -1;
    }

    element a = Q->SQ[Q->head];

    if (Q->head == Q->tail) {
        Q->head = -1;
        Q->tail = -1;
    } else {
        Q->head = next(Q->head);
    }

    return a;
}

void deleteQueue(squeue *Q) {
    Q->head = -1;
    Q->tail = -1;
}

void imprimir(squeue Q) {
    if (isEmpty(Q)) {
        printf("Cola vacia.\n");
        return;
    }

    int i = Q.head;
    printf("Cola: ");
    while (1) {
        printf("%c ", Q.SQ[i]);
        if (i == Q.tail) break;
        i = next(i);
    }
    printf("\n");
}
