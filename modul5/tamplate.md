# <h1 align="center">Laporan Praktikum Modul 5 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ewaldo Ardiansyah Widyadhana - 109082500008</p>

## Dasar Teori

Singly linked list adalah struktur data linier dinamis yang terdiri dari kumpulan simpul (node) yang saling terhubung menggunakan pointer. Setiap simpul pada representasi ini memiliki bagian info yang menyimpan data bertipe integer (infotype) serta bagian next yang berisi alamat penunjuk (address) menuju simpul berikutnya. Seluruh elemen di dalam list diakses melalui pointer utama bernama First, di mana list dinyatakan kosong jika nilai First adalah Nil.   

Dalam pengoperasiannya, ADT Singly Linked List melibatkan berbagai fungsi dan prosedur dasar seperti CreateList untuk pembentukan list kosong, alokasi untuk memesan ruang memori bagi simpul baru, dan dealokasi untuk mengembalikan memori simpul ke sistem. Selain itu, terdapat prosedur insertFirst untuk menyisipkan elemen baru pada awal list serta printInfo untuk menampilkan keseluruhan informasi nilai yang terdapat dalam setiap simpul.   

Operasi dasar lainnya adalah searching melalui fungsi findElm yang bertujuan untuk mencari simpul tertentu di dalam list berdasarkan nilai informasi tertentu. Proses ini bekerja dengan cara mengunjungi setiap simpul secara berurutan, lalu mengembalikan alamat (address) dari simpul tersebut jika ditemukan atau mengembalikan nilai Nil apabila elemen tidak ada di dalam list.   

## Guided

### 1. Header list.h

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

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list, address &prev);
void updateByNim(linkedlist &list, string nim);

address findNodeByData(linkedlist List, string data);
#endif
```

### 2. implementasi list.h

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List)
{
    if (List.first == Nil){
        return true;
    }else{
        return false;
    }
}

void createList(linkedList &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }else{
        cout<< "Node sebelumnya tidak valid"<< endl;
    }
}

void insertLast(linkedList &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }else
    {
        address nodeBantu = list.first;
        while(nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &list)
{
    address nodeHapus;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }else
    {
        cout<<"List Kosong" << endl;
    }
}

void delLast(linkedList &list)
{
    address nodeHapus, nodePrev;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first; 
        if(nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            while(nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }else
    {
        cout<<"List kosong"<< endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev)
{
    if(isEmpty(list) == true)
    {
        cout<< "List kosong"<<endl;
    }else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            cout<<"Node sebelumnya (prev) tidak valid"<< endl;
        }
    }
}

void printList(linkedList list)
{
    if(isEmpty(list))
    {
        cout<< "List kosong." << endl;
    }else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}


int nbList(linkedList list)
{
    int count = 0;
    address nodeBantu = list.first;
    while(nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;

    while(nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout<< "List sudah terhapus"<< endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedList &list)
{
		if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;
        list.first->isidata = newData;
    }
}

void updateLast(linkedList &list)
{
	if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        address nodeBantu = list.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }

        nodeBantu->isidata = newData;
        }
}

void updateAfter(linkedList list,address &prev)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        prev->next->isidata = newData;
    }
}

void updateByNim(linkedList &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodeByData(list, nim);

        if (nodeBantu!= Nil)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;
            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

address FindNodeByData(linkedList List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                // cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                // cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur<< endl;
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedList List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedList List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

### 3. main.cpp list.h

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
		linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
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

    // updateFirst(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN FIRST ---" << endl;
    // printList(List);

    // updateLast(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN LAST ---" << endl;
    // printList(List);

    // updateAfter(List, nodeC);
    // cout << "--- ISI LIST SETELAH DILAKUKAN AFTER ---" << endl;
    // printList(List);

    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    
    return 0;
}
```

## Unguided

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;

#define Nil nullptr

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
```

### 2.implementasi
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;

    P->info = x;
    P->next = Nil;

    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

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

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

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

int totalInfo(List L) {
    address P = L.First;
    int total = 0;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}
```
### 3. main.cpp
```C++
#include <iostream>
#include "Singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

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

    cout << "=== SINGLY LINKED LIST ===" << endl;
    printInfo(L);

    cout << "\n=== PENCARIAN ELEMEN ===" << endl;

    address hasil = findElm(L, 8);

    if (hasil != Nil) {
        cout << "Elemen 8 ditemukan." << endl;
        cout << "Nilai elemen: " << hasil->info << endl;
    } else {
        cout << "Elemen 8 tidak ditemukan." << endl;
    }

    cout << "\n=== TOTAL ELEMEN ===" << endl;
    cout << "Total seluruh nilai: "
         << totalInfo(L) << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/ouputmodul5.png)
contoh :

## Kesimpulan

Program C++ ini mengimplementasikan struktur data Singly Linked List yang terbagi menjadi berkas header, berkas implementasi fungsi, dan program utama. Berdasarkan eksekusi pada program utama, alur dimulai dengan menginisialisasi linked list kosong menggunakan prosedur createList. Sebanyak lima nilai integer yaitu 2, 0, 8, 12, dan 9 kemudian dimasukkan ke dalam list secara berurutan dengan metode penyisipan di depan melalui fungsi insertFirst. Karena menggunakan metode penyisipan di depan, urutan akhir elemen di dalam linked list dari depan ke belakang menjadi 9, 12, 8, 0, 2, dan diakhiri dengan NULL.   Setelah data dimasukkan, program menampilkan seluruh isi linked list menggunakan fungsi printInfo. Program juga melakukan pencarian elemen bernilai 8 menggunakan fungsi findElm, yang kemudian memberikan informasi bahwa elemen tersebut berhasil ditemukan di dalam list. Pada bagian akhir, program menghitung total keseluruhan nilai elemen yang ada di dalam linked list menggunakan fungsi totalInfo.   

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
