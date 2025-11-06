#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "dqueue.h"

int main() {
    srand(time(NULL));
    dqueue Q1;
    create(&Q1);
    int totalClientes = 20 + rand() % 81;
    printf("Se generaron %d clientes\n", totalClientes);
    for (int i = 1; i <= totalClientes; i++) {
        int asunto = 1 + rand() % 5;
        enqueue(&Q1, i, asunto);
    }
    imprimirCola(Q1);
    liberarCola(&Q1);

    return 0;
}