#include <iostream>
#include <vector>

using namespace std;

// default value of memo: -1
// infinity -> 301 (max value of S + 1)

long long dp(vector<vector<vector<int>>> &memo, vector<pair<int,int>> &coin_values, int &m, int &s, int a, int b, int c) {
    // if (a == 0 && b == 0 && c == 0)
    //     return 0;
    if (c > m)
        return 301;
    if ((a * a) + (b * b) == (s * s))
        return 0;
    // if ((a != 0 || b != 0) && c == 0)
    //     return 301;
    if ((a * a) + (b * b) > (s * s))
        return 301;

    if (memo[a][b][c] != -1)
        return memo[a][b][c];
    
    if (coin_values[c].first == 0 && coin_values[c].second == 0)
        memo[a][b][c] = dp(memo, coin_values, m, s, a, b, c + 1);
    else
        memo[a][b][c] = min(dp(memo, coin_values, m, s, a, b, c + 1),dp(memo, coin_values, m, s, a + coin_values[c].first, b + coin_values[c].second, c) + 1);
    return memo[a][b][c];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m,s;
        cin >> m >> s;
        vector<vector<vector<int>>> memo(s + 1, vector<vector<int>> (s + 1, vector<int> (m + 1, -1)));
        vector<pair<int,int>> coin_values(m + 1);
        for(int i = 1; i < m + 1; i++)
            cin >> coin_values[i].first >> coin_values[i].second;
        
        memo[0][0][1] = dp(memo, coin_values, m, s, 0, 0, 1);
        if (memo[0][0][1] == 301)
            cout << "not possible" << endl;
        else
            cout << memo[0][0][1] << endl;
    }

    return 0;
}