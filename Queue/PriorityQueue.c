#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();
void priority(int data);

int queue[10];
int front = -1, rear = -1;

void enqueue(){
    if(rear==9){
        printf("Overflow");
        return;
    }
    printf("Enter the element");
    int data;
    scanf("%d", &data);
    if(front==-1){
        ++front;
        ++rear;

        queue[rear] = data;
        return;
    }
    priority(data);
}

void priority(int data){
    if(queue[rear]< data){
        ++rear;
        queue[rear] = data;
        return;
    }
    for(int i=front;i<=rear;i++){
        if(queue[i]>data){
            for(int j=rear+1;j>i;j--){
                queue[j] = queue[j-1];
            }
            queue[i] = data;
            ++rear;
        }
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty");

        return;
    }
    if(front==rear){
        front= -1;
        rear = -1;
        return;

    }
    ++front;
}

void display(){
    if(front==-1){
        printf("underflow");
        return;

    }
    for(int i= front;i<=rear;i++){
        printf("%d",queue[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("1.Enqueue");
        printf("2.dequeue");
        printf("3.disply");
        printf("4.exit");

        printf("Enter the choice");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("exit");
            exit(0);
        default:
            printf("Invalid input");
            break;
        }
    }
    return 0;
}