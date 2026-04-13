#include <iostream>
using namespace std;
int main() {
    int a,hasil;
    cout << "Masukkan Bilangan Bulat: ";
    cin >> a;

    hasil = a % 2;

    string kondisi = hasil == 1 ?"ganjil " : "genap";
    cout << "Angka " << a << " Adalah Bilangan " << kondisi << endl;
    return 0;
}