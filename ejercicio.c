#include <stdio.h>
#include <stdlib.h>

int masGrande(int A[], int n);

int main(){
    int n = 5;
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL){
        printf("Error al reservar memoria\n");
        return 1;
    }
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    int mayor = masGrande(arr, n);
    printf("El numero mas grande es: %d\n", mayor);

    free(arr);

    return 0;
}
//[1, 2, 3, 4, 5]
int masGrande(int A[], int n){
    int mayor = A[0];
    for (int i = 0; i < n; i++){
        if (mayor < A[i])
            mayor = A[i];
    }
    return mayor;
}
