#include<iostream>
using namespace std;

int main() {

    char str1[100], str2[100];
    cout << "Enter the string. ";

    cin.getline(str1,100);

    int i;

    for(i = 0; str1[i]!='\0'; i++)
        str2[i] = str1[i];
    
    str2[i] = '\0';

    cout << "Value of string 1 is: " << str1 << endl;
    cout << "Value of string 2 is: " << str2 << endl;

}