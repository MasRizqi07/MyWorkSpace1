#include <iostream>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, fib;

    cout << "Masukkan jumlah deret Fibonacci: ";
    cin >> n;

    cout << "Deret Fibonacci: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        fib = a + b;
        a = b;
        b = fib;
    }

    return 0;
}
