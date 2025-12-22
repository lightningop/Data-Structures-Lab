#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL, *front = NULL, *rear = NULL;

void push(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop() {
    if (!top) return;
    struct node *t = top;
    top = top->next;
    free(t);
}

void enqueue(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if (!rear) front = rear = n;
    else rear->next = n, rear = n;
}

void dequeue() {
    if (!front) return;
    struct node *t = front;
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}

void display_stack() {
    struct node *t = top;
    while (t) { printf("%d ", t->data); t = t->next; }
}

void display_queue() {
    struct node *t = front;
    while (t) { printf("%d ", t->data); t = t->next; }
}

int main() {
    int ch, x;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); push(x); }
        else if (ch == 2) pop();
        else if (ch == 3) display_stack();
        else if (ch == 4) { scanf("%d", &x); enqueue(x); }
        else if (ch == 5) dequeue();
        else if (ch == 6) display_queue();
        else break;
    }
    return 0;
}
