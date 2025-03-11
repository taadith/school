#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long d;
    cin >> d;
	bool impossible = true;

    for(long x = 0; x <= 200000; x++) {
        long y_sq = (x * x) + d;
        long y = sqrt(y_sq);

        if (y * y == y_sq) {
            cout << x << " " << y << endl;
            impossible = false;
            break;
        }
    }

    if (impossible)
        cout << "impossible" << endl;
}
