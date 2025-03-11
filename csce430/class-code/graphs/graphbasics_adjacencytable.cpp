#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;  // nodes;
    std::cin >> n;
    vector<vector<int>> v(n + 1 ,(vector<int> (n + 1, -1)));

    // read in values for nodes
    for (int i = 1; i < n + 1; i++) {
        // cin >> v[i].value;
    }

    int e;  // edges
    std::cin >> e;
    for(int i = 1; i < e + 1; i++) {
        int n1, n2, w;
        std::cin >> n1 >> n2 >> w;
        v[n1][n2] = w;

        // skip this line if we're dealing w/ a directed graph
        v[n2][n1] = w;
    }

    // // BFS
    // vector<int> values(n + 1, -1);
    // values[1] = 0;

    // int time = 0;
    
    // queue<int> q;
    // q.push(1);
    // while(!q.empty()) {
    //     int a = q.front();
    //     q.pop();

    //     time++;
    //     cout << "encountered node " << a << " at time " << time << endl;

    //     for(int b = 1; b < n + 1; b++) {
    //         if (v[a][b] != -1 && values[b] == -1) {
    //             values[b] = values[a] + 1;
    //             q.push(b);
    //         }
    //     }
    // }

    // DFS
    vector<int> values(n + 1, -1);
    values[1] = 0;

    int time = 0;
    
    stack<int> s;
    s.push(1);
    while(!s.empty()) {
        int a = s.top();
        s.pop();

        time++;
        cout << "encountered node " << a << " at time " << time << endl;

        for(int b = 1; b < n + 1; b++) {
            if (v[a][b] != -1 && values[b] == -1) {
                values[b] = values[a] + 1;
                s.push(b);
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        cout << "the distance of node " << i << " from node 1 is " << values[i] << endl;
    }

    return 0;
}