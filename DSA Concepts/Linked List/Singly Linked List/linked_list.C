#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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
    newNode->next = NULL;

    return newNode;
}


void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    printf("Inserted at beginning.\n");
}


void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Inserted at end.\n");
}


void insertAtPosition(int value, int pos) {
    if(pos <=0) {
        printf("Invalid position!\n");
        return;
    }

    if(pos == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode =createNode(value);
    struct Node* temp = head;

    for(int i=1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at position %d.\n", pos);
}


void deleteFromBeginning() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    free(temp);

    printf("Deleted from beginning.\n");
}


void deleteFromEnd() {
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

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Deleted from end.\n");
}


void deleteByValue(int value) {

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(head->data == value) {
        deleteFromBeginning();
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        printf("Value not found!\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;

    free(toDelete);

    printf("Deleted value %d.\n", value);
}


void searchElement(int value) {

    struct Node* temp = head;
    int position = 1;

    while(temp!=NULL) {
        if(temp->data == value) {
            printf("Found %d at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Element not found!\n");
}


void displayList() {
    
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;

    printf("Linked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
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

int isEmpty() {
    return head == NULL;
}


void reverseList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while(current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;

    printf("List reversed.\n");
}


void clearList() {
    struct Node* temp;

    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    printf("List cleared.\n");
}


int main() {

    int choice, value, pos;

    while(1) {

        printf("\n==== LINKED LIST ADT MENU ====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Clear List\n");
        printf("12. Check if Empty\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromEnd();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchElement(value);
                break;

            case 8:
                displayList();
                break;

            case 9:
                printf("Total nodes: %d\n", countNodes());                
                break;
            
            case 10:
                reverseList();
                break;

            case 11:
                clearList();
                break;

            case 12:
                if(isEmpty())
                    printf("List is empty.\n");
                else
                    printf("List is NOT empty.\n");
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}