#include <iostream>

using namespace std;

int main() {

    int n;
    cout << "Enter the digit: "; cin >> n;
    int sum=0;
    int prod=1;
    while(n!=0) {
        int digit=n%10;
        n=n/10;
        sum+=digit;
        prod*=digit;
    }

    cout << "The difference of product and sum is: " << prod-sum;
}