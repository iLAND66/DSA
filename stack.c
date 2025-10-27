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
    node *new = (node*)malloc(sizeof(node));
    new->e = a;
    new->next = *t;
    *t = new;
    return a;
}

element popDS(node **s) {
    element a;
    node *aux;
    if (isEmpyDS(*s)){
        printf("Error de underflow");
        a = -1; return a;
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

void imprimirDS(node *t) {
    while (t != NULL) {
        printf("%d", t->e);
        t = t->next;
    }
    printf("\n");
}

void liberarPila(node **s) {
    node *actual = *s;
    while (actual != NULL) {
        node *sig = actual->next;
        free(actual);
        actual = sig;
    }
    *s = NULL;
}
