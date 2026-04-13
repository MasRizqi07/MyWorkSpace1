#include <iostream>
using namespace std;
int main() {
    int jml_arr;
    int angka[] = {87, 90, 85, 80, 95, 99, 77};
    jml_arr = sizeof(angka) / sizeof(*angka);

    for (int a = 0; a < jml_arr; a++) {
        cout << "Nilai ke- " << angka[a] << endl;
    }
    return 0;
}