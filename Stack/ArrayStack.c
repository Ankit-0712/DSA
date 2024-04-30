#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;
int stk[MAX_SIZE];

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow!\n");
    } else {
        top++;
        stk[top] = value;
        printf("%d pushed in stack\n", value);
    }
}

int pop() {
    if (top==-1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int popped_value = stk[top];
        top--;
        return popped_value;
    }
}

void display() {
    if (top==-1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stk[i]);
        }
    }
}

int main() {
    int choice, element;

    while (1) {
        
        printf("1Push\n");
        printf("2Pop\n");
        printf("3Display\n");
        printf("4Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                printf("element popped: %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
