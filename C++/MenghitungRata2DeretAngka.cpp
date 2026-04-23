#include <iostream>
using namespace std;

int main() {

    float jml_nilai, nilai, total, rata;
    cout << "Jumlah Data Nilai : ";
    cin >> jml_nilai;

    for (int a = 0; a < jml_nilai; a++) {
        cout << "Masukkan Nilai ke- " << a << " : ";
        cin >> nilai;
        total += nilai;
    }

    cout << "===============================" << endl;
    cout << "Total Nilai Adalah : " << total << endl;
    rata = total / jml_nilai;
    cout << "Rata-Rata Nilai Adalah : " << rata << endl;
    return 0;
}