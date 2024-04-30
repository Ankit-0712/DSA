#include<stdio.h>
#include<stdlib.h>
int list_size();
struct lnode{
    int info;
    struct lnode *next;
};

struct lnode * head = NULL;
void main(){
    int n, item , choice,c,flag=1;
    int choices;
    while(flag){
        printf("Entert a choice \n1\n2\n3\n4\n5\n6\n7");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Creating  nodes\nEnter the number of nodes you want");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("Etner the info of nodes");
                    scanf("%d",&item);

                }
        }
    }
}

void create_node(int item){
    struct lnode * temp;
    struct lnode *new = (struct lnode *)malloc(sizeof(struct lnode));
    if(new == NULL){
        exit(0);

    }

    if(head==NULL){
        head = new;
        new->info = item;
        new->next = NULL;
    }else{
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
        new->info = item;


    }

}
void ins_at_beg(){
    int item;
    printf("Enter the values you want to insert at begining ");
    scanf("%d",&item);

    struct lnode *new = (struct lnode *)malloc(sizeof(struct lnode));
    if(new==NULL){
        exit(0);
    }
    else{
        if(head==NULL){
            head = new;
            new->info = item;
            new->next = NULL;
        }
        else{
            new->next =  head;
            head = new;
            new->info = item;
        }
        
    }
}
void ins_at_end(){
    int item;
    printf("Enter the values you want to insert at end");
    scanf("%d",&item);

    struct lnode * temp;
    struct lnode *new = (struct lnode*)malloc(sizeof(struct lnode));
    if(new==NULL){
        exit(0);
    }
    else{
        if(head==NULL){
            head = new;
            new->info = item;
            new->next = NULL;
        }
        else{
            temp = head;
            while(temp->next!=NULL){
                temp= temp->next;
            }

            temp->next = new;
            new->info = NULL;
            new->next = item;
        }
    }
}
void ins_at_spec(){
    int item, pos;
    struct lnode *temp;
    struct lnode *new = (struct lnode*)malloc(sizeof(struct lnode));
    int size = list_size();
    if(new==NULL){
        exit(0);
    }
    else{
        printf("Enter the position you want to insert");
        scanf("%d",&pos);
        if(pos>0 && pos<size+1){
            if(pos==1)
            ins_at_beg();

            else if(pos==size+1){
                ins_at_end();
            }
            else{
                printf("Enter the values you want to insert");
                scanf("%d",&item);
                temp = head;
                int cnt = 1;
                while(cnt=pos-1){
                    temp = temp->next;
                    cnt++;
                }
                new->info = item;
                new->next = temp->next;
                temp->next = new;
            }
        }
        else{
            printf("invalid insert pos");
        }
    }
    
}

void del_at_beg(){
    if(head==NULL){
        exit(0);
    }

    else{
        struct lnode *temp = head;
        head = head->next;
        free(temp);
    }
}

void del_at_end(){
    if(head==NULL){
        exit(0);
    }
    else{
        struct lnode * temp = head;
        struct lnode * ptr;
        while(temp->next!=NULL){
            ptr = temp;
            temp = temp->next;
        }
        ptr->next= NULL;
        free(temp);
    }
}

void del_at_spec(){
    int pos, size;
    size = list_size();
    if(head==NULL){
        exit(0);

    }
    else{
        if(pos>0 && pos<=size){
            if(pos==1){
                del_at_beg();
            }
        }
        else if(pos==size){
            del_at_end;
        }

        else{
            int count = 1;
            struct lnode *ptr;
            struct lnode * temp = head;
            while(count!=pos){
                ptr = temp;
                temp = temp->next;
                count++;
            }
            ptr->next = temp->next;
            free(temp);

        }
    }
}