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
    siswa data_siswa [3];
    for(int i=0; i<3; i++) {
        cout << "Masukkan NPM= ";
        cin.getline(data_siswa[i].npm,25);
        cout << "Masukkan nama= ";
        cin.getline(data_siswa[i].nama,25);
        cout << "Masukkan alamat= ";
        cin.getline(data_siswa[i].alamat,50);
        cout << "Masukkan mk= ";
        cin.getline(data_siswa[i].mk,20);
        cout << "Masukkan nilai= ";
        cin >> data_siswa[i].nilai;
        cin.ignore();
        cout<<endl;
    }
    
    cout<<endl;
    cout<<endl;
    for(int i=0; i<3; i++) {
        cout << "NPM= " << data_siswa[i].npm << endl;
        cout << "Nama= " << data_siswa[i].nama << endl;
        cout << "Alamat= " << data_siswa[i].alamat << endl;
        cout << "MK= " << data_siswa[i].mk << endl;
        cout << "Nilai= " << data_siswa[i].nilai << endl;
        cout<<endl;
    }
    
    
}
    