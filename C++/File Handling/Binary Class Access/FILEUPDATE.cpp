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
        void getdata(void)
        {
            cout << "Enter name: "; cin >> name;
            cout << "Enter code: "; cin >> code;
            cout << "Enter cost: "; cin >> cost;
        }
        void putdata(void)
        {
            cout << setw(10) << name
                 << setw(10) << code
                 << setprecision(2) << setw(10) << fixed << cost
                 << endl;
        }
};

int main()
{
    INVENTORY item;
    fstream inoutfile;

        inoutfile.open("STOCK.DAT", ios::ate | ios:: in | ios::out | ios::binary);
            inoutfile.seekg(0, ios::beg);
            cout << "CURRENT CONTENTS OF STOCK" << "\n";
            while(inoutfile.read((char*)&item, sizeof(item))) {
                item.putdata();
            }
            inoutfile.clear();

        
    cout << "\nADD AN ITEM\n";
    item.getdata();
    char ch;
    cin.get(ch);
    inoutfile.write((char*)&item, sizeof(item));

    inoutfile.seekg(0, ios::beg);

    cout << "\nCONTENTS OF APPENDED FILE \n";

    while(inoutfile.read((char*)&item, sizeof(item))) {
        item.putdata();
    }

    inoutfile.clear(); // Clear EOF state
    inoutfile.seekg(0, ios::end); // Move to end of file

    int last = inoutfile.tellg();
    int n = last / sizeof(item);

    cout << "Number of objects = " << n << endl;
    cout << "Total bytes in the file = " << last << "\n";

    cout << "Enter object number to be updated \n";
    int object;
    cin >> object;
    
    cin.get(ch); // Clear newline character from input buffer
    
    int location = (object - 1) * sizeof(item);

    if(inoutfile.eof())
    inoutfile.clear();

    inoutfile.seekp(location, ios::beg);
    cout << "Enter new values of the object \n";
    item.getdata();
    cin.get(ch); // Clear newline character from input buffer
    inoutfile.write((char*)&item, sizeof(item)) << flush;

    inoutfile.seekg(0, ios::beg);
    cout << "\nCONTENTS OF UPDATED FILE \n";

    while(inoutfile.read((char*)&item, sizeof(item))) {
        item.putdata();
    }
    inoutfile.close();
    cin.get(ch); // Wait for user input before closing
    return 0;
}