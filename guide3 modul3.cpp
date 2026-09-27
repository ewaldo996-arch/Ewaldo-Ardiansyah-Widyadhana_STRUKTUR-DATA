#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {

        
        for (int s = n; s > i; s--) {
            cout << "  ";
        }

        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        
        cout << "*";

        
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }

        cout << endl;
    }

    return 0;
}