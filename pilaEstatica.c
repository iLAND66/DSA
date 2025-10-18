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
    create(&s1);
    isFull(s1);
    isEmpty(s1);
    push(&s1, 3);
    push(&s1, 9);
    int e = pop(&s1);

    return 0;
}

int create(struct Stack *s){
    s->top=-1;
    printf("Pila creada\n");
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
        return s->Stack[s->top+1];
    }
}
