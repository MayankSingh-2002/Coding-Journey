#include <iostream>

using namespace std;

int main() 
{
    int n;
    cout << "Enter the terms for fibonaaci series: "; cin >> n;
    int a=0;
    int b=1;
    int term=0;

    for(int i=1; i <=n; i++) {
        if(i==1) cout << a <<" ";
        else if(i==2){
         cout << b <<" ";
        }
        else{
        term=a+b;
        cout << term << " ";
        a=b;
        b=term;
        }
    }

    return 0;

}