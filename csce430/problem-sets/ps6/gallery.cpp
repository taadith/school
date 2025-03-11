#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// default value for memo is -1
// infinity = 100,000 bc max aesthetic value for a gallery can be 20,000 (100 * 200)

long long dp(vector<vector<vector<long long>>> &memo, vector<vector<int>> &gallery, int n, bool on_right, int k) {
    // cout << "DP Call - " << "Row: " << n << " ,Column: " << (int) on_right << " , Rooms Left: " << k << endl;
    // base cases:
    if (k == 0)
        return 0;
    if (n < 0)
        return 100000;
    // cout << "Checking memo..." << endl;
    if (memo[k][n][on_right] != -1)
        return memo[k][n][on_right];
    
    // cout << "... Not found in memo" << endl;
    long long current_room_value = gallery[n][on_right];
    memo[k][n][on_right] = min(
        current_room_value + dp(memo, gallery, n - 1, on_right, k - 1), // closing current room
        min(                                                            // keeping current room
            dp(memo, gallery, n - 1, on_right, k),                          
            dp(memo, gallery, n - 1, !on_right, k)
        )
    );

    return memo[k][n][on_right];
}

int main() {
    int n,k;
    long long max_val = 0;

    cin >> n >> k;
    vector<vector<int>> gallery(n,vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> gallery[i][0] >> gallery[i][1];
        max_val += gallery[i][0] + gallery[i][1];
    }
    
    vector<vector<vector<long long>>> memo(k + 1, vector<vector<long long>>(n,vector<long long>(2, -1)));

    max_val -= min(dp(memo, gallery, n - 1, false, k), dp(memo, gallery, n - 1, true, k));

    cout << max_val << endl;

    return 0;
}