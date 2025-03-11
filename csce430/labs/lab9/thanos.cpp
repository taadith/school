#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    long long killed = 0;
    for(int i = n - 2; i > -1; i--) {
        if (v[i] < v[i + 1])
            continue;
        else if (v[i] == v[i + 1]) {
            v[i]--;
            if (v[i] < 0) {
                killed = 1;
                break;
            }
            killed++;
        }
        else if (v[i] > v[i + 1]) {
            killed += v[i] - v[i + 1] + 1;
            v[i] = v[i + 1] - 1;
            if (v[i] < 0) {
                killed = 1;
                break;
            }
        }
    }

    cout << killed << endl;

    return 0;
}