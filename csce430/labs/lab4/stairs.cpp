#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int min_steps,r,o;
    cin >> min_steps >> r >> o;
    float delta1 = min_steps - r;
    float delta2 = o - r;
    if (r > o && min_steps <= r)
        cout << 2 * r << endl;
    else if (r > o && min_steps > r)
        cout << (2 * r) + (2 * ceil(delta1/2)) << endl;
    else if (o > r && min_steps <= o)
        cout << 2 * o << endl;
    else if (o > r && min_steps > o)
        cout << (2 * o) + (2 * ceil(delta2/2)) << endl;
    else if (r == o && min_steps <= r)
        cout << 2 * r << endl;
    else if (r == o && min_steps > r)
        cout << (2 * r) + (2 * ceil(delta1/2)) << endl;
    return 0;
}