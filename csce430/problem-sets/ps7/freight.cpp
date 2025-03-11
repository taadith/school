#include <iostream>

using namespace std;

#define rep(i,a,b) for(int i=a; i<b;  ++i)
#define MAXW 10000
int n, w, l;
int freights[MAXW];

bool possible(int k) {
    int l = 0, r = k-1;
    int i = 0;
    int count = 0;
    while (l <= r) {
        ++count;
        if (i == w)
            break;
        if (freights[i] > r) {
            l = freights[i];
        } else {
            while(++i < w && freights[i] <= r) {
                ++i;
                if (i < w && freights[i] <= r)
                    continue;
                else
                    break;
            }
            l = r + 1;
        }
        r = min(l + k-1, n-1);
    }
    return count <= l;
}

int main() {
    int t, n, w, l; 
    cin >> t;
    while (t--) {
        cin >> n >> w >> l;

        for(int i = 0; i < w; i++) {
            cin >> freights[i]; 
            freights[i]--; 
        }
        
        int l = 1, r = n;
        while (l < r) {
            int m = (l + r) >> 1;
            if (possible(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}