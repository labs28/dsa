#include <stdio.h>


int stack[5];
int top = -1;

// Push function
void push(int x) {
    if (top == 4)
        printf("Stack is full\n");
    else {
        top++;
        stack[top] = x;
        printf("%d\n", x);
    }
}

// Pop function
void pop() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("%d\n", stack[top]);
        top--;
    }
}

// Display stack
void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// Main function
int main() {
    push(5);
    push(10);
    push(786);
    display();
    pop();//10 is remopved
    display();
    pop();
    pop();
    pop();
    push(99);
    push(6);
    push(88);
    push(77);
    push(55);
    push(22);
    return 0;
}
