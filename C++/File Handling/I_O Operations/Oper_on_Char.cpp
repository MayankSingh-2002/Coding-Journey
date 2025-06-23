#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    char string[80];

    cout << "Enter a string: ";
    cin >> string;

    int len=strlen(string);

    fstream fout;

    cout <<  "\nOpening the 'TEXT' file and storing the storing the string in it.\n\n";

    fout.open("TEXT", ios::out | ios::in | ios::trunc);

    for (int i = 0; i < len; i++) {
        fout.put(string[i]);
    }

    fout.seekg(0, ios::beg); // Move the file pointer to the beginning

    char ch;
    cout << "Reading the file contents:  ";
    while(fout.get(ch))
    {
        cout << ch;
    }

    return 0;

}