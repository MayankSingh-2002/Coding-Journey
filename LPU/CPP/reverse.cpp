#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the no. of elements in your array. " << endl;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++) {
        cout << "Enter value: " << endl;
        cin >> arr[i];
    }

    for(int i = 0; i < n/2; i++) {
         int temp = arr[n-(i+1)];
         arr[n-(i+1)] = arr[i];
         arr[i]= temp;
    }

    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << "\t";
    }
}