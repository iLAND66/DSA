#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void copiarArreglo(int *origen, int *destino, int n);
void bubbleSort(int A[], int n);
void selectionSort(int A[], int n);
void insertionSort(int A[], int n);
void mergeSort(int A[],int ini, int fin);
void merge(int A[], int ini, int mit, int fin);



int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    char *filename = argv[2];

    int *arr = malloc(n * sizeof(int));
    int *arrBubble = malloc(n * sizeof(int));
    int *arrSelection = malloc(n * sizeof(int));
    int *arrInsertion = malloc(n * sizeof(int));
    int *arrMerge = malloc(n * sizeof(int));

    FILE *file = fopen("numeros10millones.txt", "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s\n", filename);
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error al leer el número %d\n", i);
            break;
        }
    }

    copiarArreglo(arr, arrBubble, n);
    copiarArreglo(arr, arrSelection, n);
    copiarArreglo(arr, arrInsertion, n);
    copiarArreglo(arr, arrMerge, n);

    clock_t startBubble, endBubble;
    double timeBubble;

    startBubble = clock();
    bubbleSort(arrBubble, n);
    endBubble = clock();
    timeBubble = (double)(endBubble - startBubble) / CLOCKS_PER_SEC;
    printf("Tiempo Bubble Sort: %f segundos\n", timeBubble);

    clock_t startSelection, endSelection;
    double timeSelection;
    startSelection = clock();
    selectionSort(arrSelection, n);
    endSelection = clock();
    timeSelection = (double)(endSelection - startSelection) / CLOCKS_PER_SEC;
    printf("Tiempo Selection Sort: %f segundos\n", timeSelection);

    clock_t startInsertion, endInsertion;
    double timeInsertion;
    startInsertion = clock();
    insertionSort(arrInsertion, n);
    endInsertion = clock();
    timeInsertion = (double)(endInsertion - startInsertion) / CLOCKS_PER_SEC;
    printf("Tiempo Insertion Sort: %f segundos\n", timeInsertion);

    clock_t startMerge, endMerge;
    double timeMerge;
    startMerge = clock();
    mergeSort(arrMerge, 0, n - 1);
    endMerge = clock();
    timeMerge = (double)(endMerge - startMerge) / CLOCKS_PER_SEC;
    printf("Tiempo Merge Sort: %f segundos\n", timeMerge);

    fclose(file);
    free(arr);
    free(arrBubble);
    free(arrSelection);
    free(arrInsertion);
    free(arrMerge);

    return 0;
}



void copiarArreglo(int *origen, int *destino, int n) {
    for (int i = 0; i < n; i++) {
    destino[i] = origen[i];
    }
}

void bubbleSort(int A[], int n){
    /*printf("Bubble Sort\n");
    for (int k=0;k<n;k++){
        printf("%d,\t", A[k]);
    }
    printf("\n");*/
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (A[j]>A[j+1]){
                int aux=A[j];
                A[j]=A[j+1];
                A[j+1]=aux;
            }
        }
    }
    /*for (int k=0;k<n;k++){
        printf("%d.\t", A[k]);
    }
    printf("\n");*/
}

void selectionSort(int A[], int n){
    /*printf("Selection Sort\n");
    for (int k=0;k<n;k++){
        printf("%d,\t", A[k]);
    }
    printf("\n");*/
    for (int i=0;i<=n-2;i++){
        int menor = A[i];
        int iMenor = i;
        for (int j=i+1;j<=n-1;j++){
            if (A[j] < menor){
                menor = A[j];
                iMenor = j;
            }
        }
        if (i != iMenor){
            int aux2 = A[i];
            A[i] = menor;
            A[iMenor] = aux2;
        }
    }
    /*for (int k=0;k<n;k++){
        printf("%d.\t", A[k]);
    }
    printf("\n");*/
}

void insertionSort(int A[], int n){
    /*printf("Insertion Sort\n");
    for (int k=0;k<n;k++){
        printf("%d.\t", A[k]);
    }
    printf("\n");*/
    for (int i=1;i<=n-1;i++){
        int key=A[i];
        int j=i-1;
        while (j>=0 && key < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    /*for (int k=0;k<n;k++){
        printf("%d.\t", A[k]);
    }
    printf("\n");*/
}

void mergeSort(int A[], int ini, int fin){
    if (ini < fin){
        int mit = (ini+fin)/2;
        mergeSort(A, ini, mit);
        mergeSort(A, mit + 1, fin);
        merge(A, ini, mit, fin);
    }
}

void merge(int A[], int ini, int mit, int fin){
    int tamIzq = mit-ini+1;
    int tamDer = fin-mit;
    int *I = malloc((tamIzq + 1) * sizeof(int));
    int *D = malloc((tamDer + 1) * sizeof(int));
    for (int i=0;i<tamIzq;i++)
        I[i]=A[ini+i];
    for (int j=0;j<tamDer;j++)
        D[j]=A[mit+j+1];
    I[tamIzq] = D[tamDer] = INT_MAX;
    int i = 0, j = 0;
    for (int k=ini;k<=fin;k++){
        if (I[i]<=D[j]){
            A[k]=I[i];
            i++;
        }
        else{
            A[k]=D[j];
            j++;
        }
    }
    free(I);
    free(D);
}
