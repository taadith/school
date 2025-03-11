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
};

int main() {
    int n;
    cin >> n;

    ft fen_tree(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fen_tree.incr(x, 1);
    }

    return 0;
}