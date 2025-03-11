#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n,op,x;
    cin >> n;
    while(!cin.eof()) {
        int s_len = 0;
        int q_len = 0;
        int pq_len = 0;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool is_stack = true;
        bool is_queue = true;
        bool is_pq = true;
        for(int i = 0; i < n; i++) {
            cin >> op >> x;
            if(op == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
                s_len++; q_len++; pq_len++;
            }
            else if (op == 2) {
                if (is_stack) {
                    if (s_len == 0) {
                        is_stack = false;
                    }
                    else if(s.top() == x) {
                        s.pop();
                        s_len--;
                    }
                    else
                        is_stack = false;
                }
                if (is_queue) {
                    is_queue = true;
                    if (q_len == 0) {
                        is_queue = false;
                    }
                    else if(q.front() == x) {
                        q.pop();
                        q_len--;
                    }
                    else
                        is_queue = false;
                }
                if (is_pq) {
                    is_pq = true;
                    if (pq_len == 0)
                        is_pq = false;
                    else if (pq.top() == x) {
                        pq.pop();
                        pq_len--;
                    }
                    else
                        is_pq = false;
                }
            }
        }

        if (!is_stack && !is_queue && !is_pq)
            cout << "impossible\n";
        else if ((is_stack && is_queue) || (is_stack && is_pq) || (is_queue && is_pq) || (is_stack && is_queue && is_pq))
            cout << "not sure\n";
        else if (is_stack)
            cout << "stack\n";
        else if (is_queue)
            cout << "queue\n";
        else if (is_pq)
            cout << "priority queue\n";
        cin >> n;
    }

    return 0;
}