/*
Realiza un programa que muestre continuamente al usuario el siguiente menú de opciones hasta que elija la opción salir.
    1. pop
    2. push
    3. Imprimir pila
    4. Salir
Crea una pila estática de enteros de tamaño 8 ,
Si elige la opción 1 has pop y muestra en pantalla el elemento eliminado.
Si elige la opción 2 pide al usuario que introduzca el entero y has push a la pila.
Si elige la opción 3, realiza una función imprimir que solo utilice las funciones de pila para mostrar sus elementos.
Si elige la opción 4, antes de terminar el programa deberás eliminar la pila y finalizar el programa.
 */
#include <stdio.h>

#define size 8

typedef int element;

typedef struct Stack {
    int top;
    element Stack[size];
} Stack;


int create(struct Stack *s);
int imprimirPila(struct Stack s);
int isFull(struct Stack s);
int isEmpty(struct Stack s);
int push(struct Stack *s, element e);
int pop(struct Stack *s);

int main(){
    struct Stack s1;

    int opcion = 0;
    do {
        printf("\nEscoge una opcion\n1: Pop\n2: Push\n3: Imprimir pila\n4: Finalizar el programa\n");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1://Si elige la opción 1 has pop y muestra en pantalla el elemento eliminado.
                int eliminado = pop(&s1);
                printf("Elemento %d eliminado de la pila\n", eliminado);
                break;
            case 2://Si elige la opción 2 pide al usuario que introduzca el entero y has push a la pila.
                int agregado = 0;
                printf("Que elemento quiere agregar a la pila?\n");
                scanf("%d", &agregado);
                push(&s1, agregado);
                break;
            case 3://Si elige la opción 3, realiza una función imprimir que solo utilice las funciones de pila para mostrar sus elementos.
                imprimirPila(s1);
                break;
            case 4://Si elige la opción 4, antes de terminar el programa deberás eliminar la pila y finalizar el programa.
                while (isEmpty(s1) != 1){
                    int borrar;
                    borrar = pop(&s1);
                    printf("Elemeto %d eliminado de la pila\n", borrar);
                }
                printf("Pila eliminada\n");
                break;
            default:
                printf("Opcion incorrecta\n");
        }
    } while (opcion != 4);
}

int create(struct Stack *s){
    s->top=-1;
    printf("Pila creada\n");
}

int imprimirPila(struct Stack s){
    int contador = 1;
    while (isEmpty(s) != 1){
        int imprimir;
        imprimir = pop(&s);
        printf("Elemento %d: %d\n",contador, imprimir);
        contador++;
    }
}

int isFull(struct Stack s){
    if(s.top==size-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack s){
    if(s.top==-1)
        return 1;//devuelve 1(T)
    else
        return 0;//devuelve 0 (F)
}

int push(struct Stack *s, element e){
    if(isFull(*s) == 1)
        printf("Error de overflow\n");
    else{
        s->top++;
        s->Stack[s->top]=e;
    }
}

int pop(struct Stack *s){
    if(isEmpty(*s))
        printf("Error de underflow\n");
    else{
        s->top--;
        return s->Stack[s->top+1];//devuelve 1
    }
}