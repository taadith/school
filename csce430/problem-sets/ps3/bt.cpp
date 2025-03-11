#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


unordered_map<string,int> um;
vector<int> sizes;
vector<int> parents;

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
    sizes[a] += sizes[b];
}

int main() {
    parents.resize(200000 + 1);
    sizes.resize(200000 + 1);
    for(int i = 1; i < 200001; i++) {
        parents[i] = i;
        sizes[i] = 1;
    }

    int n;
    cin >> n;
    string a,b;
    int x = 1;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        if (um.count(a) == 0) {
            um.emplace(a,x);
            x++;
        }
        if (um.count(b) == 0) {
            um.emplace(b,x);
            x++;
        }
        merge(um.at(a),um.at(b));
        cout << sizes[parents[um.at(a)]] << endl;
    }

}