#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char x) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}


char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int precedence(char x) {
    switch(x) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char x;

    printf("Enter a valid infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];


        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else {

            switch(ch) {
                case '(':
                    push(ch);
                    break;

                case ')':

                    while ((x = pop()) != '(') {
                        postfix[j++] = x;
                    }
                    break;

                default:

                    while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                        postfix[j++] = pop();
                    }
                    push(ch);
                    break;
            }
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf(" postfix expression: %s\n", postfix);

    return 0;
}

