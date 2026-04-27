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

// --- KONSTANTA WARNA ANSI ---
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BRIGHT_CYAN "\033[96m"

// ==========================================
// 1. DATA LAYER (STRUKTUR DATA MURNI)
// ==========================================

struct Kereta {
    string nomorKA;
    string namaKA;
    string tujuan;
    int    jumlahRangkaian;
    string jamKedatangan;
    Kereta* next;
};

struct Queue {
    Kereta* head;
    Kereta* tail;
    int size;
};

// Inisialisasi Queue
void initQueue(Queue& q) {
    q.head = nullptr;
    q.tail = nullptr;
    q.size = 0;
}

// Operasi Enqueue (Masuk dari belakang)
void enqueue(Queue& q, Kereta* baru) {
    baru->next = nullptr;
    if (q.head == nullptr) {
        q.head = baru;
        q.tail = baru;
    } else {
        q.tail->next = baru;
        q.tail = baru;
    }
    q.size++;
}

// Operasi Dequeue (Keluar dari depan)
Kereta* dequeue(Queue& q) {
    if (q.head == nullptr) return nullptr;
    
    Kereta* hapus = q.head;
    q.head = q.head->next;
    
    if (q.head == nullptr) {
        q.tail = nullptr;
    }
    
    q.size--;
    return hapus;
}

// ==========================================
// 2. PRESENTATION LAYER (UI & INTERAKSI PENGGUNA)
// ==========================================

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pauseScreen() {
    cout << "\n" << DIM << " Tekan Enter untuk kembali ke menu..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printHeader(const Queue& q) {
    clearScreen();
    cout << BRIGHT_CYAN << "================================================================================\n";
    cout << BOLD << "                🚂 SISTEM MANAJEMEN ANTRIAN KERETA API 🚂\n";
    cout << RESET << "                    Daerah Operasional 8 Surabaya\n";
    cout << BRIGHT_CYAN << "================================================================================\n" << RESET;
    
    cout << " Status Antrian: ";
    if (q.size == 0) cout << BG_RED << WHITE << BOLD << " KOSONG " << RESET;
    else cout << BG_GREEN << WHITE << BOLD << " AKTIF (" << q.size << " Kereta) " << RESET;
    cout << "\n--------------------------------------------------------------------------------\n";
}

void uiTambahKereta(Queue& q) {
    printHeader(q);
    cout << GREEN << BOLD << " [1] TAMBAH KERETA KE ANTRIAN\n" << RESET;
    
    Kereta* baru = new Kereta();
    
    cout << " Nomor KA        : ";
    getline(cin, baru->nomorKA);
    cout << " Nama KA         : ";
    getline(cin, baru->namaKA);
    cout << " Tujuan          : ";
    getline(cin, baru->tujuan);
    
    cout << " Jumlah Rangkaian: ";
    while (!(cin >> baru->jumlahRangkaian) || baru->jumlahRangkaian <= 0) {
        cout << RED << " Input tidak valid! Masukkan angka positif: " << RESET;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << " Jam Kedatangan  : ";
    getline(cin, baru->jamKedatangan);
    
    enqueue(q, baru);
    
    cout << "\n" << BG_GREEN << WHITE << BOLD << " ✅ Kereta " << baru->namaKA << " berhasil ditambahkan ke antrian! " << RESET << "\n";
    pauseScreen();
}

void uiLihatAntrian(const Queue& q) {
    printHeader(q);
    cout << CYAN << BOLD << " [2] SELURUH ANTRIAN KERETA\n" << RESET;
    
    if (q.head == nullptr) {
        cout << RED << " Antrian saat ini kosong.\n" << RESET;
        pauseScreen();
        return;
    }
    
    cout << BOLD << left << setw(5) << "No" << setw(10) << "No KA" << setw(20) << "Nama KA" << setw(20) << "Tujuan" << setw(10) << "Gerbong" << "Jam\n" << RESET;
    cout << DIM << "--------------------------------------------------------------------------------\n" << RESET;
    
    Kereta* curr = q.head;
    int urutan = 1;
    while (curr != nullptr) {
        cout << left << setw(5) << urutan
             << setw(10) << curr->nomorKA
             << setw(20) << curr->namaKA
             << setw(20) << curr->tujuan
             << setw(10) << curr->jumlahRangkaian
             << curr->jamKedatangan << "\n";
        curr = curr->next;
        urutan++;
    }
    pauseScreen();
}

void uiCariKereta(const Queue& q) {
    printHeader(q);
    cout << YELLOW << BOLD << " [3] CARI DATA KERETA\n" << RESET;
    
    if (q.head == nullptr) {
        cout << RED << " Antrian kosong.\n" << RESET;
        pauseScreen();
        return;
    }
    
    string keyword;
    cout << " Masukkan Nomor KA atau Nama KA yang dicari: ";
    getline(cin, keyword);
    
    string keyLower = keyword;
    transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);
    
    Kereta* curr = q.head;
    bool found = false;
    int urutan = 1;
    
    while (curr != nullptr) {
        string noLower = curr->nomorKA;
        string namaLower = curr->namaKA;
        transform(noLower.begin(), noLower.end(), noLower.begin(), ::tolower);
        transform(namaLower.begin(), namaLower.end(), namaLower.begin(), ::tolower);
        
        if (noLower.find(keyLower) != string::npos || namaLower.find(keyLower) != string::npos) {
            cout << "\n" << BG_YELLOW << BOLD << " DITEMUKAN DI POSISI #" << urutan << " " << RESET << "\n";
            cout << " Nomor KA       : " << curr->nomorKA << "\n";
            cout << " Nama KA        : " << curr->namaKA << "\n";
            cout << " Tujuan         : " << curr->tujuan << "\n";
            cout << " Jml Rangkaian  : " << curr->jumlahRangkaian << "\n";
            cout << " Jam Kedatangan : " << curr->jamKedatangan << "\n";
            found = true;
        }
        curr = curr->next;
        urutan++;
    }
    
    if (!found) cout << "\n" << RED << " Kereta tidak ditemukan.\n" << RESET;
    pauseScreen();
}

