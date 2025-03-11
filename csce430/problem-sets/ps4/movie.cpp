#include <iostream>
#include <vector>
#include <map>

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
    int t;
    cin >> t;
    while(t--) {
        int m,r,x,ft_location;
        cin >> m >> r;
        
        // vector<int> ft_locations(m + 1);
        map<int,int> ft_locations;
        for(int i = 1; i < m + 1; i++) {
            ft_locations.emplace(i,m - i + 1);
        }
        
        ft fen_tree(m + r);
        for(int i = 1; i < m + 1; i++) {
            fen_tree.incr(i, 1);
        }


        for(int i = 0; i < r; i++) {
            cin >> x;
            // cout << "processing request " << i + 1 << " for " << x << endl;
            
            ft_location = ft_locations.at(x);
            
            // cout << x << " is at " << ft_location << " in the fenwick tree" << endl;
            
            cout << fen_tree.rsq(ft_location + 1, m + r) << " ";
            
            fen_tree.incr(ft_location,-1);

            fen_tree.incr(m + i + 1, 1);

            ft_locations.at(x) = m + i + 1;
        }

        cout << endl;
    }

    return 0;
}