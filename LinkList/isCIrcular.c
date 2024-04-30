#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node * new_node(int data){
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    return temp;

}

int is_circular(struct node * head){
    struct node *ptr;
    ptr= head->next;

    while(ptr!=NULL && ptr!=head){
        ptr = ptr->next;
    }

    return ptr==head;

}

int main(){
    struct node *head = new_node(1);
    head->next = new_node(3);
    head->next->next = new_node(4);
    head->next->next->next = new_node(5);

    if(is_circular(head)){
        printf("YEs\n");
    }
    else{
        printf("no\n");
    }

    head->next->next->next->next=head;
    if(is_circular(head)){
        printf("yes\n");
    }
    else{
        printf("NO");
    }

    return 0;
}


