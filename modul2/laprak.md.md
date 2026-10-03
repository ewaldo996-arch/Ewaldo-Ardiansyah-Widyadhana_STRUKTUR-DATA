# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ewaldo Ardiansyah Widyadhana - 109082500008</p>

## Dasar Teori


### A. MAtriks <br/>

Matriks merupakan kumpulan data yang disusun dalam bentuk baris dan kolom. Dalam pemrograman C++, matriks dapat dibuat menggunakan array dua dimensi. Array dua dimensi memiliki dua indeks yang digunakan untuk menentukan posisi data berdasarkan baris dan kolom. Matriks dapat digunakan untuk melakukan berbagai operasi seperti penjumlahan, pengurangan, dan perkalian.

#### 1. Array Dua Dimensi

Array dua dimensi digunakan untuk menyimpan data yang memiliki baris dan kolom. Pada matriks berukuran 3×3 terdapat 3 baris dan 3 kolom sehingga memiliki 9 elemen.

#### 2. Penjumlahan dan Pengurangan Matriks

Penjumlahan dilakukan dengan menjumlahkan elemen yang memiliki posisi baris dan kolom yang sama. Pengurangan dilakukan dengan cara yang sama, tetapi menggunakan operasi pengurangan.

#### 3. Perkalian Matriks

Perkalian matriks dilakukan dengan mengalikan setiap elemen pada baris matriks pertama dengan elemen pada kolom matriks kedua, kemudian hasil perkalian tersebut dijumlahkan.

### B. Pointer, Reference, Function dan Procedure<br/>

Pointer adalah variabel yang digunakan untuk menyimpan alamat dari variabel lain. Pointer dapat digunakan untuk mengubah nilai variabel melalui alamat memorinya. Reference merupakan nama lain atau alias dari suatu variabel sehingga perubahan pada reference akan memengaruhi variabel aslinya.

#### 1. Pointer

Pointer digunakan untuk mengakses dan mengubah nilai suatu variabel melalui alamat memorinya. Pada C++, pointer ditandai dengan penggunaan * dan alamat variabel dapat diambil menggunakan &.

#### 2. Reference

Reference digunakan sebagai alias dari sebuah variabel. Dengan reference, sebuah fungsi dapat mengubah nilai variabel yang dikirimkan tanpa harus membuat variabel baru.

#### 3. Function dan Procedure

Function merupakan bagian program yang digunakan untuk melakukan suatu proses dan mengembalikan nilai. Procedure pada C++ dapat dibuat menggunakan fungsi bertipe void, yaitu fungsi yang menjalankan proses tetapi tidak mengembalikan nilai secara langsung.

## Guided

### 1. ...

```C++
#include <iostream>

#define MAX 5

using namespace std;

int main(){

    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX]=
    {   {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };
   
    for (i=0; i<MAX; i++){
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";
    
    for (i=0; i<MAX; i++)
        cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
    cout<<"\n nilai tahunan : \n";
    
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++)
            cout<<nilai_tahun[i][j];
        cout<<"\n";
    }
    return 0;
}
```

tersebut berfungsi untuk meminta input 5 data nilai siswa dari pengguna yang disimpan ke dalam array 1 dimensi, lalu menampilkannya kembali ke layar. Selain itu, program juga menampilkan data matriks berukuran 5x5 dari array 2 dimensi statis bernama nilai_tahun

### 2. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout <<"Alamat x= "<< &x << endl;
    cout <<"Isi px= " << px << endl;
    cout <<"Isi x= " << x << endl;
    cout <<"Nilai yang ditunjuk px= " << *px << endl;
    cout <<"Amalat y= " << y << endl;
    return 0;
    
}
```

Mempelajari konsep pointer, di mana variabel px menyimpan alamat memori dari variabel x, lalu mengakses nilai serta alamat tersebut secara langsung maupun melalui dereference.

### 3. ...

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);

int main(){
    int x,y,z;
    cout<<"masukkan nilai bilangan ke-1 =";
    cin>>x;
    cout<<"masukkan nilai bilangan ke-2 =";
    cin>>y;
    cout<<"masukkan nilai bilangan ke-3 =";
    cin>>z;
    cout<<"nilai maksimumnya adalah ="
        <<maks3(x,y,z);
    return 0;
}

int maks3(int a, int b, int c){

    int temp_max =a;
    if(b>temp_max)
        temp_max=b;
    if(c>temp_max)
        temp_max=c;
    return (temp_max);
}
```

