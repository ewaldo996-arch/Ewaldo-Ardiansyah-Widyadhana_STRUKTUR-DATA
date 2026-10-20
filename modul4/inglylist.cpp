
#include <iostream>
#include "Singlylist.h"

using namespace std;

void createList(List &L) {
    L.First = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(List L) {
    address P = L.First;

    while (P != nullptr) {
        cout << P->info;

        if (P->next != nullptr) {
            cout << " ";
        }

        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P != nullptr) {
        P->next = L.First;
        L.First = P;
    }
}
