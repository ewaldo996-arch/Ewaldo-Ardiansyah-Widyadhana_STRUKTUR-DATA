#include <iostream>
using namespace std;

int maksimum(int a[], int n) {
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

int minimum(int a[], int n) {
    int min = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

void rataRata(int a[], int n, float &rata) {
    int jumlah = 0;

    for (int i = 0; i < n; i++)
        jumlah += a[i];

    rata = (float)jumlah / n;
}

int main() {
    int arr[10] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int pilih;
    float rata;

    cout << "=== MENU PROGRAM ARRAY ===\n";
    cout << "1. Tampilkan isi array\n";
    cout << "2. Cari nilai maksimum\n";
    cout << "3. Cari nilai minimum\n";
    cout << "4. Hitung rata-rata\n";
    cout << "Pilih: ";
    cin >> pilih;

    if (pilih == 1) {
        for (int i = 0; i < 10; i++)
            cout << arr[i] << " ";
    }
    else if (pilih == 2) {
        cout << "Nilai maksimum = "
             << maksimum(arr, 10);
    }
    else if (pilih == 3) {
        cout << "Nilai minimum = "
             << minimum(arr, 10);
    }
    else if (pilih == 4) {
        rataRata(arr, 10, rata);
        cout << "Nilai rata-rata = " << rata;
    }

    return 0;
}