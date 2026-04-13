#include <iostream>
#include <string>

using namespace std;

// 1. BEST PRACTICE: Taruh Struct di luar main()
struct MasterTanggal {
    int tgl;
    int bln;
    int thn;
};

// Struct Barang yang menyimpan Struct Tanggal (Nested Struct)
struct MasterBarang {
    MasterTanggal tgl_brg; // Implementasi Struct dalam Struct
    string kode_brg;       // Pakai std::string, tinggalkan char[]
    string nama_brg;
    int jum_brg;
    float hrg_sat;
};

int main() {
    // Deklarasi variabel dengan tipe struct MasterBarang
    MasterBarang barang;

    cout << "=======================================\n";
    cout << "          INPUT DATA BARANG            \n";
    cout << "=======================================\n";

    // Input Tanggal (Integer)
    cout << "Inputkan tanggal barang (DD MM YYYY) : ";
    cin >> barang.tgl_brg.tgl >> barang.tgl_brg.bln >> barang.tgl_brg.thn;

    // FLUSHING BUFFER: Sangat penting sebelum transisi dari cin (angka) ke getline (teks)
    cin.ignore(10000, '\n');

    // Input String (Menggunakan getline agar bisa pakai SPASI)
    cout << "Inputkan kode barang                 : ";
    getline(cin, barang.kode_brg);

    cout << "Inputkan nama barang                 : ";
    getline(cin, barang.nama_brg);

    // Input Angka lagi
    cout << "Inputkan jumlah barang               : ";
    cin >> barang.jum_brg;

    cout << "Inputkan harga satuan barang         : ";
    cin >> barang.hrg_sat;

    // --- FASE OUTPUT ---
    cout << "\n=======================================\n";
    cout << "          REKAP DATA BARANG            \n";
    cout << "=======================================\n";
    
    // Format output dibikin lebih rapi dan terbaca
    cout << "TANGGAL BARANG   = " << barang.tgl_brg.tgl << "-" 
                                  << barang.tgl_brg.bln << "-" 
                                  << barang.tgl_brg.thn << endl;
    cout << "KODE BARANG      = " << barang.kode_brg << endl;
    cout << "NAMA BARANG      = " << barang.nama_brg << endl;
    cout << "JUMLAH BARANG    = " << barang.jum_brg << endl;
    cout << "HARGA SATUAN     = Rp " << barang.hrg_sat << endl;
    
    // Tambahan iseng biar kelihatan analitis: hitung total aset
    cout << "TOTAL ASET       = Rp " << (barang.jum_brg * barang.hrg_sat) << endl;
    cout << "=======================================\n";

    return 0;
}