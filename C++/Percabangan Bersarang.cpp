#include <iostream>
using namespace std;
int main() {
    int pilihan, umur;
    string jkel, status, kegiatan;

    cout << "Masukkan pilihan jenis kelamin (1/2): " << endl;
    cout << "1. laki-Laki \n2. Perempuan \n3. Rahasia \n" << endl;
    cout << "Masukkan pilihan anda: ";
    cin >> pilihan;
    cout << "Masukkan umur anda: ";
    cin >> umur;

    if (pilihan == 1) {
        jkel = "Laki-Laki ";
        if (umur >= 27) {
            status = "Sudah Waktunya ";
            kegiatan = "Cari Jodoh";
        } else {
            status = "belum Waktunya ";
            kegiatan = "Tingkatin Kualitas Diri ";
        }
    } else if (pilihan == 2) {
        jkel = "Perempuan ";
        if (umur >= 24) {
            status = "Sudah Waktunya ";
            kegiatan = "Cari Jodoh ";
        } else {
            status = "belum Waktunya ";
            kegiatan = "Tingkatkan Kualitas Diri ";
        }
    } else {
        jkel = "Rahasia ";
        status = "Rahasia ";
        kegiatan = "Rahasia ";
    }
    cout << "----------------------------------------------" << endl;
    cout << "Anda adalah " << jkel << " Berumur " << umur << " Tahun " << endl;
    cout << status << "Menikah Bos ! " << endl;
    cout << "Silahkan " << kegiatan << endl;
    return 0; 
}