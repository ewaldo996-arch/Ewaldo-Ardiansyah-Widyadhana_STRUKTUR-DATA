
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    P1 = nullptr;
    P2 = nullptr;
    P3 = nullptr;
    P4 = nullptr;
    P5 = nullptr;

    createList(L);

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

    printInfo(L);

    // Membebaskan seluruh memori
    address P = L.First;
    while (P != nullptr) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }

    L.First = nullptr;

    return 0;
}
