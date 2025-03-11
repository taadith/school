#include <iostream>

using namespace std;

// code taken from textbook: ax + by = gcd(a, b)
long long extended_euclid(long long a, long long b, long long &x, long long &y) {     // grab x and y by reference...
    long long xx = 0;
    y = 0;
    long long yy = 1;
    x = 1;
    
    while(b) {
        long long q = a / b;

        long long t = b;
        b = a % b;
        a = t;

        t = xx;
        xx = x - (q * xx);
        x = t;

        t = yy;
        yy = y - (q * yy);
        y = t;
    }

    // equivalent to gcd(a, b)
    return a;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long k,c,x,y;
        cin >> k >> c;

        // kx + cy = gcd(k, c)
        long long ee = extended_euclid(k, c, x, y);

        // x + y = gcd(1, 1)
        if (k == 1 && c == 1)
            cout << 2 << endl;
        // kx + y = gcd(k, 1)
        else if (k > 1 && c == 1)
            cout << k + 1 << endl;
        // x + cy = gcd(1, c)
        else if (k == 1 && c > 1)
            cout << 1 << endl;
        // if the gcd isn't equal to 1,
        // then kx + 1 with c candies in each bag is NOT POSSIBLE
        else if (ee != 1)
            cout << "IMPOSSIBLE" << endl;
        // otherwise, provide smallest non-negative solution for x
        else
            cout << (y + k) % k << endl;
        
    }

    return 0;
}