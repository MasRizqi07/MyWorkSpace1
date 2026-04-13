/*
#include <iostream>
using namespace std;
int main() {
    int pilihan;
    cout << "Pilih salah satu \n.1 Laki-Laki \n.2 Perempuan \n.3 Rahasia \n";
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;

    if (pilihan == 1) {
        cout << "Jenis kelamin Anda adalah Laki-Laki" << endl;
    } else if (pilihan == 2) {
        cout << "Jenis kelamin Anda adalah Perempuan" << endl;
    } else if (pilihan == 3) {
        cout << "jenis kelamin Anda adalah Rahasia" << endl;
    } else {
        cout << "Pilihan tidak tersedia" << endl;
    }
    return 0;
}
    */

#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "Masukkan angka: ";
    cin >> a;
    if (a > 0) {
        cout << "Angka positif" << endl;
    } else if (a < 0) {
        cout << "Angka negatif" << endl;
    } else {
        cout << "Angka nol" << endl;
    }
}