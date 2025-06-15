//
// Created by Debashis on 11/06/25.
//



#include <stdio.h>
#include "Stack.h"



void initStack(Stack *s) {
    s->top = -1;
}

int isEmptyStack(Stack *s) {
    return s->top == -1;
}

int isFullStack(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char data) {
    if (isFullStack(s)) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = data;

}

char pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];

}

char peek(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}


