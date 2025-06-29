#include<iostream>

using namespace std;

bool isPossible(int arr[],int n, int m, int mid) {
    int stuCount=1;
    int pageSum=0;
    for(int i=0; i<n; i++) {
        if(pageSum+arr[i]<=mid) {
            pageSum+=arr[i];
        }
        else {
            stuCount++;
            if(stuCount>m || arr[i]>mid) {
                return false;
            }
            pageSum=arr[i];
        }
    }
    return true;
}

int main() {
    int book[100];
    int n,sum=0,ans=-1;
    int m;
    cout <<"Enter no. of books in the shelf: "; cin>>n;
    cout <<"Enter no. of students: "; cin>>m;
    cout <<"Enter the no. of pages for each book: ";
    for(int i=0;i<n;i++) cin >> book[i];
    for(int i=0;i<n;i++) sum+=book[i];
    int s=0, e=sum;
    while(s<=e) {
        int mid = s+(e-s)/2;
        if(isPossible(book,n,m,mid)) {
            ans=mid;
            e = mid-1;
        }
        else {
            s=mid+1;
        }
    }

    cout << "Minimum no. of pages alloted to the student is: " << ans;
    
    return 0;
}