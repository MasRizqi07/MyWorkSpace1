#include <iostream>
using namespace std;
int main() {
    int x, y;
    bool kondisi;
    string hasil;

    x = 8;
    y = 10;
    // Operator ==
    kondisi = x == y;
    hasil = kondisi == 1? "sama dengan " : "tidak sama dengan ";
    cout << "Variabel x " << hasil << " variabel y" << endl;

    // Operator !=
    kondisi = x != y;
    hasil = kondisi == 1? "Tidak sama dengan " : "sama dengan ";
    cout << "Variabel x " << hasil << " variabel y" << endl;

    // Operator >
    kondisi = x > y;
    hasil = kondisi == 1? "Lebih besar dari " : "Tidak lebih besar dari ";
    cout << "Variabel x " << hasil << " variabel y " << endl;

    // Operator <
    kondisi = x < y;
    hasil = kondisi == 1? "lebih kecil dari " : "Tidak lebih kecil dari ";
    cout << "Variabel x " << hasil << " variabel y " << endl;

    // Operator >=
    kondisi = x >= y;
    hasil = kondisi == 1? "Lebih besar dari atau sama dengan " : "Tidak lebih besar dari atau sama dengan ";
    cout << "Variabel x " << hasil << " variabel y " << endl;

    //Operator <=
    kondisi = x <= y;
    hasil = kondisi == 1? "lebih kecil dari atau sama dengan " : "Tidakn Lebih kecil dari atau sama dengan ";
    cout << "Variabel x " << hasil << " variabel y " << endl;
}