#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL, *front = NULL, *rear = NULL;

void push(int x) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = x;
    n->next = top;
    top = n;
    printf("Pushed %d to stack\n", x);
}

void pop() {
    if (!top) {
        printf("Stack Underflow\n");
        return;
    }
    struct node *t = top;
    printf("Popped %d from stack\n", t->data);
    top = top->next;
    free(t);
}

void enqueue(int x) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        printf("Memory allocation failed\n");
        return;
    }
    n->data = x;
    n->next = NULL;
    if (!rear)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
    printf("Enqueued %d to queue\n", x);
}

void dequeue() {
    if (!front) {
        printf("Queue Underflow\n");
        return;
    }
    struct node *t = front;
    printf("Dequeued %d from queue\n", t->data);
    front = front->next;
    if (!front) rear = NULL;
    free(t);
}

void display_stack() {
    struct node *t = top;
    if (!t) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void display_queue() {
    struct node *t = front;
    if (!t) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display Stack\n4.Enqueue\n5.Dequeue\n6.Display Queue\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
        }
        else if (ch == 2)
            pop();
        else if (ch == 3)
            display_stack();
        else if (ch == 4) {
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (ch == 5)
            dequeue();
        else if (ch == 6)
            display_queue();
        else if (ch == 7)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
