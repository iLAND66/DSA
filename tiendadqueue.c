#include <stdio.h>
#include <stdbool.h>
#include "tiendadqueue.h"

void create(dqueue *Q){
    Q -> head = NULL;
    Q -> tail = NULL;
}

bool isEmpty(dqueue Q){
    if (Q.head == NULL && Q.tail == NULL)
        return true;
    else
        return false;
}

void enqueue(dqueue *Q, element a){
    node *new;
    new = (node*) malloc(sizeof(node));
    new -> next = NULL;
    new -> asunto = a;
    if (isEmpty(*Q))
        Q -> head = new;
    else
        Q -> tail -> next = new;
    Q -> tail = new;
}

element dequeue(dqueue *Q) {
    node *aux;
    element eaux;
    eaux = Q -> head -> asunto;
    if (Q->head==Q->tail)
        Q->tail=NULL;
    Q->head=Q->head->next;
    free(aux);
    return eaux;
}

void generarClientes(element a, element b) {
    return;
}
