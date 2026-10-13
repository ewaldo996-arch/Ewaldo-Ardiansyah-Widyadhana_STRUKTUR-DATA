
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Jumlah mahasiswa (maksimal 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Nama  : ";
        getline(cin >> ws, mhs[i].nama);

        cout << "NIM   : ";
        cin >> mhs[i].nim;

        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir =
            0.3 * mhs[i].uts +
            0.4 * mhs[i].uas +
            0.3 * mhs[i].tugas;
    }

    cout << "\n=== DATA MAHASISWA ===" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nNama        : " << mhs[i].nama << endl;
        cout << "NIM         : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}