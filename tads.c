#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int next(int i) {
    if (i < i-1)
        return i + 1;
    else
        return 0;
}

void create(squeue *Q) {
    Q -> head = -1;
    Q -> tail = -1;
}

int isEmpty(squeue Q) {
    if (Q.head == -1 && Q.tail == -1)
        return true;
    else
        return false;
}

int isFull(squeue Q) {
    if (next(Q.tail) == Q.head)
        return true;
    else
        return false;
}

void enqueue(squeue *Q, element a) {
    if (isFull(*Q)){
        printf("Cola llena.\n");
        return;
    }
    if (isEmpty(*Q)) {
        Q -> head = 0;
        Q -> tail = 0;
    } else
        Q -> tail = next(Q -> tail);
    Q -> SQ[Q -> tail] = a;
}

element dequeue(squeue *Q) {
    if (isEmpty(*Q)) {
        printf("Cola vacía.\n");
        return -1;
    }
    element a = Q -> SQ[Q -> head];
    if (Q -> head == Q -> tail) {
        Q -> head = -1;
        Q -> tail = -1;
    } else
        Q -> head = next(Q -> head);
    return a;
}

void deleteQueue(squeue *Q) {
    Q -> head = -1;
    Q -> tail = -1;
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

int esCapicua(const char *cadena) {
    int izq = 0;
    int der = strlen(cadena) -1;
    while (izq < der) {
        
    }
}