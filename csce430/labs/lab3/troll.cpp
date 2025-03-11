#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int b;
    float k,g;
    cin >> b >> k >> g;

    b--;
    cout << ceil(b / floor(k/g)) << endl;

    return 0;
}