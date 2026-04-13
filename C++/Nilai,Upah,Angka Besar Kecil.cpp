#include <iostream>
using namespace std;

void soal1() {
    int nilai;
    cout << "=== SOAL 1: KONVERSI NILAI KE GRADE ===" << endl;
    cout << "Masukkan nilai (0-100): ";
    cin >> nilai;
    
    if (nilai >= 85) {
        cout << "Grade: A" << endl;
    } else if (nilai >= 70 && nilai <= 84) {
        cout << "Grade: B" << endl;
    } else if (nilai >= 55 && nilai <= 69) {
        cout << "Grade: C" << endl;
    } else {
        cout << "Grade: D" << endl;
    }
    cout << endl;
}

void soal2() {
    int jamKerja;
    int upahNormal = 20000;
    int upahLembur = 30000;
    int totalUpah;
    
    cout << "=== SOAL 2: HITUNG UPAH KERJA ===" << endl;
    cout << "Masukkan jam kerja: ";
    cin >> jamKerja;
    
    if (jamKerja > 8) {
        int jamNormal = 8;
        int jamLemburTotal = jamKerja - 8;
        totalUpah = (jamNormal * upahNormal) + (jamLemburTotal * upahLembur);
        
        cout << "Jam normal: " << jamNormal << " jam x Rp " << upahNormal << " = Rp " << jamNormal * upahNormal << endl;
        cout << "Jam lembur: " << jamLemburTotal << " jam x Rp " << upahLembur << " = Rp " << jamLemburTotal * upahLembur << endl;
        cout << "Total upah: Rp " << totalUpah << endl;
    } else {
        totalUpah = jamKerja * upahNormal;
        cout << "Jam normal: " << jamKerja << " jam x Rp " << upahNormal << endl;
        cout << "Total upah: Rp " << totalUpah << endl;
    }
    cout << endl;
}

void soal3() {
    int angka1, angka2, angka3;
    int terbesar, terkecil;
    
    cout << "=== SOAL 3: ANGKA TERBESAR DAN TERKECIL ===" << endl;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    cout << "Masukkan angka ketiga: ";
    cin >> angka3;
    
    terbesar = angka1;
    if (angka2 > terbesar) {
        terbesar = angka2;
    }
    if (angka3 > terbesar) {
        terbesar = angka3;
    }
    
    terkecil = angka1;
    if (angka2 < terkecil) {
        terkecil = angka2;
    }
    if (angka3 < terkecil) {
        terkecil = angka3;
    }
    
    cout << "Angka terbesar: " << terbesar << endl;
    cout << "Angka terkecil: " << terkecil << endl;
    cout << endl;
}

int main() {
    int pilihan;
    
    do {
        cout << "========================================" << endl;
        cout << "        MENU PROGRAM C++" << endl;
        cout << "========================================" << endl;
        cout << "1. Soal 1 - Konversi Nilai ke Grade" << endl;
        cout << "2. Soal 2 - Hitung Upah Kerja" << endl;
        cout << "3. Soal 3 - Angka Terbesar & Terkecil" << endl;
        cout << "4. Jalankan Semua Soal" << endl;
        cout << "0. Keluar" << endl;
        cout << "========================================" << endl;
        cout << "Pilih menu (0-4): ";
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
                soal1();
                soal2();
                soal3();
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