#include <iostream>
using namespace std;
int main() {
    string aktivitas;
    string tempat;
    int umur;
    
    cout << "Masukkan aktivitas anda \t: ";
    getline(cin, aktivitas);
    cout << "Dimana Anda " << aktivitas << " \t: ";
    getline(cin, tempat);
    cout << "Masukkan Umur Anda \t: ";
    cin >> umur;

    cout << "saya sedang " << aktivitas << " Di " << tempat << endl;
    cout << "umur saya adalah " << umur << "tahun " << endl;
    return 0;
}