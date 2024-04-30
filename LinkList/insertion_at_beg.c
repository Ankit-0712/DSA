#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data;
    struct node * next;
};
struct node * ins_at_beg(struct node * head, int data);

int main(){
    struct node * head = malloc(sizeof(struct node));
    head->data = 34;
    head->next = NULL;

    struct node  * ptr= malloc(sizeof(struct node));
    ptr->data = 9;
    ptr->next = NULL;

    head->next = ptr;
    int data  = 3;
    head = ins_at_beg(head,data);
    ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}

struct node * ins_at_beg(struct node * head, int data){
    struct node * ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    ptr->next = head;

    head = ptr;

    return head;

}
