#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BG_BLUE     "\033[44m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_CYAN     "\033[46m"
#define BG_MAGENTA  "\033[45m"
#define BRIGHT_RED      "\033[91m"
#define BRIGHT_GREEN    "\033[92m"
#define BRIGHT_YELLOW   "\033[93m"
#define BRIGHT_BLUE     "\033[94m"
#define BRIGHT_MAGENTA  "\033[95m"
#define BRIGHT_CYAN     "\033[96m"
#define BRIGHT_WHITE    "\033[97m"

struct Kereta {
    string nomorKA;
    string namaKA;
    string tujuan;
    int    jumlahRangkaian;
    string jamKedatangan;
    Kereta* next;
};

struct DataGapeka {
    string nomorKA;
    string namaKA;
    string tujuan;
    int    jumlahRangkaian;
    string jamKedatangan;
};

DataGapeka GAPEKA_DO8[] = {
    // ── Kelas Eksekutif / Premium ──
    {"KA 1",   "Bima",              "Jakarta Gambir",   16, "19:00"},
    {"KA 2",   "Bima",              "Surabaya Gubeng",  16, "06:30"},
    {"KA 5",   "Argo Bromo Anggrek","Jakarta Gambir",   10, "09:00"},
    {"KA 6",   "Argo Bromo Anggrek","Surabaya Pasarturi",10,"20:45"},
    {"KA 7",   "Argo Lawu",         "Jakarta Gambir",   10, "08:00"},
    {"KA 17",  "Sembrani",          "Jakarta Gambir",   12, "17:00"},
    {"KA 18",  "Sembrani",          "Surabaya Pasarturi",12,"07:15"},
    {"KA 41",  "Gajayana",          "Jakarta Gambir",   14, "16:30"},
    {"KA 42",  "Gajayana",          "Malang",           14, "08:00"},
    {"KA 45",  "Brawijaya",         "Jakarta Gambir",   10, "10:30"},
    // ── Kelas Bisnis / Campuran ──
    {"KA 79",  "Gumarang",          "Jakarta Pasarsenen",12,"15:00"},
    {"KA 80",  "Gumarang",          "Surabaya Pasarturi",12,"07:30"},
    {"KA 81",  "Harina",            "Bandung",          10, "17:15"},
    {"KA 82",  "Harina",            "Surabaya Pasarturi",10,"08:20"},
    {"KA 119", "Ranggajati",        "Cirebon",          10, "07:00"},
    {"KA 120", "Ranggajati",        "Surabaya Gubeng",  10, "18:45"},
    {"KA 121", "Mutiara Selatan",   "Bandung",          12, "14:00"},
    {"KA 122", "Mutiara Selatan",   "Surabaya Gubeng",  12, "09:10"},
    // ── Kelas Ekonomi ──
    {"KA 143", "Kertajaya",         "Jakarta Pasarsenen",8, "21:00"},
    {"KA 144", "Kertajaya",         "Surabaya Pasarturi",8, "05:45"},
    {"KA 151", "Pasundan",          "Kiaracondong",      8, "07:00"},
    {"KA 152", "Pasundan",          "Surabaya Gubeng",   8, "18:00"},
    {"KA 161", "Logawa",            "Purwokerto",        8, "06:00"},
    {"KA 162", "Logawa",            "Surabaya Gubeng",   8, "20:30"},
    {"KA 175", "Sri Tanjung",       "Ketapang (Banyuwangi)",8,"05:30"},
    {"KA 176", "Sri Tanjung",       "Yogyakarta",        8, "15:20"},
    {"KA 181", "Probowangi",        "Ketapang (Banyuwangi)",6,"08:15"},
    {"KA 182", "Probowangi",        "Surabaya Gubeng",   6, "19:00"},
    {"KA 235", "Penataran",         "Blitar",            6, "05:00"},
    {"KA 236", "Penataran",         "Surabaya Gubeng",   6, "09:30"},
    // ── Kereta Lokal ──
    {"KA 411", "KRL Commuter Sby",  "Sidoarjo",          4, "06:15"},
    {"KA 412", "KRL Commuter Sby",  "Surabaya Kota",     4, "07:00"},
    {"KA 455", "Lokal Bojonegoro",  "Bojonegoro",        4, "06:30"},
    {"KA 456", "Lokal Bojonegoro",  "Surabaya Pasarturi",4, "09:45"},
    {"KA 461", "Lokal Bangil",      "Bangil",            4, "07:10"},
    {"KA 462", "Lokal Bangil",      "Surabaya Gubeng",   4, "10:30"}
};

