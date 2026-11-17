#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "Balik Stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}