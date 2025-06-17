#include <ctype.h>
#include <stdio.h>
#include "stack/Stack.h"
#include "infixPrefix/InfixPrefix.h"




int main2(void) {
    char infix[MAX] , postfix[MAX];

    printf("Enter infix expression: ");
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    struct  Stack s;
    initStack(&s);
   printf("%c",peek(&s));
    printf("%d",isalnum('a'));
}