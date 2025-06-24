#include <iostream>

using namespace std;

int main() {
    int n;
    int dec=0;
    cout << "Enter the no. to convert in Decimal: "; cin >> n;

    int pow=1;

    while(n>0) {
        if((n%10)==1)
        {
            dec=pow+dec;
        }
        n=n/10;
        pow*=2;
    }

    cout << "Deciaml conversion is:" << dec;

    return 0;
}