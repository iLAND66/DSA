#include <stdio.h>
#include <string.h>
#include "stack.h"

int main() {
    char num1[1000], num2[1000];

    printf("Introduce el primer número: ");
    scanf("%s", num1);

    printf("Introduce el segundo número: ");
    scanf("%s", num2);

    node *n1, *n2, *n3;
    createDS(&n1);
    createDS(&n2);
    createDS(&n3);

    for (int i = 0; i < strlen(num1); i++) {
        pushDS(&n1, num1[i] - '0');
    }
    for (int i = 0; i < strlen(num2); i++) {
        pushDS(&n2, num2[i] - '0');
    }


    int acr = 0;
    while (!isEmpyDS(n1) || !isEmpyDS(n2)) {
        int a = !isEmpyDS(n1) ? popDS(&n1) : 0;
        int b = !isEmpyDS(n2) ? popDS(&n2) : 0;
        int sum = a + b + acr;
        pushDS(&n3, sum % 10);
        acr = sum / 10;
    }

    if (acr > 0) {
        pushDS(&n3, acr);
    }

    printf("Resultado de la suma: ");
    imprimirDS(n3);

    liberarPila(&n1);
    liberarPila(&n2);
    liberarPila(&n3);

    return 0;
}
