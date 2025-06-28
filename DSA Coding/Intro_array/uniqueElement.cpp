#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int n, unique=0;
    cout << "Enter no. of elements in array: "; cin >>n;
    cout << "Enter the values of array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        unique = unique^arr[i]; 
    }

    cout << "Unique element is: " << unique;

    return 0;   
}