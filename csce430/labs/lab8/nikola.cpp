#include <iostream>
#include <vector>

using namespace std;

// define infinity to be 500 * 1000 = 500,000

int dp(vector<vector<int>> &memo, vector<int> &costs, int &n, int a, int b) {
    if (a == 1 && b == 0)
        return 0;
    if (a > n || a <= 0 || b < 0 || b >= n)
        return 500000;
    if (a > 1 && b == 0)
        return 500000;
    
    // cout << "at a: " << a << ",b: " << b << endl;
    
    if (memo[a][b] != -1)
        return memo[a][b];
    else {
        memo[a][b] = costs[a] + min(dp(memo, costs, n, a - b, b - 1), dp(memo, costs, n, a + b, b));
        return memo[a][b];
    }
}

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> costs(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> costs[i];
    
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
    memo[1][0] = 0;

    int resulting_cost = dp(memo, costs, n, n, 0);
    for(int i = 1; i < n; i++)
        resulting_cost = min(dp(memo, costs, n, n, i), resulting_cost);

    cout << resulting_cost << endl;

    return 0;
}