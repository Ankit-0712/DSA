#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(rear==NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue(){
    if(front==NULL){
        printf("Underflow\n");
        return -1;
    }
    Node *temp = front;
    front = front->next;
    if(front==NULL){
        rear=NULL;
    }
    int data = temp->data;
    free(temp);
    return data;

}

void display(){
    Node *temp = front;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int choice, element;
    
    while(1){
        printf("1.Enqueue");
        printf("1.dequeue");
        printf("1.display");
        printf("1.Exit");

        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue\n");
            scanf("%d\n", &enqueue);
            enqueue(element);
            break;
        case 2:
            printf("dequeued element %d\n",dequeue());
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exit!");
            exit(0);
            break;

        
        default:
            printf("Invalid input");
            break;
        }

    
    }
    return 0;
}