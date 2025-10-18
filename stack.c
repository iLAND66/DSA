#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createDS(node **t){
    *t = NULL;
}

element isEmpyDS(node *t) {
    if (t == NULL)
        return 1;
    else
        return 0;
}

element pushDS(node **t, element a) {
    node *new;
    new = (node*)malloc(sizeof(node));
    new->e=a;
}

element popDS(node **s) {
    element a;
    node *aux;
    if (isEmpyDS(*s)){
        printf("Error de underflow\n");
        a = -1;
        return a;
    } else if ((*s)->next==NULL) {
        a = (*s)->e;
        free(*s);
        *s = NULL;
        return a;
    } else {
        a = (*s)->e;
        aux = (*s)->next;
        free(*s);
        (*s) = aux;
        return a;
    }
}

void liberarPila(node **s) {
    node *top = *s;
    node *next;

    while (top != NULL) {
        next = top->next;
        free(top);
        top = next;
    }

    *s = NULL;
}
