#include <iostream>
using namespace std;
int main() {
    int awal, akhir;
    cout << "Masukkan angka awal: ";
    cin >> awal;
    cout << "Masukkan angka terakhir: ";
    cin >> akhir;
    for (int a = awal; a <= akhir; a++) {
        cout << a << ". Saya Senang Belajar C++" << endl;
    }
}