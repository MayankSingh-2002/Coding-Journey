#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int freq[101]={0};
    int size;
    cout << "Enter the size of the array: "; cin >> size;
    cout << "Enter the values of array: ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for(int i=1; i<=size; i++) {
        if(freq[i]>1){
            cout << i << " ";
        }
         
    }

    return 0; 
}