//Write a program to implement a priority queue
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, size = 0;
    printf("Enter queue size: ");
    scanf("%d", &n);

    int *pq = malloc(n * sizeof(int));

    void enqueue(int x) {
        if (size == n) {
            printf("Overflow\n");
            return;
        }
        int i = size - 1;
        while (i >= 0 && pq[i] > x) {
            pq[i + 1] = pq[i];
            i--;
        }
        pq[i + 1] = x;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            printf("Underflow\n");
            return;
        }
        printf("%d deleted\n", pq[0]);
        for (int i = 0; i < size - 1; i++)
            pq[i] = pq[i + 1];
        size--;
    }

    void display() {
        if (size == 0) {
            printf("Empty\n");
            return;
        }
        printf("Priority Queue: ");
        for (int i = 0; i < size; i++)
            printf("%d ", pq[i]);
        printf("\n");
    }

    enqueue(30);
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    display();
}