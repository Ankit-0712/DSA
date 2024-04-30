#include<stdio.h>
#include<stdlib.h>

struct Lnode {
    int info; 
    struct Lnode *next;
};

struct Lnode *head;


void create_node(int item);
void display_node();

int main() { 
    int n, item;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the info of node: ");
        scanf("%d", &item);
        create_node(item);
    }

    for(int i=0;i<n;i++){
        display_node();
    }

    return 0;
}

void create_node(int item) {
    struct Lnode *temp;
    struct Lnode *new_node = (struct Lnode *)malloc(sizeof(struct Lnode));
    
    if (new_node == NULL)
        exit(0);
    else {
        if (head == NULL) {
            head = new_node;
            new_node->info = item;
            new_node->next = NULL;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = NULL;
            new_node->info = item;
        }
    }
}
void display_node(){
    if(head==NULL)
    exit(0);

    else{
        struct Lnode *temp;
        temp = head;
        while(temp != NULL){
            printf("\nCurrent node address = %u and next node address =%u", temp, temp->next);
            

            temp= temp->next;
        }
    }
}


