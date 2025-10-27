#include <stdio.h>
#include <string.h>
#include "stack2.h"

int main() {
    char formula[1000];
    printf("Ingresa la fórmula: ");
    fgets(formula, sizeof(formula), stdin);
    formula[strcspn(formula, "\n")] = '\0';

    validarFormula(formula);

}
