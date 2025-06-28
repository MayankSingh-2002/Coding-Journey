#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int n;
    cout << "Enter the total no. of elements in array: ";
    cin >> n;

    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i < n/2; i++) {
        int temp;
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }

    cout << "Reverse of array is: ";
    for(int i=0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    return 0;
}