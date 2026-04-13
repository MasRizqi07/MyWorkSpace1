#include <iostream>
using namespace std;
int main() {
    int y, x = 87, *px;
    px = &x;
    y = *px;

    cout << "Alamat x: " << &x << endl;
    cout << "Isi px: " << px << endl;
    cout << "Isi x: " << x << endl;
    cout << "*px: " << *px << endl;
    cout << "isi y: " << y << endl;
    return 0;
}