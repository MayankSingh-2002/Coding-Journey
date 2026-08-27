#include<iostream>
using namespace std;

int main() {

    string str1, str2;
    cout << "Enter a string." << endl;

    getline(cin, str1);

    str2 = str1;

    cout << "String one is: " << str1 << endl;
    cout << "String two is: " << str2 << endl;
}