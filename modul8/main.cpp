
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout << "=== CIRCULAR QUEUE ===" << endl;
    cout << "H - T | Queue Info" << endl;

    enqueue(Q, 5);
    enqueue(Q, 2);
    enqueue(Q, 7);
    enqueue(Q, 4);
    enqueue(Q, 8);

    printInfo(Q);

    cout << "\nDequeue dua kali:" << endl;
    dequeue(Q);
    dequeue(Q);
    printInfo(Q);

    cout << "\nEnqueue 10 dan 20:" << endl;
    enqueue(Q, 10);
    printInfo(Q);

    enqueue(Q, 20);
    printInfo(Q);

    return 0;
}
