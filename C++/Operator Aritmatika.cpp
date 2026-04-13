//Operator Penjumlahan
//#include <iostream>
//using namespace std;

//int main() {
   //int a, b , hasil;
    
    //cout << "Masukkan Nilai a : ";
    //cin >> a;
    //cout << "Masukkan Nilai B : ";
    //cin >> b;
    //hasil = a + b;
    //cout << "Hasil Penjumlahan " << a << " + " << b << " Adalah = " << hasil << endl;
    //return 0;
//}


//Operator Pengurangan
//#include <iostream>
//using namespace std;
//int main() {
    //int sekarang, thn_lahir, umur;

    //cout << "Masukkan Tahun sekarang = ";
    //cin >> sekarang;
    //cout << "Tahun Lahir Anda : ";
    //cin >> thn_lahir;
    //umur = sekarang - thn_lahir;

    //cout << "Sekarang Tahun : " << sekarang << endl;
    //cout << "Tahun Lahir Anda adalah : " << thn_lahir << endl;
    //cout << "Umur Anda Sekarang Adalah = " << umur << " tahun" << endl;
    
    //return 0;
//}


//Operator Perkalian
//#include <iostream>
//using namespace std;
//int main() {
    //int a, b, hasil;

    //cout << "Masukkan Nilai a : ";
    //cin >> a;
   //cout << "Masukkan Nilai b : ";
    //cin >> b;

    //hasil = a * b;

    //cout << "Hasil Perkalian " << a << " * " << b << " Adalah = " << hasil << endl;
    //return 0;
//}


//Operator Pembagian
//#include <iostream>
//using namespace std;
//int main() {
    //float a, b, hasil;

    //cout << "Masukkan Nilai a : ";
    //cin >> a;
    //cout << "Masukkan Nilai b : ";
    //cin >> b;

    //hasil = a / b;

    //cout << "Hasil Pembagian " << a << " / " << b << " Adalah = " << hasil << endl;
    //return 0;
//}

//Operator Modulus
#include <iostream>
using namespace std;
int main() {
    int a, hasil;

    cout << "Masukkan Nilai a : ";
    cin >> a;

    hasil = a % 2;
    string jenis = hasil == 1 ? "ganjil " : "genap ";
    
    cout <<"Bilangan " << a << " adalah bilangan " << jenis << endl;
    
    return 0;
}