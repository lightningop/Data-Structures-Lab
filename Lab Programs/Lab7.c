#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

void insert_end(int x) {
    struct node *n = create(x), *t = head;
    if (!head) {
        head = n;
        printf("Inserted %d as first node\n", x);
        return;
    }
    while (t->next)
        t = t->next;
    t->next = n;
    n->prev = t;
    printf("Inserted %d at end\n", x);
}

void insert_left(int x, int key) {
    struct node *t = head;
    while (t && t->data != key)
        t = t->next;

    if (!t) {
        printf("Key %d not found. Insertion failed\n", key);
        return;
    }

    struct node *n = create(x);
    n->next = t;
    n->prev = t->prev;

    if (t->prev)
        t->prev->next = n;
    else
        head = n;

    t->prev = n;
    printf("Inserted %d to the left of %d\n", x, key);
}

void delete_key(int key) {
    struct node *t = head;

    if (!head) {
        printf("List Underflow\n");
        return;
    }

    while (t && t->data != key)
        t = t->next;

    if (!t) {
        printf("Key %d not found\n", key);
        return;
    }

    if (t->prev)
        t->prev->next = t->next;
    else
        head = t->next;

    if (t->next)
        t->next->prev = t->prev;

    printf("Deleted node with value %d\n", key);
    free(t);
}

void display() {
    struct node *t = head;
    if (!t) {
        printf("List is empty\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x, k;
    while (1) {
        printf("\n1.Insert End\n2.Insert Left\n3.Delete Key\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insert_end(x);
        }
        else if (ch == 2) {
            printf("Enter new value and key: ");
            scanf("%d %d", &x, &k);
            insert_left(x, k);
        }
        else if (ch == 3) {
            printf("Enter key to delete: ");
            scanf("%d", &k);
            delete_key(k);
        }
        else if (ch == 4)
            display();
        else if (ch == 5)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
