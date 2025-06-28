 #include <iostream>

 using namespace std;

 int main() {
    int arr[100];
    int n;
    int sum;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the sum: "; cin >> sum;

    cout << "Enter the values of array: ";
    for (int i=0; i<n; i++) cin >> arr[i];

    cout << "The pair of elements with sum " << sum << " is: ";

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i]+arr[j]==sum) cout << "(" << arr[i] << "," << arr[j] << ") ";
        }
    }
 }