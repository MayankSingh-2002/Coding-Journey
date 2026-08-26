#include<iostream>
using namespace std;

int main(){
    int num, a = 0, b = 1, sum;
    cout << "Enter the digit to print fibonacci sequence: "; cin >> num;

    cout << a << " " << b << " ";
    for (int i = 2; i <= num; i++) {
        sum = a+b;
        cout << sum << " ";
        a = b;
        b = sum; 
    }
}