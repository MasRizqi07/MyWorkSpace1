#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. Struct Tanggal Lahir (Blueprint untuk tanggal)
struct TanggalLahir {
    int tgl;
    int bln;
    int thn;
};

// 2. Struct Siswa (Blueprint utama yang punya relasi ke TanggalLahir)
struct Siswa {
    TanggalLahir ttl; // Cukup 1 variabel struct, BUKAN array!
    string npm;
    string nama;
    string alamat;
    string mk;
};

int main() {
    int jumlah_siswa;
    cout << "=========================================\n";
    cout << "     SISTEM DATA MAHASISWA & TGL LAHIR   \n";
    cout << "=========================================\n";
    cout << "Masukkan Banyaknya Siswa: ";
    
    // Validasi input
    if (!(cin >> jumlah_siswa) || jumlah_siswa <= 0) {
        cout << "[ERROR] Input tidak valid, harus angka bro!" << endl;
        return 1;
    }

    // Menggunakan vector agar dinamis
    vector<Siswa> data_siswa(jumlah_siswa);

    // --- FASE INPUT DATA ---
    for (int i = 0; i < jumlah_siswa; i++) {
        cout << "\n--- Input Data Siswa Ke-" << (i + 1) << " ---" << endl;
        
        // Input Tanggal Lahir
        cout << "Masukkan Tanggal Lahir (DD) : ";
        cin >> data_siswa[i].ttl.tgl; // Perhatikan logikanya: Siswa ke-i -> ttl -> tgl
        
        cout << "Masukkan Bulan Lahir (MM)   : ";
        cin >> data_siswa[i].ttl.bln;
        
        cout << "Masukkan Tahun Lahir (YYYY) : ";
        cin >> data_siswa[i].ttl.thn;

        // FLUSHING BUFFER SEKALI AJA SEBELUM STRING
        // Ini cara paling aman bersihin sisa 'Enter' dari input tahun
        cin.ignore(10000, '\n'); 

        // Input String pakai getline
        cout << "Masukkan NPM                : ";
        getline(cin, data_siswa[i].npm);
        
        cout << "Masukkan Nama Siswa         : ";
        getline(cin, data_siswa[i].nama);
        
        cout << "Masukkan Alamat             : ";
        getline(cin, data_siswa[i].alamat);
        
        cout << "Masukkan Mata Kuliah        : ";
        getline(cin, data_siswa[i].mk);
    }

    // --- FASE OUTPUT DATA ---
    cout << "\n\n=========================================\n";
    cout << "          REKAP DATA MAHASISWA           \n";
    cout << "=========================================\n";

    for (int i = 0; i < jumlah_siswa; i++) {
        cout << "\n[ Data Siswa Ke-" << (i + 1) << " ]" << endl;
        // Format Output Tanggal jadi DD/MM/YYYY
        cout << "Tanggal Lahir : " << data_siswa[i].ttl.tgl << "/" 
                                   << data_siswa[i].ttl.bln << "/" 
                                   << data_siswa[i].ttl.thn << endl;
        cout << "NPM           : " << data_siswa[i].npm << endl;
        cout << "Nama          : " << data_siswa[i].nama << endl;
        cout << "Alamat        : " << data_siswa[i].alamat << endl;
        cout << "Mata Kuliah   : " << data_siswa[i].mk << endl;
    }

    return 0;
}