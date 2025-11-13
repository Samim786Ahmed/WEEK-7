//Write a program to perform enqueue and dequeue operations and display the queue after each operation
#include <stdio.h>

int main() {
    int n;
    printf("Enter queue size: ");
    scanf("%d", &n);

    int queue[n], front = -1, rear = -1;

    void display() {
        if (front == -1 || front > rear) {
            printf("Empty\n");
            return;
        }
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }

    void enqueue(int x) {
        if (rear == n - 1) {
            printf("Overflow\n");
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = x;
        printf("%d inserted\n", x);
        display();
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            printf("Underflow\n");
            return;
        }
        printf("%d deleted\n", queue[front++]);
        display();
    }

    int choice, value;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}