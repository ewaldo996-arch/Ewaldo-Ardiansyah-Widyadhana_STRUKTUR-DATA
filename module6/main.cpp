#include <iostream>
#include "Doublylist.h"

using namespace std;

// Fungsi pembantu untuk insertFirst sesuai urutan tumpukan pada output contoh
void insertFirst(List &L, address P) {
    if (L.First == nullptr && L.Last == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;

    // --- BAGIAN 1: Input Data Kendaraan ---
    // Input 1
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    P = alokasi(data);
    insertFirst(L, P);
    cout << endl;

    // Input 2
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    P = alokasi(data);
    insertFirst(L, P);
    cout << endl;

    // Input 3 (Uji coba nomor polisi duplikat)
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    if (findElm(L, data) != nullptr) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertFirst(L, P);
    }
    cout << endl;

    // Input 4
    cout << "masukkan nomor polisi: ";
    cin >> data.nopol;
    cout << "masukkan warna kendaraan: ";
    cin >> data.warna;
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    P = alokasi(data);
    insertFirst(L, P);
    cout << endl;

    // Menampilkan isi List
    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    // --- BAGIAN 2: Cari Elemen (Soal No. 2) ---
    infotype cariData;
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cariData.nopol;
    
    address found = findElm(L, cariData);
    if (found != nullptr) {
        cout << endl;
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;

    // --- BAGIAN 3: Hapus Elemen (Soal No. 3) ---
    infotype hapusData;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusData.nopol;

    address target = findElm(L, hapusData);
    address deletedNode = nullptr;

    if (target != nullptr) {
        if (target == L.First) {
            deleteFirst(L, deletedNode);
        } else if (target == L.Last) {
            deleteLast(L, deletedNode);
        } else {
            deleteAfter(target->prev, deletedNode);
        }

        if (deletedNode != nullptr) {
            cout << "Data dengan nomor polisi " << deletedNode->info.nopol << " berhasil dihapus." << endl;
            dealokasi(deletedNode);
        }
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << endl;
    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}