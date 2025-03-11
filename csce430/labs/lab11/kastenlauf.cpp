#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

//union find implementation:
vector<int> parents;
// not necessary: vector<int> maxsize;

int find(int x) {
    if (parents[x] == x)
        return x;
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void merge(int x, int y) {
    int a,b;
    a = find(x);
    b = find(y);
    
    if (a == b)
        return;
    parents[b] = a;

    // if (maxsize[a] == maxsize[b]) {
    //     parents[b] = a;
    //     maxsize[a]++;
    // }
    // else if (maxsize[a] > maxsize[b]) {
    //     parents[b] = a;
    // }
    // else if (maxsize[a] < maxsize[b]) {
    //     parents[a] = b;
    // }
}


int dist(pair<int, int> &coords1, pair<int, int> &coords2) {
    return abs(coords1.first - coords2.first) + abs(coords1.second - coords2.second);
}

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> locations(n + 2);
        parents.assign(n + 2, 0);
        for(int i = 0; i < n + 2; i++) {
            cin >> locations[i].first >> locations[i].second;
            parents[i] = i;
        }
        for(int i = 0; i < n + 2; i++) {
            for(int j = i + 1; j < n + 2; j++) {
                if (dist(locations[i], locations[j]) <= 1000)
                    merge(i, j);
            }
        }

        if (find(0) == find(n + 1))
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
    }

    return 0;
}