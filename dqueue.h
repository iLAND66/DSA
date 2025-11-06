#ifndef DQUEUE_H
#define DQUEUE_H

typedef int element;

typedef struct node {
    element identificador;
    element asunto;
    struct node *next;
}node;

typedef struct dqueue {
    node *tail;
    node *head;
}dqueue;

void create(dqueue *Q);
bool isEmpty(dqueue Q);
void enqueue(dqueue *Q, element id, element asunto);
element dequeue(dqueue *Q);
void imprimirCola(dqueue Q);
void liberarCola(dqueue *Q);

#endif