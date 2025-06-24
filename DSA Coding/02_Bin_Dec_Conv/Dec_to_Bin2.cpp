#include <iostream>

using namespace std;

int main() {

    int num;
    int binary=0;
    cout << "Enter Number: ";
    cin >> num;

    int i=1;

    while(num>0) {
        int digit=num%2;
        binary= i*digit+binary;
        num=num/2;
        i=i*10;
    }

    cout << binary << endl;

    return 0;
}