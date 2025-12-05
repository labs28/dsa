#include <stdio.h>

int queue[5];
int front = 0, rear = -1;

// Function to insert element
void enqueue(int x) {
    if (rear == 4)
        printf("Queue is full\n");
    else {
        rear++;
        queue[rear] = x;
        printf("%d added\n", x);
    }
}
// Function to delete element
void dequeue() {
    if (front > rear)
        printf("Queue is empty\n");
    else {
        printf("%d removed\n", queue[front]);
        front++;
        if (front > rear) { // Reset when queue becomes empty
            front = 0;
            rear = -1;
        }
    }
}

// Function to show elements
void display() {
    if (front ==-1)
        printf("Queue is empty\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);  // will show queue full
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();    // will show queue empty
    return 0;
}
