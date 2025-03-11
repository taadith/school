#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int bombs = 0;

    
    while (true) {
        n -= 3;
        bombs++;
        if (n <= 0)
            break;
        n += 2;
    }
    cout << bombs << endl;
    return 0;
}