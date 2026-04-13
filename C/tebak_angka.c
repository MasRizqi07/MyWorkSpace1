#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;
    int max_attempts = 10;

    // Inisialisasi random seed
    srand(time(0));
    number = rand() % 100 + 1; // Angka acak 1-100

    printf("=== GAME TEBAK ANGKA ===\n");
    printf("Saya memikirkan angka antara 1 sampai 100.\n");
    printf("Kamu punya %d kesempatan.\n\n", max_attempts);

    while (attempts < max_attempts) {
        printf("Tebakan ke-%d: ", attempts + 1);
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            printf("Selamat! Kamu menebak dengan benar!\n");
            printf("Angkanya adalah %d.\n", number);
            return 0;
        } else if (guess < number) {
            printf("Terlalu rendah!\n");
        } else {
            printf("Terlalu tinggi!\n");
        }
    }

    printf("Game Over! Angkanya adalah %d.\n", number);
    return 0;
}