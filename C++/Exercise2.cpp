#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double angka1;
    int angka2 = 38; // 2 digit terakhir NIM = 38
    int pilihan;
    double hasil;

    cout << "\n";
    cout << "==============================================" << endl;
    cout << "       KALKULATOR SEDERHANA - C++            " << endl;
    cout << "       EXERCISE 2 | NIM: ...138              " << endl;
    cout << "==============================================" << endl;
    cout << endl;

    // Input pertama dari user
    cout << "Masukkan Angka Pertama  : ";
    cin >> angka1;

    // Input kedua sudah ditetapkan (melibatkan 2 digit terakhir NIM)
    cout << "Angka Kedua (tetap)     : " << angka2 << "  <-- 2 digit terakhir NIM" << endl;
    cout << endl;

    // Pilih operator
    cout << "Pilih Operator:" << endl;
    cout << "  1. Penjumlahan  (+)" << endl;
    cout << "  2. Pengurangan  (-)" << endl;
    cout << "  3. Perkalian    (*)" << endl;
    cout << "  4. Pembagian    (/)" << endl;
    cout << "  5. Modulus      (%)" << endl;
    cout << endl;
    cout << "Masukkan Pilihan (1-5)  : ";
    cin >> pilihan;
    cout << endl;

    // Proses operator
    cout << "----------------------------------------------" << endl;
    switch (pilihan) {
        case 1:
            hasil = angka1 + angka2;
            cout << "  " << angka1 << " + " << angka2 << " = " << hasil << endl;
            break;
        case 2:
            hasil = angka1 - angka2;
            cout << "  " << angka1 << " - " << angka2 << " = " << hasil << endl;
            break;
        case 3:
            hasil = angka1 * angka2;
            cout << "  " << angka1 << " * " << angka2 << " = " << hasil << endl;
            break;
        case 4:
            if (angka2 != 0) {
                hasil = angka1 / angka2;
                cout << "  " << angka1 << " / " << angka2 << " = " << fixed << setprecision(4) << hasil << endl;
            } else {
                cout << "  ERROR: Tidak bisa dibagi dengan 0!" << endl;
            }
            break;
        case 5: {
            int a1 = (int)angka1;
            hasil = a1 % angka2;
            cout << "  " << a1 << " % " << angka2 << " = " << (int)hasil << endl;
            break;
        }
        default:
            cout << "  Pilihan tidak valid! Masukkan angka 1-5." << endl;
    }

    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "==============================================" << endl;
    cout << "              PROGRAM SELESAI                " << endl;
    cout << "==============================================" << endl;
    cout << endl;

    return 0;
}