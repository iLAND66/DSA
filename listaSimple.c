#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct node {
    element e;
    struct node *next;
}node;

typedef struct slist {
    node *head;
}slist;

void create(slist *L);
bool is_Empty(slist L);
void insert_after_node_i(slist *L, element a, int i);
element remove_node_i(slist *L, int i);

int main() {
    slist L1;

    return 0;
}

void create(slist *L) {
    L->head = NULL;
}

bool is_Empty(slist L) {
    if (L.head == NULL)
        return true;
    else
        return false;
}

void insert_after_node_i(slist *L, element a, int i) {
    if (i < 1) {
        printf("Error: entero negativo\n");
        return;
    }
    node *aux = L->head;
    int cont = 1;
    while (cont < i && aux->next != NULL) {
        aux = aux->next;
        cont++;
    }
    if (i > cont) {
        printf("Error: i fuera de rango\n");
        return;
    }
    node *new = (node*)malloc(sizeof(node));
    new->e = a;
    new->next = aux->next;
    aux->next = new;
}

element remove_node_i(slist *L, int i) {
    if (i < 1) {
        printf("Error: entero negativo\n");
        return 0;
    }
    if (is_Empty(*L)) {
        printf("Error: lista vacia\n");
        return 0;
    }
    node *aux = L->head;
    element a;
    if (i == 1) {
        L->head = aux->next;
        a = aux->e;
        free(aux);
        return a;
    }
    int cont = 1;
    while (cont < i - 1 && aux->next != NULL) {
        aux = aux->next;
        cont++;
    }
    if (aux->next == NULL) {
        printf("Error: i fuera de rango\n");
        return 0;
    }
    node *eliminado = aux->next;
    a = eliminado->e;
    aux->next = eliminado->next;
    free(eliminado);
    return a;
}
