//Write a program to check overflow and underflow conditions
#include <stdio.h>

int main() {
    int n;
    printf("Enter queue size: ");
    scanf("%d", &n);

    int q[n], f = -1, r = -1;

    int isFull() { return r == n - 1; }
    int isEmpty() { return (f == -1 || f > r); }

    void enqueue(int x) {
        if (isFull())
            printf("Overflow\n");
        else {
            if (f == -1) f = 0;
            q[++r] = x;
            printf("%d inserted\n", x);
        }
    }

    void dequeue() {
        if (isEmpty())
            printf("Underflow\n");
        else
            printf("%d deleted\n", q[f++]);
    }

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
}