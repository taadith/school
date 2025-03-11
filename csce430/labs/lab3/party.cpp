#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int,int> m;
    int n,x,min;
    cin >> n;
    min = n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if (m.count(x) == 0) {
            m.emplace(x,i);
        }
        else {
            if (i - m.at(x) < min)
                min = i - m.at(x);
            m.at(x) = i;
        }
    }

    cout << min << endl;
    return 0;
}