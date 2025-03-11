#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    size_t ones = 0;
    size_t twos = 0;
    size_t swaps = 0;

    cin >> line;
    for(size_t i = 0; i < line.length(); i++) {
        if (line[i] == '0')
            swaps += ones + twos;
        else if (line[i] == '1') {
            ones++;
            swaps += twos;
        }
        else if (line[i] == '2')
            twos++;
    }
    cout << swaps << endl;
    return 0;
}