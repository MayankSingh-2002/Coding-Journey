#include<iostream>

using namespace std;

int binarySearch(int arr[],int size, int key) {
    int s=0,end=size-1;
    int mid = (s+end)/2;
    while(s<=end) {
        if(arr[mid]==key) return mid;

        if (key<arr[mid]) {
         end=mid-1;
        }
        else {
            s=mid+1;
        }

        mid = (s+end)/2;
    }
    return -1;
}

int main() {
    int arr[100];
    int n,key,res;

    cout << "Enter no. of elements in array: "; cin >> n;
    cout << "Enter values of array: ";
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << "Enter the value for search: "; cin >> key;

    res=binarySearch(arr,n,key);

    if(res==-1) cout << "Key is not in the array";

    else cout << "The key is at index: " << res;


}