void uiUpdateKereta(Queue& q) {
    printHeader(q);
    cout << CYAN << BOLD << " [4] UPDATE DATA KERETA\n" << RESET;
    
    if (q.head == nullptr) {
        cout << RED << " Antrian kosong.\n" << RESET;
        pauseScreen();
        return;
    }
    
    string targetNomor;
    cout << " Masukkan Nomor KA yang ingin diupdate: ";
    getline(cin, targetNomor);
    
    Kereta* curr = q.head;
    bool found = false;
    
    while (curr != nullptr) {
        if (curr->nomorKA == targetNomor) {
            found = true;
            cout << "\n" << DIM << " Kosongkan lalu tekan Enter jika tidak ingin mengubah data tersebut.\n" << RESET;
            
            string input;
            cout << " Nama KA baru [" << curr->namaKA << "]: ";
            getline(cin, input);
            if (!input.empty()) curr->namaKA = input;
            
            cout << " Tujuan baru [" << curr->tujuan << "]: ";
            getline(cin, input);
            if (!input.empty()) curr->tujuan = input;
            
            cout << " Jumlah Rangkaian baru [" << curr->jumlahRangkaian << "]: ";
            getline(cin, input);
            if (!input.empty()) {
                try { curr->jumlahRangkaian = stoi(input); }
                catch (...) { cout << RED << " Input tidak valid. Angka lama dipertahankan.\n" << RESET; }
            }
            
            cout << " Jam Kedatangan baru [" << curr->jamKedatangan << "]: ";
            getline(cin, input);
            if (!input.empty()) curr->jamKedatangan = input;
            
            cout << "\n" << BG_GREEN << WHITE << BOLD << " ✅ Data berhasil diupdate! " << RESET << "\n";
            break;
        }
        curr = curr->next;
    }
    
    if (!found) cout << RED << " Nomor KA tidak ditemukan dalam antrian.\n" << RESET;
    pauseScreen();
}

void uiHapusKereta(Queue& q) {
    printHeader(q);
    cout << RED << BOLD << " [5] HAPUS KERETA DARI ANTRIAN (MASUK STASIUN)\n" << RESET;
    
    Kereta* keretaMasuk = dequeue(q);
    
    if (keretaMasuk == nullptr) {
        cout << BG_RED << WHITE << BOLD << " 🚫 Antrian kosong! Tidak ada kereta untuk dihapus.\n" << RESET;
    } else {
        cout << BG_GREEN << WHITE << BOLD << " 🚉 KERETA BERHASIL MASUK STASIUN & DIHAPUS DARI ANTRIAN! " << RESET << "\n";
        cout << " Nomor KA       : " << keretaMasuk->nomorKA << "\n";
        cout << " Nama KA        : " << keretaMasuk->namaKA << "\n";
        cout << " Tujuan         : " << keretaMasuk->tujuan << "\n";
        
        // Hapus alokasi memori
        delete keretaMasuk;
    }
    pauseScreen();
}

void uiImportRahasia(Queue& q) {
    // Data dummy singkat untuk import cepat
    Kereta* k1 = new Kereta{"KA 1", "Bima", "Gambir", 16, "19:00", nullptr};
    Kereta* k2 = new Kereta{"KA 2", "Argo Bromo", "Pasarturi", 10, "20:45", nullptr};
    Kereta* k3 = new Kereta{"KA 3", "Gajayana", "Malang", 14, "08:00", nullptr};
    
    enqueue(q, k1);
    enqueue(q, k2);
    enqueue(q, k3);
    
    cout << BG_GREEN << WHITE << BOLD << "\n ✅ 3 Data GAPEKA rahasia berhasil di-import! " << RESET << "\n";
    pauseScreen();
}

void tampilMenuUtama() {
    cout << BOLD << " MENU PROGRAM:\n" << RESET;
    cout << " 1. Tambah kereta ke dalam antrian\n";
    cout << " 2. Lihat seluruh antrian kereta\n";
    cout << " 3. Cari data kereta\n";
    cout << " 4. Update data kereta\n";
    cout << " 5. Hapus kereta dari antrian\n";
    cout << " 6. Keluar\n";
    cout << "\n Pilihan Anda: ";
}

// ==========================================
// 3. MAIN PROGRAM
// ==========================================

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    Queue antrianStasiun;
    initQueue(antrianStasiun);
    
    string input;
    bool running = true;
    
    while (running) {
        printHeader(antrianStasiun);
        tampilMenuUtama();
        getline(cin, input);
        
        if (input.empty()) continue;
        
        char pilihan = input[0];
        
        switch (pilihan) {
            case '1': uiTambahKereta(antrianStasiun); break;
            case '2': uiLihatAntrian(antrianStasiun); break;
            case '3': uiCariKereta(antrianStasiun); break;
            case '4': uiUpdateKereta(antrianStasiun); break;
            case '5': uiHapusKereta(antrianStasiun); break;
            case '6': running = false; break;
            case 'G': 
            case 'g': uiImportRahasia(antrianStasiun); break;
            default:
                cout << RED << " Pilihan tidak valid!\n" << RESET;
                pauseScreen();
        }
    }
    
    // Pembersihan memori sebelum keluar
    while (antrianStasiun.head != nullptr) {
        Kereta* hapus = dequeue(antrianStasiun);
        delete hapus;
    }
    
    cout << "\n Program selesai. Terima kasih.\n";
    return 0;
}