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
    long long gems,queries;
    cin >> gems >> queries;
    vector<int> gem_list(gems + 1);
    vector<long long> values(7);

    // taking in values
    for(int i = 0; i < 6; i++)
        cin >> values[i + 1];

    // individual fenwick trees for each gem type
    ft gems_zero(gems);
    ft gems_one(gems);
    ft gems_two(gems);
    ft gems_three(gems);
    ft gems_four(gems);
    ft gems_five(gems);
    ft gems_six(gems);

    // vector of fenwick trees 
    vector<ft> vft;
    vft.push_back(gems_zero);
    vft.push_back(gems_one);
    vft.push_back(gems_two);
    vft.push_back(gems_three);
    vft.push_back(gems_four);
    vft.push_back(gems_five);
    vft.push_back(gems_six);
    
    char c;
    int val;
    for(int i = 0; i < gems; i++) {
        cin >> c;
        val = c - '0';
        gem_list[i + 1] = val;
        vft[val].incr(i + 1,1);
    }

    // now take in queries
    int opt;
    long long val1, val2;
    while(queries--) {
        cin >> opt;
        if (opt == 1) {
            cin >> val1 >> val2;
            // current value: gem_list[val1]
            // take current value's fenwick tree and decrement at the index val1
            vft[gem_list[val1]].incr(val1,-1);

            // change value in gem list to val2 for future tracking
            gem_list[val1] = val2;

            // change new value's fenwick tree
            vft[val2].incr(val1,1);
        }
        else if (opt == 2) {
            cin >> val1 >> val2;
            values[val1] = val2;
        }
        else if (opt == 3) {
            cin >> val1 >> val2;
            cout << (values[1] * vft[1].rsq(val1,val2)) + (values[2] * vft[2].rsq(val1,val2)) + (values[3] * vft[3].rsq(val1,val2)) + (values[4] * vft[4].rsq(val1,val2)) + (values[5] * vft[5].rsq(val1,val2)) + (values[6] * vft[6].rsq(val1,val2)) << endl;
        }
    }
    return 0;
}