#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    q[rear] = x;
    printf("Inserted %d\n", x);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", q[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("%d ", q[i]);
    printf("%d\n", q[i]);
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (ch == 2)
            dequeue();
        else if (ch == 3)
            display();
        else if (ch == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
