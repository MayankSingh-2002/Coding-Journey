//Creating files with open() function

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open("COUNTRY");

    fout <<"Unites States of America\n";
    fout <<"United Kingdom\n";
    fout <<"South Korea\n";

    fout.close();

    fout.open("Capital");

    fout <<"Washington D.C.\n";
    fout <<"London\n";
    fout <<"Seoul\n";

    fout.close();

    const int N = 80;
    char line[N];

    ifstream fin;
    fin.open("COUNTRY");

    cout << "Contents of COUNTRY file:\n";

    while(fin) {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();
    fin.open("Capital");

    cout << "\nContents of Capital file:\n";

    while(fin) {
        fin.getline(line, N);
        cout << line << "\n";
    }

    fin.close();

    return 0;

}