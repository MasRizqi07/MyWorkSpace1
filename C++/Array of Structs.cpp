#include <iostream>
#include <string> // Gunakan ini, lupakan char[25] untuk teks panjang!

using namespace std;

// 1. Blueprint Struct (Lebih rapi huruf kapital di awal untuk nama Struct)
struct Mahasiswa {
    string nama;
    string npm;    // NPM lebih aman pakai string untuk mencegah integer overflow
    string alamat;
    char gender;
    int umur;
};

int main() {
    // 2. Deklarasi Array of Structs
    // Kita pesan 3 loker (indeks 0, 1, 2)
    const int JUMLAH_MHS = 3;
    Mahasiswa dataMhs[JUMLAH_MHS];

    cout << "=== INPUT DATA MAHASISWA ===" << endl;

    // 3. Looping Input: Analitis & Strict (SELALU mulai dari 0)
    for (int i = 0; i < JUMLAH_MHS; i++) {
        // Tampilan ke user tetap ramah (Mulai dari 1), tapi mesin tetap hitung dari 0
        cout << "\nData Mahasiswa ke-" << (i + 1) << ":" << endl; 
        
        cout << "Nama\t\t: ";
        // cin >> ws ini *lifehack* buat buang sisa 'Enter' (whitespace) dari input sebelumnya
        // Biar fungsi getline() nggak ke-skip.
        getline(cin >> ws, dataMhs[i].nama); 
        
        cout << "NPM\t\t: ";
        getline(cin >> ws, dataMhs[i].npm);
        
        cout << "Alamat\t\t: ";
        getline(cin >> ws, dataMhs[i].alamat);
        
        cout << "Gender (L/P)\t: ";
        cin >> dataMhs[i].gender;
        
        cout << "Umur\t\t: ";
        cin >> dataMhs[i].umur;
    }

    // --- Pemisah Visual ---
    cout << "\n=====================================" << endl;
    cout << "=== HASIL OUTPUT DATA MAHASISWA ===" << endl;
    cout << "=====================================" << endl;

    // 4. Looping Output
    for (int i = 0; i < JUMLAH_MHS; i++) {
        cout << "\nMahasiswa ke-" << (i + 1) << endl;
        cout << "Nama\t: " << dataMhs[i].nama << endl;
        cout << "NPM\t: " << dataMhs[i].npm << endl;
        cout << "Alamat\t: " << dataMhs[i].alamat << endl;
        cout << "Gender\t: " << dataMhs[i].gender << endl;
        cout << "Umur\t: " << dataMhs[i].umur << " tahun" << endl;
    }

    return 0; // Biasakan selalu return 0 tanda program sukses berjalan
}