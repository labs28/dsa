#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push character to stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop character from stack
char pop() {
    return stack[top--];
}

int main() {
    char str[MAX], reversed[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);  // reads one word (simple for beginners)

    // Push all characters onto stack
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters to get reversed string
    i = 0;
    while (top != -1) {
        reversed[i++] = pop();
    }
    reversed[i] = '\0';   // end the string

    printf("Reversed string: %s\n", reversed);

    return 0;
}
