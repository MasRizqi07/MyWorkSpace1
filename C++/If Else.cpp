/*
#include <iostream>
using namespace std;
int main() {
    int biaya, total;
    cout << "Masukkan biaya: ";
    cin >> biaya;
    if (biaya > 10) {
        total = biaya - 2;
        cout << "Anda telah mendapatkan potongan 2 " << total << endl;
    } else {
        total = biaya;
        cout << "Anda tidak mendoatkan potongan " << total << endl;
    }
    cout << "Biaya awal: " << biaya << endl;
    cout << "Total = " << total << endl;
    return 0;
}
    */

#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "Masukkan angka: ";
    cin >> a;
    if (a % 2 == 1) {
        cout << "Angka " << a << " Adalah bilangan ganjil";
    } else {
        cout << "Angka " << a << " Adalah bilangan genap";
    }
    return 0;

}