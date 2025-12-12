#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if ((front == (rear + 1) % SIZE)) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)  // first element
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("Enqueued: %d\n", x);
}

// Dequeue
void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front]);

    if (front == rear) {
        // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display
void display() {
    if (front == -1) {
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
    enqueue(50);  // full

    display();

    dequeue();
    dequeue();

    display();

    enqueue(99);
    enqueue(88);

    display();

    enqueue(77); // full

    return 0;
}
