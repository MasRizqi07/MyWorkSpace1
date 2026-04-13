#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

struct Barang {
    string kodeBarang, namaBarang, kategori;
    int stok;
    double hargaSatuan;
};

const int MAX_BARANG = 100, JUMLAH_GUDANG = 10;
Barang inventori[JUMLAH_GUDANG][MAX_BARANG];
int jumlahBarang[JUMLAH_GUDANG] = {0};

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "\nTekan ENTER untuk melanjutkan...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void garis() {
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
}

void header() {
    cout << "\n╔════════════════════════════════════════════════════════════════╗\n"
        << "║          SISTEM MANAJEMEN GUDANG MBG - SURABAYA UTARA             ║\n"
        << "║                    Warehouse Management System                    ║\n"
        << "╚════════════════════════════════════════════════════════════════   ╝\n";
}

void menuHeader(const string& judul, int gudang) {
    clearScreen();
    header();
    cout << "\n┌─────────────────────────────────────────┐\n"
        << "│  " << left << setw(41) << ("  " + judul) << "│\n"
        << "│        Gudang #" << gudang + 1 << "                         │\n"
        << "└─────────────────────────────────────────┘\n\n";
}

double nilaiBarang(int g, int i)  { return inventori[g][i].stok * inventori[g][i].hargaSatuan; }
double nilaiGudang(int g)         { double t = 0; for (int i = 0; i < jumlahBarang[g]; i++) t += nilaiBarang(g, i); return t; }
int    stokGudang(int g)          { int t = 0;   for (int i = 0; i < jumlahBarang[g]; i++) t += inventori[g][i].stok; return t; }

bool gudangKosong(int g) {
    if (jumlahBarang[g] == 0) { cout << "📦 Gudang masih kosong.\n"; pause(); return true; }
    return false;
}

int cariIndexByKode(int g, const string& kode) {
    for (int i = 0; i < jumlahBarang[g]; i++)
        if (inventori[g][i].kodeBarang == kode) return i;
    return -1;
}

void tambahBarang(int g) {
    menuHeader("TAMBAH BARANG BARU", g);

    if (jumlahBarang[g] >= MAX_BARANG) {
        cout << "❌ GUDANG PENUH! Tidak dapat menambah barang lagi.\n";
        pause(); return;
    }

    Barang b;
    cin.ignore();
    cout << "Kode Barang    : "; getline(cin, b.kodeBarang);
    cout << "Nama Barang    : "; getline(cin, b.namaBarang);
    cout << "Kategori       : "; getline(cin, b.kategori);
    cout << "Stok Awal      : "; cin >> b.stok;
    cout << "Harga Satuan   : Rp "; cin >> b.hargaSatuan;

    if (b.stok < 0 || b.hargaSatuan < 0) {
        cout << "\n❌ Error: Stok dan harga tidak boleh negatif!\n";
        pause(); return;
    }

    inventori[g][jumlahBarang[g]++] = b;
    cout << "\n✅ Barang berhasil ditambahkan!\n"
        << "   Total nilai barang: Rp " << fixed << setprecision(2)
        << nilaiBarang(g, jumlahBarang[g] - 1) << "\n";
    pause();
}

void lihatStokBarang(int g) {
    menuHeader("DAFTAR STOK BARANG", g);
    if (gudangKosong(g)) return;

    cout << left << setw(5) << "No" << setw(12) << "Kode" << setw(20) << "Nama Barang"
        << setw(15) << "Kategori" << right << setw(8) << "Stok"
        << setw(15) << "Harga" << setw(18) << "Total Nilai" << "\n";
    garis();

    for (int i = 0; i < jumlahBarang[g]; i++) {
        auto& b = inventori[g][i];
        cout << left << setw(5) << (i+1) << setw(12) << b.kodeBarang
            << setw(20) << b.namaBarang << setw(15) << b.kategori
            << right << setw(8) << b.stok
            << setw(15) << fixed << setprecision(0) << b.hargaSatuan
            << setw(18) << nilaiBarang(g, i) << "\n";
    }

    garis();
    cout << "\n📊 STATISTIK GUDANG:\n"
        << "   Total Jenis Barang : " << jumlahBarang[g] << "\n"
        << "   Total Stok         : " << stokGudang(g) << " unit\n"
        << "   Total Nilai Gudang : Rp " << fixed << setprecision(2) << nilaiGudang(g) << "\n";
    pause();
}

