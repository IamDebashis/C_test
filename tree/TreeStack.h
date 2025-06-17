//
// Created by debah on 16-06-2025.
//

#ifndef TREESTACK_H
#define TREESTACK_H
#include <stdio.h>
#include <stdlib.h>
#include "TreeNode.h"


 struct Stack{
    int size;
    struct Node **s;
    int top;
};



void initStack(struct Stack *s,  int size) {
    s->top = -1;
    s->size = size;
    s->s =(struct Node **) malloc(sizeof(struct Node*) * size);
}

int isEmptyStack(struct Stack *s) {
    return s->top == -1;
}

int isFullStack(struct Stack *s) {
    return s->top == s->size - 1;
}

void push(struct Stack *s, struct Node* data) {
    if (isFullStack(s)) {
        printf("Stack is full\n");
        return;
    }
    s->s[++s->top] = data;

}

struct Node* pop(struct Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return s->s[s->top--];

}

struct Node* peek(struct Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return s->s[s->top];
}



#endif //TREESTACK_H
