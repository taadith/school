#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //fast input & output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    long l, n;
    cin >> t;

    long long current_ant;
    long long distance_to_end;
    
    for(int i = 0; i < t; i++) {
        cin >> l >> n;
        if (n == 0) {
            cout << 0 << " " << 0 << endl;
            continue;
        }
        vector<long long> min_dist;
        vector<long long> max_dist;
        for(int j = 0; j < n; j++) {
            cin >> current_ant;
            distance_to_end = l - current_ant;
            if (current_ant > distance_to_end) {
                max_dist.push_back(current_ant);
                min_dist.push_back(distance_to_end);
            }
            else {
                max_dist.push_back(distance_to_end);
                min_dist.push_back(current_ant);
            }
        }

        sort(min_dist.begin(),min_dist.end());
        sort(max_dist.begin(),max_dist.end());

        cout << min_dist[n-1] << " " << max_dist[n - 1] << endl;
    }

    return 0;
}