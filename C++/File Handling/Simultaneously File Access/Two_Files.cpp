// Reads the files created in Program 11.2

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main() {
    const int N = 80;
    char line[N];

    ifstream fin1, fin2;
    fin1.open("COUNTRY");
    fin2.open("Capital");

    for (int i =1; i <= 10; i++) {
        if(fin1.eof()!= 0) {
            cout << "Exit from country \n";
            exit(1);
        }

        fin1.getline(line, N);
        cout << "Capital of " << line ;

        if(fin2.eof()!= 0) {
            cout << "Exit from capital \n";
            exit(1);
        }

        fin2.getline(line, N);
        cout << " is "<< line << "\n";
    }

    fin1.close();
    fin2.close();

    return 0;
}
