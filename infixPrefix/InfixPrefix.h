//
// Created by Debashis on 11/06/25.
//

#ifndef INFIXPREFIX_H
#define INFIXPREFIX_H

int isOperator(char c);
int precedence(char c);

void infixToPostfix(char *infix,char *prefix);
void infixToPrefix(char *infix,char *prefix);

#endif //INFIXPREFIX_H
