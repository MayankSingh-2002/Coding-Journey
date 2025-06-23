//Creating files with constructor and function

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout("ITEM");

    cout << "Enter item name:";
    char name[30];
    cin >> name;

    fout << name << "\n";

    cout << "Enter item cost:";
    float cost;
    cin >> cost;

    fout << cost << "\n";

    fout.close();

    ifstream fin("ITEM");
    fin >> name;
    fin >> cost;
    cout << "\n";
    cout << "Item name: " << name << "\n";
    cout << "Item cost: " << cost << "\n";

    fin.close();

    return 0;
}