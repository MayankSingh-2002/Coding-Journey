#include <iostream>

using namespace std;

int main() {
    int m,n, mask=0, comp;
    cout << "Enter the number for the complement: "; cin >> n;
    m=n;

    while(m!=0) {
        mask = (mask << 1) | 1;
        m=m>>1;
    }

    comp = ~n&mask;

    cout << "The complement of number is:" << comp;

    return 0;

}