const int TOTAL_GAPEKA = sizeof(GAPEKA_DO8) / sizeof(GAPEKA_DO8[0]);

Kereta* head = nullptr;
Kereta* tail = nullptr;
int totalKereta = 0;


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\n" << DIM << "  Tekan Enter untuk kembali ke menu..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printLine(char c = '-', int len = 80, string color = DIM) {
    cout << color;
    for (int i = 0; i < len; i++) cout << c;
    cout << RESET << "\n";
}

void printDoubleLine(int len = 80) {
    cout << BRIGHT_CYAN;
    for (int i = 0; i < len; i++) cout << "═";
    cout << RESET << "\n";
}

void printSingleLine(int len = 80) {
    cout << CYAN;
    for (int i = 0; i < len; i++) cout << "─";
    cout << RESET << "\n";
}

string statusBadge(string text, string color) {
    return color + BOLD + " " + text + " " + RESET;
}

void printCentered(string text, int width = 80, string color = "") {
    int padding = (width - (int)text.length()) / 2;
    if (padding < 0) padding = 0;
    cout << color;
    for (int i = 0; i < padding; i++) cout << " ";
    cout << text << RESET << "\n";
}

void printHeader() {
    clearScreen();
    cout << "\n";
    printDoubleLine();
    cout << BRIGHT_CYAN << BOLD;
    printCentered("🚂  SISTEM MANAJEMEN ANTRIAN KERETA API  🚂", 80, BRIGHT_CYAN);
    cout << RESET;
    printCentered("Daerah Operasional 8 Surabaya  |  GAPEKA 2025", 80, YELLOW);
    printCentered("Laboratorium RPL - Praktikum Struktur Data ITATS", 80, DIM);
    printDoubleLine();

    
    cout << BRIGHT_BLUE << "  📊 Status: ";
    if (totalKereta == 0) {
        cout << BG_RED << WHITE << BOLD << " ANTRIAN KOSONG " << RESET;
    } else if (totalKereta < 5) {
        cout << BG_GREEN << WHITE << BOLD << " NORMAL " << RESET;
    } else if (totalKereta < 10) {
        cout << BG_YELLOW << " PADAT " << RESET;
    } else {
        cout << BG_RED << WHITE << BOLD << " PENUH " << RESET;
    }
    cout << BRIGHT_BLUE << "  |  🚃 Kereta dalam antrian: " << BRIGHT_WHITE << BOLD << totalKereta << RESET << "\n";

    if (totalKereta > 0) {
        cout << BRIGHT_BLUE << "  ⬆  Depan: " << BRIGHT_GREEN << head->namaKA 
            << " (" << head->nomorKA << ")" << RESET;
        cout << BRIGHT_BLUE << "  |  ⬇  Belakang: " << BRIGHT_MAGENTA << tail->namaKA 
            << " (" << tail->nomorKA << ")" << RESET << "\n";
    }
    printSingleLine();
}

