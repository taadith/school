#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

const int INF = 500001;

// dp
int longest_increasing_subsequence(vector<int> &v) {
    int n = v.size();
    
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    for(int i = 1; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i]);
    
    return dp[n - 1];
}

// dp and binary search
int longest_increasing_subsequence2(vector<int> &v) {
    int n = v.size();
    
    vector<int> dp(n + 1, INF);
    dp[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (dp[j - 1] < v[i] && v[i] < dp[j])
            dp[j] = v[i];
    }

    int lis = 0;
    for (int i = 0; i <= n; i++) {
        if (dp[i] < INF)
            lis = i;
    }
    return lis;
}

int main() {
    int n;
    cin >> n;

    vector<int> signal_mapping(n);
    for(int i = 0; i < n; i++)
        cin >> signal_mapping[i];
        
	cout << longest_increasing_subsequence2(signal_mapping) << endl;

	return 0;
}
