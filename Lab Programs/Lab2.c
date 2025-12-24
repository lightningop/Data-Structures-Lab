#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int pr(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;
    printf("enter infix:");
    scanf("%s", infix);
    push('#');

    while ((ch = infix[i++]) != '\0') {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while (pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (stack[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("%s", postfix);

    return 0;
}
