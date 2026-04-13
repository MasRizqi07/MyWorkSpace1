#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi Struktur Produk
struct Produk {
    int id;
    char nama[50];
    int stok;
    float harga;
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("\n==================================");
    printf("\n   SISTEM INVENTARIS TOKO C");
    printf("\n==================================");
    printf("\n1. Tambah Barang Baru");
    printf("\n2. Lihat Semua Barang");
    printf("\n3. Cari Barang (Berdasarkan ID)");
    printf("\n4. Total Aset Toko");
    printf("\n5. Keluar");
    printf("\nPilih menu (1-5): ");
}

int main() {
    int pilihan;
    struct Produk p;
    FILE *fp;

    while (1) {
        tampilkanMenu();
        scanf("%d", &pilihan);

        if (pilihan == 5) {
            printf("Program selesai. Sampai jumpa!\n");
            break;
        }

        switch (pilihan) {
            case 1: // TAMBAH BARANG
                fp = fopen("inventaris.dat", "ab"); // Mode append binary
                printf("Masukkan ID Barang: ");
                scanf("%d", &p.id);
                printf("Nama Barang: ");
                scanf(" %[^\n]s", p.nama); // Membaca string dengan spasi
                printf("Jumlah Stok: ");
                scanf("%d", &p.stok);
                printf("Harga per Unit: ");
                scanf("%f", &p.harga);

                fwrite(&p, sizeof(struct Produk), 1, fp);
                fclose(fp);
                printf("✅ Barang berhasil disimpan!\n");
                break;

            case 2: // LIHAT SEMUA BARANG
                fp = fopen("inventaris.dat", "rb"); // Mode read binary
                if (fp == NULL) {
                    printf("❌ Data masih kosong.\n");
                    break;
                }
                printf("\n%-5s | %-20s | %-10s | %-15s\n", "ID", "Nama Barang", "Stok", "Harga");
                printf("------------------------------------------------------------\n");
                while (fread(&p, sizeof(struct Produk), 1, fp)) {
                    printf("%-5d | %-20s | %-10d | Rp %-12.2f\n", p.id, p.nama, p.stok, p.harga);
                }
                fclose(fp);
                break;

            case 3: // CARI BARANG
                {
                    int cariId, ditemukan = 0;
                    printf("Masukkan ID yang dicari: ");
                    scanf("%d", &cariId);
                    fp = fopen("inventaris.dat", "rb");
                    while (fread(&p, sizeof(struct Produk), 1, fp)) {
                        if (p.id == cariId) {
                            printf("\n🔍 Barang Ditemukan:");
                            printf("\nNama  : %s", p.nama);
                            printf("\nStok  : %d", p.stok);
                            printf("\nHarga : Rp %.2f\n", p.harga);
                            ditemukan = 1;
                            break;
                        }
                    }
                    if (!ditemukan) printf("❌ Barang dengan ID %d tidak ada.\n", cariId);
                    fclose(fp);
                }
                break;

            case 4: // TOTAL ASET
                {
                    float totalAset = 0;
                    fp = fopen("inventaris.dat", "rb");
                    if (fp == NULL) break;
                    while (fread(&p, sizeof(struct Produk), 1, fp)) {
                        totalAset += (p.stok * p.harga);
                    }
                    printf("\n💰 Total Nilai Aset di Toko: Rp %.2f\n", totalAset);
                    fclose(fp);
                }
                break;

            default:
                printf("⚠️ Pilihan tidak tersedia.\n");
        }
    }

    return 0;
}