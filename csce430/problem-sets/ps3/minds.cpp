#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//union find implementation:
vector<int> parents;
// vector<int> maxsize;
vector<int> totals;

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
    totals[a] += totals[b];
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
    int ok_recipes = 0;
    parents.resize(500001);
    totals.resize(500001);

    for(int i = 0; i < 500001; i++) {
        parents[i] = i;
        totals[i] = 1;
    }
    
    int n,m,parent,x;
    
    cin >> n;
    while(n--) {
        cin >> m;
        
        unordered_map<int,int> um;
        while(m--) {
            cin >> x;
            
            parent = find(x);
            if (um.count(parent) == 0)
                um.emplace(parent,1);
            else
                um.at(parent)++;
        }
        
        unordered_map<int,int>::iterator umit;
        bool valid_recipe = true;
        for(umit = um.begin(); umit != um.end(); umit++) {
            if (umit -> second != totals[umit -> first]) {
                valid_recipe = false;
                break;
            }
        }

        if (valid_recipe) {
            for(umit = um.begin(); umit != um.end(); umit++)
                merge(um.begin() -> first,umit -> first);
            ok_recipes++;
        }
    }

    cout << ok_recipes << endl;
    
    return 0;
}