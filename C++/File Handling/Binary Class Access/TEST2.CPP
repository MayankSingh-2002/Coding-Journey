#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class INVENTORY {
private:
    char name[10];
    int code;
    float cost;
public:
    void readata(void);
    void writedata(void);
};

void INVENTORY::readata(void) {
    cout << "Enter name: ";
    cin >> setw(10) >> name; // prevents overflow
    cout << "Enter code: ";
    cin >> code;
    cout << "Enter cost: ";
    cin >> cost;
}

void INVENTORY::writedata(void) {
    cout << setw(10) << name
         << setw(10) << code
         << fixed << setprecision(2) << fixed
         << setw(10) << cost << endl;
}

int main() {
    INVENTORY item[5];
    fstream file;

    // ✅ Open in binary read-write mode
    file.open("STOCK.DAT", ios::in | ios::out | ios::binary | ios::trunc);

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    cout << "ENTER DETAILS FOR 5 ITEMS\n";
    for (int i = 0; i < 5; i++) {
        item[i].readata();
        file.write((char*)&item[i], sizeof(item[i]));
    }

    file.seekg(0, ios::beg); // reset to start to read

    cout << "\nOUTPUT\n\n";
    for (int i = 0; i < 5; i++) {
        file.read((char*)&item[i], sizeof(item[i]));
        item[i].writedata();
    }

    file.close();
    return 0;
}
