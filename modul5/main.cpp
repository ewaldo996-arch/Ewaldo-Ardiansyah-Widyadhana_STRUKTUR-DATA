#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    // Membuat list kosong
    createList(L);

    // Memasukkan data ke dalam list
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    // Menampilkan linked list
    cout << "=== SINGLY LINKED LIST ===" << endl;
    printInfo(L);

    // Mencari elemen bernilai 8
    cout << "\n=== PENCARIAN ELEMEN ===" << endl;

    address hasil = findElm(L, 8);

    if (hasil != Nil) {
        cout << "Elemen 8 ditemukan." << endl;
        cout << "Nilai elemen: " << hasil->info << endl;
    } else {
        cout << "Elemen 8 tidak ditemukan." << endl;
    }

    // Menghitung total seluruh elemen
    cout << "\n=== TOTAL ELEMEN ===" << endl;
    cout << "Total seluruh nilai: "
         << totalInfo(L) << endl;

    return 0;
}