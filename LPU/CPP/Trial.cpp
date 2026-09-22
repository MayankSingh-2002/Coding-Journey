#include<iostream>
using namespace std;

int factorial(int n) {
    int fact =1;
    
    for(int i =1; i <=n; i++) 
    fact *=1;

    return fact;
}

int main(){
    int num = 145;
    int original = num, sum = 0;

    while(num > 0) {
        int digit = num%10;

        sum += factorial(digit);
        int num = num/10;
    }

    if(sum == original)
    cout << original << " is Strong Number.";
    else cout << original << " is not strong number.";

    return 0;
}