void tambahKereta() {
    printHeader();
    cout << BRIGHT_GREEN << BOLD << "  ➕  TAMBAH KERETA KE ANTRIAN\n" << RESET;
    printSingleLine();

    
    Kereta* baru = new Kereta();
    baru->next = nullptr;

    cout << CYAN << "  Nomor KA        : " << RESET;
    getline(cin, baru->nomorKA);

    cout << CYAN << "  Nama KA         : " << RESET;
    getline(cin, baru->namaKA);

    cout << CYAN << "  Tujuan          : " << RESET;
    getline(cin, baru->tujuan);

    cout << CYAN << "  Jumlah Rangkaian: " << RESET;
    while (!(cin >> baru->jumlahRangkaian) || baru->jumlahRangkaian <= 0) {
        cout << BRIGHT_RED << "  ⚠  Input tidak valid! Masukkan angka positif: " << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << CYAN << "  Jam Kedatangan  : " << RESET;
    getline(cin, baru->jamKedatangan);

    
    if (head == nullptr) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
    totalKereta++;

    printSingleLine();
    cout << BG_GREEN << WHITE << BOLD << "  ✅  Kereta " << baru->namaKA 
        << " (" << baru->nomorKA << ") berhasil ditambahkan ke antrian!  " << RESET << "\n";
    pauseScreen();
}

void lihatAntrian() {
    printHeader();
    cout << BRIGHT_BLUE << BOLD << "  📋  DAFTAR ANTRIAN KERETA\n" << RESET;
    printSingleLine();

    if (head == nullptr) {
        cout << "\n";
        cout << BG_RED << WHITE << BOLD;
        printCentered("🚫  ANTRIAN KOSONG - Belum ada kereta yang terdaftar", 80, "");
        cout << RESET << "\n";
        pauseScreen();
        return;
    }

    // Header tabel
    cout << BRIGHT_WHITE << BOLD;
    cout << "  " << left
        << setw(5)  << "No"
        << setw(10) << "Nomor KA"
        << setw(24) << "Nama KA"
        << setw(22) << "Tujuan"
        << setw(8)  << "Rangkaian"
        << setw(8)  << "Jam"
        << "Status\n" << RESET;
    printSingleLine();

    Kereta* curr = head;
    int urutan = 1;
    while (curr != nullptr) {
        
        string rowColor = (urutan % 2 == 0) ? DIM : "";
        string posLabel = "";
        string posColor = "";

        if (curr == head && curr == tail) {
            posLabel = "◀▶ SATU-SATUNYA";
            posColor = BG_MAGENTA;
        } else if (curr == head) {
            posLabel = "◀ PERTAMA (DEPAN)";
            posColor = BG_GREEN;
        } else if (curr == tail) {
            posLabel = "▶ TERAKHIR (BELAKANG)";
            posColor = BG_BLUE;
        } else {
            posLabel = "  ANTRI";
            posColor = rowColor;
        }

        cout << posColor << "  " << left
            << setw(5)  << urutan
            << setw(10) << curr->nomorKA
            << setw(24) << curr->namaKA
            << setw(22) << curr->tujuan
            << setw(8)  << (to_string(curr->jumlahRangkaian) + " gbg")
            << setw(8)  << curr->jamKedatangan
            << posLabel
            << RESET << "\n";

        curr = curr->next;
        urutan++;
    }

    printSingleLine();
    cout << BRIGHT_CYAN << "  Total: " << BOLD << totalKereta << " kereta" << RESET;
    cout << "  │  " << BRIGHT_GREEN << "◀ = Kereta berikutnya masuk stasiun" << RESET;
    cout << "  │  " << BRIGHT_BLUE << "▶ = Kereta terakhir ditambahkan\n" << RESET;
    pauseScreen();
}

void cariKereta() {
    printHeader();
    cout << BRIGHT_YELLOW << BOLD << "  🔍  CARI DATA KERETA\n" << RESET;
    printSingleLine();

    if (head == nullptr) {
        cout << BG_RED << WHITE << "  🚫  Antrian kosong! Tidak ada data untuk dicari.\n" << RESET;
        pauseScreen();
        return;
    }

    cout << CYAN << "  Cari berdasarkan [1] Nomor KA  [2] Nama KA  [3] Tujuan\n";
    cout << "  Pilihan: " << RESET;

    int pilCari;
    cin >> pilCari;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string keyword;
    cout << CYAN << "  Masukkan keyword: " << RESET;
    getline(cin, keyword);

    
    string keyLower = keyword;
    transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);

    printSingleLine();
    cout << BRIGHT_YELLOW << "  Hasil pencarian untuk: \"" << keyword << "\"\n" << RESET;
    printSingleLine();

    Kereta* curr = head;
    int found = 0;
    int urutan = 1;

    while (curr != nullptr) {
        string fieldVal = "";
        if      (pilCari == 1) fieldVal = curr->nomorKA;
        else if (pilCari == 2) fieldVal = curr->namaKA;
        else if (pilCari == 3) fieldVal = curr->tujuan;
        else                   fieldVal = curr->namaKA;

        string fieldLower = fieldVal;
        transform(fieldLower.begin(), fieldLower.end(), fieldLower.begin(), ::tolower);

        if (fieldLower.find(keyLower) != string::npos) {
            found++;
            cout << BG_YELLOW << " DITEMUKAN #" << found << " " << RESET << "\n";
            cout << BRIGHT_WHITE << "  ┌─ Posisi dalam antrian : " << BRIGHT_CYAN << urutan << RESET << "\n";
            cout << BRIGHT_WHITE << "  ├─ Nomor KA             : " << BRIGHT_GREEN << curr->nomorKA << RESET << "\n";
            cout << BRIGHT_WHITE << "  ├─ Nama KA              : " << BRIGHT_GREEN << curr->namaKA << RESET << "\n";
            cout << BRIGHT_WHITE << "  ├─ Tujuan               : " << BRIGHT_GREEN << curr->tujuan << RESET << "\n";
            cout << BRIGHT_WHITE << "  ├─ Jumlah Rangkaian     : " << BRIGHT_GREEN << curr->jumlahRangkaian << " gerbong" << RESET << "\n";
            cout << BRIGHT_WHITE << "  └─ Jam Kedatangan       : " << BRIGHT_GREEN << curr->jamKedatangan << RESET << "\n";
            printSingleLine();
        }
        curr = curr->next;
        urutan++;
    }

    if (found == 0) {
        cout << BG_RED << WHITE << BOLD << "  ❌  Tidak ada kereta yang cocok dengan keyword \"" << keyword << "\"  " << RESET << "\n";
    } else {
        cout << BRIGHT_GREEN << "  ✅  Ditemukan " << BOLD << found << " kereta\n" << RESET;
    }
    pauseScreen();
}

