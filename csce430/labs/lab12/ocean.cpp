#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> fib_seq(1010, 0);
    fib_seq[0] = 1;
    fib_seq[1] = 1;
    for(int i = 2; i < 1010; i++)
        fib_seq[i] = (fib_seq[i - 1] + fib_seq[i - 2]) % ((int) 1e9 + 7);
    while(t--) {
        long n;
        cin >> n;
        cout << fib_seq[n + 1] << endl;
    }

    return 0;
}