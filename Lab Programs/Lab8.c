#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *l, *r;
};

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->l = n->r = NULL;
    return n;
}

struct node* insert(struct node *r, int x) {
    if (!r) return create(x);
    if (x < r->data) r->l = insert(r->l, x);
    else if (x > r->data) r->r = insert(r->r, x);
    return r;
}

void inorder(struct node *r) {
    if (!r) return;
    inorder(r->l);
    printf("%d ", r->data);
    inorder(r->r);
}

void preorder(struct node *r) {
    if (!r) return;
    printf("%d ", r->data);
    preorder(r->l);
    preorder(r->r);
}

void postorder(struct node *r) {
    if (!r) return;
    postorder(r->l);
    postorder(r->r);
    printf("%d ", r->data);
}

int main() {
    int ch, x;
    struct node *root = NULL;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); root = insert(root, x); }
        else if (ch == 2) inorder(root);
        else if (ch == 3) preorder(root);
        else if (ch == 4) postorder(root);
        else break;
    }
    return 0;
}
