 //
// Created by Debashis on 11/06/25.
//



#include <stdio.h>
#include "Stack.h"



void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmptyStack(struct Stack *s) {
    return s->top == -1;
}

int isFullStack(struct Stack *s) {
    return s->top == MAX - 1;
}

void push(struct Stack *s, char data) {
    if (isFullStack(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = data;

}

char pop(struct Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];

}

char peek(struct Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}


