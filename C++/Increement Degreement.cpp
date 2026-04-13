#include <iostream>
using namespace std;
int main() {
    // Increment Dan Degrement
    int x, y;
    // Increment
    // Post Increment
    x = 1;
    cout << x++ << endl;
    cout << x++ << endl;
    cout << x << endl;
    cout << "----------------- " << endl;

    //Pre Increment
    y = 1;
    cout << ++y << endl;
    cout << ++y << endl;
    cout << y << endl;
    cout << "----------------- " << endl;

    // Degrement
    int a, b;
    // Post Degrement
    a = 5;
    cout << a-- << endl;
    cout << a-- << endl;
    cout << a << endl;
    cout << "----------------- " << endl;
    // Pre Degrement
    b = 10;
    cout << --b << endl;
    cout << --b << endl;
    cout << b << endl;

    return 0;
}