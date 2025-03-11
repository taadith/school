#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    //FAST IO:
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> s;
    priority_queue<int> top_pq;     // min heap
    priority_queue<int> bot_pq;     // max heap
    while(!cin.eof()) {
        if (s == "#") {
            cout << "taking " << -1 * top_pq.top() << " from top_pq" << endl;
            // cout << -1 * top_pq.top() << endl;
            top_pq.pop();
            if (bot_pq.size() > top_pq.size()) {
                cout << "bot_pq got too big, moving " << bot_pq.top() << " from bot_pq to top_pq" << endl;
                top_pq.push(-1 * bot_pq.top());
                bot_pq.pop();
            }
        }
        else {
            n = stoi(s);
            if (top_pq.size() == 0) {
                top_pq.push(n * -1);
                cout << "(first item) moving " << n << " to top_pq" << endl;
            }
            else if (n > (-1 * top_pq.top())) {
                top_pq.push(-1 * n);
                cout << "moving " << n << " to top_pq" << endl;
            }
            else {
                bot_pq.push(n);
                cout << "moving " << n << " to bot_pq" << endl;
            }
            if (top_pq.size() > bot_pq.size() + 1) {
                cout << "top_pq got too big, moving " << -1 * top_pq.top() << " to bot_pq" << endl;
                bot_pq.push(-1 * top_pq.top());
                top_pq.pop();
            }
            else if (bot_pq.size() > top_pq.size()) {
                cout << "bot_pq got too big, moving " << bot_pq.top() << " from bot_pq to top_pq" << endl;
                top_pq.push(-1 * bot_pq.top());
                bot_pq.pop();
            }
        }
        cin >> s;
    }
    return 0;
}