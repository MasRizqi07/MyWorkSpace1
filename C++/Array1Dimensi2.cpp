#include <iostream>
using namespace std;

int main() {
    
    int jml_arr;
    cout << "Masukkan Jumlah Index : ";
    cin >> jml_arr;
    int angka[jml_arr];

    for (int a = 0; a < jml_arr; a++) {
        cout << "Masukkan Nilai Index ke- " << a << " : ";
        cin >> angka[a];
    }

    cout << "===============================" << endl;
    cout << "Nilai Index yang tersimpan adalah : " << endl;
    cout << "===============================" << endl;
    
    for (int a = 0; a < jml_arr; a++) {
        cout << "Nilai Index ke- " << a << " : " << angka[a] << endl;
    }
    return 0;
}