#include <iostream>
#include "Singlylist.h"

using namespace std;

// Membuat list kosong
void createList(List &L) {
    L.First = Nil;
}

// Membuat elemen baru
address alokasi(infotype x) {
    address P = new ElmList;

    P->info = x;
    P->next = Nil;

    return P;
}

// Menghapus elemen dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menampilkan seluruh elemen
void printInfo(List L) {
    address P = L.First;

    cout << "Isi Linked List: ";

    while (P != Nil) {
        cout << P->info;

        if (P->next != Nil) {
            cout << " -> ";
        }

        P = P->next;
    }

    cout << " -> NULL" << endl;
}

// Menambahkan elemen di awal list
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// Mencari elemen berdasarkan nilai
address findElm(List L, infotype x) {
    address P = L.First;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }

        P = P->next;
    }

    return Nil;
}

// Menghitung total seluruh nilai elemen
int totalInfo(List L) {
    address P = L.First;
    int total = 0;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}