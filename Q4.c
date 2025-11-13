//Write a program to implement a double-ended queue (Deque)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter deque size: ");
    scanf("%d", &n);

    int *dq = malloc(n * sizeof(int));
    int front = -1, rear = -1;

    void insertFront(int x) {
        if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
            printf("Overflow\n");
            return;
        }
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = n - 1;
        else
            front--;

        dq[front] = x;
    }

    void insertRear(int x) {
        if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
            printf("Overflow\n");
            return;
        }
        if (rear == -1)
            front = rear = 0;
        else if (rear == n - 1)
            rear = 0;
        else
            rear++;

        dq[rear] = x;
    }

    void deleteFront() {
        if (front == -1) {
            printf("Underflow\n");
            return;
        }
        if (front == rear)
            front = rear = -1;
        else if (front == n - 1)
            front = 0;
        else
            front++;
    }

    void deleteRear() {
        if (rear == -1) {
            printf("Underflow\n");
            return;
        }
        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = n - 1;
        else
            rear--;
    }

    void display() {
        if (front == -1) {
            printf("Empty\n");
            return;
        }
        int i = front;
        while (i != rear) {
            printf("%d ", dq[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", dq[rear]);
    }

    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    display();
}