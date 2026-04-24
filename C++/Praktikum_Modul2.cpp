#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Node {
    int id;
    string nama;
    string npm;
    string jurusan;
    double ipk;
    Node* next;
};

class MahasiswaList {
private:
    Node* head;
    Node* tail; // Optimasi: Insert di akhir jadi O(1)
    int idCounter;

    // Helper untuk cek duplikat NPM
    bool isDuplicateNPM(const string& npm) {
        Node* current = head;
        while (current != nullptr) {
            if (current->npm == npm) return true;
            current = current->next;
        }
        return false;
    }

public:
    MahasiswaList() : head(nullptr), tail(nullptr), idCounter(1) {}

    ~MahasiswaList() {
        clearAll();
    }

    void addMahasiswa() {
        string nama, npm, jurusan, ipkStr;
        double ipk;

        cout << "Masukkan nama: ";
        getline(cin >> ws, nama);
        cout << "Masukkan NPM (8 digit): ";
        cin >> npm;
        cout << "Masukkan jurusan: ";
        getline(cin >> ws, jurusan);
        cout << "Masukkan IPK (0.0 - 4.0): ";
        cin >> ipkStr;

        // Validasi Input
        if (nama.empty() || npm.empty() || jurusan.empty() || ipkStr.empty()) {
            cout << "Kesalahan: Data tidak boleh kosong!" << endl;
            return;
        }

        if (npm.length() != 8) {
            cout << "Kesalahan: NPM harus 8 digit!" << endl;
            return;
        }

        if (isDuplicateNPM(npm)) {
            cout << "Kesalahan: NPM sudah terdaftar!" << endl;
            return;
        }

        try {
            ipk = stod(ipkStr);
            if (ipk < 0.0 || ipk > 4.0) {
                cout << "Kesalahan: IPK harus antara 0.0 - 4.0!" << endl;
                return;
            }
        } catch (...) {
            cout << "Kesalahan: IPK harus berupa angka!" << endl;
            return;
        }

        // Pembuatan Node Baru
        Node* newNode = new Node{idCounter++, nama, npm, jurusan, ipk, nullptr};

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Data berhasil ditambahkan ke akhir list." << endl;
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "Daftar mahasiswa kosong." << endl;
            return;
        }
        Node* curr = head;
        cout << "\nDAFTAR MAHASISWA" << endl;
        while (curr != nullptr) {
            cout << "[" << curr->id << "] " << curr->npm << " - " << curr->nama 
                 << " (" << curr->jurusan << ") IPK: " << curr->ipk << endl;
            curr = curr->next;
        }
    }

    void searchByNPM() {
        string target;
        cout << "Cari NPM: ";
        cin >> target;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->npm == target) {
                cout << "Data Ditemukan: " << curr->nama << " | " << curr->jurusan << " | IPK: " << curr->ipk << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Mahasiswa dengan NPM " << target << " tidak ditemukan." << endl;
    }

    void updateByNPM() {
        string target;
        cout << "NPM yang akan diupdate: ";
        cin >> target;

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->npm == target) {
                cout << "Nama Baru: "; getline(cin >> ws, curr->nama);
                cout << "Jurusan Baru: "; getline(cin >> ws, curr->jurusan);
                cout << "IPK Baru: "; cin >> curr->ipk;
                cout << "Update berhasil." << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "NPM tidak ditemukan." << endl;
    }

    void deleteByNPM() {
        string target;
        cout << "NPM yang akan dihapus: ";
        cin >> target;

        Node *curr = head, *prev = nullptr;
        while (curr != nullptr) {
            if (curr->npm == target) {
                if (prev == nullptr) head = curr->next;
                else prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                cout << "Data berhasil dihapus." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "NPM tidak ditemukan." << endl;
    }

    void clearAll() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Semua data dibersihkan." << endl;
    }
};

int main() {
    MahasiswaList list;
    int pilihan;

    do {
        cout << "\n====== MENU DATA MAHASISWA ======" << endl;
        cout << "1. Tambah Mahasiswa\n2. Tampilkan Semua Mahasiswa\n3. Cari (NPM)\n";
        cout << "4. Update Data\n5. Hapus (NPM)\n6. Hapus Semua Data\n7. Keluar\nPilih: ";
        
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (pilihan) {
            case 1: list.addMahasiswa(); break;
            case 2: list.displayAll(); break;
            case 3: list.searchByNPM(); break;
            case 4: list.updateByNPM(); break;
            case 5: list.deleteByNPM(); break;
            case 6: list.clearAll(); break;
        }
    } while (pilihan != 7);

    return 0;
}