void cariBarang(int g) {
    menuHeader("PENCARIAN BARANG", g);
    if (gudangKosong(g)) return;

    string keyword;
    cin.ignore();
    cout << "Masukkan kode/nama barang: ";
    getline(cin, keyword);

    bool ditemukan = false;
    int hasil = 0;
    cout << "\n🔍 Hasil Pencarian:\n";
    garis();

    for (int i = 0; i < jumlahBarang[g]; i++) {
        auto& b = inventori[g][i];
        if (b.kodeBarang.find(keyword) != string::npos || b.namaBarang.find(keyword) != string::npos) {
            if (!ditemukan) {
                cout << left << setw(5) << "No" << setw(12) << "Kode"
                    << setw(20) << "Nama" << right << setw(8) << "Stok"
                    << setw(15) << "Harga" << "\n";
                garis();
            }
            cout << left << setw(5) << (i+1) << setw(12) << b.kodeBarang
                << setw(20) << b.namaBarang << right << setw(8) << b.stok
                << setw(15) << fixed << setprecision(0) << b.hargaSatuan << "\n";
            ditemukan = true; hasil++;
        }
    }

    if (!ditemukan) cout << "❌ Barang tidak ditemukan.\n";
    else { garis(); cout << "Ditemukan " << hasil << " barang.\n"; }
    pause();
}

void updateStokBarang(int g) {
    menuHeader("UPDATE STOK BARANG", g);
    if (gudangKosong(g)) return;

    string kode;
    cin.ignore();
    cout << "Masukkan kode barang: ";
    getline(cin, kode);

    int idx = cariIndexByKode(g, kode);
    if (idx == -1) {
        cout << "\n❌ Barang dengan kode '" << kode << "' tidak ditemukan.\n";
        pause(); return;
    }

    auto& b = inventori[g][idx];
    cout << "\n📦 Barang ditemukan:\n"
        << "   Nama  : " << b.namaBarang << "\n"
        << "   Stok  : " << b.stok << " unit\n\n";

    int pilihan, jumlah, stokLama = b.stok;
    cout << "1. Tambah stok\n2. Kurangi stok\n3. Set stok baru\nPilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Jumlah yang ditambahkan: "; cin >> jumlah;
            if (jumlah > 0) { b.stok += jumlah; cout << "\n✅ Stok berhasil ditambahkan!\n"; }
            else cout << "\n❌ Jumlah tidak valid!\n";
            break;
        case 2:
            cout << "Jumlah yang dikurangi: "; cin >> jumlah;
            if (jumlah > 0 && jumlah <= b.stok) { b.stok -= jumlah; cout << "\n✅ Stok berhasil dikurangi!\n"; }
            else cout << "\n❌ Jumlah tidak valid atau melebihi stok!\n";
            break;
        case 3:
            cout << "Stok baru: "; cin >> jumlah;
            if (jumlah >= 0) { b.stok = jumlah; cout << "\n✅ Stok berhasil diupdate!\n"; }
            else cout << "\n❌ Stok tidak boleh negatif!\n";
            break;
        default:
            cout << "\n❌ Pilihan tidak valid!\n"; pause(); return;
    }

    cout << "   Stok lama : " << stokLama << " unit\n"
        << "   Stok baru : " << b.stok << " unit\n";
    pause();
}

