#include <iostream>

using namespace std;

struct simpul {
    char data;
    simpul *next;
};

simpul *head = NULL;
simpul *tail = NULL;

void tampilkanList() {
    if (head == NULL) {
        cout << "Linked list kosong!" << endl;
        return;
    }
    simpul *bantu = head;
    cout << "Isi List: Head -> ";
    while (bantu != NULL) {
        cout << "[" << bantu->data << "] -> ";
        bantu = bantu->next;
    }
    cout << "NULL" << endl;
}

void tambahBelakang(char elemen) {
    simpul *baru = new simpul;
    baru->data = elemen;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

void sisipTengah(char elemenBaru, char posisiData) {
    simpul *baru = new simpul;
    baru->data = elemenBaru;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        tail = baru;
        cout << "[Info] List kosong, data masuk sebagai node pertama." << endl;
    } else {
        simpul *bantu = head;
        
        while (bantu != NULL && bantu->data != posisiData) {
            bantu = bantu->next;
        }

        if (bantu == NULL) {
            cout << "[Error] Data posisi '" << posisiData << "' tidak ditemukan! Node baru gagal ditambahkan." << endl;
            delete baru;
            return;
        }

        baru->next = bantu->next;
        bantu->next = baru;

        if (baru->next == NULL) {
            tail = baru;
        }
        cout << "[Sukses] Data '" << elemenBaru << "' disisipkan setelah '" << posisiData << "'." << endl;
    }
}

int main() {
    cout << "=== Program Linked List Sisip Tengah ===" << endl;
    
    tambahBelakang('A');
    tambahBelakang('B');
    tambahBelakang('D');
    
    cout << "\nKeadaan Awal:" << endl;
    tampilkanList();

    cout << "\n> Mengeksekusi: Sisip Tengah (elemen 'C', setelah posisi 'B')" << endl;
    sisipTengah('C', 'B');
    tampilkanList();

    cout << "\n> Mengeksekusi: Sisip Tengah (elemen 'X', setelah posisi 'Z')" << endl;
    sisipTengah('X', 'Z');
    tampilkanList();

    cout << "\n========================================" << endl;

    return 0;
}