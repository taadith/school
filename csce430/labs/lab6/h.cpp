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
    
    sort(v.begin(), v.end());
    
    int h = 0;
    for(int i = n - 1; i > -1; i--) {
        if (v[i] >= h + 1)
            h++;
        else
            break;
    }

    cout << h << endl;

    return 0;
}