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

int count() {
    int c = 0;
    struct node *t = head;
    while (t) {
        c++;
        t = t->next;
    }
    return c;
}

void insert_begin(int x) {
    struct node *n = create(x);
    n->next = head;
    head = n;
}

void insert_end(int x) {
    struct node *n = create(x), *t = head;
    if (!head) {
        head = n;
        return;
    }
    while (t->next) t = t->next;
    t->next = n;
}

void insert_pos(int x, int pos) {
    int i = 1;
    struct node *n = create(x), *t = head;
    if (pos == 1) {
        insert_begin(x);
        return;
    }
    if (pos > count() + 1) return;
    while (i < pos - 1) {
        t = t->next;
        i++;
    }
    n->next = t->next;
    t->next = n;
}

void display() {
    struct node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    int ch, x, pos;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); insert_begin(x); }
        else if (ch == 2) { scanf("%d", &x); insert_end(x); }
        else if (ch == 3) { scanf("%d %d", &x, &pos); insert_pos(x, pos); }
        else if (ch == 4) display();
        else break;
    }
    return 0;
}
