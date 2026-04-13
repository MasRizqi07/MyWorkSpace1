#include <iostream>
using namespace std;
int main() {
    int pilihan;
    string jkel;

    cout << "Masukkan jenis kelamin (L/P): " << endl;
    cout << "1. laki - laki\n2. Perempuan\n" << endl;
    cout << "Masukkan pilihan (1/2): ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            jkel = "Laki - laki";
            break;
        case 2:
            jkel = "Perempuan";
            break;
            default:
            jkel = "Pilihan tidak valid! ";
    }
    cout << "jenis kelamin: " << jkel << endl;
    return 0;
}
