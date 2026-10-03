#include <iostream>
using namespace std;

void pointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void reference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:\n";
    cout << a << " " << b << " " << c << endl;

    pointer(&a, &b, &c);

    cout << "Setelah pointer:\n";
    cout << a << " " << b << " " << c << endl;

    reference(a, b, c);

    cout << "Setelah reference:\n";
    cout << a << " " << b << " " << c << endl;

    return 0;
}