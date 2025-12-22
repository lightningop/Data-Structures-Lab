#include <stdio.h>
#define MAX 50

int q[MAX], front = -1, rear = -1;

void insert() {
    int x;
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    scanf("%d", &x);
    q[++rear] = x;
}

void delete() {
    if (front == -1 || front > rear) return;
    front++;
}

void display() {
    int i;
    if (front == -1 || front > rear) return;
    for (i = front; i <= rear; i++) printf("%d ", q[i]);
}

int main() {
    int ch;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) insert();
        else if (ch == 2) delete();
        else if (ch == 3) display();
        else break;
    }
    return 0;
}
