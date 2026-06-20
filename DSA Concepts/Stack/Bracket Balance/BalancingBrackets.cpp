#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    private:
        char arr[MAX];
        int top;
        
    public:
        Stack(){
            top = -1;
        }

        bool isEmpty(){
            return top == -1;
        }

        bool isFUll(){
            return top == 99;
        }

        void push(char value){
            if(isFUll()){
                cout << "Stack Overflow!" << endl;
                return;
            }

            top++;
            arr[top] = value;
        }

        char pop(){
            if (isEmpty()){
                return '\0';
            }

            char temp = arr[top];
            top--;
            return temp;
        }
};

bool isMatchingPair(char open, char close) {
    return  (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
}

bool checkBalanced(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if ( ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false;
            }

            char topElement = s.pop();

            if (!isMatchingPair(topElement, ch)) {
                return false;
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string expression;

    cout << "Enter expresssion: ";
    cin >> expression;

    if(checkBalanced(expression)) {
        cout << "Parentheses are Balaned." << endl;
    } else {
        cout << "Parentheses are Not Balanced." << endl;
    }

    return 0;
}