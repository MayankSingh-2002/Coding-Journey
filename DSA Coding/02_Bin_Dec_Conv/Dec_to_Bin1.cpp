#include <iostream>
#include <string>

using namespace std;

int main() {

    int num;
    string bin;
    cout << "Enter Number: ";
    cin >> num;

    while(num>0) {
        if(num%2==0) bin.insert(bin.begin(), '0');
        else bin.insert(bin.begin(),'1');
        num=num/2;
    }

    cout << bin << endl;

    return 0;
}