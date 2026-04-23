#include <iostream>
using namespace std;

int main() {

    int jml_index;
    cout << "Masukkan Jumlah Index : ";
    cin >> jml_index;

    float nilai[jml_index], total, rerata;
    for (int a = 0; a < jml_index; a++) {
        cout << "Masukkan Nilai Index ke- " << a << " : ";
        cin >> nilai[a];
    }

    for (int b = 0; b < jml_index; b++) {
        total += nilai[b];
    }
    cout << "===============================" << endl;
    cout << "Total Nilai Index Adalah : " << total << endl;
    cout << "===============================" << endl;
    rerata = total / jml_index;
    cout << "Rata-Rata Nilai Index Adalah : " << rerata << endl;
    return 0;
}
