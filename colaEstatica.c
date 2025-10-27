#include <stdio.h>
#include "queue.h"

int main() {
    squeue Q1;
    create(&Q1);

    enqueue(&Q1, 'A');
    enqueue(&Q1, 'B');
    enqueue(&Q1, 'C');
    imprimir(Q1);

    printf("Elemento eliminado: %c\n", dequeue(&Q1));
    imprimir(Q1);

    deleteQueue(&Q1);
    imprimir(Q1);

    return 0;
}
