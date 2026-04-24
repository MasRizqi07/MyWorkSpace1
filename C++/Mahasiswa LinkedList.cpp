#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Struct untuk node mahasiswa
struct Mahasiswa {
    int id;
    string nama;
    string npm;
    string jurusan;
    float ipk;
    Mahasiswa* next;
};

// Class untuk mengelola Single Linked List
class LinkedListMahasiswa {
private:
    Mahasiswa* head;
    int lastId;

    // Helper function untuk clear input buffer
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Validasi NPM (harus 8 digit angka)
    bool isValidNPM(const string& npm) {
        if (npm.length() != 8) return false;
        for (char c : npm) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    // Cek duplikasi NPM
    bool isDuplicateNPM(const string& npm) {
        Mahasiswa* current = head;
        while (current != nullptr) {
            if (current->npm == npm) return true;
            current = current->next;
        }
        return false;
    }

    // Validasi IPK (0.0 - 4.0)
    bool isValidIPK(float ipk) {
        return ipk >= 0.0 && ipk <= 4.0;
    }

    // Validasi string tidak kosong
    bool isNotEmpty(const string& str) {
        return !str.empty() && str.find_first_not_of(' ') != string::npos;
    }

public:
    // Constructor
    LinkedListMahasiswa() : head(nullptr), lastId(0) {}

    // Destructor untuk membersihkan memory
    ~LinkedListMahasiswa() {
        hapusSemua();
    }

    // 1. Tambah data (ke akhir linked list)
    void tambahData() {
        cout << "\n===== TAMBAH DATA MAHASISWA =====" << endl;
        
        Mahasiswa* newNode = new Mahasiswa;
        newNode->id = ++lastId;
        newNode->next = nullptr;

        // Input Nama
        while (true) {
            cout << "Nama Mahasiswa: ";
            getline(cin, newNode->nama);
            if (isNotEmpty(newNode->nama)) break;
            cout << "Error: Nama tidak boleh kosong!" << endl;
        }

        // Input NPM dengan validasi
        while (true) {
            cout << "NPM (8 digit): ";
            getline(cin, newNode->npm);
            
            if (!isNotEmpty(newNode->npm)) {
                cout << "Error: NPM tidak boleh kosong!" << endl;
                continue;
            }
            if (!isValidNPM(newNode->npm)) {
                cout << "Error: NPM harus 8 digit angka!" << endl;
                continue;
            }
            if (isDuplicateNPM(newNode->npm)) {
                cout << "Error: NPM sudah terdaftar!" << endl;
                continue;
            }
            break;
        }

        // Input Jurusan
        while (true) {
            cout << "Jurusan: ";
            getline(cin, newNode->jurusan);
            if (isNotEmpty(newNode->jurusan)) break;
            cout << "Error: Jurusan tidak boleh kosong!" << endl;
        }

        // Input IPK dengan validasi
        while (true) {
            cout << "IPK (0.0 - 4.0): ";
            if (cin >> newNode->ipk) {
                if (isValidIPK(newNode->ipk)) {
                    clearInputBuffer();
                    break;
                }
                cout << "Error: IPK harus antara 0.0 - 4.0!" << endl;
            } else {
                cout << "Error: Input IPK tidak valid!" << endl;
                clearInputBuffer();
            }
        }

        // Tambah ke akhir linked list
        if (head == nullptr) {
            head = newNode;
        } else {
            Mahasiswa* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "\n✓ Data mahasiswa berhasil ditambahkan!" << endl;
    }

    // 2. Tampilkan semua data
    void tampilkanSemuaData() {
        cout << "\n===== DATA MAHASISWA =====" << endl;
        
        if (head == nullptr) {
            cout << "Tidak ada data mahasiswa." << endl;
            return;
        }

        cout << left;
        cout << setw(5) << "ID" 
             << setw(25) << "Nama" 
             << setw(12) << "NPM" 
             << setw(20) << "Jurusan" 
             << setw(6) << "IPK" << endl;
        cout << string(68, '-') << endl;

        Mahasiswa* current = head;
        while (current != nullptr) {
            cout << setw(5) << current->id
                 << setw(25) << current->nama
                 << setw(12) << current->npm
                 << setw(20) << current->jurusan
                 << fixed << setprecision(2) << current->ipk << endl;
            current = current->next;
        }
    }

    // 3. Cari berdasarkan NPM
    void cariByNPM() {
        cout << "\n===== CARI MAHASISWA =====" << endl;
        
        string npm;
        cout << "Masukkan NPM yang dicari: ";
        getline(cin, npm);

        Mahasiswa* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->npm == npm) {
                cout << "\nData ditemukan:" << endl;
                cout << "ID      : " << current->id << endl;
                cout << "Nama    : " << current->nama << endl;
                cout << "NPM     : " << current->npm << endl;
                cout << "Jurusan : " << current->jurusan << endl;
                cout << "IPK     : " << fixed << setprecision(2) << current->ipk << endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Data dengan NPM " << npm << " tidak ditemukan." << endl;
        }
    }

    // 4. Update data
    void updateData() {
        cout << "\n===== UPDATE DATA MAHASISWA =====" << endl;
        
        string npm;
        cout << "Masukkan NPM yang akan diupdate: ";
        getline(cin, npm);

        Mahasiswa* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->npm == npm) {
                found = true;
                cout << "\nData saat ini:" << endl;
                cout << "Nama    : " << current->nama << endl;
                cout << "NPM     : " << current->npm << endl;
                cout << "Jurusan : " << current->jurusan << endl;
                cout << "IPK     : " << fixed << setprecision(2) << current->ipk << endl;

                cout << "\n--- Masukkan data baru ---" << endl;
                
                string oldNPM = current->npm;

                // Update Nama
                while (true) {
                    cout << "Nama Mahasiswa: ";
                    getline(cin, current->nama);
                    if (isNotEmpty(current->nama)) break;
                    cout << "Error: Nama tidak boleh kosong!" << endl;
                }

                // Update NPM
                while (true) {
                    cout << "NPM (8 digit): ";
                    string newNPM;
                    getline(cin, newNPM);
                    
                    if (!isNotEmpty(newNPM)) {
                        cout << "Error: NPM tidak boleh kosong!" << endl;
                        continue;
                    }
                    if (!isValidNPM(newNPM)) {
                        cout << "Error: NPM harus 8 digit angka!" << endl;
                        continue;
                    }
                    // Cek duplikasi hanya jika NPM berubah
                    if (newNPM != oldNPM && isDuplicateNPM(newNPM)) {
                        cout << "Error: NPM sudah terdaftar!" << endl;
                        continue;
                    }
                    current->npm = newNPM;
                    break;
                }

                // Update Jurusan
                while (true) {
                    cout << "Jurusan: ";
                    getline(cin, current->jurusan);
                    if (isNotEmpty(current->jurusan)) break;
                    cout << "Error: Jurusan tidak boleh kosong!" << endl;
                }

                // Update IPK
                while (true) {
                    cout << "IPK (0.0 - 4.0): ";
                    if (cin >> current->ipk) {
                        if (isValidIPK(current->ipk)) {
                            clearInputBuffer();
                            break;
                        }
                        cout << "Error: IPK harus antara 0.0 - 4.0!" << endl;
                    } else {
                        cout << "Error: Input IPK tidak valid!" << endl;
                        clearInputBuffer();
                    }
                }

                cout << "\n✓ Data berhasil diupdate!" << endl;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Data dengan NPM " << npm << " tidak ditemukan." << endl;
        }
    }

