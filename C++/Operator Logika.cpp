#include <iostream>
using namespace std;
int main() {
    bool output;

    //== (perbandingan)
    output = 2 == 2; //true
    cout << output << endl;
    output =  2 == 4; // false
    cout << output << endl;

    //not = Kebalikan
    output = not(2 == 4); //true
    cout << output << endl;
    output = !(2 == 2); //false
    cout << output << endl;

    //and (perkalian)
    //Dia bernilai true jika kedua nilai bernilai true
    // 1 and 1 = 1 - else 0
    output = (2 < 4) and (2 > 1); //1 and 1 = 1 (true)
    cout << output << endl;
    output = (2 < 4) and (2 > 1); //1 and 0 = 0 (false)
    cout << output << endl;
    output = (2 > 4) and (2 > 1); //0 and 1 = 0 (false)
    cout << output << endl;
    output = (2 > 4) and (2 > 1); //0 and 0 = 0 (false)
    cout << output << endl;

    //or (penjumlahan)
    //Dia bernilai false jika kedua nilai bernilai false
    output = (2 < 4) or (2 > 1); //1 or 1 = 1 (true
    cout << output << endl;
    output = (2 < 4) or (2 > 1); //1 or 0 = 1 (true)
    cout << output << endl;
    output = (2 > 4) or (2 > 1); //0 or 1 = 1 (true)
    cout << output << endl;
    output = (2 > 4) or (2 > 1); //0 or 0 = 0 (false)
    cout << output << endl;
}