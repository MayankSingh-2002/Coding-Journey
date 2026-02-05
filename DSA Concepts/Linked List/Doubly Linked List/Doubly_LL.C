#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


int countNodes() {
    int count = 0;
    struct Node* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}


void insertBeginning(int value) {

    struct Node* newNode = createNode(value);
    
    if(newNode == NULL)
        return;

    if(head == NULL) {
        head = newNode;
        printf("Inserted at beginning\n");
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    printf("Inserted at beginning\n");
}


void insertEnd(int value) {
    struct Node* newNode = createNode(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Inserted at end\n");
}


void insertPosition(int value, int pos) {
    if(pos <= 0 || pos > countNodes() + 1) {
        printf("Invalid position!\n");
        return;
    }

    if(pos ==1) {
        insertBeginning(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    for(int i = 1; i < pos -1; i++)
        temp = temp->next;
    
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Inserted at position %d\n", pos);
}


void deleteBeginning() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    head = head->next;

    if(head!=NULL)
        head->prev = NULL;

    free(temp);

    printf("Deleted from beginning\n");
}


void deleteEnd() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;

    free(temp);

    printf("Deleted from end\n");
}


void deletePosition(int pos) {
    if(pos <= 0 || pos > countNodes()) {
        printf("Invalid position!\n");
        return;
    }

    if(pos ==1) {
        deleteBeginning();
        return;
    }

    struct Node* temp = head;

    for(int i = 1; i < pos; i++)
        temp = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);

    printf("Deleted from position %d\n", pos);
}


void displayForward() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    printf("Forward: ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


void displayBackward() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");

    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}


int main() {
    int choice, value, pos;

    while(1) {
        printf("\n==== DOUBLY LINKED LIST ADT MENU ====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Count Nodes\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;
            
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            
            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;
            
            case 9:
                printf("Total nodes: %d\n", countNodes());
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}