#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = x;
    n->next = NULL;
    return n;
}

void insert_begin(int x) {
    struct node *n = create(x);
    n->next = head;
    head = n;
    printf("Inserted %d at beginning\n", x);
}

void delete_begin() {
    if (!head) {
        printf("List Underflow\n");
        return;
    }
    struct node *t = head;
    printf("Deleted %d from beginning\n", t->data);
    head = head->next;
    free(t);
}

void delete_end() {
    struct node *t = head, *p = NULL;
    if (!head) {
        printf("List Underflow\n");
        return;
    }
    if (!head->next) {
        printf("Deleted %d from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (t->next) {
        p = t;
        t = t->next;
    }
    p->next = NULL;
    printf("Deleted %d from end\n", t->data);
    free(t);
}

void delete_key(int key) {
    struct node *t = head, *p = NULL;
    if (!head) {
        printf("List Underflow\n");
        return;
    }
    if (head->data == key) {
        delete_begin();
        return;
    }
    while (t && t->data != key) {
        p = t;
        t = t->next;
    }
    if (!t) {
        printf("Element %d not found\n", key);
        return;
    }
    p->next = t->next;
    printf("Deleted element %d\n", key);
    free(t);
}

void display() {
    struct node *t = head;
    if (!t) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert Begin\n2.Delete Begin\n3.Delete End\n4.Delete Key\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insert_begin(x);
        }
        else if (ch == 2)
            delete_begin();
        else if (ch == 3)
            delete_end();
        else if (ch == 4) {
            printf("Enter key: ");
            scanf("%d", &x);
            delete_key(x);
        }
        else if (ch == 5)
            display();
        else if (ch == 6)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
