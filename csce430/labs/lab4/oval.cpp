#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> players(n);
    for(int i = 0; i < n; i++)
        players[i] = i;
    
    // vector<pair<int,int>> vp(k);
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < k; i++) {
        // cin >> vp[i].second;
        // cin >> vp[i].first;
        pair<int,int> p;
        cin >> p.second;
        cin >> p.first;
        pq.push(p);
    }

    // sort(vp.begin(),vp.end());

    for(int i = k - 1; i > -1; i--) {
        int leg = pq.top().second;
        // players[vp[i].second] = vp[i].second + 1;
        // players[vp[i].second + 1] = vp[i].second;
        int temp = players[leg];
        players[leg] = players[leg  + 1];
        players[leg + 1] = temp;
        pq.pop();
    }

    for(int i = 0; i < n; i++)
        cout << players[i] << " ";
    cout << endl;

    return 0;
}