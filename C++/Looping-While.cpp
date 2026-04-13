#include <iostream>
using namespace std;
int main() {
    int awal, akhir;
    cout << "Masukkan angka awal: ";
    cin >> awal;
    cout << "Masukkan angka terakhir: ";
    cin >> akhir;
    int z = awal;
    while (z >= akhir) {
        cout << z << ". Saya Senang belajar C++" << endl;
        z--;
    }
}