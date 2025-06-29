#include<iostream>

using namespace std;


int main() {
    int arr[100];
    int n,key,ans=-1;

    cout << "Enter no. of elements in array: "; cin >> n;
    cout << "Enter the key for search: "; cin >> key;
    cout << "Enter values of array: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    int s=0,e=n-1,pivot;

    while(s<e) {
        int mid = s+(e-s)/2;
        if (arr[mid]>=arr[0]) {
            s=mid+1;
        }
        else {
            e=mid;
        }
    }
    pivot = s;
    s=0; e=n-1;
    if(pivot==0) {
        s=0;
        e=n-1;
        while(s<=e) {
            int mid = s + (e-s)/2;
            if (arr[mid]==key) {
                ans=mid;
                break;
            }
            else if (arr[mid]<key) {
                s = mid+1;
            }
            else {
                e = mid -1;
            }
        }
    }
    else if(arr[s]<=key && key<=arr[pivot-1]){
        e = pivot-1;
        while(s<=e) {
            int mid = s + (e-s)/2;
            if (arr[mid]==key) {
                ans=mid;
                break;
            }
            else if (arr[mid]<key) {
                s = mid+1;
            }
            else {
                e = mid -1;
            }
        }
    }
    else {
        s = pivot;
        while(s<=e) {
            int mid = s + (e-s)/2;
            if (arr[mid]==key) {
                ans=mid;
                break;
            }
            else if (arr[mid]<key) {
                s = mid+1;
            }
            else {
                e = mid -1;
            }
        }
    }

    if(ans==-1) {
        cout << "Key is absent in the array.";
    }
    else {
    cout << "The key is at position: " << ans;
    }

    return 0;
}