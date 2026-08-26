#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the digit to calculate factorial. " << endl;
    cin >> n;
    long fact = 1;

    for (int i = 1 ; i <= n; i++){
        fact = fact * i;   
    }

    cout << "factorial is: " << fact << endl;
}