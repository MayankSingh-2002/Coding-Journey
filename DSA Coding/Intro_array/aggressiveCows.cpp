#include<iostream>
#include<algorithm>

using namespace std;

bool isPossible(int arr[],int cow,int n,int mid) {
    int cowCount=1;
    int lastPos=arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i]-lastPos>=mid){
            cowCount++;
            if(cowCount==cow){
                return true;
            }
            lastPos=arr[i];
        }
    }
    return false;
}

int main() {
    int stall[100],n;
    int cow,ans=-1;

    cout<<"Enter the no. of stalls: "; cin>>n;
    cout<<"Enter the no.of cows: "; cin>>cow;
    cout<<"Enter the value of each stalls: ";
    for(int i=0;i<n;i++) cin>>stall[i];

    sort(stall,stall+n);

    int s=0,e=stall[n-1]-stall[0];
    
    while(s<=e) {
        int mid=s+(e-s)/2;
        if(isPossible(stall,cow,n,mid)) {
            ans=mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    cout << "Maximum distance between cow is: " << ans;
    
    return 0;
}