void updateKereta() {
    printHeader();
    cout << BRIGHT_MAGENTA << BOLD << "  ✏️   UPDATE DATA KERETA\n" << RESET;
    printSingleLine();

    if (head == nullptr) {
        cout << BG_RED << WHITE << "  🚫  Antrian kosong!\n" << RESET;
        pauseScreen();
        return;
    }

    cout << CYAN << "  Masukkan Nomor KA yang ingin diupdate: " << RESET;
    string targetNomor;
    getline(cin, targetNomor);

    Kereta* curr = head;
    bool ditemukan = false;

    while (curr != nullptr) {
        if (curr->nomorKA == targetNomor) {
            ditemukan = true;
            cout << "\n" << BG_BLUE << WHITE << BOLD << "  DATA SAAT INI  " << RESET << "\n";
            cout << "  Nomor KA       : " << BRIGHT_CYAN << curr->nomorKA << RESET << "\n";
            cout << "  Nama KA        : " << BRIGHT_CYAN << curr->namaKA << RESET << "\n";
            cout << "  Tujuan         : " << BRIGHT_CYAN << curr->tujuan << RESET << "\n";
            cout << "  Jml Rangkaian  : " << BRIGHT_CYAN << curr->jumlahRangkaian << RESET << "\n";
            cout << "  Jam Kedatangan : " << BRIGHT_CYAN << curr->jamKedatangan << RESET << "\n";
            printSingleLine();

            cout << YELLOW << "  (Kosongkan / tekan Enter untuk tidak mengubah field)\n\n" << RESET;

            string input;

            cout << CYAN << "  Nama KA baru         [" << curr->namaKA << "]: " << RESET;
            getline(cin, input);
            if (!input.empty()) curr->namaKA = input;

            cout << CYAN << "  Tujuan baru          [" << curr->tujuan << "]: " << RESET;
            getline(cin, input);
            if (!input.empty()) curr->tujuan = input;

            cout << CYAN << "  Jumlah Rangkaian baru[" << curr->jumlahRangkaian << "]: " << RESET;
            getline(cin, input);
            if (!input.empty()) {
                try { curr->jumlahRangkaian = stoi(input); }
                catch (...) { cout << BRIGHT_RED << "  ⚠  Nilai tidak valid, tetap menggunakan nilai lama.\n" << RESET; }
            }

            cout << CYAN << "  Jam Kedatangan baru  [" << curr->jamKedatangan << "]: " << RESET;
            getline(cin, input);
            if (!input.empty()) curr->jamKedatangan = input;

            printSingleLine();
            cout << BG_GREEN << WHITE << BOLD << "  ✅  Data kereta " << curr->nomorKA << " berhasil diperbarui!  " << RESET << "\n";
            break;
        }
        curr = curr->next;
    }

    if (!ditemukan) {
        cout << BG_RED << WHITE << BOLD << "  ❌  Kereta dengan nomor \"" << targetNomor << "\" tidak ditemukan!\n" << RESET;
    }
    pauseScreen();
}

