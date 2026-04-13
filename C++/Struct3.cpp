#include <iostream>
using namespace std;

struct siswa {
    char npm[15];
    char nama[25];
    char alamat[30];
    char mk[30];
    float na;
};
siswa data_siswa[6];
int main() {
    int i,b;
    cout << "Banyaknya Siswa: ";
    cin >> b;
    for (i = 1; i <= b; i++) {
        cin.ignore();
        cout << endl;

        cin.getline(data_siswa[i].npm, 12);
        cout << "Masukkan NPM Ke- " << i << "=";
        cin.getline(data_siswa[i].npm, 12);
        cout << "Masukkan Nama Ke- " << i << "=";
        cin.getline(data_siswa[i].nama, 25);
        cout << "Masukkan Alamat ke- " << i << "=";
        cin.getline(data_siswa[i].alamat, 30);
        cout << "Masukkan Mata Kuliah Ke- " << i << "=";
        cin.getline(data_siswa[i].mk, 30);
        cout << "Masukkan Nilai Akhir Ke- " << i << "=";
        cin >> data_siswa[i].na;
    }

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "NPM Ke- " << i << "=" << data_siswa[i].npm << endl;
    cout << "Nama Ke- " << i << "=" << data_siswa[i].nama << endl;
    cout << "Alamat Ke- " << i << "=" << data_siswa[i].alamat << endl;
    cout << "Mata Kuliah ke- " << i << "=" << data_siswa[i].mk << endl;
    cout << "Nilai Akhir Ke- " << i << "=" << data_siswa[i].na << endl;

    if ((data_siswa[i].na >= 80.56) && (data_siswa[i].na <= 100)) {
        cout << "Nilai Huruf Siswa Ke- " << i << "= A";
    }
    else if ((data_siswa[i].na >= 85.56) && (data_siswa[i].na <= 80.55)) {
        cout << "Nilai Huruf Siswa Ke- " << i << "= B";
    }
    else if ((data_siswa[i].na >= 55.56) && (data_siswa[i].na <= 65.55)) {
        cout << "Nilai Huruf Siswa Ke- " << i << "= C";
    }
    else if ((data_siswa[i].na >= 40.56) && (data_siswa[i].na <= 55.56)) {
        cout << "Nilai Huruf Siswa Ke- " << i << "= D";
    }
    else {
        cout << "Nilai Huruf Siswa ke- " << i << "= E";
                }
        } 