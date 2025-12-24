#include <stdio.h>
#define MAX 50

int q[MAX], front = -1, rear = -1;

void insert() {
    int x;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    printf("Enter element: ");
    scanf("%d", &x);
    q[++rear] = x;
    printf("Inserted %d\n", x);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", q[front]);
    front++;
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1)
            insert();
        else if (ch == 2)
            delete();
        else if (ch == 3)
            display();
        else if (ch == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
