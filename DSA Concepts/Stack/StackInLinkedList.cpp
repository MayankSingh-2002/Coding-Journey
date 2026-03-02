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

class StackLinkedList {
    private:
        Node* top;

    public:
        StackLinkedList() {
            top = NULL;
        }

        bool isEmpty() {
            return (top == NULL);
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            cout << value << " pushed into stack.\n";
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack Underflow! Cannot pop.\n";
                return;
            }

            Node* temp = top;
            cout << temp->data << " popped from stack.\n";
            top = top->next;
            delete temp;
        }

        void peek() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }
            cout << "Top element: " << top->data << endl;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }

            cout << "Stack elements:\n";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }

        ~StackLinkedList() {
            while (!isEmpty()) {
                pop();
            }
        }
};

int main() {
    StackLinkedList stack;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}