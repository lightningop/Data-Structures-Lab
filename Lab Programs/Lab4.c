#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) exit(1);
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
    printf("Inserted %d at beginning\n", x);
}

void insert_end(int x) {
    struct node *n = create(x), *t = head;
    if (!head) {
        head = n;
        printf("Inserted %d as first node\n", x);
        return;
    }
    while (t->next) t = t->next;
    t->next = n;
    printf("Inserted %d at end\n", x);
}

void insert_pos(int x, int pos) {
    int i;
    struct node *t = head;

    if (pos < 1 || pos > count() + 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insert_begin(x);
        return;
    }

    for (i = 1; i < pos - 1; i++)
        t = t->next;

    struct node *n = create(x);
    n->next = t->next;
    t->next = n;

    printf("Inserted %d at position %d\n", x, pos);
}

void display() {
    struct node *t = head;
    if (!t) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x, pos;
    while (1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            scanf("%d", &x);
            insert_begin(x);
        }
        else if (ch == 2) {
            scanf("%d", &x);
            insert_end(x);
        }
        else if (ch == 3) {
            scanf("%d %d", &x, &pos);
            insert_pos(x, pos);
        }
        else if (ch == 4)
            display();
        else if (ch == 5)
            break;
    }
    return 0;
}
