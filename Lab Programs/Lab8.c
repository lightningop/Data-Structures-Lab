#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *l, *r;
};

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    n->data = x;
    n->l = n->r = NULL;
    return n;
}

struct node* insert(struct node *r, int x) {
    if (!r) {
        printf("Inserted %d\n", x);
        return create(x);
    }
    if (x < r->data)
        r->l = insert(r->l, x);
    else if (x > r->data)
        r->r = insert(r->r, x);
    else
        printf("Duplicate value %d not inserted\n", x);
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
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            if (!root) printf("Tree is empty\n");
            else {
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
            }
        }
        else if (ch == 3) {
            if (!root) printf("Tree is empty\n");
            else {
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
            }
        }
        else if (ch == 4) {
            if (!root) printf("Tree is empty\n");
            else {
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
            }
        }
        else if (ch == 5)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
