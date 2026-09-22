#include<iostream>
using namespace std;

void value(int a, int b) {
    a = 10;
    b = 20;
    cout <<"Call by value \nValue of a is: " << a << " and b is: " << b << endl;
}

void pointer(int *a, int *b) {
    *a = 11;
    *b = 21;
    cout << "Call by reference \nValue of a is: " << *a << " and b is: " << *b << endl;
}

void reference(int &a, int &b) {
    a = 12;
    b = 22;
    cout << "Call by address\nValue of a is: " << a << " and b is: " << b << endl;
}

int main(int argc, char const *argv[])
{
    int a = 5, b = 10;
    cout << "Value of a is: " << a << " and b is: " << b << endl;
    value(a, b);
    cout << "After call by value: \n Value of a is: " << a << " and b is: " << b << endl;
    pointer(&a, &b);
    cout << "After call by pointer: \n Value of a is: " << a << " and b is: " << b << endl;
    reference(a, b);
    cout << "After call b reference: \n Value of a is: " << a << " and b is: " << b << endl;
    return 0;
}
