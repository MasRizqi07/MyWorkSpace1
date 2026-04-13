#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;


struct TanggalLahir {
    int tanggal;
    int bulan;
    int tahun;
};


struct IP {
    float ips;  
    float ipk;  
};


struct Mahasiswa {
    string nama;
    string npm;
    string jurusan;
    string alamat;
    string jenisKelamin;
    TanggalLahir tempatTanggalLahir;
    string tempatLahir;
    int umur;
    IP indeksPrestasi;
};


const int MAX = 100;
Mahasiswa dataMhs[MAX];
int jumlahMhs = 0;



string pilihJurusan() {
    cout << "Jurusan:\n";
    cout << "  1. T. Informatika\n";
    cout << "  2. T. Elektro\n";
    cout << "  3. T. Mesin\n";
    cout << "  4. T. Sipil\n";
    cout << "  5. T. Kimia\n";
    cout << "  6. T. Industri\n";
    cout << "Pilih (1-6) : ";

    int pil;
    cin >> pil;

    string jur[] = {"T. Informatika", "T. Elektro", "T. Mesin", "T. Sipil", "T. Kimia", "T. Industri"};
    if (pil >= 1 && pil <= 6) return jur[pil - 1];
    return "T. Informatika";
}

void cetakHeaderTabel() {
    cout << "\n" << string(90, '=') << "\n";
    cout << left
         << setw(4)  << "No"
         << setw(20) << "Nama"
         << setw(12) << "NPM"
         << setw(16) << "Jurusan"
         << setw(12) << "JK"
         << setw(5)  << "Umur"
         << setw(6)  << "IPS"
         << setw(6)  << "IPK"
         << "\n";
    cout << string(90, '-') << "\n";
}

void cetakBarisTable(Mahasiswa m, int no) {
    cout << left
         << setw(4)  << no
         << setw(20) << m.nama
         << setw(12) << m.npm
         << setw(16) << m.jurusan
         << setw(12) << m.jenisKelamin
         << setw(5)  << m.umur
         << setw(6)  << fixed << setprecision(2) << m.indeksPrestasi.ips
         << setw(6)  << fixed << setprecision(2) << m.indeksPrestasi.ipk
         << "\n";
}

void cetakDetailMahasiswa(Mahasiswa m, int no) {
    cout << "\n+--------------------------------------------+\n";
    cout << "| Detail Mahasiswa #" << no << setw(26) << "|\n";
    cout << "+--------------------------------------------+\n";
    cout << "| Nama          : " << left << setw(28) << m.nama << "|\n";
    cout << "| NPM           : " << setw(28) << m.npm << "|\n";
    cout << "| Jurusan       : " << setw(28) << m.jurusan << "|\n";
    cout << "| Alamat        : " << setw(28) << m.alamat << "|\n";
    cout << "| Jenis Kelamin : " << setw(28) << m.jenisKelamin << "|\n";
    cout << "| Tempat Lahir  : " << setw(28) << m.tempatLahir << "|\n";

    string tgl = to_string(m.tempatTanggalLahir.tanggal) + "/" +
                 to_string(m.tempatTanggalLahir.bulan) + "/" +
                 to_string(m.tempatTanggalLahir.tahun);
    cout << "| Tgl Lahir     : " << setw(28) << tgl << "|\n";
    cout << "| Umur          : " << setw(28) << (to_string(m.umur) + " tahun") << "|\n";
    cout << "| IPS           : " << setw(28) << fixed << setprecision(2) << m.indeksPrestasi.ips << "|\n";
    cout << "| IPK           : " << setw(28) << fixed << setprecision(2) << m.indeksPrestasi.ipk << "|\n";
    cout << "+--------------------------------------------+\n";
}




void inputDataMahasiswa() {
    int n;
    cout << "\n=== INPUT DATA MAHASISWA ===\n";
    cout << "Masukkan jumlah mahasiswa yang akan diinput: ";
    cin >> n;

    if (jumlahMhs + n > MAX) {
        cout << "Data melebihi kapasitas maksimum (" << MAX << ")!\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        Mahasiswa &m = dataMhs[jumlahMhs];
        cout << "\n--- Input Mahasiswa ke-" << (i + 1) << " ---\n";

        cin.ignore();
        cout << "Nama           : ";
        getline(cin, m.nama);

        cout << "NPM            : ";
        getline(cin, m.npm);

        m.jurusan = pilihJurusan();

        cin.ignore();
        cout << "Alamat         : ";
        getline(cin, m.alamat);

        cout << "Jenis Kelamin (L/P) : ";
        getline(cin, m.jenisKelamin);

        cout << "Tempat Lahir   : ";
        getline(cin, m.tempatLahir);

        cout << "Tanggal Lahir:\n";
        cout << "  Tanggal : ";
        cin >> m.tempatTanggalLahir.tanggal;
        cout << "  Bulan   : ";
        cin >> m.tempatTanggalLahir.bulan;
        cout << "  Tahun   : ";
        cin >> m.tempatTanggalLahir.tahun;

        cout << "Umur           : ";
        cin >> m.umur;

        cout << "IPS (IP Semester) : ";
        cin >> m.indeksPrestasi.ips;

        cout << "IPK (IP Kumulatif): ";
        cin >> m.indeksPrestasi.ipk;

        jumlahMhs++;
        cout << "Data berhasil disimpan!\n";
    }
}


