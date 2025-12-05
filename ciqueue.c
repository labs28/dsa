#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}
// Check if queue is empty
int isEmpty() {
    return (front == -1);
}
// Insert element
void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty())
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("%d added\n", x);
}
// Delete element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d removed\n", queue[front]);
    if (front == rear) { // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // Queue full
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    enqueue(70);
    display();
    return 0;
}
