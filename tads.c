#include <stdbool.h>
#include <stdio.h>
#include "tads.h"

int next(int i) {
    if (i < i-1)
        return i + 1;
    else
        return 0;
}

void createQueue(squeue *Q) {
    Q -> head = -1;
    Q -> tail = -1;
}

int isEmptyQueue(squeue Q) {
    if (Q.head == -1 && Q.tail == -1)
        return true;
    else
        return false;
}

int isFullQueue(squeue Q) {
    if (next(Q.tail) == Q.head)
        return true;
    else
        return false;
}

void enqueue(squeue *Q, element a) {
    if (isFullQueue(*Q)){
        printf("Cola llena.\n");
        return;
    }
    if (isEmptyQueue(*Q)) {
        Q -> head = 0;
        Q -> tail = 0;
    } else
        Q -> tail = next(Q -> tail);
    Q -> SQ[Q -> tail] = a;
}

element dequeue(squeue *Q) {
    if (isEmptyQueue(*Q)) {
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
    if (isEmptyQueue(Q)) {
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

void createStack(struct stack *s) {
    s -> top =-1;
}

int isFullStack(struct stack s) {
    if (s.top == n-1)
        return 1;
    else
        return 0;
}

int isEmptyStack(struct stack s) {
    if (s.top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *s, element e) {
    if (isFullStack(*s) == 1) {
        printf("Error de overflow\n");
        return;
    } else {
        s -> top++;
        s -> stack[s -> top] = e;
    }
}

element pop(struct stack *s) {
    if (isEmptyStack(*s)) {
        printf("Error de underflow\n");
        return -1;
    } else {
        s -> top--;
        return s -> stack[s -> top+1];
    }
}
