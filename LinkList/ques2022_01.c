#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

void searchAndUpdate(struct Node** head_ref, int key) {
    // Initialize two pointers, one to store the previous node
    // and one to iterate through the list
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp); 
        printf("%d found and deleted from the list\n", key);
        return;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("%d not found in the list\n", key);
        return;
    }

    
    prev->next = temp->next;

   
    free(temp);

    printf("%d found and deleted from the list\n", key);
}


void insertAtBeginning(struct Node** head_ref, int new_data) {
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   
    new_node->data = new_data;
    
    new_node->next = *head_ref;
    
    *head_ref = new_node;
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL; 
    int key;

    
    printf("Enter a number to search in the list: ");
    scanf("%d", &key);

   
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    
    printf("Original List: ");
    printList(head);

    
    searchAndUpdate(&head, key);

   
    printf("Updated List: ");
    printList(head);

    return 0;
}
