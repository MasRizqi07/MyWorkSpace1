#include <iostream>
using namespace std;

int main() {
    const int MAHASISWA = 2;
    const int MATKUL = 3;
    const int KOMPONEN = 3;

    int nilai[MAHASISWA][MATKUL][KOMPONEN];

    // Input nilai
    for (int i = 0; i < MAHASISWA; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        for (int j = 0; j < MATKUL; j++) {
            cout << "  Mata kuliah ke-" << j + 1 << endl;
            for (int k = 0; k < KOMPONEN; k++) {
                cout << "    Nilai komponen ke-" << k + 1 << ": ";
                cin >> nilai[i][j][k];
            }
        }
        cout << endl;
    }

    // Output nilai
    cout << "Rekap Nilai Mahasiswa" << endl;
    for (int i = 0; i < MAHASISWA; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        for (int j = 0; j < MATKUL; j++) {
            cout << "  Mata kuliah ke-" << j + 1 << ": ";
            for (int k = 0; k < KOMPONEN; k++) {
                cout << nilai[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
