#include <iostream>
#include <vector>
// #include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> lrange, pair<int,int> rrange) {
    //if the end is the same, we want the biggest range, so return the one that has the smallest beginning
    if(lrange.second == rrange.second)
        return lrange.first < rrange.first;
    // otherwise unequal, so we just want the smallest end
    return lrange.second < rrange.second;
}

int main() {
    int n;
    vector<pair<int,int>> vpii;

    cin >> n;
    for(int i = 0; i < n; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        vpii.push_back(p);
    }
    sort(vpii.begin(),vpii.end(),cmp);

    int rooms = 1;
    // int l = vpii[0].first;
    // want to track the greatest end
    int u = vpii[0].second;
    
    // int idx = 0;
    for(unsigned long i = 1; i < vpii.size(); i++) {
        // cout << "comparing " << vpii[i].first << " with " << vpii[i - 1].first << "-" << vpii[i - 1].second << endl;
        // if (vpii[i].first >= l && vpii[i].first <= u)
        //     continue;
        // else
        //     rooms++;

        if (vpii[i].first > u) {
            u = vpii[i].second;
            rooms++;
        }
    }

    cout << rooms << endl;
    return 0;
}