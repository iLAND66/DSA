#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
