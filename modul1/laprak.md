# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ewaldo Ardiansyah Widyadhana - 109082500008</p>

## Dasar Teori


### A. ...<br/>

1. Bahasa C++

C++ merupakan bahasa pemrograman yang dapat digunakan untuk membuat berbagai jenis program. C++ memiliki struktur program yang terdiri dari fungsi, variabel, tipe data, operator, percabangan, dan perulangan. Dalam pemrograman C++, program umumnya dimulai dari fungsi main() sebagai fungsi utama yang akan dijalankan terlebih dahulu

2. Tipe Data dan Variabel

Tipe data digunakan untuk menentukan jenis nilai yang dapat disimpan oleh sebuah variabel. Beberapa tipe data yang umum digunakan dalam C++ adalah int untuk bilangan bulat, float untuk bilangan pecahan, dan string untuk menyimpan teks. Variabel digunakan sebagai tempat penyimpanan data yang nilainya dapat digunakan atau diubah selama program berjalan

3. Input dan Output

Input digunakan untuk menerima data dari pengguna, sedangkan output digunakan untuk menampilkan hasil pemrosesan program. Pada C++, proses input dapat dilakukan menggunakan cin, sedangkan output menggunakan cout. Keduanya tersedia melalui library iostream

### B. ...<br/>

1. Operator

Operator merupakan simbol yang digunakan untuk melakukan operasi terhadap suatu nilai atau variabel. Operator aritmatika pada C++ meliputi penjumlahan (+), pengurangan (-), perkalian (*), dan pembagian (/). Operator tersebut dapat digunakan untuk melakukan perhitungan dalam program.

2. Percabangan

Percabangan digunakan untuk menentukan perintah yang akan dijalankan berdasarkan kondisi tertentu. Salah satu bentuk percabangan pada C++ adalah if, else if, dan else. Percabangan dapat digunakan untuk menentukan keluaran yang berbeda sesuai dengan nilai input yang diberikan



### 1. (isi dengan soal unguided 1)

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;

    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian = " << a / b << endl;
    } else {
        cout << "Pembagian tidak dapat dilakukan karena pembagi 0" << endl;
    }

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/ewaldo996-arch/Ewaldo-Ardiansyah-Widyadhana_STRUKTUR-DATA/tree/main/STRUKTUR_DATA/modul1/output_ss/output_guide1.png)

penjelasan unguided 1

Program pertama dibuat untuk menerima input berupa dua buah bilangan bertipe float. Kedua bilangan tersebut kemudian digunakan untuk melakukan empat operasi aritmatika, yaitu penjumlahan, pengurangan, perkalian, dan pembagian. Program menggunakan cin untuk menerima input dari pengguna dan cout untuk menampilkan hasil operasi. Pada operasi pembagian diberikan pengecekan agar pembagian dengan angka nol tidak dilakukan. Dengan program ini, pengguna dapat mengetahui hasil dari beberapa operasi aritmatika berdasarkan dua bilangan yang dimasukkan.

### 2. (isi dengan soal unguided 2)

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan",
        "sembilan", "sepuluh", "sebelas"
    };

    if (angka >= 0 && angka <= 11) {
        cout << satuan[angka] << endl;
    }
    else if (angka < 20) {
        cout << satuan[angka - 10] << " belas" << endl;
    }
    else if (angka < 100) {
        int puluhan = angka / 10;
        int satuanAngka = angka % 10;

        cout << satuan[puluhan] << " puluh";

        if (satuanAngka != 0) {
            cout << " " << satuan[satuanAngka];
        }

        cout << endl;
    }
    else if (angka == 100) {
        cout << "seratus" << endl;
    }
    else {
        cout << "Angka harus 0 sampai 100" << endl;
    }

    return 0;
}
```

### Output Unguided 2 :


##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

Program kedua dibuat untuk menerima input berupa bilangan bulat dari 0 sampai 100 dan mengubah bilangan tersebut menjadi bentuk tulisan dalam bahasa Indonesia. Program menggunakan array bertipe string untuk menyimpan nama-nama bilangan dari nol sampai sebelas. Selanjutnya, percabangan if, else if, dan else digunakan untuk menentukan bentuk tulisan berdasarkan nilai angka yang dimasukkan. Untuk angka puluhan, program memisahkan nilai puluhan dan satuan menggunakan operasi pembagian dan modulus. Dengan demikian, angka seperti 79 dapat ditampilkan menjadi "tujuh puluh sembilan", sedangkan angka 100 ditampilkan sebagai "seratus".

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {

        
        for (int s = n; s > i; s--) {
            cout << "  ";
        }

        
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        
        cout << "*";

        
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

penjelasan unguided 3

Program ketiga digunakan untuk membuat pola berbentuk segitiga terbalik berdasarkan angka yang dimasukkan oleh pengguna. Program menggunakan perulangan for untuk mengatur jumlah baris, spasi, dan angka yang ditampilkan. Pada setiap baris, jumlah angka semakin sedikit sehingga pola membentuk segitiga terbalik. Tanda * diletakkan di bagian tengah setiap baris sebagai pemisah antara angka bagian kiri dan kanan. Spasi pada awal baris juga digunakan agar posisi pola semakin ke tengah pada baris berikutnya. Jika input yang diberikan adalah 3, maka pola yang dihasilkan adalah tiga baris angka dan satu baris terakhir yang hanya berisi tanda

## Kesimpulan

Praktikum ini memberikan pemahaman mengenai dasar pemrograman menggunakan bahasa C++. Dari ketiga program yang dibuat, dapat dipahami penggunaan input dan output, tipe data, operator aritmatika, percabangan, array, serta perulangan. Program pertama menerapkan operasi aritmatika pada dua bilangan float, program kedua menggunakan percabangan dan array untuk mengubah angka menjadi tulisan, sedangkan program ketiga menggunakan perulangan untuk menghasilkan pola segitiga terbalik. Dengan menerapkan beberapa konsep dasar tersebut, program C++ dapat digunakan untuk mengolah input dan menghasilkan output sesuai dengan kebutuhan.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
