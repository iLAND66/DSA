#include <stdio.h>
#include <string.h>
#include "tads.h"

int main() {
    char numero[100];
    printf("Ingrese un numero:\n");
    fgets(numero, sizeof(numero), stdin);
    numero[strcspn(numero, "\n")] = '\0';
    squeue Q1;
    stack s1;
    createQueue(&Q1);
    createStack(&s1);

    for (int i = 0; numero[i] != '\0'; i++) {
        enqueue(&Q1, numero[i]);
        push(&s1, numero[i]);
    }
    int esCapicula = 1;
    while (!isEmptyQueue(Q1) && !isEmptyStack(s1)) {
        char c1 = dequeue(&Q1);
        char c2 = pop(&s1);
        if (c1 != c2) {
            esCapicula = 0;
            break;
        }
    }
    if (esCapicula)
        printf("El numero es capicula\n");
    else
        printf("El numero no es capicula\n");

    return 0;
}
