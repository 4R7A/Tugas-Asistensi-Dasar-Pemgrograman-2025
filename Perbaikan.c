#include <stdio.h>  // Diperlukan untuk printf, scanf, fgets
#include <stdlib.h> // Diperlukan untuk malloc, free

/**
 * @brief Mengkonversi nilai angka (0-100) menjadi indeks huruf.
 * @param nilai Nilai angka (float).
 * @return String (const char*) yang mewakili indeks (A, AB, B, dst.).
 */
const char* index_nilai(float nilai) {
    if (nilai >= 86) {
        return "A";
    } 
    else if (nilai >= 76) {
        return "AB";
    } 
    else if (nilai >= 66) {
        return "B";
    } 
    else if (nilai >= 61) {
        return "BC";
    } 
    else if (nilai >= 56) {
        return "C";
    } 
    else if (nilai >= 41) {
        return "D";
    } 
    else {
        return "E";
    }
}

/**
 * @brief Menghitung Indeks Prestasi (IP) sebagai rata-rata tertimbang dari nilai.
 * @param matkul Array (pointer) nilai-nilai matkul (float).
 * @param sks Array (pointer) SKS untuk setiap matkul (int).
 * @param n Jumlah mata kuliah.
 * @return Nilai IP (rata-rata tertimbang).
 */
float kalkulasi_ip(float *matkul, int *sks, int n) {
    // Variabel lokal untuk total nilai dan SKS harus diinisialisasi
    float totalNilai = 0; 
    int totalSKS = 0;

    for (int i = 0; i < n; i++) {
        totalNilai += matkul[i] * sks[i];  
        totalSKS += sks[i];
    }

    // Hindari pembagian dengan nol jika totalSKS = 0
    if (totalSKS == 0) {
        return 0;
    }

    return totalNilai / (float)totalSKS; 
}

int main(){
    char nama[100]; // Ukuran buffer ditambah untuk nama panjang
    int umur;
    long long nrp; // Menggunakan long long untuk NRP (bisa menampung > 10 digit)
    int n;

    printf("Ingfo nama: ");
    // Menggunakan scanf " %[^\n]" untuk membaca string dengan spasi
    // dan membersihkan buffer
    scanf(" %[^\n]%*c", nama);

    printf("P Umur: ");
    scanf("%d" , &umur);

    printf("NRP dong biar tau: ");
    // Menggunakan %lld untuk long long
    scanf("%lld" , &nrp);

    printf("Jumlah matkul Semester ini berapa: ");
    scanf("%d", &n);

    // Alokasi memori harus menggunakan sizeof(float) untuk array float
    float *matkul = malloc(n * sizeof(float)); 
    int *sks = malloc(n * sizeof(int));

    // Cek jika alokasi memori gagal
    if (matkul == NULL || sks == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1; // Keluar dengan kode error
    }

    for(int i = 0; i < n; i++){
        printf("Masukkan nilai matkul %d tersebut \n" , i + 1);
        scanf("%f", &matkul[i]);
        printf("Masukkan SKS matkul %d tersebut \n" , i + 1);
        scanf("%d" , &sks[i]);
        
        // Logika validasi harus menggunakan OR (||)
        // Jika salah satu (nilai ATAU sks) negatif, maka input tidak valid.
        if((matkul[i] < 0) || (sks[i] < 0)){ 
            printf("Nilai matkul dan sks tidak boleh negatif. Menghentikan input.\n");
            free(matkul);
            free(sks);
            return 0;
        }
    }

    // --- Output Data Mahasiswa ---
    printf("\nNama: %s\n", nama); // Tambah \n untuk kerapian
    printf("Umur: %d \n", umur);
    printf("NRP: %lld \n" , nrp); // Menggunakan %lld untuk long long

    // --- Output Nilai ---
    for(int j = 0; j < n ; j++){
        printf("Indeks nilai matkul %d: %s\n", j + 1, index_nilai(matkul[j]));
    }
    
    float ip = kalkulasi_ip(matkul, sks, n);
    // IP yang dihitung adalah rata-rata nilai (0-100), lalu dikonversi ke indeks
    printf("Indeks Prestasi (IP) Rata-rata: %.2f (%s)\n", ip , index_nilai(ip));

    // Selalu bebaskan memori yang telah dialokasikan
    free(matkul); 
    free(sks);
    
    return 0;
}
// Kelebihan '}' di akhir file asli telah dihapus
