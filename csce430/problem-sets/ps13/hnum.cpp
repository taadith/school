#include <vector>
#include <iostream>

using namespace std;

int main() {

    int h;
    while(cin >> h) {
        if (h == 0)
            break;
        
        vector<int> num_diff_prime_factors(h + 1, 0);
        for (int i = 5; i <= h; i += 4) {
            if (num_diff_prime_factors[i] == 0) {
                for (int j = i; j <= h; j += i) {
                    num_diff_prime_factors[j]++;
                }
            }
        }

        int semi_primes = 0;
        for(int i = 5; i <= h; i += 4) {
            if (num_diff_prime_factors[i] != 0)
                continue;
            for(int j = i; j <= h; j += 4) {
                if (num_diff_prime_factors[j] != 0)
                    continue;
                if (i * j > h)
                    break;
                semi_primes++;
            }
        }
            
        cout << h << " " << semi_primes << endl;
    }

    return 0;
}