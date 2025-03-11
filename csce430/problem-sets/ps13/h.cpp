#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int h;
    while(cin >> h && h != 0) {
        cout << h << " ";
        
        vector<int> h_num_diff_prime_factors(h + 1, 0);
        vector<int> h_primes;
        for(int i = 5; i <= h; i += 4) {
            if (h_num_diff_prime_factors[i] == 0 && i % 4 == 1) {
                h_primes.push_back(i);
                for(int j = i; j <= h; j += 4)
                    h_num_diff_prime_factors[i]++;
            }
        }
        
        vector<int> h_num_occurences(h + 1, 0);
        for(unsigned int i = 0; i < h_primes.size(); i++) {
            for(unsigned int j = i; j < h_primes.size(); j++) {
                int num = h_primes[i] * h_primes[j];
                // larger than h, we can break!
                if (num > h)
                    break;
                // not a h-number
                else if (num % 4 != 1)
                    continue;
                // otherwise, add it as an occurence of two factors
                h_num_occurences[num]++;
            }
            if (h_primes[i] > h)
                break;
        }

        int sum = 0;
        for(int i = 0; i < h + 1; i++) {
            if (h_num_occurences[i] == 1)
                sum += h_num_occurences[i];
        }
            
        cout << sum << endl;
    }

    return 0;
}