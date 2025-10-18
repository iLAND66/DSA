#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int indice;
    int valor;
} Grupo;

typedef struct {
    char* nombre;
    int boleta;
} Alumno;

int busquedaIndexada(Alumno A[], int n, int s);
int binarySearch(Alumno A[], int s, int ini, int fin);
void mergeSort(Alumno A[], int ini, int fin);
void merge(Alumno A[], int ini, int mit, int fin);

int main(){
    char* nombres[50] = {
        "Ana", "Luis", "Maria", "Carlos", "Sofia", "Jorge", "Lucia", "Pedro", "Valentina", "Miguel",
        "Camila", "Andres", "Isabella", "Fernando", "Paula", "Ricardo", "Daniela", "Manuel", "Renata", "Sebastian",
        "Gabriela", "Alejandro", "Nicole", "Eduardo", "Sara", "Diego", "Monica", "Raul", "Patricia", "Ivan",
        "Laura", "Hector", "Bianca", "Tomas", "Claudia", "Emilio", "Julieta", "Ramiro", "Natalia", "Benjamin",
        "Fatima", "Esteban", "Carolina", "Axel", "Elena", "Martin", "Ariadna", "Alonso", "Noemi", "Simon"
    };

    int n = 50;
    Alumno* alumnos = malloc(n * sizeof(Alumno));
    if(alumnos == NULL){
        printf("Error al asignar memoria\n");
        return 1;
    }

    int top = 999;
    int bot = 100;
    for(int i = 0; i < n; i++){
        alumnos[i].nombre = nombres[i];
        alumnos[i].boleta = rand() % (top - bot + 1) + bot;
        printf("Alumo: %s\t\tBoleta: %d\n", alumnos[i].nombre, alumnos[i].boleta);
    }
    mergeSort(alumnos, 0, n - 1);
    int ganador;
    int indiceGanador = -1;
    do {
       ganador = rand() % (top - bot + 1) + bot;
       indiceGanador = busquedaIndexada(alumnos, n, ganador);
    } while (indiceGanador == -1);

    printf("\nGanador\nNombre: %s\n", alumnos[indiceGanador].nombre);

    free(alumnos);
    return 0;
}

int busquedaIndexada(Alumno A[], int n, int s){
    if (n <= 0) return -1;

    int GN = (int)sqrt(n);
    if (GN == 0) GN = 1;
    int G = (n + GN - 1) / GN;

    Grupo* Grupos = malloc(G* sizeof(Grupo));
    if (Grupos == NULL) return -1;

    int j = 0;
    for (int i = 0; i < n; i+= GN){
        Grupos[j].indice = i;
        Grupos[j].valor = A[i].boleta;
        j++;
    }

    int ini = 0, fin = n - 1;
    if (s < Grupos[0].valor){
        free(Grupos);
        return -1;
    }

    for (int k = 1; k < G; k++){
        if (s < Grupos[k].valor){
            ini = Grupos[k - 1].indice;
            fin = Grupos[k].indice - 1;
            break;
        }
    }

    if (s >= Grupos[G - 1].valor){
        ini = Grupos[G - 1]. indice;
        fin = n - 1;
    }

    int resultado = binarySearch(A, s, ini, fin);
    free(Grupos);
    return resultado;

}

int binarySearch(Alumno A[], int s, int ini, int fin){
     while (ini<=fin){
         int mit = (ini + fin) / 2;
         if (s == A[mit].boleta){
             return mit;
         }
         else if (s > A[mit].boleta){
             ini = mit + 1;
         }
         else{
             fin = mit - 1;
         }
     }
     return -1;
}

void mergeSort(Alumno A[], int ini, int fin){
    if (ini < fin){
        int mit = (ini + fin) / 2;
        mergeSort(A, ini, mit);
        mergeSort(A, mit + 1, fin);
        merge(A, ini, mit, fin);
    }
}

void merge(Alumno  A[], int ini, int mit, int fin){
    int tamIzq = mit-ini+1;
    int tamDer = fin-mit;
    Alumno *I = malloc((tamIzq + 1) * sizeof(Alumno));
    Alumno *D = malloc((tamDer + 1) * sizeof(Alumno));
    for (int i = 0; i < tamIzq; i++)
        I[i] = A[ini + i];
    for (int j = 0; j < tamDer; j++)
        D[j] = A[mit+j+1];
    I[tamIzq].boleta = D[tamDer].boleta = INT_MAX;
    int i = 0, j = 0;
    for (int k = ini; k <= fin; k++){
        if (I[i].boleta <= D[j].boleta){
            A[k]=I[i++];
        } else {
            A[k] = D[j++];
        }
    }

    free(I);
    free(D);
}