    // 5. Hapus data
    void hapusData() {
        cout << "\n===== HAPUS MAHASISWA =====" << endl;
        
        if (head == nullptr) {
            cout << "Tidak ada data untuk dihapus." << endl;
            return;
        }

        string npm;
        cout << "Masukkan NPM yang akan dihapus: ";
        getline(cin, npm);

        Mahasiswa* current = head;
        Mahasiswa* previous = nullptr;
        bool found = false;

        while (current != nullptr) {
            if (current->npm == npm) {
                found = true;
                
                // Konfirmasi hapus
                char confirm;
                cout << "Yakin ingin menghapus data " << current->nama << "? (y/n): ";
                cin >> confirm;
                clearInputBuffer();

                if (confirm == 'y' || confirm == 'Y') {
                    if (previous == nullptr) {
                        // Hapus node pertama
                        head = current->next;
                    } else {
                        // Hapus node di tengah/akhir
                        previous->next = current->next;
                    }
                    delete current;
                    cout << "✓ Data berhasil dihapus!" << endl;
                } else {
                    cout << "Penghapusan dibatalkan." << endl;
                }
                break;
            }
            previous = current;
            current = current->next;
        }

        if (!found) {
            cout << "Data dengan NPM " << npm << " tidak ditemukan." << endl;
        }
    }

    // 6. Hapus semua data
    void hapusSemua() {
        if (head == nullptr) {
            return;
        }

        char confirm = 'n';
        if (head != nullptr) {  // Hanya konfirmasi jika ada data
            cout << "\nYakin ingin menghapus SEMUA data? (y/n): ";
            cin >> confirm;
            clearInputBuffer();
        }

        if (confirm == 'y' || confirm == 'Y' || head == nullptr) {
            Mahasiswa* current = head;
            while (current != nullptr) {
                Mahasiswa* temp = current;
                current = current->next;
                delete temp;
            }
            head = nullptr;
            lastId = 0;
            
            if (confirm == 'y' || confirm == 'Y') {
                cout << "✓ Semua data berhasil dihapus!" << endl;
            }
        } else {
            cout << "Penghapusan dibatalkan." << endl;
        }
    }
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\n===== MENU DATA MAHASISWA =====" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Tampilkan Semua Mahasiswa" << endl;
    cout << "3. Cari Mahasiswa (berdasarkan NPM)" << endl;
    cout << "4. Update Data Mahasiswa" << endl;
    cout << "5. Hapus Mahasiswa (berdasarkan NPM)" << endl;
    cout << "6. Hapus Semua Data" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih: ";
}

int main() {
    LinkedListMahasiswa list;
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // Clear newline dari buffer

        switch (pilihan) {
            case 1:
                list.tambahData();
                break;
            case 2:
                list.tampilkanSemuaData();
                break;
            case 3:
                list.cariByNPM();
                break;
            case 4:
                list.updateData();
                break;
            case 5:
                list.hapusData();
                break;
            case 6:
                list.hapusSemua();
                break;
            case 7:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
        }

        if (pilihan != 7) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.get();
        }

    } while (pilihan != 7);

    return 0;
}