#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int arr2[100];
    int n1,n2;
    cout << "No. of elements in array 1: "; cin >> n1;
    cout << "No. of elements in array 2: "; cin >> n2;

    cout << "Enter elements of array 1: ";
    for(int i=0; i<n1; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter elements of array 2: ";
    for(int i=0; i<n2; i++) {
        cin >> arr2[i];
    }

    cout << "Intersection of array is: ";
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if(arr[i]==arr2[j]) {
                bool alreadyPrinted = false;
                for(int k=0;k<i;k++) {
                    if(arr[k]==arr[i]) {
                        alreadyPrinted = true;
                        break;
                    }
                }
                if(!alreadyPrinted) {
                    cout << arr[i] << " ";
                }
                break;
            }
        }
    }
    return 0;
}