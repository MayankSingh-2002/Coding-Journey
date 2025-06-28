//Using sign flipping method.
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int arr[100];
    int size;
    cout << "Enter the size of the array: "; cin >> size;
    cout << "Enter the values of array: ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }
    cout << "Duplicates: ";
    for(int i=0; i<size; i++) {
        int idx = abs(arr[i])-1;
        if(arr[idx]>0) arr[idx]=-arr[idx];
        else cout << abs(arr[i])<< " ";     
    }

    return 0; 
}