void cetakSemuaMahasiswa() {
    cout << "\n=== CETAK DATA SEMUA MAHASISWA ===\n";

    if (jumlahMhs == 0) {
        cout << "Belum ada data mahasiswa!\n";
        return;
    }

    cetakHeaderTabel();
    for (int i = 0; i < jumlahMhs; i++) {
        cetakBarisTable(dataMhs[i], i + 1);
    }
    cout << string(90, '=') << "\n";
    cout << "Total: " << jumlahMhs << " mahasiswa\n";
}


void cariDataMahasiswa() {
    cout << "\n=== CARI DATA MAHASISWA ===\n";

    if (jumlahMhs == 0) {
        cout << "Belum ada data mahasiswa!\n";
        return;
    }

    int pil;
    cout << "Cari berdasarkan:\n";
    cout << "  1. Nama\n";
    cout << "  2. NPM\n";
    cout << "  3. Jurusan\n";
    cout << "Pilih (1-3) : ";
    cin >> pil;

    cin.ignore();
    string keyword;
    cout << "Masukkan kata kunci : ";
    getline(cin, keyword);

    
    string keyLower = keyword;
    transform(keyLower.begin(), keyLower.end(), keyLower.begin(), ::tolower);

    bool found = false;
    cout << "\nHasil Pencarian:\n";
    cetakHeaderTabel();

    for (int i = 0; i < jumlahMhs; i++) {
        string target = "";

        if (pil == 1) target = dataMhs[i].nama;
        else if (pil == 2) target = dataMhs[i].npm;
        else if (pil == 3) target = dataMhs[i].jurusan;

        
        string targetLower = target;
        transform(targetLower.begin(), targetLower.end(), targetLower.begin(), ::tolower);

        
        if (targetLower.find(keyLower) != string::npos) {
            cetakBarisTable(dataMhs[i], i + 1);
            found = true;
        }
    }

    cout << string(90, '=') << "\n";

    if (!found) {
        cout << "Data dengan keyword \"" << keyword << "\" tidak ditemukan!\n";
    }
}


void urutkanData() {
    cout << "\n=== URUTKAN DATA MAHASISWA ===\n";

    if (jumlahMhs == 0) {
        cout << "Belum ada data mahasiswa!\n";
        return;
    }

    
    for (int i = 0; i < jumlahMhs - 1; i++) {
        for (int j = 0; j < jumlahMhs - i - 1; j++) {
            bool perluTukar = false;

            if (dataMhs[j].jurusan > dataMhs[j + 1].jurusan) {
                
                perluTukar = true;
            } else if (dataMhs[j].jurusan == dataMhs[j + 1].jurusan) {
                
                if (dataMhs[j].npm > dataMhs[j + 1].npm) {
                    perluTukar = true;
                }
            }

            if (perluTukar) {
                Mahasiswa temp = dataMhs[j];
                dataMhs[j] = dataMhs[j + 1];
                dataMhs[j + 1] = temp;
            }
        }
    }

    cout << "Data berhasil diurutkan berdasarkan Jurusan & NPM (Ascending)!\n";

    
    cetakHeaderTabel();
    for (int i = 0; i < jumlahMhs; i++) {
        cetakBarisTable(dataMhs[i], i + 1);
    }
    cout << string(90, '=') << "\n";
}


void tampilkanMenu() {
    cout << "\n============================================\n";
    cout << "       PROGRAM DATA MAHASISWA - SOAL 2     \n";
    cout << "============================================\n";
    cout << "  a. Input & Cetak Data Mahasiswa\n";
    cout << "  b. Cari Data Mahasiswa\n";
    cout << "  c. Urutkan Data (NPM & Jurusan Ascending)\n";
    cout << "  d. Cetak Semua Data\n";
    cout << "  0. Keluar\n";
    cout << "============================================\n";
    cout << "Pilih menu : ";
}

int main() {
    char pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        pilihan = tolower(pilihan);

        switch (pilihan) {
            case 'a':
                inputDataMahasiswa();
                break;
            case 'b':
                cariDataMahasiswa();
                break;
            case 'c':
                urutkanData();
                break;
            case 'd':
                cetakSemuaMahasiswa();
                break;
            case '0':
                cout << "\nTerima kasih! Program selesai.\n";
                break;
            default:
                cout << "\nMenu tidak valid! Coba lagi.\n";
        }

    } while (pilihan != '0');

    return 0;
}