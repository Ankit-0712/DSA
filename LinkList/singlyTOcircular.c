#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data = data;
    new_node ->next = *head;
    *head = new_node;
}

struct node *circular(struct node *head){
    struct node *start= head;
    while(head->next!=NULL){
        head = head->next;
    }
    head->next = start;

    return start;
}

void display(struct node *node){
    struct node * start = node;
    while(node->next != start){
        printf(" %d",node->data);
        node = node->next;
    }

    printf(" %d",node->data);
}

int main(){
    struct node *head = NULL;
    push(&head,12);
    push(&head,13);
    push(&head,14);
    push(&head,15);
    push(&head,16);

    circular(head);

    printf("Display list:\n");
    display(head);

    return 0;
}
