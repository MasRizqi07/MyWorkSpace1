#include <stdio.h>
#include <math.h>

// ============================
// SOAL 1: Ganjil & Genap
// ============================
void soal1() {
    int x = 238; // x = 100 + 138 (3 digit terakhir NIM)
    int genap[238];
    int count_ganjil = 0;
    int count_genap = 0;

    printf("============================================\n");
    printf("   SOAL 1 - x = %d bilangan (NIM: ...138)\n", x);
    printf("============================================\n\n");

    // Cari ganjil dan genap dari 1 sampai x
    for (int i = 1; i <= x; i++) {
        if (i % 2 != 0) {
            // Bilangan ganjil + simpan hanya 5 bilangan pertama
            if (count_ganjil < 5) {
                count_ganjil++;
            }
        } else {
            // Bilangan genap - simpan semua ke array
            genap[count_genap] = i;
            count_genap++;
        }
    }

    // Tampilkan 5 bilangan ganjil pertama (1,3,5,7,9)
    printf("5 Bilangan GANJIL PERTAMA dari 1 sampai %d:\n", x);
    printf("  -> ");
    int g = 0;
    for (int i = 1; i <= x && g < 5; i++) {
        if (i % 2 != 0) {
            printf("%d", i);
            g++;
            if (g < 5) printf(", ");
        }
    }
    printf("\n\n");

    // Tampilkan 5 bilangan genap terakhir
    printf("5 Bilangan GENAP TERAKHIR dari 1 sampai %d:\n", x);
    printf("  -> ");
    for (int j = count_genap - 5; j < count_genap; j++) {
        printf("%d", genap[j]);
        if (j < count_genap - 1) printf(", ");
    }
    printf("\n\n");
}

// ============================
// SOAL 2: Bilangan Prima
// ============================
int isPrima(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= (int)sqrt((double)n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void soal2() {
    int x = 88; // x = 50 + 38 (2 digit terakhir NIM)

    printf("============================================\n");
    printf("   SOAL 2 - Bilangan Prima dari 1 sampai %d\n", x);
    printf("   (x = 50 + 38, NIM: ...138)\n");
    printf("============================================\n\n");

    printf("Bilangan Prima dari 1 sampai %d:\n  -> ", x);

    int pertama = 1;
    for (int i = 2; i <= x; i++) {
        if (isPrima(i)) {
            if (!pertama) printf(", ");
            printf("%d", i);
            pertama = 0;
        }
    }
    printf("\n\n");
}

// ============================
// MAIN
// ============================
int main() {
    printf("\n");
    printf("*********************************************\n");
    printf("*        EXERCISE 1 - ALGORITMA & C        *\n");
    printf("*        NIM: ...138                        *\n");
    printf("*********************************************\n\n");

    soal1();
    soal2();

    printf("*********************************************\n");
    printf("*              SELESAI                      *\n");
    printf("*********************************************\n\n");

    return 0;
}