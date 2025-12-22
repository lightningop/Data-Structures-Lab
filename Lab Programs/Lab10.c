#include <stdio.h>
#include <stdlib.h>

int *ht, m, count = 0;

void insert(int key) {
    int i = key % m;
    while (ht[i] != -1)
        i = (i + 1) % m;
    ht[i] = key;
    count++;
}

void display() {
    int i;
    for (i = 0; i < m; i++)
        printf("%d %d\n", i, ht[i]);
}

int main() {
    int n, i, x;
    scanf("%d%d", &n, &m);
    ht = malloc(m * sizeof(int));
    for (i = 0; i < m; i++) ht[i] = -1;
    while (n--) {
        scanf("%d", &x);
        if (count < m) insert(x);
    }
    display();
    return 0;
}
