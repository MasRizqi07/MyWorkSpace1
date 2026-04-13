#include <iostream>
using namespace std;

struct siswa {
    char npm[25];
    char nama[25];
    char kelas[25];
    char alamat[50];
    char mk[20];
    float nilai;
} data_siswa;

int main() {
    siswa data_siswa;
    cout << "Masukkan NPM= ";
    cin.getline(data_siswa.npm,25);
    cout << "Masukkan nama= ";
    cin.getline(data_siswa.nama,25);
    cout << "Masukkan alamat= ";
    cin.getline(data_siswa.alamat,50);
    cout << "Masukkan mk= ";
    cin.getline(data_siswa.mk,20);
    cout << "Masukkan nilai= ";
    cin >> data_siswa.nilai;

    cout << endl;
    cout << endl;
    cout << "NPM= " << data_siswa.npm << endl;
    cout << "Nama= " << data_siswa.nama << endl;
    cout << "Alamat= " << data_siswa.alamat << endl;
    cout << "MK= " << data_siswa.mk << endl;
    cout << "Nilai= " << data_siswa.nilai << endl;
    return 0;
}