#include <iostream>
using namespace std;

class StackArray {
    private:
        int *arr;
        int top;
        int capacity;

    public:
        StackArray(int size) {
            capacity = size;
            arr = new int[capacity];
            top = -1;
        }

        ~StackArray() {
            delete[] arr;
        }

        bool isEmpty() {
            return (top == -1);
        }

        bool isFUll() {
            return (top == capacity - 1);
        }

        void push(int value) {
            if (isFUll()) {
                cout << "Stack Overflow! Cannot push" << value << endl;
                return;
            }
            arr[++top] = value;
            cout << value << " pushed into stack.\n";
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack Underflow! Cannot pop.\n";
                return;
            }
            cout << arr[top] << " popped from stack.\n";
            top--;
        }

        void peek() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }
            cout << "Top element: " << arr[top] << endl;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty.\n";
                return;
            }
            cout << "Stack elements:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
};

int main() {
    int size, choice, value;
    cout << "Enter stack size: ";
    cin >> size;

    StackArray stack(size);

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