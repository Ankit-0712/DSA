#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(0);
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    
}

int pop() {
    if (top == NULL) {
        exit(0);
    }
    struct Node* temp = top;
    int popValue = temp->data;
    top = top->next;
    free(temp);
    return popValue;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements\n");
    struct Node* ptr = top;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("1Push\n");
        printf("2Pop\n");
        printf("3Display\n");
        printf("4Exit\n");

        printf("Enter your choice ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                printf("element popped %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
