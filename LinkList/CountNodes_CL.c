#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void push(struct node **h_ref, int data){
    struct node *ptr1 = (struct node*)malloc(sizeof(struct node));
    struct node * temp =  *h_ref;
    ptr1 ->data = data;
    ptr1->next = *h_ref;


    if(*h_ref != NULL){
        while(temp->next != *h_ref){
            temp =  temp -> next;
            temp -> next = ptr1;
        }
    }
    else{
        ptr1->next = ptr1;
        *h_ref = ptr1;
    }
}

int countNodes(struct node *head){
    struct node *temp = head;
    int count = 0;
    if(head!=NULL){
        do{
            temp = temp->next;
            count++;
        }while(temp!=NULL);
    }

    return count;

}

int main(){
     struct node *head = NULL;
     push(&head, 12);
     push(&head, 13);
     push(&head, 14);
     push(&head, 15);

     printf("%d", countNodes(head));

     return 0;
}