#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create() {
    int x;
    struct node *newNode;
    printf("Enter data(-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;

    printf("Enter left child of %d: ", x);
    newNode->left = create();

    printf("Enter right child of %d: ", x);
    newNode->right = create();

    return newNode;
}

void Preorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    struct node *root = create();
    
    printf("Preorder is:\n");
    Preorder(root);
    printf("\n");

    printf("Inorder is:\n");
    inorder(root);
    printf("\n");

    printf("Postorder is:\n");
    postorder(root);
    printf("\n");

    return 0;
}
