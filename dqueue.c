#include <cstdlib>
#include <stdio.h>
#include <stdbool.h>
#include "dqueue.h"
#include "stack2.h"

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
    new -> e = a;
    if (isEmpty(*Q))
        Q -> head = new;
    else
        Q -> tail -> next = new;
    Q -> tail = new;
}
