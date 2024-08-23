#include<stdio.h>
#include<stdlib.h>

#define max_size 100

int stk[max_size];
int top = -1;

void push(int value){
    if(top==max_size-1){
        printf("overflow");
    }
    else{
        top++;
        stk[top] = value;
        printf("%d is pushed in stack", value);
    }
}

int pop(){
    if(top==-1){
        printf("Underflow");
        return -1;
    }
    else{
        int popped_value = stk[top];
        top--;
        return popped_value;
    }
}

void display(){
    if(top==-1){
        printf("List not existed");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d",stk[i]);
        }
    }
}

int main(){
    int choice, element;
    while(1){
        printf("Push");
        printf("pop");
        printf("Display");
        printf("exit");

        printf("Enter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to inserted");
            scanf("%d",&element);
            push(element);
            break;
        case 2:
            printf("Popped element %d", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit...");
            exit(0);
            break;
        
        default:
            printf("Enter a valid choice");
            break;
        }
    }
    return 0;
}