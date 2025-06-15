//
// Created by Debashis on 11/06/25.
//

#ifndef STACK_H
#define STACK_H
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
}Stack;


void initStack(Stack *s);
void push(Stack *s, char x);
char pop(Stack *s);
int isEmptyStack(Stack *s);
int isFullStack(Stack *s);
char peek(Stack *s);

#endif //STACK_H
