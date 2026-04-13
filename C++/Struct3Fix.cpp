#include <iostream>
#include <string>
#include <vector>

using namespace std; 


struct Siswa {
    string npm;
    string nama;
    string alamat;
    string mk;
    float na;
};

string tentukanNilaiHuruf(float na) {
    if (na >= 80.56 && na <= 100) {
        return "A";
    } 
    
    else if (na >= 65.56 && na <= 80.55) { 
        return "B";
    } 
    else if (na >= 55.56 && na <= 65.55) {
        return "C";
    } 
    
    else if (na >= 40.56 && na <= 55.55) { 
        return "D";
    } 
    else if (na >= 0 && na < 40.56) {
        return "E";
    }
    return "Tidak Valid"; // Fallback kalau nilainya minus atau > 100
}

int main() {
    int jumlah_siswa;
    cout << "Masukkan Banyaknya Siswa: ";
    
    // Validasi anti-crash kalau user masukin huruf pas diminta angka
    if (!(cin >> jumlah_siswa) || jumlah_siswa <= 0) {
        cout << "[ERROR] Input jumlah siswa tidak valid!" << endl;
        return 1; 
    }

    // Alokasi dinamis pakai vector
    vector<Siswa> data_siswa(jumlah_siswa);

    // --- FASE INPUT ---
    for (int i = 0; i < jumlah_siswa; i++) {
        cout << "\n--- Input Data Siswa Ke-" << (i + 1) << " ---" << endl;
        
        cin.ignore(10000, '\n'); // Flushing buffer

        cout << "Masukkan NPM          : ";
        getline(cin, data_siswa[i].npm);

        cout << "Masukkan Nama         : ";
        getline(cin, data_siswa[i].nama);

        cout << "Masukkan Alamat       : ";
        getline(cin, data_siswa[i].alamat);

        cout << "Masukkan Mata Kuliah  : ";
        getline(cin, data_siswa[i].mk);

        cout << "Masukkan Nilai Akhir  : ";
        cin >> data_siswa[i].na;
    }

    // --- FASE OUTPUT & GRADING ---
    cout << "\n=====================================";
    cout << "\n        REKAP DATA MAHASISWA         ";
    cout << "\n=====================================\n";

    // Looping di sini biar SEMUA siswa dieksekusi, bukan cuma data terakhir
    for (int i = 0; i < jumlah_siswa; i++) {
        cout << "\n[ Data Siswa Ke-" << (i + 1) << " ]" << endl;
        cout << "NPM          : " << data_siswa[i].npm << endl;
        cout << "Nama         : " << data_siswa[i].nama << endl;
        cout << "Alamat       : " << data_siswa[i].alamat << endl;
        cout << "Mata Kuliah  : " << data_siswa[i].mk << endl;
        cout << "Nilai Akhir  : " << data_siswa[i].na << endl;
        
        // Panggil fungsi grading dengan parameter Nilai Akhir
        cout << "Nilai Huruf  : " << tentukanNilaiHuruf(data_siswa[i].na) << endl;
    }

    return 0;
}