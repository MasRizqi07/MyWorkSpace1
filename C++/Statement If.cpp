#include <iostream>
using namespace std;
int main() {
    int nomor;
    cout << "Masukkan nomor: ";
    cin >> nomor;
    if (nomor == 6) {
        cout << "Anda memilih nomor 6" << endl;
    } 
    if (nomor > 1) {
        cout << "Nomor Lebih dari 1" << endl;
    }
    cout << "Program selesai" << endl;
    return 0;
}