#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//union find implementation:
vector<int> parents;
// vector<int> maxsize;

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
    else if (a < b)
        parents[b] = a;
    else if (a > b)
        parents[a] = b;
    
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
    // initialization:
    int n;
    cin >> n;
    parents.resize(n + 1);

    for(int i = 1; i < n + 1; i++)
        parents[i] = i;
    
    // cout << "created parents vector" << endl;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x,y;
        cin >> x >> y;
        merge(x,y);
    }

    // cout << "merged" << endl;
    bool connected = true;
    for(int i = 1; i < n + 1; i++) {
        if (find(parents[i]) != 1) {
            cout << i << endl;
            connected = false;
        }
    }

    if (connected)
        cout << "Connected" << endl;

    return 0;
}