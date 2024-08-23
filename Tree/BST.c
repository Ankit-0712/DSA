#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node * insert(struct Node* root, int value){
    if(root==NULL){

    
         return createNode(value);
    }
    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else if(value > root->data){
        root->right = insert(root->right,value);
    }

    return root;

}

struct Node *search(struct Node* root,int key){
    if(root==NULL || root->data==key) return root;
    if(key<root->data){
        return search(root->left,key);
    }
   
     return search(root->right, key);
    
    
}

void inorderTraversal(struct Node *root){

    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d",root->data);
        inorderTraversal(root->right);
    }
}

void preOrder(struct Node * root){
    if(root!=NULL){
        printf("%d",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root){
    if(root !=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->data);
    }
}
int height(struct Node *root){
    if(root==NULL) return 0;
    int leftHeigth = height(root->left);
    int rightHeight = height(root->right);

    return(leftHeigth > rightHeight ? leftHeigth : rightHeight) + 1;

}
struct Node *minValue(struct Node * node){
    struct Node *current = node;
    while(current && current->left !=NULL){
        current = current->left;

        return current;
    }

}

struct Node *deleteNode(struct Node* root, int key){
    if(root==NULL) return root;
    if(key< root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        
        root->right = deleteNode(root->right, key);
    }
    else{
        if(root->left==NULL){
            struct Node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);


    }
    return root;
}
int main(){
   struct Node* root = NULL;
    int choice, value;
    struct Node* searchResult;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. In-order Traversal\n5. Pre-order Traversal\n6. Post-order Traversal\n7. Height\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchResult = search(root, value);
                if (searchResult != NULL)
                    printf("Value found: %d\n", searchResult->data);
                else
                    printf("Value not found\n");
                break;
            case 4:
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 7:
                printf("Height of the tree: %d\n", height(root));
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}