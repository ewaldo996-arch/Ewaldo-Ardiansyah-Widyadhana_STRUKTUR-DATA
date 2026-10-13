
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3],
                int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    cout << "Array A awal:" << endl;
    tampilArray(A);

    cout << "\nArray B awal:" << endl;
    tampilArray(B);

    tukarArray(A, B, 1, 1);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    int x = 100;
    int y = 200;

    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "\nSetelah tukar pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}