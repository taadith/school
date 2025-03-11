#include <iostream>
#include <vector>

using namespace std;

inline int LSOne(const int x) {
    return x & (-x);
}

class ft {
    vector<long long> v;
    int n;

    public:
        ft(int x) {
            n = x;
            v.resize(x + 1,0);
        }

        void incr(int elem, long long val) {
            while(elem <= n) {
                v[elem] += val;
                elem = elem + LSOne(elem);
            }
        }

        long long rsq(int elem) {
            long long summation = 0;
            while(elem > 0) {
                summation += v[elem];
                elem -= LSOne(elem);
            }
            return summation;
        }

        long long rsq(int i, int j) {
            return rsq(j) - rsq(i - 1);
        }

        void flip(int elem) {
            if (rsq(elem,elem) == 0)
                incr(elem,1);
            else
                incr(elem,-1);
        }
};

int main() {
    int n,k;
    cin >> n >> k;
    ft fen_tree(n);
    
    int a,b;
    char c;
    while(k--) {
        cin >> c;
        if (c == 'F') {
            cin >> a;
            fen_tree.flip(a);
        }
        else if (c == 'C') {
            cin >> a >> b;
            cout << fen_tree.rsq(a,b) << endl;
        }
    }
    
    return 0;
}