#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the no. of lines: " << endl;
    cin >> n;

    for ( int i=1; i <= n; i++ ) {
        for ( int j=n-i; j >=1;j--){
            cout << " ";
        }
        for ( int j=1; j <= i; j++ ) {
            cout << j;
        }
        int m=i-1;
        for ( int j=1; j <= (i-1); j++ ) {
            cout << m;
            m--;
        }
        cout << endl;
    }
    return 0;
}