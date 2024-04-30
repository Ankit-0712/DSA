#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;



void enqueue(int value) {
    if (rear == MAX_SIZE-1) {
        printf(" Overflow!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf(" Underflow!\n");
        return -1;
    } else {
        int dequeued_value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return dequeued_value;
    }
}

void display() {
    if (front==-1&& rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
