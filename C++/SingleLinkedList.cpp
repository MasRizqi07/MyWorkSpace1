#include <iostream>
using namespace std;

struct simpul {
    char data;
    simpul *next;
};

int main() {
    simpul *awal = NULL;
    simpul *akhir = NULL;
    simpul *baru;

    char data1;
    int tekan;

    cout << "=== Program Linked List Tambah Depan ===" << endl;

    do {
        cout << "\nmasukkan data (1 karakter): ";
        cin >> data1;

        baru = new simpul;
        baru->data = data1;
        baru->next = NULL;

        if (awal == NULL) {
            awal = baru;
            akhir = baru;
        } else {
            baru->next = awal;
            awal = baru;
        }

        cout << "Ingin  tambah depan lagi? (1: ya, 0: tidak): ";
        cin >> tekan;

    } while (tekan == 1);

    cout << "\n==========================" << endl;
    cout << "Hasil akhir Linked List lu: " << endl;
    cout << "Head -> ";

    simpul *bantu = awal;
    while (bantu != NULL) {
        cout << "[" << bantu->data << "] -> ";
        bantu = bantu->next;
    }

    cout << "NULL" << endl;
    cout << "==========================" << endl;

    return 0;

}
