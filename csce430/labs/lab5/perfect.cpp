#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    while(n != 0) {
        // bool found = false;

        if (n < 0) {
            n = -n;
            for(int i = 31; i >= 1; i-=2) {
                double v = pow(n,1.0/double(i));
                long long p = round(v);
                if (pow(p,i) == n) {
                    cout << i << endl;
                    break;
                }
            }
        }
        else {
            for(int i = 32; i >= 1; i--) {
                double v = pow(n,1.0/double(i));
                long long p = round(v);
                if (pow(p,i) == n) {
                    cout << i << endl;
                    break;
                }
            }
        }
            

        cin >> n;
    }

    return 0;
}