#include <iostream>
#include <iomanip>
using namespace std;

struct Film {
    int ID;
    char Judul[50];
    char Genre[30];
    int harga_tiket;
};

struct Transaksi {
    int ID_transaksi;
    int jumlah_tiket;
};

struct DataFilm {
    Film film;
    Transaksi transaksi;
};


void inputDataFilm(DataFilm daftar_film[], int jumlah_film) {
    for (int i = 0; i < jumlah_film; i++) {
        cout << "\n=== Film ke-" << (i + 1) << " ===" << endl;
        
        cout << "ID Film\t\t: ";
        cin >> daftar_film[i].film.ID;
        
        cout << "Judul Film\t: ";
        cin.ignore();
        cin.getline(daftar_film[i].film.Judul, 50);
        
        cout << "Genre\t\t: ";
        cin.getline(daftar_film[i].film.Genre, 30);
        
        cout << "Harga Tiket\t: ";
        cin >> daftar_film[i].film.harga_tiket;
        
        cout << "\n--- Transaksi ---" << endl;
        cout << "ID Transaksi\t: ";
        cin >> daftar_film[i].transaksi.ID_transaksi;
        
        cout << "Jumlah Tiket\t: ";
        cin >> daftar_film[i].transaksi.jumlah_tiket;
    }
}


void tampilkanDataFilm(DataFilm daftar_film[], int jumlah_film) {
    cout << "\n\n" << string(80, '=') << endl;
    cout << setw(40) << "DATA FILM BIOSKOP" << endl;
    cout << string(80, '=') << "\n" << endl;
    
    for (int i = 0; i < jumlah_film; i++) {
        cout << "Film ke-" << (i + 1) << endl;
        cout << "ID Film\t\t: " << daftar_film[i].film.ID << endl;
        cout << "Judul Film\t: " << daftar_film[i].film.Judul << endl;
        cout << "Genre\t\t: " << daftar_film[i].film.Genre << endl;
        cout << "Harga Tiket\t: Rp " << daftar_film[i].film.harga_tiket << endl;
        
        cout << "\n--- Transaksi ---" << endl;
        cout << "ID Transaksi\t: " << daftar_film[i].transaksi.ID_transaksi << endl;
        cout << "Jumlah Tiket\t: " << daftar_film[i].transaksi.jumlah_tiket << endl;
        cout << "Total Pendapatan: Rp " << (daftar_film[i].film.harga_tiket * daftar_film[i].transaksi.jumlah_tiket) << endl;
        
        cout << "\n" << string(80, '-') << "\n" << endl;
    }
}


int hitungTotalPendapatan(DataFilm daftar_film[], int jumlah_film) {
    int total = 0;
    for (int i = 0; i < jumlah_film; i++) {
        total += daftar_film[i].film.harga_tiket * daftar_film[i].transaksi.jumlah_tiket;
    }
    return total;
}

int main() {
    const int JUMLAH_FILM = 2;
    DataFilm daftar_film[JUMLAH_FILM];
    
    
    inputDataFilm(daftar_film, JUMLAH_FILM);
    
    
    tampilkanDataFilm(daftar_film, JUMLAH_FILM);
    
    
    int total_pendapatan = hitungTotalPendapatan(daftar_film, JUMLAH_FILM);
    
    cout << "\n" << string(80, '=') << endl;
    cout << setw(50) << "Total Pendapatan Semua Film: Rp " << total_pendapatan << endl;
    cout << string(80, '=') << endl;
    
    return 0;
}



