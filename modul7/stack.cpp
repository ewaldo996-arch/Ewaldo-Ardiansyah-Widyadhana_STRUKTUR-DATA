
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top++;
        S.info[S.top - 1] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        infotype x = S.info[S.top - 1];
        S.top--;
        return x;
    }

    cout << "Stack kosong!" << endl;
    return -1;
}

void printInfo(Stack S) {
    if (S.top == 0) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Isi Stack: ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top - 1;

    while (i < j) {
        infotype temp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = temp;

        i++;
        j--;
    }
}
void pushAscending(Stack &S, infotype x) {
    if (S.top >= 20) {
        cout << "Stack penuh!" << endl;
        return;
    }

    int i = S.top - 1;

    while (i >= 0 && S.info[i] < x) {
        S.info[i + 1] = S.info[i];
        i--;
    }

    S.info[i + 1] = x;
    S.top++;
}
void getInputStream(Stack &S) {
    char input;

    cout << "Masukkan angka (tekan Enter untuk selesai): ";

    while (cin.get(input) && input != '\n') {
        if (input >= '0' && input <= '9') {
            push(S, input - '0');
        }
    }
}