void hapusBarang(int g) {
    menuHeader("HAPUS BARANG", g);
    if (gudangKosong(g)) return;

    string kode;
    cin.ignore();
    cout << "Masukkan kode barang yang akan dihapus: ";
    getline(cin, kode);

    int idx = cariIndexByKode(g, kode);
    if (idx == -1) {
        cout << "\n❌ Barang tidak ditemukan.\n";
        pause(); return;
    }

    auto& b = inventori[g][idx];
    cout << "\n⚠️  KONFIRMASI PENGHAPUSAN:\n"
        << "   Kode  : " << b.kodeBarang << "\n"
        << "   Nama  : " << b.namaBarang << "\n"
        << "   Stok  : " << b.stok << " unit\n\n";

    char konfirmasi;
    cout << "Yakin ingin menghapus? (y/n): ";
    cin >> konfirmasi;

    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        for (int i = idx; i < jumlahBarang[g] - 1; i++)
            inventori[g][i] = inventori[g][i + 1];
        jumlahBarang[g]--;
        cout << "\n✅ Barang berhasil dihapus!\n";
    } else {
        cout << "\n❌ Penghapusan dibatalkan.\n";
    }
    pause();
}

void menuGudang(int g) {
    int pilihan;
    do {
        clearScreen(); header();
        cout << "\n┌─────────────────────────────────────────┐\n"
            << "│   MENU GUDANG #" << g+1 << "                      │\n"
            << "└─────────────────────────────────────────┘\n\n"
            << "1. ➕ Tambah Barang\n"
            << "2. 📊 Lihat Stok Barang\n"
            << "3. 🔍 Cari Barang\n"
            << "4. ♻️  Update Stok Barang\n"
            << "5. 🗑️  Hapus Barang\n"
            << "0. ⬅️  Kembali ke Menu Utama\n";
        garis();
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBarang(g);     break;
            case 2: lihatStokBarang(g);  break;
            case 3: cariBarang(g);       break;
            case 4: updateStokBarang(g); break;
            case 5: hapusBarang(g);      break;
            case 0: cout << "\n↩️  Kembali ke menu utama...\n"; break;
            default: cout << "\n❌ Pilihan tidak valid!\n"; pause();
        }
    } while (pilihan != 0);
}

void menuUtama() {
    int pilihan;
    do {
        clearScreen(); header();
        cout << "\n┌─────────────────────────────────────────┐\n"
            << "│        PILIH GUDANG                     │\n"
            << "└─────────────────────────────────────────┘\n\n"
            << "🏢 Daftar Gudang MBG Surabaya Utara:\n";
        garis();

        for (int i = 0; i < JUMLAH_GUDANG; i++) {
            cout << (i+1) << ". 📦 Gudang #" << (i+1)
                << " (" << jumlahBarang[i] << " jenis barang";
            if      (jumlahBarang[i] == 0)               cout << " - KOSONG";
            else if (jumlahBarang[i] >= MAX_BARANG * 0.8) cout << " - HAMPIR PENUH";
            cout << ")\n";
        }

        cout << "0. 🚪 Keluar Program\n";
        garis();
        cout << "Pilihan: ";
        cin >> pilihan;

        if      (pilihan >= 1 && pilihan <= JUMLAH_GUDANG) menuGudang(pilihan - 1);
        else if (pilihan == 0) {
            clearScreen(); header();
            cout << "\n╔════════════════════════════════════════╗\n"
                << "║   Terima kasih telah menggunakan       ║\n"
                << "║   Sistem Manajemen Gudang MBG!         ║\n"
                << "║                                        ║\n"
                << "║   © 2026 MBG Surabaya Utara            ║\n"
                << "╚════════════════════════════════════════╝\n\n";
        } else {
            cout << "\n❌ Pilihan tidak valid!\n"; pause();
        }
    } while (pilihan != 0);
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    clearScreen();
    cout << "\n\n╔════════════════════════════════════════════════════════════════╗\n"
        << "║                                                                ║\n"
        << "║              SELAMAT DATANG DI SISTEM MBG                      ║\n"
        << "║         Management Warehouse System - Surabaya Utara           ║\n"
        << "║                                                                ║\n"
        << "║              Mengelola 10 Gudang Operasional                   ║\n"
        << "║                                                                ║\n"
        << "╚════════════════════════════════════════════════════════════════╝\n\n";

    pause();
    menuUtama();
    return 0;
}