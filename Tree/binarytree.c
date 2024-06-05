#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;

};

struct Node* createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value){
    if(root==NULL){
        return createNode(value);
    }
    
    if(value < root->data ){
        root->left = insert(root->left , value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrderTravelsal(struct Node* root){
    if(root!=NULL){
        inOrderTravelsal(root->left);
        printf("%d ",root->data);
        inOrderTravelsal(root->right);
    }
}

int main(){

    struct Node* root= NULL;
     root = insert(root, 50);
     insert(root, 30);
     insert(root, 40);
     insert(root, 70);
     insert(root, 20);
     insert(root, 80);
     insert(root, 60);
     insert(root, 10);

     inOrderTravelsal(root);

     return 0;
}