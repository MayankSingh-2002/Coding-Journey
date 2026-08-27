#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100], str2[100];
    cout << "Enter the string.: ";
    cin.getline(str1,100);

    strcpy(str2, str1);

    cout << "String one is: " << str1 << endl;
    cout << "String two is: " << str2 << endl;
}