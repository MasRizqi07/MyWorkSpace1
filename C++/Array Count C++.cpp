#include <iostream>
using namespace std;

int main() {

    int jml_item;
    cout << "Masukkan Jumlah Item: ";
    cin >> jml_item;
    int harga[jml_item];
    int total;

    for (int a = 0; a < jml_item; a++) {
        cout << "Masukkan Harga Item ke- " << a << " : ";
        cin >> harga[a];
    }
    cout << "===============================" << endl;
    cout << "Jumlah Item yang tersimpan adalah : " << jml_item << endl;
    
    for (int b = 0; b < jml_item; b++) {
        cout << "Item ke- " << b << " : Rp. " << harga[b] << endl;
        total += harga[b];
    }
    cout << "===============================" << endl;
    cout << "Total Harga Item Adalah : Rp. " << total << endl;
    return 0;
}