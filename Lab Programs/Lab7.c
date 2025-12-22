#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

void insert_end(int x) {
    struct node *n = create(x), *t = head;
    if (!head) { head = n; return; }
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void insert_left(int x, int key) {
    struct node *t = head, *n = create(x);
    while (t && t->data != key) t = t->next;
    if (!t) return;
    n->next = t;
    n->prev = t->prev;
    if (t->prev) t->prev->next = n;
    else head = n;
    t->prev = n;
}

void delete_key(int key) {
    struct node *t = head;
    while (t && t->data != key) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    free(t);
}

void display() {
    struct node *t = head;
    while (t) { printf("%d ", t->data); t = t->next; }
}

int main() {
    int ch, x, k;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); insert_end(x); }
        else if (ch == 2) { scanf("%d%d", &x, &k); insert_left(x, k); }
        else if (ch == 3) { scanf("%d", &k); delete_key(k); }
        else if (ch == 4) display();
        else break;
    }
    return 0;
}
