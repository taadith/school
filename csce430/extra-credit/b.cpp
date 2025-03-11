#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    // (happiness, (limit, topping name))
    priority_queue<pair<int, pair<int, string>>> pq;
    for(int i = 0; i < n; i++) {
        string t;
        int h,l;

        cin >> t >> h >> l;
        
        pq.push({h, {l, t}});
    }

    for(int i = 0; i < 8; i++) {
        pair<int, pair<int, string>> p = pq.top();
        pq.pop();

        cout << p.second.second << endl;
        if (p.second.first > 1) {
            p.second.first--;
            pq.push(p);
        }
    }

    return 0;
}