#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//union find implementation:
vector<int> parents;
vector<int> maxsize;

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

    parents[b] = a;
    
    // if (a == b)
    //     return;
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

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<bool>> painting(n + 1, vector<bool>(m + 1, false));

    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x2 >> y2 >> x2 >> y2;

        
    }

    return 0;
}