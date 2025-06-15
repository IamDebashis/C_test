//
// Created by Debashis on 11/06/25.
//


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../stack/Stack.h"
#include "InfixPrefix.h"


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    const int len = strlen(infix);
    Stack s;
    initStack(&s);
    int j = 0;
    int i;
    for (i = 0; i < len; i++) {
        char c = infix[i];
        if (isalnum(c) || c == '|') {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (!isEmptyStack(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmptyStack(&s) && peek(&s) == '(') {
                pop(&s);
            }
        } else {
            while (!isEmptyStack(&s) && precedence(c) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
    }

    // pop any remaining operators
    while (!isEmptyStack(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

void reverseString(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[len - i - 1];
        s[len - i - 1] = s[i];
        s[i] = temp;
    }
}

void replaceParenthesis(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            switch (s[i]) {
                case '(':
                    s[i] = ')';
                    break;
                case '{' :
                    s[i] = '}';
                case '[' :
                    s[i] = ']';
                default: ;
            }
            continue;
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            switch (s[i]) {
                case ')':
                    s[i] = '(';
                    break;
                case '}' :
                    s[i] = '{';
                case ']' :
                    s[i] = '[';
                default: ;
            }
        }
    }
}

void infixToPrefix(char *infix, char *prefix) {
    reverseString(infix);
    replaceParenthesis(infix);
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, prefix);
    reverseString(prefix);
    replaceParenthesis(prefix);
}
