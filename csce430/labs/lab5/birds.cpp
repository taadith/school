#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n,l,d;
    long long num = 0;
    cin >> l >> d >> n;

    // float x = d;
    if (n == 0) {
        num += ((l - 12) / d) + 1;
    }
    else {
        vector<long long> birds(n);
        for(long long i = 0; i < n; i++) {
            cin >> birds[i];
        }

        sort(birds.begin(), birds.end());

        num += (birds[0] - 6) / d;
        num += (l - birds[n - 1] - 6) / d;

        for(int i = 0; i < n - 1; i++) {
            num += (birds[i + 1] - birds[i] - d) / d;
        }
    }
    

    cout << num << endl;

}