#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    if (y % 2 != 0)
        cout << "impossible" << endl;
    else
        cout << "possible" << endl;
}