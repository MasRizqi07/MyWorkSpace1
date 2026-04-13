#include <iostream>
using namespace std;
int main() {
    int luas, panjang, Lebar;
    string ulang;
    do {
        cout << "Program Menghitung Luas Persegi Panjang dengan Do While" << endl;
        cout << "Masukkan panjang: ";
        cin >> panjang;
        cout << "Masukkan Lebar: ";
        cin >> Lebar;
        luas = panjang * Lebar;
        cout << "Luas Persegi Panjang: " << luas << endl;
        cout << "Apakah Anda ingin melanjutkan? (ya/tidak): ";
        cin >> ulang;
    } while (ulang == "ya" || ulang == "Ya" || ulang == "YA" );
    cout << "Terima Kasih telah menggunakan program ini!" << endl;
    return 0;
}