#include <vector>
#include <iostream>

using namespace std;

//union find implementation:
vector<int> parents;
// vector<int> maxsize;
vector<int> money_sums;

int find(int x) {
    if (parents[x] == x)
        return x;
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void merge(int x, int y) {
    // cout << "merging the sets that " << x + 1 << " and " << y + 1 << " belong to!" << endl;
    
    int a,b;
    a = find(x);
    b = find(y);

    // cout << "x's parent: " << a << endl;
    // cout << "y's parent: " << b << endl;
    
    if (a == b)
        return;
    parents[b] = a;
    money_sums[a] += money_sums[b];
    // cout << "total money owned/owed: " << money_sums[a] << endl;
    // money_sums[b] += money_sums[a];
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
    int friends, friendships;
    cin >> friends >> friendships;

    parents.resize(friends + 1);
    money_sums.resize(friends + 1);
    
    for(int i = 1; i < friends + 1; i++) {
        parents[i] = i;
        cin >> money_sums[i];
    }
        
    
    int a,b;
    for(int i = 0; i < friendships; i++) {
        cin >> a >> b;
        merge(a + 1, b + 1);
    }

    bool possible = true;
    for(int i = 1; i < friends + 1; i++) {
        int p = find(i);
        if (money_sums[p] != 0) {
            possible = false;
            break;
        }
    }
    
    if (possible)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}