//Write a program to implement a circular queue
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter queue size: ");
    scanf("%d", &n);

    int *cq = malloc(n * sizeof(int));
    int front = -1, rear = -1;

    void enqueue(int x) {
        if ((rear + 1) % n == front) {
            printf("Overflow\n");
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % n;
        cq[rear] = x;
        printf("%d inserted\n", x);
    }

    void dequeue() {
        if (front == -1) {
            printf("Underflow\n");
            return;
        }
        printf("%d deleted\n", cq[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % n;
    }

    void display() {
        if (front == -1) {
            printf("Empty\n");
            return;
        }
        printf("Queue: ");
        int i = front;
        while (i != rear) {
            printf("%d ", cq[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", cq[rear]);
    }

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}