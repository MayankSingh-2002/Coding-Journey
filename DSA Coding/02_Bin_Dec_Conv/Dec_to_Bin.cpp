#include <iostream>
#include <string>

using namespace std;

int main() {

    int num;
    string bin;

    cout << "Enter the digit for binary conversion: "; cin >> num; cout << endl;

    for(int i=0; i<32; i++) {
        if((num&1)){
            bin.push_back('1');
        }
        else {
            bin.push_back('0');
        }
        num = num >> 1;
    }

    for(int i=31; i>=0; i--) cout<<bin[i];

    return 0;
}