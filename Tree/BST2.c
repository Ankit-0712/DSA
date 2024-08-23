#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left = NULL;
    struct Node *right = NULL;
};

struct Node * createNode(int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node*root, int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->data){
        root->left = insert(root->left);
    }
    else if(val<root->data){
        root->right = insert(root->right);
    }
}

struct Node *search(struct Node *root, int key){
    if(root==NULL|| root->data=key) return root;
    if(key<root->data){
        return search(root->left,key);
    }
    else if(key>root->data){
        return search(root->right,key);
        
    }
}

void inorderTraversal(struct Node *root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d",root->data);
        inorderTraversal(root->right);
    }
}

void preorder(struct Node *root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

struct Node *minvalue(struct Node *node){
    struct Node *current = node;
    while(current && current->left != NULL){
        current= current->left;
        return current;
    }
}