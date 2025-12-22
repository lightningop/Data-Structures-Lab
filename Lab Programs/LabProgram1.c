#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
        printf("Inserted %d\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Deleted %d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

int main() {
    int choice, value;
    do {
        printf("\n1.Push 2.Pop 3.Display 4.Peek 5.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 5);
    return 0;
}
