#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

void createDS(node **t){
    *t = NULL;
}

int isEmpyDS(node *t) {
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

int esPareja(char apertura, char cierre) {
    return (apertura == '(' && cierre == ')') ||
           (apertura == '[' && cierre == ']') ||
           (apertura == '{' && cierre == '}');
}

void validarFormula(const char *formula) {
    node *pila;
    createDS(&pila);

    int error = 0;
    int aperturaSinCierreParentesis = 0, cierreSinAperturaParentesis = 0;
    int aperturaSinCierreCorchetes = 0, cierreSinAperturaCorchetes = 0;
    int aperturaSinCierreLlaves = 0, cierreSinAperturaLlaves = 0;

    for (int i = 0; formula[i] != '\0'; i++) {
        char c = formula[i];
        if (c == '(' || c == '[' || c == '{') {
            pushDS(&pila, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpyDS(pila)) {
                error = 1;
                if (c == ')') cierreSinAperturaParentesis++;
                else if (c == ']') cierreSinAperturaCorchetes++;
                else if (c == '}') cierreSinAperturaLlaves++;
            } else {
                char apertura = popDS(&pila);
                if (!esPareja(apertura, c)) {
                    error = 1;
                    // Aquí asumimos que ambos están mal
                    if (apertura == '(') aperturaSinCierreParentesis++;
                    else if (apertura == '[') aperturaSinCierreCorchetes++;
                    else if (apertura == '{') aperturaSinCierreLlaves++;

                    if (c == ')') cierreSinAperturaParentesis++;
                    else if (c == ']') cierreSinAperturaCorchetes++;
                    else if (c == '}') cierreSinAperturaLlaves++;
                }
            }
        }
    }

    while (!isEmpyDS(pila)) {
        char apertura = popDS(&pila);
        error = 1;
        if (apertura == '(') aperturaSinCierreParentesis++;
        else if (apertura == '[') aperturaSinCierreCorchetes++;
        else if (apertura == '{') aperturaSinCierreLlaves++;
    }


    if (!error) {
        printf("La fórmula está balanceada.\n");
    } else {
        printf("La fórmula NO está balanceada.\n");
        if (aperturaSinCierreParentesis) printf("Faltan %d paréntesis de cierre.\n", aperturaSinCierreParentesis);
        if (cierreSinAperturaParentesis) printf("Faltan %d paréntesis de apertura.\n", cierreSinAperturaParentesis);
        if (aperturaSinCierreCorchetes) printf("Faltan %d corchetes de cierre.\n", aperturaSinCierreCorchetes);
        if (cierreSinAperturaCorchetes) printf("Faltan %d corchetes de apertura.\n", cierreSinAperturaCorchetes);
        if (aperturaSinCierreLlaves) printf("Faltan %d llaves de cierre.\n", aperturaSinCierreLlaves);
        if (cierreSinAperturaLlaves) printf("Faltan %d llaves de apertura.\n", cierreSinAperturaLlaves);
    }


    liberarPila(&pila);
}

