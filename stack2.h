#ifndef STACK_H
#define STACK_H

typedef char element;

typedef struct node {
    element e;
    struct node *next;
} node;

void createDS(node **t);
int isEmpyDS(node *t);
element pushDS(node **t, element a);
element popDS(node **s);
void imprimirDS(node *t);
void liberarPila(node **s);
void validarFormula(const char *formula);
int esPareja(char apertura, char cierre);

#endif