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
int isFull(struct Stack s);
int isEmpty(struct Stack s);
int push(struct Stack *s, element e);
int pop(struct Stack *s);

int main(){
    struct Stack s1;
    int opcion = 0;

    printf("1: Pop\n2: Push\n3: Imprimir pila\n4: Finalizar el programa\n");
    scanf("%d", &opcion);
    int a = 0;
    switch(opcion) {
        case 1://Si elige la opción 1 has pop y muestra en pantalla el elemento eliminado.
            a = pop(&s1);
            printf("%d eliminado de la pila", a);
        case 2://Si elige la opción 2 pide al usuario que introduzca el entero y has push a la pila.
            int num = 0;
            printf("Que elemento quiere agregar a la pila?");
            scanf("%d", &num);
            a = push(&s1, num);
        case 3://Si elige la opción 3, realiza una función imprimir que solo utilice las funciones de pila para mostrar sus elementos.
            a = pop(&s1);
        case 4://Si elige la opción 4, antes de terminar el programa deberás eliminar la pila y finalizar el programa.
            pop(&s1);
        default:
            printf("");
    }
}

int create(struct Stack *s){
    s->top=-1;
    printf("Pila creada\n");
}

int isFull(struct Stack s){
    if(s.top==size-1){
        //printf("si\n");
        return 1;
    } else {
    //printf("no\n");
    }
}

int isEmpty(struct Stack s){
    if(s.top==-1) {
        //printf("si\n");
        return 1;
    }
    else {
        //printf("no\n");
        return 0;
    }
}

int push(struct Stack *s, element e){
    if(isFull(*s)== 1)
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
        return s->Stack[s->top+1];
    }
}