#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <memory>
#include <ctime>

using namespace std;

struct Transaksi {
    string tanggal;
    string tipe;
    double jumlah;

    void tampilkan() const {
        cout << "  [" << tanggal << "] " << tipe << ": Rp" << jumlah << endl;
    }
};

class Akun {
protected:
    string nomorAkun;
    string pemilik;
    string pin; // Disimpan dalam bentuk sederhana
    double saldo;
    vector<Transaksi> riwayat;

    string getWaktuSekarang() {
        time_t now = time(0);
        char* dt = ctime(&now);
        string s(dt);
        return s.substr(0, s.length() - 1); // Menghapus karakter newline
    }

public:
    Akun(string no, string nama, string p, double sal) 
        : nomorAkun(no), pemilik(nama), pin(p), saldo(sal) {}

    virtual ~Akun() {}

    bool verifikasiPin(string inputPin) {
        return pin == inputPin;
    }

    void catatTransaksi(string tipe, double jml) {
        riwayat.push_back({getWaktuSekarang(), tipe, jml});
    }

    virtual void setor(double jumlah) {
        if (jumlah > 0) {
            saldo += jumlah;
            catatTransaksi("SETOR", jumlah);
            cout << "Berhasil! Saldo saat ini: Rp" << fixed << setprecision(2) << saldo << endl;
        }
    }

    virtual bool tarik(double jumlah) = 0;

    void tampilkanRiwayat() const {
        cout << "\n--- Riwayat Transaksi Akun: " << nomorAkun << " ---" << endl;
        if (riwayat.empty()) cout << "Belum ada transaksi." << endl;
        for (const auto& t : riwayat) t.tampilkan();
    }

    string getNoAkun() const { return nomorAkun; }
    double getSaldo() const { return saldo; }
};

class AkunPremium : public Akun {
public:
    AkunPremium(string no, string nama, string p, double sal) 
        : Akun(no, nama, p, sal) {}

    bool tarik(double jumlah) override {
        if (saldo - jumlah < -1000000) { // Limit overdraft 1 juta
            cout << "Gagal: Melebihi limit overdraft Premium!" << endl;
            return false;
        }
        saldo -= jumlah;
        catatTransaksi("TARIK", jumlah);
        cout << "Penarikan berhasil. Sisa saldo (termasuk limit): Rp" << saldo << endl;
        return true;
    }
};

class BankController {
private:
    vector<unique_ptr<Akun>> database;

public:
    void registrasiNasabah() {
        string no, nama, pin;
        double awal;
        cout << "\n--- REGISTRASI NASABAH BARU ---" << endl;
        cout << "No Akun: "; cin >> no;
        cout << "Nama Pemilik: "; cin.ignore(); getline(cin, nama);
        cout << "Buat PIN (4-6 digit): "; cin >> pin;
        cout << "Setoran Awal: "; cin >> awal;

        database.push_back(make_unique<AkunPremium>(no, nama, pin, awal));
        cout << "Akun berhasil dibuat!" << endl;
    }

    void menuTransaksi() {
        string no, pin;
        cout << "\n--- LOGIN TRANSAKSI ---" << endl;
        cout << "Masukkan No Akun: "; cin >> no;
        
        for (auto& a : database) {
            if (a->getNoAkun() == no) {
                cout << "Masukkan PIN: "; cin >> pin;
                if (a->verifikasiPin(pin)) {
                    prosesAksi(a.get());
                } else {
                    cout << "PIN SALAH!" << endl;
                }
                return;
            }
        }
        cout << "Akun tidak ditemukan." << endl;
    }

    void prosesAksi(Akun* akun) {
        int subPilihan;
        do {
            cout << "\nSelamat Datang, Saldo: Rp" << akun->getSaldo() << endl;
            cout << "1. Tarik Tunai\n2. Setor Tunai\n3. Cetak Mutasi (Riwayat)\n4. Logout\nPilihan: ";
            cin >> subPilihan;

            if (subPilihan == 1) {
                double nominal;
                cout << "Nominal Tarik: "; cin >> nominal;
                akun->tarik(nominal);
            } else if (subPilihan == 2) {
                double nominal;
                cout << "Nominal Setor: "; cin >> nominal;
                akun->setor(nominal);
            } else if (subPilihan == 3) {
                akun->tampilkanRiwayat();
            }
        } while (subPilihan != 4);
    }
};

int main() {
    BankController sistem;
    int pil;

    do {
        cout << "\n===============================" << endl;
        cout << "   SISTEM BANK DIGITAL C++     " << endl;
        cout << "===============================" << endl;
        cout << "1. Registrasi Nasabah\n2. Transaksi (Login)\n3. Keluar\n";
        cout << "Pilihan: "; cin >> pil;

        if (pil == 1) sistem.registrasiNasabah();
        else if (pil == 2) sistem.menuTransaksi();

    } while (pil != 3);

    cout << "Terima kasih telah menggunakan layanan kami." << endl;
    return 0;
}