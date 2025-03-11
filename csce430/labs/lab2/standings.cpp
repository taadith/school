#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    long long t,n,p;
    string team;
    cin >> t;

    for(long long i = 0; i < t; i++) {
        vector<long long> v;
        v.push_back(-1);
        cin >> n;
        for(long long j = 0; j < n; j++) {
            cin >> team >> p;
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        long long bad = 0;
        for(long long j = 1; j < n + 1; j++) {
            bad += abs(v[j]-j);
        }
        cout << bad << endl;
    }

    return 0;
}