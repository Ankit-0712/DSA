#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node  *next;
};

struct node *push(struct node *head, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data = data;
    new_node ->next = head;
    head = new_node;

    return head;
}

void reverse(struct node *head){
    if(!head)
    return;

    reverse(head->next);

    printf(" %d",head->data);
}

int printList(struct node *head){
    int i = 0;
    struct node *temp = head;
    while(temp!=NULL){
        printf(" %d", temp->data);

        temp = temp->next;
        i++;
    }
    return i;
}

int main(){
    struct node * head = NULL;
    head = push(head,1);
   head =  push(head,2);
    head = push(head,3);
    head = push(head,4);
    head = push(head,5);

    printf("The given link list\n");
    int n = printList(head);

    printf("\nREverse linklist\n");
    reverse(head);

    printf("\n");


    return 0;

}