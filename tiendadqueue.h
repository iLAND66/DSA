#ifndef TIENDADQUEUE_H
#define TIENDADQUEUE_H

typedef int element;

typedef struct node {
    element identificador;
    element asunto;
    struct node *next;
}node;

typedef struct dqueue {
    node *head;
    node *tail;
}dqueue;

#endif