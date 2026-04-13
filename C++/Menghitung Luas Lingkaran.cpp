#include <iostream>
using namespace std;
int main() {
    const float PI = 3.14;
    float L, r;

    cout << "Masukkan Jari-jari Lingkaran: ";
    cin >> r;

    L = PI * r * r;

    cout << "Diketahui Lingkaran dengan jari-jari " << r << endl;
    cout << "PI \t= " << PI << endl;
    cout << "r \t= " << r << endl;
    cout << "===========================" << endl;

    cout << "Maka, Luas Lingkaran adalah: " << L << endl;
    cout << L << "cm2";
    return 0;

}
