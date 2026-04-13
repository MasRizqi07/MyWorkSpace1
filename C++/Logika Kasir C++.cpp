#include <iostream>
using namespace std;
int main() {
    int roti, susu, sampo, total_harga;
    int jml_roti, jml_susu, jml_sampo;

    roti = 5000;
    susu = 4000;
    sampo = 500;

    cout << "Selamat datang di Toko Serba Ada!" << endl;
    cout << "Item Tersedia: " << endl;
    cout << "1. Roti - Rp " << roti << endl;
    cout << "2. Susu - Rp " << susu << endl;
    cout << "3. Sampo - Rp " << sampo << endl;
    cout << "===============================" << endl;

    cout << "Masukkan jumlah roti yang ingin dibeli: ";
    cin >> jml_roti;
    cout << "Masukkan jumlah susu yang ingin dibeli: ";
    cin >> jml_susu;
    cout << "Masukkan jumlah sampo yang ingin dibeli: ";
    cin >> jml_sampo;
    cout << "===============================" << endl;

    total_harga = (roti * jml_roti) + (susu * jml_susu) + (sampo * jml_sampo);
    cout << "Total Harga: Rp " << total_harga << endl;
    cout << "Terima kasih telah berbelanja!" << endl;
    return 0;
}