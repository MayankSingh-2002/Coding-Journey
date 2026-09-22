#include<iostream>
using namespace std;

int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int minElement(int arr[], int size) {
    int min = INT8_MAX;
    for (int i = 0; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main() {
    int n;
    cout << "Enter the no. of elements in the array: ";
    cin >> n;
    int arr[n]; 
    int i;
    for(i = 0; i < n ; i++) {
        cout << "Enter the element: ";
        cin >> arr[i];
    }

    int max = maxElement(arr, n);
    int min = minElement(arr, n);

    cout << "Maximum element in the array is: " << max << endl;

    cout << "Minimum element in the array is: " << min << endl;

}
