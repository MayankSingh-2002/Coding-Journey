#include<iostream>
using namespace std;

long factorial (int num);

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << factorial (num);

}
long factorial (int num) {
    if (num == 0 || num == 1) {
        return num;
    }
    return num*factorial(num-1);
}