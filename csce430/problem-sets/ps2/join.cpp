#include <iostream>
#include <vector>
#include <string>

using namespace std;

void recursive_print(vector<vector<int>> &vvi, vector<string> &vs, int &b) {
    cout << vs[b];
    for(unsigned long i = 0; i < vvi[b].size(); i++)
        recursive_print(vvi,vs,vvi[b][i]);
}

int main() {
    int n;
    cin >> n;

    vector<string> vs(n);
    for(int i = 0; i < n; i++)
        cin >> vs[i];
    
    int a,b;
    vector<vector<int>> vvi(n,vector<int>());
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        vvi[a].push_back(b);
    }

    recursive_print(vvi,vs,a);
    cout << endl;
}