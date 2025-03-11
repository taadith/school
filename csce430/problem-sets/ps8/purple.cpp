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
    cin >> n;
    vector<node> nodes(n + 1);

    int e;  // edges
    cin >> e;
    for(int i = 1; i < e + 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        nodes[n1].adj.push_back(n2);

        // skip these lines if we're dealing w/ a directed graph
        nodes[n2].adj.push_back(n1);
    }

    // // BFS
    for(int i = 1; i < n + 1; i++)
        nodes[i].value = -1;
    nodes[1].value = 0;
    
    queue<int> q;
    q.push(1);
    bool reached_end_node = false;
    while(!q.empty() && !reached_end_node) {
        int a = q.front();
        q.pop();

        for(unsigned int i = 0; i < nodes[a].adj.size(); i++) {
            int b = nodes[a].adj[i];
            if (nodes[b].value == -1) {
                nodes[b].value = nodes[a].value + 1;
                if (b == n) {
                    reached_end_node = true;
                    break;
                }
                q.push(b);
            }
        }
    }

    cout << nodes[n].value - 1 << endl;

    return 0;
}