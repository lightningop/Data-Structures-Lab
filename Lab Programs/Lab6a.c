#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

struct node* insert(struct node *head, int x) {
    struct node *n = create(x);
    n->next = head;
    return n;
}

void display(struct node *h) {
    while (h) {
        printf("%d ", h->data);
        h = h->next;
    }
}

struct node* reverse(struct node *h) {
    struct node *p = NULL, *c = h, *n;
    while (c) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

struct node* sort(struct node *h) {
    struct node *i, *j;
    int t;
    for (i = h; i; i = i->next)
        for (j = i->next; j; j = j->next)
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
    return h;
}

struct node* concat(struct node *a, struct node *b) {
    struct node *t = a;
    if (!a) return b;
    while (t->next) t = t->next;
    t->next = b;
    return a;
}

int main() {
    int m, n, x;
    struct node *h1 = NULL, *h2 = NULL;
    scanf("%d%d", &m, &n);
    while (m--) { scanf("%d", &x); h1 = insert(h1, x); }
    while (n--) { scanf("%d", &x); h2 = insert(h2, x); }
    h1 = reverse(h1);
    h2 = sort(h2);
    h1 = concat(h1, h2);
    display(h1);
    return 0;
}
