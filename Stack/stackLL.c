#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;

};

struct Node *top = NULL;

void push(int value){
    struct Node *newNode = (struct node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        exit(0);
    }
    else{
        newNode ->data = value;
        newNode ->data = top;
        top = newNode;

    }
}

int pop(){
    if(top==NULL){
        exit(0);
    }
    struct Node *temp = top;
    int popValue = temp->data;
    top = top->next;
    free(temp);
    return popValue;
}

void display(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node *ptr = top;
    while(ptr != NULL){
        printf("%d", ptr->data);

        ptr = ptr->next;
    }
    
}