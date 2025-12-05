#include <stdio.h>
#include <ctype.h>  // for isalpha()

int main() {
    char infix[100], postfix[100], stack[100];
    int top = -1, j = 0;
    char ch;

    printf("Enter infix expression (e.g., A+B*C): ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalpha(ch))          // if operand (A, B, C...)
            postfix[j++] = ch;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            stack[++top] = ch;
        }
        else if (ch == '(')
            stack[++top] = ch;
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; // remove '('
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
