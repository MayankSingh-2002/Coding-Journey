#include <iostream>

using namespace std;

int main() {
    int num;
    int rev=0;
    int digit;
    cout << "Enter the digit you want to reverse: "; cin >> num;

    while(num>0) {
        digit=num%10;
        rev=rev*10+digit;
        num/=10;
    }

    cout << "Reverse of the number is:" << rev;

    return 0;
}