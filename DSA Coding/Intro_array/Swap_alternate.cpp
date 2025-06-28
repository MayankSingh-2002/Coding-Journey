#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int n;
    cout << "Enter no. of elements in array: "; cin >>n;
    cout << "Enter the values of array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n-1; i=i+2) {
        int temp;
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }

    cout << "Array after alternate swaping: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;   
}