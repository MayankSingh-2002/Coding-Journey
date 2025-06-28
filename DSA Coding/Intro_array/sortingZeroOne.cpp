#include<iostream>

using namespace std;

int main() {
    int arr[100];
    int n;
    cout << "Enter size of array: "; cin >>n;
    cout << "Enter values of array: ";

    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "Array after sorting: ";

    int i=0,j=n-1;

    while(i<j) {
        while(arr[i]==0 && i<j) i++;
        while(arr[j]==1 && i<j) j--;
        
        if(i<j) {
        swap(arr[i],arr[j]);
        i++;j--;
        }
    }

    for(int i=0;i<n;i++) cout << arr[i] << " ";
    return 0;
}