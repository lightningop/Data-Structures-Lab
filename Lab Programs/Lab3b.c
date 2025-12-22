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
    if (isFull()) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    q[rear] = x;
}

void dequeue() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
}

void display() {
    int i;
    if (isEmpty()) return;
    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("%d ", q[i]);
    printf("%d ", q[i]);
}

int main() {
    int ch, x;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); enqueue(x); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else break;
    }
    return 0;
}
