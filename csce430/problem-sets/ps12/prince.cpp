#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// C++ code for the above approach:
#include <bits/stdc++.h>
using namespace std;

int levenshtein_dist(const vector<int>& first_seq, const vector<int>& second_seq, unsigned int m, unsigned int n) {
	// first_seq is empty
	if (m == 0)
		return n;
    
	// second_seq is empty
	if (n == 0)
		return m;

    // values are equal
	if (first_seq[m - 1] == second_seq[n - 1])
		return 1 + levenshtein_dist(first_seq, second_seq, m - 1, n - 1);
    else {
        return min(
            // insert
            levenshtein_dist(first_seq, second_seq, m, n - 1),
            min(
                // remove
                levenshtein_dist(first_seq, second_seq, m - 1, n),
                // replace
                (int)1e9 + levenshtein_dist(first_seq, second_seq, m - 1, n - 1)
            )
        );
    }
}


int main() {
    int t, n, p, q;
    cin >> t;
    for(int testcase = 1; testcase < t + 1; testcase++) {
        cin >> n >> p >> q;
        
        p++;
        q++;

        vector<int> first_seq(p);
        for(int i = 0; i < p; i++)
            cin >> first_seq[i];
        
        vector<int> second_seq(q);
        for(int i = 0; i < q; i++)
            cin >> second_seq[i];

        vector<vector<int>> dp(p + 1, vector<int>(q + 1, -1));
        
        cout << "Case " << testcase << ": " << levenshtein_dist(first_seq, second_seq, first_seq.size(), second_seq.size()) << endl;
    }
    return 0;
}