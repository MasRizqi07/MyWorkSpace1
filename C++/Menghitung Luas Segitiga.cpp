#include <iostream>
using namespace std;
int main() {
    double L, a, t;
    cout << "Masukkan alas segitiga\n======================";
    cout << "\nAlas \t\t: ";
    cin >> a;
    cout << "Tinggi \t\t: ";
    cin >> t;

    L =(a * t) / 2;

    cout << "Luas segitiga yang diketahui:  " << L << endl;
    cout << "Alas\t= " << a << endl;
    cout << "Tinggi\t= " << t << endl;
    cout << "Adalah : " << endl;
    cout << "L = (a x t) / 2\nL = (" << a << " x " << t << ") /2" << endl;
    cout << "Luas segitiga Tersebut Adalah = " << L << endl;
    return 0;
}