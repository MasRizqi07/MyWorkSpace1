#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    string str1, str2;
    string cleaned1, cleaned2;
    
    // Input dua string
    cout << "=== ANAGRAM CHECKER ===" << endl;
    cout << "Masukkan string pertama: ";
    getline(cin, str1);
    
    cout << "Masukkan string kedua: ";
    getline(cin, str2);
    
    // Membersihkan string: hapus spasi dan ubah ke lowercase
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != ' ') {
            cleaned1 += tolower(str1[i]);
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        if (str2[i] != ' ') {
            cleaned2 += tolower(str2[i]);
        }
    }
    
    // Cek apakah panjang string sama
    if (cleaned1.length() != cleaned2.length()) {
        cout << "\n=== HASIL ===" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "String 1: " << str1 << endl;
        cout << "String 2: " << str2 << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Hasil: Bukan Anagram" << endl;
        cout << "(Panjang string berbeda)" << endl;
        cout << "-------------------------------------------" << endl;
        return 0;
    }
    
    // Sorting kedua string
    sort(cleaned1.begin(), cleaned1.end());
    sort(cleaned2.begin(), cleaned2.end());
    
    // Bandingkan kedua string setelah di-sort
    bool isAnagram = (cleaned1 == cleaned2);
    
    // Output hasil
    cout << "\n=== HASIL ===" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Setelah dibersihkan:" << endl;
    cout << "String 1: " << cleaned1 << " (sebelum sort)" << endl;
    cout << "String 2: " << cleaned2 << " (sebelum sort)" << endl;
    cout << "-------------------------------------------" << endl;
    
    // Untuk menampilkan string yang sudah di-sort
    string sorted1 = cleaned1;
    string sorted2 = cleaned2;
    
    cout << "Setelah di-sort:" << endl;
    cout << "String 1: " << sorted1 << endl;
    cout << "String 2: " << sorted2 << endl;
    cout << "-------------------------------------------" << endl;
    
    if (isAnagram) {
        cout << "Hasil: Anagram" << endl;
    } else {
        cout << "Hasil: Bukan Anagram" << endl;
    }
    
    cout << "-------------------------------------------" << endl;
    
    return 0;
}