//
// Created by Debashis on 11/06/25.
//

#ifndef STACK_H
#define STACK_H
#define MAX 100


 struct Stack{
    char data[MAX];
    int top;
};


void initStack(struct Stack *s);
void push(struct Stack *s, char x);
char pop(struct Stack *s);
int isEmptyStack(struct Stack *s);
int isFullStack(struct Stack *s);
char peek(struct Stack *s);

#endif //STACK_H
