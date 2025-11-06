#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "dqueue.h"

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

void enqueue(dqueue *Q, element id, element asunto){
    node *new;
    new = (node*) malloc(sizeof(node));
    new -> identificador = id;
    new -> asunto = asunto;
    new -> next = NULL;
    if (isEmpty(*Q))
        Q -> head = new;
    else
        Q -> tail -> next = new;
    Q -> tail = new;
}

element dequeue(dqueue *Q) {
    if (isEmpty(*Q)) {
        printf("Error: Cola vacia.\n");
        return -1;
    }
    node *aux = Q -> head;
    element eaux = aux -> asunto;
    if (Q -> head == Q -> tail) {
        Q -> tail = NULL;
        Q -> head = NULL;
    } else {
        Q -> head = Q -> head -> next;
    }
    free(aux);
    return eaux;
}

void imprimirCola(dqueue Q) {
    node *aux = Q.head;
    while (aux != NULL) {
        printf("Cliente %d | Asunto %d\n", aux->identificador, aux->asunto);
        aux = aux->next;
    }
}

void liberarCola(dqueue *Q) {
    node *aux;
    while (Q->head != NULL) {
        aux = Q->head;
        Q->head = Q->head->next;
        free(aux);
    }
    Q->tail = NULL;
}
