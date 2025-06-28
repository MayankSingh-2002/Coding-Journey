#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int n,max = INT32_MIN, min = INT32_MAX;
    cout << "Enter the numbers of elements: "; cin >> n;
    for(int i=0;i<n;i++) {
        cout << "Enter the " << i+1 << " element: " << "\n";
        cin >> arr[i];
    }

    for(int i=0; i<n;i++) {
        if(arr[i]>max) max = arr[i];
        if(arr[i]<min) min = arr[i];
    }

    cout << "The largest element is: " << max << endl;
    cout << "The smallest element is: " << min << endl;

    return 0;
    
}