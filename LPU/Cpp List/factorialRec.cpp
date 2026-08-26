#include<iostream>
using namespace std;

long factorial (int n) {
    if(n == 1 || n == 0) {
        return 1;
    }

    return n*factorial(n-1);
}

int main() {
    int num;
    cout << "Enter the number to calculate factorial. "; cin >> num;

    cout << "Factorial of " << num << " is " << factorial(num);
}