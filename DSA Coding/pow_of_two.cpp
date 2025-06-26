#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter the number:"; cin >> num;
    int mask=31;

    if(num>0 && (num&(num-1))==0)cout << num << " :is power of 2";
    else cout << "not power of two";

    return 0;
}