#ifndef DQUEUE_H
#define DQUEUE_H

typedef int element;

typedef struct node{
    element e;
    struct node *next;
}node;

typedef struct dqueue {
    node *tail;
    node *head;
}dqueue;

#endif