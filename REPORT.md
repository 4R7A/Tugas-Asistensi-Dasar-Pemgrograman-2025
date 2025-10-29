# Laporan Pengerjaan Tugas Asistensi - Modul 1

**Nama:** Arya Syarif Nur Assaqy
**NRP:** 5022251259
**Program:** Kalkulator Indeks Prestasi (IP) Semester

---

## Log Perubahan (Commit)

Berikut adalah catatan perbaikan (bug fix) dan refactor yang dilakukan pada file `main.c` untuk membuatnya berfungsi:

### Commit 1: Fix - Deklarasi Variabel dan Header
* Menambahkan `#include <stdio.h>` untuk fungsi I/O (printf/scanf).
* Menambahkan `#include <stdlib.h>` untuk alokasi memori (malloc/free).
* Mendeklarasikan variabel yang hilang di `main()`: `int umur;` dan `long long nrp;`.
* Mendeklarasikan dan menginisialisasi variabel yang hilang di `kalkulasi_ip()`: `float totalNilai = 0;` dan `int totalSKS = 0;`.
* Memperbaiki sintaks parameter fungsi `index_nilai` menjadi `(float nilai)` dan `kalkulasi_ip` menjadi `(float *matkul, int *sks, int n)`.

### Commit 2: Fix - Tipe Data dan Format Specifier
* Mengubah tipe data `nrp` dari `int` (yang diasumsikan) menjadi `long long nrp;` untuk menampung NRP 10 digit.
* Mengganti format specifier `scanf` dan `printf` untuk `nrp` dari `%d` menjadi `%lld` agar sesuai dengan tipe data `long long`.

### Commit 3: Fix - Alokasi Memori
* Mengubah alokasi memori untuk `matkul` dari `malloc(n * sizeof(int))` menjadi `malloc(n * sizeof(float))` agar ukuran alokasi sesuai dengan tipe data pointernya.
* Menambahkan pengecekan `NULL` setelah `malloc` untuk `matkul` dan `sks` untuk memastikan alokasi memori berhasil.

### Commit 4: Fix - Logika Validasi Input
* Mengganti operator logika pada validasi input negatif dari `if((matkul[i] < 0) && (sks[i] < 0))` menjadi `if((matkul[i] < 0) || (sks[i] < 0))`.
* *Alasan: Program harus berhenti jika **salah satu** (bukan keduanya) dari nilai atau SKS bernilai negatif.*

### Commit 5: Refactor - Input String dan Sintaks
* Mengganti `fgets()` untuk input `nama` dengan `scanf(" %[^\n]%*c", nama)`.
* *Alasan: `fgets()` menyimpan karakter `\n` yang mengganggu output, sedangkan `scanf` ini dapat membaca spasi dan membuang `\n` dari buffer.*
* Menghapus satu kurung kurawal tutup `}` berlebih di akhir file yang menyebabkan *compile error*.

### Commit 6: Docs - Penambahan Laporan
* Membuat file `REPORT.md` dan mencatat semua perubahan yang telah dilakukan.

---

## Contoh Input/Output Program

Berikut adalah contoh eksekusi program setelah semua perbaikan dilakukan:

Ingfo nama: Arya Syarif P Umur: 19 NRP dong biar tau: 5022251259 Jumlah matkul Semester ini berapa: 3 Masukkan nilai matkul 1 tersebut 88 Masukkan SKS matkul 1 tersebut 3 Masukkan nilai matkul 2 tersebut 70 Masukkan SKS matkul 2 tersebut 2 Masukkan nilai matkul 3 tersebut 78 Masukkan SKS matkul 3 tersebut 3

Nama: Arya Syarif Umur: 19 NRP: 5022251259 Indeks nilai matkul 1: A Indeks nilai matkul 2: B Indeks nilai matkul 3: AB Indeks Prestasi (IP) Rata-rata: 80.25 (AB)
