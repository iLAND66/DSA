#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int elementDL;

typedef struct nodeDL{
    struct nodeDL *next;
    struct nodeDLde *prev;
    elementDL e;
}nodeDL;

typedef struct dlist{
    nodeDL *head;
    nodeDL *tail;
}dlist;

void createDL(dlist *DL);
bool isEmptyDL(dlist DL);
void insertAtFirstDL(dlist *DL, elementDL a);
void insertNodeDL(dlist *DL, elementDL a, int i);
void insertBeforeNodeiDL(dlist *DL, elementDL a, int i);
void insertAtEndDL(dlist *DL, elementDL a);
elementDL deleteNodeDL(dlist *DL, elementDL a);
elementDL deleteNodeiDL(dlist *DL, int i);
elementDL deleteFirstDL(dlist *DL);
elementDL deleteLastDL(dlist *DL);
nodeDL* searchNodeDL(dlist DL, int i);
nodeDL* searchNodeiDL(dlist DL, int i);

int main(){
    dlist DL1;
    createDL(&DL1);

    return 0;
}

void createDL(dlist *DL){
    DL->head = NULL;
    DL->tail = NULL;
}

bool isEmptyDL(dlist DL){
    if (DL.head == NULL && DL.tail == NULL)
        return true;
    else
        return false;
}

void insertAtFirstDL(dlist *DL, elementDL a){}

void insertNodeDL(dlist *DL, elementDL a, int i){}

void insertBeforeNodeiDL(dlist *DL, elementDL a, int i){}

void insertAtEndDL(dlist *DL, elementDL a){
    nodeDL *new = (nodeDL*)malloc(sizeof(nodeDL));
    new->next = NULL;
    new->e = a;
    new->prev = DL->tail;
    if (!isEmptyDL(*DL))
        DL->tail->next = new;
    else
        DL->head = new;
    DL->tail = new;
}

elementDL deleteNodeDL(dlist *DL, elementDL a){}

elementDL deleteNodeiDL(dlist *DL, int i){ //O(n)
    if (i < 1){
        printf("Error: entero negativo\n");
        return -1;
    }
    if (isEmptyDL(*DL)){
        printf("Error: lista doble vacia\n");
        return -1;
    }
    nodeDL *aux = DL->head;
    elementDL a;
    if (i == 1)
        return deleteFirstDL(DL);
    int cont = 1;
    while (cont < i && aux != NULL){
        aux = aux->next;
        cont++;
    }
    if (aux == NULL){
        printf("Error: i fuera de rango\n");
        return -1;
    }
    if (aux->next == NULL)
        return deleteLastDL(DL);
    a = aux->e;
    aux->prev->next = aux->next;
    aux->next->prev = aux->prev;
    free(aux);

    return a;
}

elementDL deleteFirstDL(dlist *DL){}

elementDL deleteLastDL(dlist *DL){}

nodeDL* searchNodeDL(dlist DL, int i){}

nodeDL* searchNodeiDL(dlist DL, int i){ //O(n)
    if (i < 1){
        printf("Error: entero negativo\n");
        return NULL;
    }
    nodeDL *aux = DL.head;
    int cont = 1;
    while (aux != NULL && cont < i){
        aux = aux->next;
        cont++;
    }
    return aux;
}
