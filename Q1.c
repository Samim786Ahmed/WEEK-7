//Write a program to implement a queue using array
#include <stdio.h>

int main() {
    int n;
    printf("Enter queue size: ");
    scanf("%d", &n);

    int queue[n];
    int front = -1, rear = -1;

    void enqueue(int x) {
        if (rear == n - 1) {
            printf("Overflow\n");
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("%d inserted\n", x);
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            printf("Underflow\n");
            return;
        }
        printf("%d deleted\n", queue[front++]);
    }

    void display() {
        if (front == -1 || front > rear) {
            printf("Queue Empty\n");
            return;
        }
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
}