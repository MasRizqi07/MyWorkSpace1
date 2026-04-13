#include <stdio.h>
#include <string.h>

// Definisi Struktur Data Siswa
struct Siswa {
    char nama[50];
    float nilai;
};

int main() {
    struct Siswa siswa[5];
    float total = 0, rata_rata;
    int i;

    printf("=== SISTEM NILAI SISWA ===\n\n");

    // Input Data
    for (i = 0; i < 5; i++) {
        printf("Masukkan nama siswa ke-%d: ", i + 1);
        scanf("%s", siswa[i].nama);
        printf("Masukkan nilai siswa ke-%d: ", i + 1);
        scanf("%f", &siswa[i].nilai);
        total += siswa[i].nilai;
    }

    rata_rata = total / 5;

    // Tampilkan Data
    printf("\n=== HASIL ===\n");
    printf("%-20s | %-10s\n", "Nama", "Nilai");
    printf("--------------------------------\n");
    
    for (i = 0; i < 5; i++) {
        printf("%-20s | %-10.2f\n", siswa[i].nama, siswa[i].nilai);
    }

    printf("--------------------------------\n");
    printf("Rata-rata kelas: %.2f\n", rata_rata);

    return 0;
}