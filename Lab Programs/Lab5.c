#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insert_begin(int x) {
    struct node *n = create(x);
    n->next = head;
    head = n;
}

void delete_begin() {
    if (!head) return;
    struct node *t = head;
    head = head->next;
    free(t);
}

void delete_end() {
    struct node *t = head, *p = NULL;
    if (!head) return;
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    while (t->next) {
        p = t;
        t = t->next;
    }
    p->next = NULL;
    free(t);
}

void delete_key(int key) {
    struct node *t = head, *p = NULL;
    if (!head) return;
    if (head->data == key) {
        delete_begin();
        return;
    }
    while (t && t->data != key) {
        p = t;
        t = t->next;
    }
    if (!t) return;
    p->next = t->next;
    free(t);
}

void display() {
    struct node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    int ch, x;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); insert_begin(x); }
        else if (ch == 2) delete_begin();
        else if (ch == 3) delete_end();
        else if (ch == 4) { scanf("%d", &x); delete_key(x); }
        else if (ch == 5) display();
        else break;
    }
    return 0;
}
