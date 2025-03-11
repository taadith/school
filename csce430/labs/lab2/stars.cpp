#include <iostream>

using namespace std;

int main() {
    int s, x = 2, y = 1;
    cin >> s;
    cout << s <<":\n";
    while(x + y <= s) {
        if(s % (x + y) == 0 || (s - x) % (x + y) == 0)
            cout << x << "," << y << "\n";
        if (x == y)
            ++x;
        else
            ++y;
    }
    return 0;
}