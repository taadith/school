#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n,m,p;
    vector<long long> v;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    
    long long wasted = 0;
    for(int i = 0; i < m; i++) {
        cin >> p;
        for(int j = 0; j < v.size(); j++) {
            if(p <= v[j]) {
                wasted += v[j] - p;
                break;
            }
        }
    }
    
    cout << wasted;
    
    return 0;
}