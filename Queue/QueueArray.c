#include<stdio.h>
#include<stdlib.h>

#define Max_size 100
int queue[Max_size];
int front = -1, rear = -1;

void enqueue(int val){
    if(rear== Max_size-1){
        printf("Overflow\n");
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear] = val;
    }
}

int dequeue(){
    if(front==-1 && rear == -1){
        printf("Underflow\n");
    }
    else{
        int dequeued_value = queue[front];

        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    return dequeued_value;
    }
}

void display(){
    if(front==-1 && rear ==-1){
        printf("Queue is empty");
    }
    else{
        printf("Queue Element\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
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