#include <iostream>
using namespace std;

void soal1() {
    int angka;
    cout << "=== SOAL 1: DUA KALI LIPAT ===" << endl;
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Dua kali lipatnya: " << angka * 2 << endl;
    cout << endl;
}

void soal2() {
    int angka1, angka2;
    cout << "=== SOAL 2: PENJUMLAHAN ===" << endl;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << endl;
}

void soal3() {
    double panjang, lebar;
    cout << "=== SOAL 3: LUAS PERSEGI PANJANG ===" << endl;
    cout << "Masukkan panjang: ";
    cin >> panjang;
    cout << "Masukkan lebar: ";
    cin >> lebar;
    cout << "Luas persegi panjang: " << panjang * lebar << endl;
    cout << endl;
}

void soal4() {
    int umur;
    cout << "=== SOAL 4: KATEGORI UMUR ===" << endl;
    cout << "Masukkan umur: ";
    cin >> umur;
    
    if (umur < 12) {
        cout << "Anak anak" << endl;
    } else if (umur >= 12 && umur <= 17) {
        cout << "Remaja" << endl;
    } else {
        cout << "Dewasa" << endl;
    }
    cout << endl;
}

int main() {
    int pilihan;
    
    do {
        cout << "========================================" << endl;
        cout << "     MENU PROGRAM C++ - 4 SOAL" << endl;
        cout << "========================================" << endl;
        cout << "1. Soal 1 - Dua Kali Lipat" << endl;
        cout << "2. Soal 2 - Penjumlahan" << endl;
        cout << "3. Soal 3 - Luas Persegi Panjang" << endl;
        cout << "4. Soal 4 - Kategori Umur" << endl;
        cout << "5. Jalankan Semua Soal" << endl;
        cout << "0. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu (0-5): ";
        cin >> pilihan;
        cout << endl;
        
        switch(pilihan) {
            case 1:
                soal1();
                break;
            case 2:
                soal2();
                break;
            case 3:
                soal3();
                break;
            case 4:
                soal4();
                break;
            case 5:
                soal1();
                soal2();
                soal3();
                soal4();
                break;
            case 0:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl << endl;
        }
        
    } while(pilihan != 0);
    
    return 0;
}