#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int n, duplicate=0;
    cout << "Enter no. of elements in array: "; cin >>n;
    cout << "Enter the values of array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        duplicate = duplicate^arr[i]; 
    }

    for(int i=1; i<n; i++) {
        duplicate=duplicate^i;
    }

    cout << "Duplicate element is: " << duplicate;

    return 0;   
}