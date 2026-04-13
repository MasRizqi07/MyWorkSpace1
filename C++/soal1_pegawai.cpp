#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Tanggal {
    int tanggal;
    int bulan;
    int tahun;
};


struct Pegawai {
    string nama;
    string npp;        
    string alamat;
    string jenisKelamin;
    Tanggal tanggalMasuk;
    string status;     
    double gaji;
};


void inputPegawai(Pegawai &p, int no) {
    cout << "\n--- Input Data Pegawai ke-" << no << " ---\n";

    cout << "Nama           : ";
    cin.ignore();
    getline(cin, p.nama);

    cout << "NPP            : ";
    getline(cin, p.npp);

    cout << "Alamat         : ";
    getline(cin, p.alamat);

    cout << "Jenis Kelamin (L/P) : ";
    getline(cin, p.jenisKelamin);

    cout << "Tanggal Masuk\n";
    cout << "  Tanggal      : ";
    cin >> p.tanggalMasuk.tanggal;
    cout << "  Bulan        : ";
    cin >> p.tanggalMasuk.bulan;
    cout << "  Tahun        : ";
    cin >> p.tanggalMasuk.tahun;

    int pil;
    cout << "Status Pegawai:\n";
    cout << "  1. Honorer\n";
    cout << "  2. Tetap\n";
    cout << "Pilih (1/2)    : ";
    cin >> pil;
    p.status = (pil == 1) ? "Honorer" : "Tetap";

    cout << "Gaji           : ";
    cin >> p.gaji;
}


void cetakPegawai(Pegawai p, int no) {
    cout << "\n+------------------------------------------+\n";
    cout << "| Data Pegawai ke-" << no << setw(26) << "|\n";
    cout << "+------------------------------------------+\n";
    cout << "| Nama           : " << left << setw(24) << p.nama << "|\n";
    cout << "| NPP            : " << setw(24) << p.npp << "|\n";
    cout << "| Alamat         : " << setw(24) << p.alamat << "|\n";
    cout << "| Jenis Kelamin  : " << setw(24) << p.jenisKelamin << "|\n";
    cout << "| Tanggal Masuk  : "
         << setw(2) << setfill('0') << p.tanggalMasuk.tanggal << "/"
         << setw(2) << setfill('0') << p.tanggalMasuk.bulan << "/"
         << setfill(' ') << p.tanggalMasuk.tahun
         << setw(17) << "|\n";
    cout << "| Status         : " << setw(24) << p.status << "|\n";
    cout << "| Gaji           : Rp " << fixed << setprecision(0) << setw(21) << p.gaji << "|\n";
    cout << "+------------------------------------------+\n";
}

int main() {
    int n;

    cout << "============================================\n";
    cout << "      PROGRAM DATA PEGAWAI - SOAL 1        \n";
    cout << "============================================\n";
    cout << "Masukkan jumlah pegawai (n) : ";
    cin >> n;

    
    Pegawai *dataPegawai = new Pegawai[n];

    
    for (int i = 0; i < n; i++) {
        inputPegawai(dataPegawai[i], i + 1);
    }

    
    cout << "\n\n============================================\n";
    cout << "         CETAK DATA SEMUA PEGAWAI          \n";
    cout << "============================================\n";

    for (int i = 0; i < n; i++) {
        cetakPegawai(dataPegawai[i], i + 1);
    }

    
    delete[] dataPegawai;

    return 0;
}