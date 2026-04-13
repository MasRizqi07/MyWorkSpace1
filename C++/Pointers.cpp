#include <iostream>
using namespace std;

int main() {
    int y;
    int x = 87;
    int *px;

    px = &x;
    y = *px;

    cout << "Alamat x = " << &x << endl;
    cout << "Isi px = " << px << endl;
    cout << "Isi x = " << x << endl;
    cout << "*px = " << *px << endl;
    cout << "Isi y = " << y << endl;

    return 0;
}