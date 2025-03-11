#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int vx;
    for(int i = 0; i < n; i++) {
        cin >> vx;
        v.push_back(vx);
    }

    vector<int> v_asc (n);
    v_asc.at(0) = v.at(0);
    for(int i = 1; i < n; i++) {
        if (v.at(i) > v_asc.at(i - 1))
            v_asc.at(i) = v.at(i);
        else
            v_asc.at(i) = v_asc.at(i-1);
    }
    
    vector<int> v_des (n);
    v_des.at(n-1) = v.at(n-1);
    for(int i = n - 2; i > -1; i--) {
        if (v.at(i) < v_des.at(i + 1))
            v_des.at(i) = v.at(i);
        else
            v_des.at(i) = v_des.at(i + 1);
    }
    int pivots = 0;
    for(int i = 0; i < n; i++) {
        if (v_asc.at(i) == v_des.at(i))
            ++pivots;
    }
    cout << pivots << endl;

    return 0;
}