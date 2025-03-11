#include <vector>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

// dp[a][b] is # of floors computable w/ a eggs and b drops allowed
// a,b <= 32 (yippee)

long long dp(vector<vector<long long>> &memo, long long eggs_allowed, long long drops_allowed) {
    if (eggs_allowed == 0 || drops_allowed == 0) {
        // cout << "didn't really work :(" << endl;
        return 0;
    }
        
    else if (eggs_allowed == 1) {
        // cout << "one egg remaining" << endl;
        return drops_allowed;
    }
    else if (memo[eggs_allowed][drops_allowed] != -1) {
        // cout << "found in memo" << endl;
        return memo[eggs_allowed][drops_allowed];
    }
    else {
        // cout << "oh boy here we go again" << endl;
        memo[eggs_allowed][drops_allowed] = 
              dp(memo, eggs_allowed, drops_allowed - 1) 
            + dp(memo, eggs_allowed - 1, drops_allowed - 1) 
            + 1
        ;
        return memo[eggs_allowed][drops_allowed];
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long floors, eggs;
        cin >> floors >> eggs;

        vector<vector<long long>> memo(33, vector<long long>(33, -1));
        long long min_floors_needed = LLONG_MAX;


        for(long long i = 0; i < 33; i++) {
            long long result = dp(memo, eggs, i);
            if (result >= floors)
                min_floors_needed = min(min_floors_needed, i);
        }

        if (min_floors_needed > 32)
            cout << "Impossible" << endl;
        else
            cout << min_floors_needed << endl;
    }

    return 0;
}