# <h1 align="center">Laporan Praktikum Modul 4 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ewaldo Ardiansyah Widyadhana - 109082500008</p>


## Guided

### 1. Header

```C++
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty (linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list,address nodeBaru);
void insertAfter(linkedlist &list,address nodeBaru, address prev);
void insertLast(linkedlist &list,address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);
#endif
```

### 2. implementasi

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &List)
{
    {
        List.first = Nil;
    }
}

address alokasi(string nama, string nim, int umur)
{
    {
        address nodeBaru = new node;
        nodeBaru->isidata.nama = nama;
        nodeBaru->isidata.nim = nim;
        nodeBaru->isidata.umur = umur;
        nodeBaru->next = Nil;
        return nodeBaru;
    }
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List)
{
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next !=Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deletelist(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus." << endl;
}
```

### 3. main.cpp

```C++
#include "list.h"
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
}
```

penjelasan singkat guided 3

## Unguided

### 1. Header Singlylist

```C++

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

```
penjelasan Header
berfungsi sebagai header yang berisi deklarasi tipe data, struktur node ElmList, struktur List, serta fungsi-fungsi yang digunakan dalam program Singly Linked List. Struktur node memiliki info untuk menyimpan data dan next untuk menunjuk ke node berikutnya

### 2. implementasi 

```C++

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

```
penjelasan implementasi
berisi implementasi fungsi-fungsi yang telah dideklarasikan dalam Singlylist.h. Fungsi tersebut meliputi pembuatan list kosong, alokasi node baru, pembebasan memori, menampilkan data, dan menambahkan elemen pada awal linked list.

### 3. main.cpp

```C++

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

```
penjelasan main.cpp

merupakan program utama yang menjalankan fungsi-fungsi dari Singlylist.cpp. Program membuat linked list kosong, memasukkan data 2, 0, 8, 12, dan 9 menggunakan fungsi insertFirst(), kemudian menampilkan hasilnya dengan printInfo().
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputmodul4.png)

## Kesimpulan

Berdasarkan ketiga file tersebut, dapat disimpulkan bahwa implementasi ADT Singly Linked List dalam bahasa C++ memisahkan deklarasi struktur data, implementasi fungsi, dan program utama ke dalam tiga file berbeda. Pemisahan ini membuat program lebih terorganisasi dan mudah dipahami.

Program berhasil menunjukkan cara membuat node secara dinamis, menghubungkan setiap node menggunakan pointer next, menambahkan elemen pada awal list, menampilkan seluruh elemen, serta membebaskan memori yang telah digunakan. Karena proses penyisipan dilakukan pada bagian awal, urutan data yang ditampilkan menjadi kebalikan dari urutan pemasukan data, yaitu 9, 12, 8, 0, 2.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
