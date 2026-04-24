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

class LinkedList {
    private:
        Node* head;
        int idCounter;

    public:
        LinkedList();
        ~LinkedList();
        void addMahasiswa();
        void displayAll() const;
        void searchByNPM() const;
        void updateByNPM();
        void deleteByNPM();
        void clearAll();
        bool isDuplicateNPM(const string& npm) const;
        static bool isValidNPM(const string& npm);
        static bool isValidIPK(double ipk);
        static string readLine(const string& prompt);
};

LinkedList::LinkedList() {
    head = nullptr;
    idCounter = 1;
}

LinkedList::~LinkedList() {
    clearAll();
}

string LinkedList::readLine(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

bool LinkedList::isValidNPM(const string& npm) {
    if (npm.length() != 8) return false;
    for (char c : npm) {
        if (!isdigit(static_cast<unsigned char>(c))) return false;
    }
    return true;
}

bool LinkedList::isValidIPK(double ipk) {
    return ipk >= 0.0 && ipk <= 4.0;
}

bool LinkedList::isDuplicateNPM(const string& npm) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->npm == npm) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::addMahasiswa() {
    string nama = readLine("Masukkan nama: ");
    if (nama.empty()) {
        cout << "Nama tidak boleh kosong." << endl;
        return;
    }

    string npm = readLine("Masukkan NPM (8 digit): ");
    if (npm.empty()) {
        cout << "NPM tidak boleh kosong." << endl;
        return;
    }
    if (!isValidNPM(npm)) {
        cout << "NPM harus 8 digit angka." << endl;
        return;
    }
    if (isDuplicateNPM(npm)) {
        cout << "NPM sudah terdaftar. Gunakan NPM lain." << endl;
        return;
    }

    string jurusan = readLine("Masukkan jurusan: ");
    if (jurusan.empty()) {
        cout << "Jurusan tidak boleh kosong." << endl;
        return;
    }

    string ipkString = readLine("Masukkan IPK (0.0 - 4.0): ");
    if (ipkString.empty()) {
        cout << "IPK tidak boleh kosong." << endl;
        return;
    }

    try {
        double ipk = stod(ipkString);
        if (!isValidIPK(ipk)) {
            cout << "IPK harus antara 0.0 sampai 4.0." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->id = idCounter++;
        newNode->nama = nama;
        newNode->npm = npm;
        newNode->jurusan = jurusan;
        newNode->ipk = ipk;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Data mahasiswa berhasil ditambahkan." << endl;
    } catch (const invalid_argument&) {
        cout << "IPK harus berupa angka." << endl;
    } catch (const out_of_range&) {
        cout << "IPK tidak valid." << endl;
    }
}

void LinkedList::displayAll() const {
    if (head == nullptr) {
        cout << "Belum ada data mahasiswa." << endl;
        return;
    }

    cout << "\nDaftar Mahasiswa:" << endl;
    cout << "-----------------------------------------------" << endl;
    Node* current = head;
    while (current != nullptr) {
        cout << "ID      : " << current->id << endl;
        cout << "Nama    : " << current->nama << endl;
        cout << "NPM     : " << current->npm << endl;
        cout << "Jurusan : " << current->jurusan << endl;
        cout << "IPK     : " << current->ipk << endl;
        cout << "-----------------------------------------------" << endl;
        current = current->next;
    }
}

void LinkedList::searchByNPM() const {
    string npm = readLine("Masukkan NPM yang dicari: ");
    if (npm.empty()) {
        cout << "NPM tidak boleh kosong." << endl;
        return;
    }
    if (!isValidNPM(npm)) {
        cout << "NPM harus 8 digit angka." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->npm == npm) {
            cout << "Data ditemukan:" << endl;
            cout << "ID      : " << current->id << endl;
            cout << "Nama    : " << current->nama << endl;
            cout << "NPM     : " << current->npm << endl;
            cout << "Jurusan : " << current->jurusan << endl;
            cout << "IPK     : " << current->ipk << endl;
            return;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
}

void LinkedList::updateByNPM() {
    string npm = readLine("Masukkan NPM mahasiswa yang akan diupdate: ");
    if (npm.empty()) {
        cout << "NPM tidak boleh kosong." << endl;
        return;
    }
    if (!isValidNPM(npm)) {
        cout << "NPM harus 8 digit angka." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->npm == npm) {
            string nama = readLine("Masukkan nama baru: ");
            if (nama.empty()) {
                cout << "Nama tidak boleh kosong." << endl;
                return;
            }
            string jurusan = readLine("Masukkan jurusan baru: ");
            if (jurusan.empty()) {
                cout << "Jurusan tidak boleh kosong." << endl;
                return;
            }
            string ipkString = readLine("Masukkan IPK baru (0.0 - 4.0): ");
            if (ipkString.empty()) {
                cout << "IPK tidak boleh kosong." << endl;
                return;
            }
            try {
                double ipk = stod(ipkString);
                if (!isValidIPK(ipk)) {
                    cout << "IPK harus antara 0.0 sampai 4.0." << endl;
                    return;
                }
                current->nama = nama;
                current->jurusan = jurusan;
                current->ipk = ipk;
                cout << "Data mahasiswa berhasil diperbarui." << endl;
            } catch (const invalid_argument&) {
                cout << "IPK harus berupa angka." << endl;
            } catch (const out_of_range&) {
                cout << "IPK tidak valid." << endl;
            }
            return;
        }
        current = current->next;
    }
    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
}

void LinkedList::deleteByNPM() {
    string npm = readLine("Masukkan NPM mahasiswa yang akan dihapus: ");
    if (npm.empty()) {
        cout << "NPM tidak boleh kosong." << endl;
        return;
    }
    if (!isValidNPM(npm)) {
        cout << "NPM harus 8 digit angka." << endl;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->npm == npm) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Data mahasiswa berhasil dihapus." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan." << endl;
}

void LinkedList::clearAll() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    cout << "Semua data mahasiswa telah dihapus." << endl;
}

int main() {
    LinkedList list;
    int pilihan = 0;

    while (true) {
        cout << "\n====== MENU DATA MAHASISWA ======" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari mahasiswa (berdasarkan NPM)" << endl;
        cout << "4. Update Data Mahasiswa" << endl;
        cout << "5. Hapus Mahasiswa (berdasarkan NPM)" << endl;
        cout << "6. Hapus Semua Data" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih: ";

        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Silakan masukkan angka 1-7." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                list.addMahasiswa();
                break;
            case 2:
                list.displayAll();
                break;
            case 3:
                list.searchByNPM();
                break;
            case 4:
                list.updateByNPM();
                break;
            case 5:
                list.deleteByNPM();
                break;
            case 6:
                list.clearAll();
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih 1-7." << endl;
                break;
        }
    }

    return 0;
}

