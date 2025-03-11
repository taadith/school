#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// (1) adjacency list approach
struct node {
    int value; // storing a value per node
    vector<int> adj;
    vector<int> weights;
};
// don't necessarily need a struct
//  - could have just made a vector<int> value, vector<vector<int>> adj, and vector<vector<int>> weights

int main() {
    int n;  // nodes;
    std::cin >> n;
    vector<node> v(n + 1);

    // read in values for nodes
    for (int i = 1; i < n + 1; i++) {
        // cin >> v[i].value;
    }

    int e;  // edges
    std::cin >> e;
    for(int i = 1; i < e + 1; i++) {
        int n1, n2, w;
        std::cin >> n1 >> n2 >> w;
        v[n1].adj.push_back(n2);
        v[n1].weights.push_back(w);

        // skip these lines if we're dealing w/ a directed graph
        v[n2].adj.push_back(n1);
        v[n2].weights.push_back(w);
    }

    // BFS
    for(int i = 1; i < n + 1; i++)
        v[i].value = -1;
    v[1].value = 0;

    int time = 0;
    
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        if (v[a].value != -1)
            continue;
        time++;
        cout << "encountered node " << a << " at time " << time << endl;
        for(unsigned int i = 0; i < v[a].adj.size(); i++) {
            int b = v[a].adj[i];
            if (v[b].value == -1) {
                v[b].value = v[a].value + 1;
                q.push(b);
            }
        }
    }

    // DFS
    for(int i = 1; i < n + 1; i++)
        v[i].value = -1;
    v[1].value = 0;

    int time = 0;
    
    stack<int> s;
    s.push(1);
    while(!s.empty()) {
        int a = s.top();
        s.pop();

        cout << "encountered node " << a << " at time " << time << endl;
        time++;
        for(unsigned int i = 0; i < v[a].adj.size(); i++) {
            int b = v[a].adj[i];
            if (v[b].value == -1) {
                v[b].value = v[a].value + 1;
                s.push(b);
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        cout << "the distance of node " << i << " from node 1 is " << v[i].value << endl;

    }

    return 0;
}