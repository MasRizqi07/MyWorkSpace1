#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definisi struktur data untuk satu kontak
struct Kontak {
    char nama[50];
    char nomor[15];
    char email[50];
};

// Definisi maksimum jumlah kontak yang bisa disimpan
#define MAX_KONTAK 100
#define FILE_NAME "kontak.txt"

// Fungsi untuk membandingkan string case insensitive
int caseInsensitiveCompare(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
            return 1;
        }
        s1++;
        s2++;
    }
    return *s1 != *s2;
}

// Fungsi untuk menginisialisasi file jika belum ada
void initFile() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Gagal membuat file kontak!\n");
        exit(1);
    }
    fclose(file);
}

// Fungsi untuk menambah kontak baru
void tambahKontak() {
    struct Kontak kontak;
    FILE *file;
    
    // Validasi input
    printf("\n=== TAMBAH KONTAK ===\n");
    printf("Nama: ");
    scanf("%s", kontak.nama);
    printf("Nomor HP: ");
    scanf("%s", kontak.nomor);
    printf("Email: ");
    scanf("%s", kontak.email);
    
    // Buka file dalam mode append (menambah di akhir)
    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis!\n");
        return;
    }
    
    // Tulis data ke file dengan format khusus
    fprintf(file, "%s|%s|%s\n", kontak.nama, kontak.nomor, kontak.email);
    fclose(file);
    
    printf("Kontak berhasil ditambahkan!\n");
}

// Fungsi untuk menampilkan semua kontak
void tampilkanKontak() {
    struct Kontak kontak;
    FILE *file;
    char line[150];
    int count = 0;
    
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("File kontak belum ada atau tidak ditemukan!\n");
        return;
    }
    
    printf("\n=== DAFTAR KONTAK ===\n");
    printf("%-20s | %-15s | %-30s\n", "Nama", "Nomor HP", "Email");
    printf("------------------------------------------------------------\n");
    
    // Baca file baris demi baris
    while (fgets(line, sizeof(line), file) != NULL) {
        // Parse data dari string ke struktur
        char *token = strtok(line, "|");
        if (token != NULL) strcpy(kontak.nama, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(kontak.nomor, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(kontak.email, token);
        
        // Tampilkan data yang sudah diparse
        printf("%-20s | %-15s | %-30s\n", 
            kontak.nama, kontak.nomor, kontak.email);
        count++;
    }
    
    fclose(file);
    printf("Total kontak: %d\n", count);
}

// Fungsi untuk mencari kontak berdasarkan nama
void cariKontak() {
    struct Kontak kontak;
    FILE *file;
    char namaCari[50];
    char line[150];
    int found = 0;
    
    printf("\n=== CARI KONTAK ===\n");
    printf("Masukkan nama yang dicari: ");
    scanf("%s", namaCari);
    
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("File kontak belum ada!\n");
        return;
    }
    
    printf("\nHasil pencarian:\n");
    printf("%-20s | %-15s | %-30s\n", "Nama", "Nomor HP", "Email");
    printf("------------------------------------------------------------\n");
    
    // Baca dan cari sesuai nama
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "|");
        if (token != NULL) strcpy(kontak.nama, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(kontak.nomor, token);
        
        token = strtok(NULL, "|");
        if (token != NULL) strcpy(kontak.email, token);
        
        // Bandingkan nama (case insensitive sederhana)
        if (caseInsensitiveCompare(kontak.nama, namaCari) == 0) {
            printf("%-20s | %-15s | %-30s\n", 
            kontak.nama, kontak.nomor, kontak.email);
            found = 1;
        }
    }
    
    fclose(file);
    if (!found) {
        printf("Kontak tidak ditemukan!\n");
    }
}

// Fungsi untuk menghapus kontak berdasarkan nama
void hapusKontak() {
    struct Kontak kontak;
    FILE *file, *temp;
    char namaCari[50];
    char line[150];
    int found = 0;
    
    printf("\n=== HAPUS KONTAK ===\n");
    printf("Masukkan nama yang akan dihapus: ");
    scanf("%s", namaCari);
    
    file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("File kontak belum ada!\n");
        return;
    }
    
    // Buat file sementara untuk menyimpan data yang tidak dihapus
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        fclose(file);
        printf("Gagal membuat file sementara!\n");
        return;
    }
    
    // Baca file asli dan tulis ke temp kecuali yang dihapus
    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, "|");
        if (token != NULL) strcpy(kontak.nama, token);
        
        if (strcmp(kontak.nama, namaCari) != 0) {
            // Jika nama tidak cocok, tulis ke file temp
            fprintf(temp, "%s", line);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(temp);
    
    // Ganti file asli dengan file temp
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);
    
    if (found) {
        printf("Kontak berhasil dihapus!\n");
    } else {
        printf("Kontak tidak ditemukan!\n");
    }
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    printf("\n=== SISTEM MANAJEMEN KONTAK ===\n");
    printf("1. Tambah Kontak\n");
    printf("2. Tampilkan Semua Kontak\n");
    printf("3. Cari Kontak\n");
    printf("4. Hapus Kontak\n");
    printf("5. Keluar\n");
    printf("Pilih menu (1-5): ");
}

int main() {
    int pilihan;
    
    // Inisialisasi file jika belum ada
    initFile();
    
    // Loop menu utama
    while (1) {
        tampilkanMenu();
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                tambahKontak();
                break;
            case 2:
                tampilkanKontak();
                break;
            case 3:
                cariKontak();
                break;
            case 4:
                hapusKontak();
                break;
            case 5:
                printf("Terima kasih! Program selesai.\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
    
    return 0;
}