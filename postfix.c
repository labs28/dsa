#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <stdlib.h>  // for atoi()

#define MAX 100

int stack[MAX];
int top = -1;

// push function
void push(int x) {
    stack[++top] = x;
}

// pop function
int pop() {
    return stack[top--];
}

// function to evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {  // if operand (number)
            push(ch - '0'); // convert char to int
        }
        else if (ch == ' ' || ch == '\t') {
            continue; // skip spaces
        }
        else { // operator
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

// main function
int main() {
    char exp[100];

    printf("Enter postfix expression (e.g., 23*5+): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}
