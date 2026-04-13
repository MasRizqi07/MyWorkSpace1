#include <iostream>
#include <string>

using namespace std;

const int MAX_CHAT = 50;


string username[MAX_CHAT];
string pesan[MAX_CHAT];
int jumlahChat = 0;

string sensorKata(string teks) {
    string kataKasar[] = {"jelek", "bodoh"};
    int jumlahKata = 2;

    for (int i = 0; i < jumlahKata; i++) {
        size_t posisi;
        while ((posisi = teks.find(kataKasar[i])) != string::npos) {
            teks.replace(posisi, kataKasar[i].length(), "***");
        }
    }
    return teks;
}


void tampilkanChat() {
    cout << "\n===== FORUM CHAT =====\n";
    for (int i = 0; i < jumlahChat; i++) {
        cout << i + 1 << ". " << username[i] << " : " << pesan[i] << endl;
    }
}

int main() {
    int pilih;

    do {
        cout << "Masukkan username : ";
        getline(cin, username[jumlahChat]);

        cout << "Masukkan chat : ";
        getline(cin, pesan[jumlahChat]);

        pesan[jumlahChat] = sensorKata(pesan[jumlahChat]);
        jumlahChat++;

        tampilkanChat();

        cout << "\n1. Chat lagi\n";
        cout << "2. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;
        cin.ignore();

    } while (pilih == 1);

    cout << "\nProgram selesai." << endl;
    return 0;
}
