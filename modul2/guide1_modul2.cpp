#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int pilih;

    cout << "Masukkan matriks A:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "Masukkan matriks B:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << "\n1. Penjumlahan";
    cout << "\n2. Pengurangan";
    cout << "\n3. Perkalian";
    cout << "\nPilih: ";
    cin >> pilih;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (pilih == 1)
                C[i][j] = A[i][j] + B[i][j];

            else if (pilih == 2)
                C[i][j] = A[i][j] - B[i][j];

            else {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }

        }
    }

    cout << "\nHasil:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}