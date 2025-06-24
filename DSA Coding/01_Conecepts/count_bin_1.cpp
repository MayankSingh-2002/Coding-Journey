#include <iostream>

using namespace std;

int main() {
    int n;
    int count=0;
    cout << "Enter the digit: "; cin >> n;
    while(n!=0) {
        if(n&1) count++;
        n=n>>1;
    }

    cout << "Total 1's in the binary form of number is: "<<count;
}