#include <iostream>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
    private:
    Node * head;

    public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        }else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted at beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        }else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted at end.\n";
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Inserted at position " << position << ".\n";
    }

    void deleteFormBeginning() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        }else {
            Node* temp = head;
            Node* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;
            delete temp;
        }

        cout << "Deleted from beginning.\n";
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        }else {
            Node* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }

            Node* last = temp->next;
            temp->next = head;
            delete last;
        }

        cout << "Deleted from end.\n";
    }

    void deleteByValue(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        do {
            if (curr->data == value) {
                if (curr == head) {
                    deleteFormBeginning();
                }else {
                    prev->next = curr->next;
                    delete curr;
                }
                cout << "Value deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }while (curr != head);

        cout << "Value not found.\n";
    }

    void search(int value) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        int position = 1;

        do {
            if (temp->data == value) {
                cout << "Found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }while (temp != head);

        cout << "Value not found.\n";
    }

    void countNode() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        int count = 0;

        do{
            count++;
            temp = temp->next;
        }while (temp != head);

        cout << "Total nodes: " << count << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Circular List: ";

        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        }while (temp != head);

        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by value\n";
        cout << "7. Search\n";
        cout << "8. Count Nodes\n";
        cout << "9. Display\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            cll.insertAtBeginning(value);
            break;
        case 2:
            cin >> value;
            cll.insertAtEnd(value);
            break;
        case 3:
            cin >> value >> position;
            cll.insertAtPosition(value, position);
            break;
        case 4:
            cll.deleteFormBeginning();
            break;
        case 5:
            cll.deleteFromEnd();
            break;
        case 6:
            cin >> value;
            cll.deleteByValue(value);
            break;
        case 7:
            cin >> value;
            cll.search(value);
            break;
        case 8:
            cll.countNode();
            break;
        case 9:
            cll.display();
            break;
        }
    } while (choice != 0);

    return 0;
}