void hapusKereta() {
    printHeader();
    cout << BRIGHT_RED << BOLD << "  🗑️   HAPUS KERETA DARI ANTRIAN\n" << RESET;
    printSingleLine();

    if (head == nullptr) {
        cout << BG_RED << WHITE << BOLD << "  🚫  Antrian kosong! Tidak ada kereta untuk dihapus.\n" << RESET;
        pauseScreen();
        return;
    }

    cout << YELLOW << "  Mode hapus:\n";
    cout << "  [1] 🚉  Hapus dari DEPAN antrian (kereta masuk stasiun)\n";
    cout << "  [2] 🔍  Hapus kereta tertentu berdasarkan Nomor KA\n";
    cout << CYAN << "  Pilihan: " << RESET;

    int pilHapus;
    cin >> pilHapus;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (pilHapus == 1) {
        
        Kereta* hapus = head;

        cout << "\n" << BG_GREEN << WHITE << BOLD << "  🚉  KERETA MASUK STASIUN!  " << RESET << "\n";
        cout << BRIGHT_WHITE << "  ┌─ Nomor KA       : " << BRIGHT_GREEN << hapus->nomorKA << RESET << "\n";
        cout << BRIGHT_WHITE << "  ├─ Nama KA        : " << BRIGHT_GREEN << hapus->namaKA << RESET << "\n";
        cout << BRIGHT_WHITE << "  ├─ Tujuan         : " << BRIGHT_GREEN << hapus->tujuan << RESET << "\n";
        cout << BRIGHT_WHITE << "  ├─ Jml Rangkaian  : " << BRIGHT_GREEN << hapus->jumlahRangkaian << " gerbong" << RESET << "\n";
        cout << BRIGHT_WHITE << "  └─ Jam Kedatangan : " << BRIGHT_GREEN << hapus->jamKedatangan << RESET << "\n";
        printSingleLine();

        cout << RED << "  Konfirmasi hapus? (y/n): " << RESET;
        char confirm;
        cin >> confirm;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (confirm == 'y' || confirm == 'Y') {
            head = head->next;
            if (head == nullptr) tail = nullptr;
            delete hapus;
            totalKereta--;
            cout << BG_GREEN << WHITE << BOLD << "\n  ✅  Kereta berhasil dihapus dari antrian (sudah masuk stasiun)!\n" << RESET;
        } else {
            cout << YELLOW << "  ↩  Penghapusan dibatalkan.\n" << RESET;
        }

    } else if (pilHapus == 2) {
        cout << CYAN << "  Masukkan Nomor KA yang akan dihapus: " << RESET;
        string targetNomor;
        getline(cin, targetNomor);

        Kereta* curr = head;
        Kereta* prev = nullptr;
        bool ditemukan = false;

        while (curr != nullptr) {
            if (curr->nomorKA == targetNomor) {
                ditemukan = true;

                cout << "\n" << BG_RED << WHITE << BOLD << "  ⚠  DATA YANG AKAN DIHAPUS  " << RESET << "\n";
                cout << "  " << curr->nomorKA << " - " << curr->namaKA << " → " << curr->tujuan << "\n";
                printSingleLine();

                cout << RED << "  Konfirmasi hapus? (y/n): " << RESET;
                char confirm;
                cin >> confirm;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (confirm == 'y' || confirm == 'Y') {
                    if (prev == nullptr) {
                        
                        head = curr->next;
                        if (head == nullptr) tail = nullptr;
                    } else {
                        prev->next = curr->next;
                        if (curr == tail) tail = prev;
                    }
                    delete curr;
                    totalKereta--;
                    cout << BG_GREEN << WHITE << BOLD << "\n  ✅  Kereta " << targetNomor << " berhasil dihapus!\n" << RESET;
                } else {
                    cout << YELLOW << "  ↩  Penghapusan dibatalkan.\n" << RESET;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        if (!ditemukan) {
            cout << BG_RED << WHITE << BOLD << "  ❌  Kereta \"" << targetNomor << "\" tidak ditemukan!\n" << RESET;
        }
    } else {
        cout << BRIGHT_RED << "  ❌  Pilihan tidak valid!\n" << RESET;
    }
    pauseScreen();
}

void importGapeka() {
    printHeader();
    cout << BRIGHT_YELLOW << BOLD << "  🌐  IMPORT DATA GAPEKA 2025 - DO 8 SURABAYA\n" << RESET;
    printSingleLine();
    cout << YELLOW << "  ℹ  Data berbasis GAPEKA 2025 resmi PT KAI Daop 8 Surabaya\n";
    cout << "     API publik KAI tidak tersedia secara terbuka,\n";
    cout << "     dataset ini di-embed langsung dari referensi jadwal resmi.\n" << RESET;
    printSingleLine();

    
    cout << BRIGHT_WHITE << "  Pilih kategori import:\n";
    cout << BRIGHT_CYAN   << "  [1] 🏆 Kereta Eksekutif/Premium    (10 kereta)\n";
    cout << BRIGHT_YELLOW << "  [2] 🎫 Kereta Bisnis/Campuran      (8 kereta)\n";
    cout << BRIGHT_GREEN  << "  [3] 🎟  Kereta Ekonomi              (10 kereta)\n";
    cout << BRIGHT_BLUE   << "  [4] 🚇 Kereta Lokal/Komuter        (6 kereta)\n";
    cout << BRIGHT_WHITE  << "  [5] 📦 Import SEMUA (" << TOTAL_GAPEKA << " kereta)\n";
    cout << BRIGHT_MAGENTA<< "  [6] 🔎 Pilih satu kereta dari daftar\n";
    cout << CYAN << "\n  Pilihan: " << RESET;

    int pilGapeka;
    cin >> pilGapeka;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    
    int startIdx = -1, endIdx = -1;
    bool pilihSatu = false;

    switch (pilGapeka) {
        case 1: startIdx = 0;  endIdx = 9;  break;  // Eksekutif
        case 2: startIdx = 10; endIdx = 17; break;  // Bisnis
        case 3: startIdx = 18; endIdx = 27; break;  // Ekonomi
        case 4: startIdx = 28; endIdx = 35; break;  // Lokal
        case 5: startIdx = 0;  endIdx = TOTAL_GAPEKA - 1; break;  // Semua
        case 6: pilihSatu = true; break;
        default:
            cout << BRIGHT_RED << "  ❌  Pilihan tidak valid!\n" << RESET;
            pauseScreen();
            return;
    }

    if (pilihSatu) {
        
        cout << "\n" << BRIGHT_WHITE << BOLD;
        cout << "  " << left << setw(5) << "No" << setw(10) << "Nomor KA" << setw(26) << "Nama KA" << setw(24) << "Tujuan" << "Jam\n" << RESET;
        printSingleLine();
        for (int i = 0; i < TOTAL_GAPEKA; i++) {
            cout << "  " << left
                << BRIGHT_CYAN << setw(5) << (i + 1)
                << BRIGHT_WHITE << setw(10) << GAPEKA_DO8[i].nomorKA
                << setw(26) << GAPEKA_DO8[i].namaKA
                << DIM << setw(24) << GAPEKA_DO8[i].tujuan
                << BRIGHT_YELLOW << GAPEKA_DO8[i].jamKedatangan
                << RESET << "\n";
        }
        printSingleLine();
        cout << CYAN << "  Masukkan nomor urut kereta: " << RESET;
        int idxPilih;
        cin >> idxPilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (idxPilih < 1 || idxPilih > TOTAL_GAPEKA) {
            cout << BRIGHT_RED << "  ❌  Nomor tidak valid!\n" << RESET;
            pauseScreen();
            return;
        }
        startIdx = endIdx = idxPilih - 1;
    }

    
    int imported = 0;
    int skipped  = 0;

    for (int i = startIdx; i <= endIdx; i++) {
        
        bool sudahAda = false;
        Kereta* cek = head;
        while (cek != nullptr) {
            if (cek->nomorKA == GAPEKA_DO8[i].nomorKA) {
                sudahAda = true;
                break;
            }
            cek = cek->next;
        }

        if (sudahAda) {
            skipped++;
            cout << DIM << "  ↷  Skip " << GAPEKA_DO8[i].nomorKA << " (sudah ada)\n" << RESET;
            continue;
        }

        
        Kereta* baru = new Kereta();
        baru->nomorKA         = GAPEKA_DO8[i].nomorKA;
        baru->namaKA          = GAPEKA_DO8[i].namaKA;
        baru->tujuan          = GAPEKA_DO8[i].tujuan;
        baru->jumlahRangkaian = GAPEKA_DO8[i].jumlahRangkaian;
        baru->jamKedatangan   = GAPEKA_DO8[i].jamKedatangan;
        baru->next            = nullptr;

        if (head == nullptr) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
        totalKereta++;
        imported++;

        cout << BRIGHT_GREEN << "  ✓  " << RESET
            << left << setw(8) << GAPEKA_DO8[i].nomorKA
            << setw(24) << GAPEKA_DO8[i].namaKA
            << "→ " << GAPEKA_DO8[i].tujuan << "\n";
    }

    printSingleLine();
    cout << BG_GREEN << WHITE << BOLD
        << "  ✅  Import selesai! " << imported << " kereta ditambahkan"
        << (skipped > 0 ? (", " + to_string(skipped) + " dilewati (duplikat)") : "")
        << "  " << RESET << "\n";
    pauseScreen();
}

void tampilMenu() {
    cout << "\n";
    cout << BRIGHT_WHITE << BOLD << "  ┌────────────────────────────────────┐\n";
    cout << "  │       " << BRIGHT_CYAN << "M E N U  U T A M A" << BRIGHT_WHITE << "         │\n";
    cout << "  ├────────────────────────────────────┤\n";
    cout << "  │  " << BRIGHT_GREEN  << "[1]" << BRIGHT_WHITE << " Tambah Kereta ke Antrian      │\n";
    cout << "  │  " << BRIGHT_BLUE   << "[2]" << BRIGHT_WHITE << " Lihat Seluruh Antrian         │\n";
    cout << "  │  " << BRIGHT_YELLOW << "[3]" << BRIGHT_WHITE << " Cari Data Kereta              │\n";
    cout << "  │  " << BRIGHT_MAGENTA<< "[4]" << BRIGHT_WHITE << " Update Data Kereta            │\n";
    cout << "  │  " << BRIGHT_RED    << "[5]" << BRIGHT_WHITE << " Hapus Kereta dari Antrian     │\n";
    cout << "  ├────────────────────────────────────┤\n";
    cout << "  │  " << YELLOW  << "[G]" << BRIGHT_WHITE << " 🌐 Import Data GAPEKA 2025    │\n";
    cout << "  ├────────────────────────────────────┤\n";
    cout << "  │  " << RED     << "[0]" << BRIGHT_WHITE << " Keluar dari Program           │\n";
    cout << "  └────────────────────────────────────┘\n" << RESET;
    cout << "\n  " << CYAN << "Pilih menu: " << RESET;
}

void splashScreen() {
    clearScreen();
    cout << "\n\n\n";
    cout << BRIGHT_CYAN << BOLD;
    cout << "         ██╗  ██╗ █████╗     ██████╗ ██████╗  █████╗ \n";
    cout << "         ██║ ██╔╝██╔══██╗   ╚════██╗╚════██╗██╔══██╗\n";
    cout << "         █████╔╝ ███████║    █████╔╝ █████╔╝╚█████╔╝\n";
    cout << "         ██╔═██╗ ██╔══██║   ██╔═══╝  ╚═══██╗██╔══██╗\n";
    cout << "         ██║  ██╗██║  ██║   ███████╗██████╔╝╚█████╔╝\n";
    cout << "         ╚═╝  ╚═╝╚═╝  ╚═╝   ╚══════╝╚═════╝  ╚════╝ \n";
    cout << RESET;
    cout << "\n";
    cout << YELLOW << BOLD;
    printCentered("Sistem Antrian Kereta Api", 80, YELLOW);
    printCentered("Daerah Operasional 8 Surabaya", 80, YELLOW);
    cout << RESET << "\n";
    printDoubleLine();
    cout << "\n";
    printCentered("🚂 ════════════════════════ 🚃 ════════════════════════ 🚃", 80, BRIGHT_CYAN);
    cout << "\n\n";
    printCentered("Praktikum Struktur Data - ITATS Periode XVI 2025/2026", 80, DIM);
    printCentered("Laboratorium Rekayasa Perangkat Lunak", 80, DIM);
    cout << "\n";
    printDoubleLine();
    cout << "\n";
    cout << BRIGHT_WHITE << "  Tekan " << BG_CYAN << " ENTER " << RESET << BRIGHT_WHITE << " untuk mulai..." << RESET;
    cin.get();
}

bool konfirmasiKeluar() {
    printHeader();
    cout << "\n";
    printCentered("⚠️  KONFIRMASI KELUAR", 80, BRIGHT_RED);
    cout << "\n";

    if (totalKereta > 0) {
        cout << BG_YELLOW << " PERHATIAN " << RESET << YELLOW
            << " Masih ada " << BOLD << totalKereta << RESET << YELLOW
            << " kereta dalam antrian yang belum diproses!\n" << RESET;
        printSingleLine();
    }

    cout << CYAN << "  Yakin ingin keluar? (y/n): " << RESET;
    char c;
    cin >> c;
    return (c == 'y' || c == 'Y');
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    splashScreen();

    string input;
    bool running = true;

    while (running) {
        printHeader();
        tampilMenu();
        getline(cin, input);

        
        if (!input.empty()) {
            
            char pilihan = (input.length() == 1) ? input[0] : '?';

            switch (pilihan) {
                case '1':
                    tambahKereta();
                    break;
                case '2':
                    lihatAntrian();
                    break;
                case '3':
                    cariKereta();
                    break;
                case '4':
                    updateKereta();
                    break;
                case '5':
                    hapusKereta();
                    break;
                case 'G':
                case 'g':
                    importGapeka();
                    break;
                case '0':
                    if (konfirmasiKeluar()) {
                        running = false;
                    }
                    break;
                default:
                    printHeader();
                    cout << "\n";
                    cout << BG_RED << WHITE << BOLD;
                    printCentered("❌  Pilihan tidak valid! Masukkan 1-5, G, atau 0", 80, "");
                    cout << RESET << "\n";
                    pauseScreen();
            }
        }
    }

    
    Kereta* curr = head;
    while (curr != nullptr) {
        Kereta* next = curr->next;
        delete curr;
        curr = next;
    }

    clearScreen();
    cout << "\n\n";
    printDoubleLine();
    cout << BRIGHT_CYAN << BOLD;
    printCentered("🚂  Terima kasih telah menggunakan", 80, BRIGHT_CYAN);
    printCentered("Sistem Antrian KA DO 8 Surabaya  🚂", 80, BRIGHT_CYAN);
    cout << RESET;
    printCentered("Sampai jumpa! - ITATS Struktur Data 2025", 80, YELLOW);
    printDoubleLine();
    cout << "\n\n";

    return 0;
}