#include<iostream>

using namespace std;


int main() {
    int arr[100];
    int n;

    cout << "Enter no. of elements in array: "; cin >> n;
    cout << "Enter values of array: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    int s=0,e=n-1;

    while(s<e) {
        int mid = s+(e-s)/2;
        if (arr[mid]>=arr[0]) {
            s=mid+1;
        }
        else {
            e=mid;
        }
    }

    cout << "Pivot of array is: " << s;


    return 0;
}