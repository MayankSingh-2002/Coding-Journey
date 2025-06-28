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
    int n,key,res=-1;

    cout << "Enter no. of elements in array: "; cin >> n;
    cout << "Enter values of array: ";
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << "Enter the value for search: "; cin >> key;
    int s=0,e=n-1;
    while(s<=e) {
        int mid = (s+e)/2;
        if(arr[mid]==key) {
            res = mid;
            e = mid-1;
        }
        else if(arr[mid]<key) {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    cout << "First occurance of element is: " << res;

    res =-1; s=0;e=n-1;

    while(s<=e) {
        int mid = (s+e)/2;
        if(arr[mid]==key) {
            res = mid;
            s = mid+1;
        }
        else if(arr[mid]<key) {
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    cout << "Last occurance of element is: " << res;
    return 0;

}