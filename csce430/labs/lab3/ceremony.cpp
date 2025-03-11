#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(),v.end());

    long long minimum = n;

    for(int i = 0; i < n; i++) {
        long long temp_clear = v[i] + (n - i - 1);
        if (minimum > temp_clear)
            minimum = temp_clear;
    }
    cout << minimum << endl;

    return 0;
}