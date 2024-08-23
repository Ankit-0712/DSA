#include<stdio.h>
#define size 5
int dequeue[size];
int front = -1, rear = -1;

void insert_front(int x){
    if((front==0 && rear==size-1)||(front==rear+1)){
        printf("Overflow");
    }
    else if((front==-1)&& (rear==-1)){
        front = rear = 0;
        dequeue[front] = x;

    }
    else if(front==0){
        front = size-1;
        dequeue[front] = x;
    }
    else{
        front = front+1;
        dequeue[front] = x;

    }
}

void insert_rear(int x){
    if((front==0 && rear ==size-1)|| (front==rear+1)){
        printf("Overflow");
    }
    else if((front==-1)&&(rear==-1)){
        rear = 0;
        dequeue[rear] = x;
    }
    else if(rear==size-1){
        rear = 0;
        dequeue[rear] = x;

    }
    else{
        rear++;
        dequeue[rear] = x;
    }
}

void display(){
    int i = front;
    printf("The elements in deque are\n");

    while(i!=rear){
        printf("%d",dequeue[i]);
        i = (i+1)%size;
    }
    printf("%d",dequeue[rear]);
}

void getFront(){
    if((front==-1)&&(rear==-1)){
        printf("Dequeue is empty");
    }
    else{
        printf("\nThe value of element at front is%d", dequeue[front]);
    }
}

void getrear(){
    if((front==-1)&&(rear==-1)){
        printf("Empty");
        
    }else{
        printf("\nThe value of the element at rear is %d",dequeue[rear]);
    }
}

void deleteFront(){
    if((front==-1)&&(rear==-1)){
        printf("Empty");
    }
    else if(front==rear){
        printf("\ndeleted elment is %d", dequeue[front]);

        front=-1;
        rear = -1;
    }
    else if(front==(size-1)){
        printf("\nThe deleted element is %d",dequeue[front]);
        front=0;

    }
    else{
        printf("\nThe deleted element is %d", dequeue[front]);
        front = front+1;
    }
}
void delete_rear()    
{    
    if((front==-1) && (rear==-1))    
    {    
        printf("Deque is empty");    
    }    
    else if(front==rear)    
    {    
        printf("\nThe deleted element is %d", dequeue[rear]);    
        front=-1;    
        rear=-1;    
            
    }    
     else if(rear==0)    
     {    
         printf("\nThe deleted element is %d", dequeue[rear]);    
         rear=size-1;    
     }    
     else    
     {    
          printf("\nThe deleted element is %d", dequeue[rear]);    
          rear=rear-1;    
     }    
}
int main()    
{    
    insert_front(20);    
    insert_front(10);    
    insert_rear(30);    
    insert_rear(50);    
    insert_rear(80);    
    display();  // Calling the display function to retrieve the values of deque    
    getFront();  // Retrieve the value at front-end  
    getrear();  // Retrieve the value at rear-end   
    deleteFront();    
    delete_rear();    
    display(); // calling display function to retrieve values after deletion   
    return 0;    
} 