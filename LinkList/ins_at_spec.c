#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
void ins_at_end(struct node * head, int data);
void add_at_pos(struct node * head, int data, int pos);


int main(){
    struct node * head = malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    ins_at_end(head,98);
    ins_at_end(head,5);

    int data = 63, position = 3;
    add_at_pos(head,data,position);
    struct node *ptr = head;

    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
void add_at_pos(struct node * head, int data, int pos){
    struct node * ptr = head;
    struct node * ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->next = NULL;
    pos--;
    while(pos !=1){
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;

}

void ins_at_end(struct node * head, int data){
    struct node * ptr, *temp;
    ptr = head;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    while(ptr->next!=NULL){
        ptr = ptr->next;
    }

    ptr->next = temp;

    
}