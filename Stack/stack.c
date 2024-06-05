#include<stdio.h>
#include<stdlib.h>
#define max_size 100

int top = - 1;
int stk[max_size];

void push(int value){
    if(top = max_size - 1){
        printf("overflow\n");

    }
    else{
        top++;
        stk[top] = value;
        printf("%d, pushed in stack", value);
    }
}

int pop(){
    if(top ==-1){
        printf("Underflow\n");
        return -1;
    }
    else{
        int poped_elemet = stk[top];
        top--;
        return poped_elemet;
    }
}
void display(){
    if(top == -1){
        printf("stack is empty");

    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d",stk[i]);
        }
    }
}

int main(){
    int choice,  element;

    while(1){
        printf("1Push\n");
        printf("2Pop\n");
        printf("3Disply\n");
        printf("1Exit\n");

        printf("Enter your choice");
        scanf("%d",&choice);
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