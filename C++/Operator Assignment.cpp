#include <iostream>
using namespace std;
int main() {
    int bil = 10;
    cout << "Nilai awal bil: " << bil << endl;
    // Operator assignment
    // Penjumlahan dan penugasan
    bil += 5; // bil = bil + 5
    cout << "Setelah += 5, bil: " << bil << endl;
    // Pengurangan dan penugasan
    bil -= 3; // bil = bil - 3
    cout << "Setelah -= 3, bil: " << bil << endl;
    // Perkalian dan penugasan
    bil *= 2; // bil = bil * 2
    cout << "Setelah *= 2, bil: " << bil << endl;
    // Pembagian dan penugasan
    bil /= 4; // bil = bil / 4
    cout << "Setelah /= 4, bil: " << bil << endl;
    // Modulus dan penugasan
    bil %= 3; // bil = bil % 3
    cout << "Setelah %= 3, bil: " << bil << endl;
    return 0;
}