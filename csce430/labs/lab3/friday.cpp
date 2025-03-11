#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n,x;
    cin >> n;
    vector<int> idx(7, 0);
    for(int i = 1; i < n + 1; i++) {
        cin >> x;
        // cout << "read in " << x << ", ";
        if (idx[x] == 0) {
            idx[x] = i;
            // cout << "saw it for the first time at " << i << endl;
        }
        else if (idx[x] >= 1) {
            idx[x] = -1;
            // cout << "saw it again at " << i << endl;
        }
        else if (idx[x] == -1) {
            // cout << "have seen it to many times (at " << i << ")" << endl;
            continue;
        }
            
    }
    for(int i = 6; i > 0; i--) {
        if (idx[i] >= 1) {
            cout << idx[i] << endl;
            return 0;
        }
    }
    
    cout << "none" << endl;
    return 0;
}