#include <iostream>

using namespace std;

int main() {
    for(int i = 0; i < 8; i++)
        cout << "value " << i << ": a - " << (i ^ (1 << 0)) << ", b - " << (i ^ (1 << 1)) << ", c - " << (i ^ (1 << 2)) << endl;
}