#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int num;
    float ans=-1;
    cout << "Enter the number to find square root: "; cin>> num;

    int s=0,e=num;

    while(s<=e) {
        int mid=s+(e-s)/2;
        if((mid*mid)==num) {
            ans = mid;
            break;
        }
        else if((mid*mid)>num) {
            e=mid-1;
        }
        else {
            s=mid+1;
            ans=mid;
        }
    }

    float factor=1;
    for(int i=0;i<3;i++) {
        factor = factor/10;
        for(float j=ans; j*j<=num;j=j+factor) {
            ans=j;
        }
    }
    
    cout << "Square root of number is: "<< setprecision(3) << fixed << ans;
    return 0;
}