Mencari nilai maksimum dari tiga buah bilangan yang diinputkan pengguna menggunakan fungsi tambahan

### 4. ...

```C++
#include <iostream>
using namespace std;

void tulis(int x);
int main()
{
    int jum;
    cout << "jumlah baris kata=";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x){
    for (int i=0;i<x;i++)
        cout<<"baris ke-"<<i+1<<endl;
}
```
Menampilkan cetakan baris kata sebanyak jumlah yang diinputkan oleh pengguna menggunakan fungsi prosedur tulis berulang.

### 5. ...

```C++
#include <iostream>
using namespace std;

void tukarValue(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}   

int main() {
    int a = 5, b = 10;

    cout << "Sebelum tukarValue: a = " << a << ", b = " << b << endl;
    tukarValue(a, b);
    cout << "Setelah tukarValue: a = " << a << ", b = " << b << endl;

    cout << "Sebelum tukarPointer: a = " << a << ", b = " << b << endl;
    tukarPointer(&a, &b);
    cout << "Setelah tukarPointer: a = " << a << ", b = " << b << endl;

    cout << "Sebelum tukarReference: a = " << a << ", b = " << b << endl;
    tukarReference(a, b);
    cout << "Setelah tukarReference: a = " << a << ", b = " << b << endl;

    return 0;
}
```
Mendemonstrasikan tiga cara menukar nilai variabel ($a$ dan $b$) di C++, yaitu menggunakan fungsi dengan value/reference (tukarValue), pointer (tukarPointer), dan reference (tukarReference). 

## Unguided

### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3], C[3][3];
    int pilih;

    cout << "Masukkan matriks A:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "Masukkan matriks B:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << "\n1. Penjumlahan";
    cout << "\n2. Pengurangan";
    cout << "\n3. Perkalian";
    cout << "\nPilih: ";
    cin >> pilih;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (pilih == 1)
                C[i][j] = A[i][j] + B[i][j];

            else if (pilih == 2)
                C[i][j] = A[i][j] - B[i][j];

            else {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }

        }
    }

    cout << "\nHasil:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputGuide1_modul2.png)

Program ini digunakan untuk melakukan operasi pada dua buah matriks berukuran 3×3. Program menerima input berupa elemen matriks A dan matriks B. Setelah itu pengguna dapat memilih operasi berupa penjumlahan, pengurangan, atau perkalian. Hasil operasi disimpan ke dalam matriks C dan kemudian ditampilkan ke terminal. Pada proses perkalian digunakan perulangan tambahan untuk menghitung hasil perkalian setiap baris dan kolom.

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;

void pointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void reference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:\n";
    cout << a << " " << b << " " << c << endl;

    pointer(&a, &b, &c);

    cout << "Setelah pointer:\n";
    cout << a << " " << b << " " << c << endl;

    reference(a, b, c);

    cout << "Setelah reference:\n";
    cout << a << " " << b << " " << c << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputGuide2_modul2.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputGuide2_modul22.png)

Program ini digunakan untuk menukar nilai dari tiga variabel. Program menggunakan dua metode, yaitu pointer dan reference. Pada metode pointer, alamat variabel dikirimkan ke fungsi sehingga nilai dapat diubah melalui pointer. Sedangkan pada metode reference, variabel dikirim secara langsung sebagai reference. Pertukaran nilai dilakukan menggunakan variabel sementara temp.

### 3. (isi dengan soal unguided 3)

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/blob/main/output%20_ss/outputGuide3_modul2.png)

Program ini menggunakan array yang berisi 10 data, yaitu 48, 2, 7, 21, 5, 20, 77, 9, 10, 1. Program memiliki menu untuk menampilkan isi array, mencari nilai maksimum, mencari nilai minimum, dan menghitung rata-rata. Pencarian nilai maksimum dan minimum dilakukan menggunakan function. Sedangkan perhitungan rata-rata menggunakan procedure dengan parameter reference untuk mengembalikan hasil perhitungan ke fungsi utama.

## Kesimpulan

Praktikum ini mempelajari penggunaan array, matriks, pointer, reference, function, dan procedure dalam bahasa C++. Array dua dimensi dapat digunakan untuk menyimpan dan mengolah data berbentuk matriks, sedangkan pointer dan reference dapat digunakan untuk mengubah nilai variabel melalui fungsi. Function digunakan untuk melakukan proses yang menghasilkan nilai, sedangkan procedure digunakan untuk menjalankan proses tertentu. Dengan menggunakan konsep-konsep tersebut, program dapat dibuat lebih terstruktur dan mudah dipahami.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
