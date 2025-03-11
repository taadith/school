#include <vector>
#include <iostream>

using namespace std;

//union find implementation:
vector<int> elements;
vector<int> parents;
// vector<int> maxsize;
vector<int> counts;
vector<int> sums;

int find(int x) {
    int p = elements[x];
    
    while(p != parents[p])
        p = parents[p];
    
    elements[x] = p;
    return p;
}

void merge(int x, int y) {
    int a,b;
    a = find(x);
    b = find(y);
    
    if (a == b)
        return;
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
    // elements[x] = b;
    parents[a] = b;
    counts[b] += counts[a];
    sums[b] += sums[a];
}

void move(int x, int y) {
    int a = find(x);
    int b = find(y);

    if (a == b)
        return;
    
    elements[x] = b;

    sums[a] -= x;
    sums[b] += x;

    counts[a] -= 1;
    counts[b] += 1;
}

int main() {
    int n,m,op,x,y;
    cin >> n >> m;
    
    elements.resize(n + 1);
    parents.resize(n + 1);
    counts.resize(n + 1, 1);
    sums.resize(n + 1);
    for(int i = 1; i < n + 1; i++) {
        elements[i] = i;
        parents[i] = i;
        sums[i] = i;
    }

    while (m--) {
        cin >> op;

        // union
        if (op == 1) {
            cin >> x >> y;
            merge(x,y);
        }
        // move p to set q
        else if (op == 2) {
            cin >> x >> y;
            move(x,y);
        }
        // print
        else if (op == 3) {
            cin >> x;
            cout << counts[find(x)] << " " << sums[find(x)] << endl;
        }
    }

    return 0;
}