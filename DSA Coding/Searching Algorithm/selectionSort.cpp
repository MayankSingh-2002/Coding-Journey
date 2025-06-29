#include<iostream>
#include<climits>

using namespace std;

void selectionSort(int arr[],int n) {
    for(int i=0;i<n-1;i++) {
        int idx=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[idx]) {
                idx=j;
            } 
        }
        int temp=arr[i];
        arr[i]=arr[idx];
        arr[idx]=temp;
    }
}

int main() {
    int arr[100];
    int n;

    cout << "Enter the size of the array: "; cin >> n;
    cout << "Enter the values of array: ";
    for(int i=0; i<n;i++) cin >> arr[i];

    cout << "Array after sorting is: " << endl;

    selectionSort(arr,n);

    for(int i=0; i<n;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}