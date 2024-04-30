#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print_data(struct node *head);
void ins_at_end(struct node *head, int data);


int main(){
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));

    head->data  = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    head->link->link = current;
    ins_at_end(head,7);
    print_data(head);

    return 0;
}

void print_data(struct node *head){
    if(head == NULL){
        printf("Linked list is empty");
        return;
    }

    struct node *ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
 void ins_at_end(struct node *head, int data){
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link !=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
 }
