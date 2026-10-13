# <h1 align="center">Laporan Praktikum Modul 3 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ewaldo Ardiansyah Widyadhana - 109082500008</p>


## Guided

### 1. HEADER

```C++
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct buku{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void tampilkanisiBuku(buku buku);
bool checkpenulis(buku buku);


#endif
```

### 2. Implentasi

```C++
s#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku)
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanisiBuku(buku buku)
{
    cout<<"judul buku : "<< buku.judul<<endl;
    cout<<"halaman : "<< buku.halaman<<endl;
    cout<<"penulis : "<< buku.penulis<<endl;

}

bool checkpenulis(buku buku)
{
    return buku.penulis == "";
}

```

### 3. main

```C++
#include <iostream>
#include "buku.h"

using namespace std;

int main(){
    buku novel;
    string judul, penulis;
    int halaman;

    cout<<"masukan judul buku : ";
    cin>> judul;
    cout<<"masukan halaman buku : ";
    cin>> halaman;
    cout<<"masukan penulis buku : ";
    cin>> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanisiBuku(novel);

    cout << checkpenulis(novel);
    return 0;
}
```

## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++

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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputmodul3_soal1.png)


penjelasan unguided 1
Program ini digunakan untuk menyimpan data maksimal 10 mahasiswa menggunakan struct dan array. Data yang disimpan meliputi nama, NIM, nilai UTS, UAS, dan tugas. Nilai akhir dihitung menggunakan rumus dengan bobot UTS 30%, UAS 40%, dan tugas 30%, kemudian hasilnya ditampilkan.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:

```C++

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namapel;
    string kodepel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namapel = namapel;
    pel.kodepel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namapel << endl;
    cout << "nilai : " << pel.kodepel << endl;
}
```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputmodul3_soal2.png)



penjelasan unguided 2
Program ini menerapkan konsep Abstract Data Type (ADT) untuk mengelola data pelajaran yang terdiri dari nama pelajaran dan kode pelajaran. File pelajaran.h berisi deklarasi struktur dan fungsi, sedangkan pelajaran.cpp berisi implementasi fungsi untuk membuat dan menampilkan data pelajaran. File main.cpp digunakan untuk menjalankan fungsi tersebut.

### 3. (isi dengan soal unguided 3)

```C++

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3],
                int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    cout << "Array A awal:" << endl;
    tampilArray(A);

    cout << "\nArray B awal:" << endl;
    tampilArray(B);


    tukarArray(A, B, 1, 1);

    cout << "\nArray A setelah ditukar:" << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar:" << endl;
    tampilArray(B);

    int x = 100;
    int y = 200;

    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "\nSetelah tukar pointer:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputmodul3_soal3.png)


penjelasan unguided 3
Program ini menggunakan dua array integer berukuran 3×3 serta dua pointer integer. Fungsi tampilArray() digunakan untuk menampilkan isi array, sedangkan tukarArray() menukar elemen kedua array pada posisi tertentu. Fungsi tukarPointer() digunakan untuk menukar nilai dua variabel melalui pointer dengan bantuan variabel sementara (temp).

## Kesimpulan

Berdasarkan latihan yang telah dikerjakan, dapat disimpulkan bahwa bahasa C++ dapat digunakan untuk mengelola data menggunakan struct, array, fungsi, ADT, dan pointer. Array dan struct membantu menyimpan data secara terstruktur, ADT memisahkan deklarasi dan implementasi program agar lebih terorganisasi, sedangkan pointer memungkinkan pengaksesan dan pertukaran nilai melalui alamat memori. Dengan memahami konsep-konsep tersebut, program dapat dibuat lebih terstruktur, mudah dipahami, dan efisien.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
