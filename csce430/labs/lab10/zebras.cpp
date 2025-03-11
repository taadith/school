#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    unsigned long long binary_count = 0;

    for(int i = n; i > 0; i--) {
        string x;
        cin >> x;
        if (x == "Z")
            binary_count += (((unsigned long long) 1) << (i - 1));
    }

    unsigned long long max_binary_value = (((unsigned long long) 1) << n) - 1;

    cout << max_binary_value - binary_count << endl;

}