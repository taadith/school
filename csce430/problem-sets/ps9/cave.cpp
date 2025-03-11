#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

// adjacency list approach
struct node {
    vector<int> adj;
    int value;
};

vector<bool> visited;
vector<int> first_time_seen, lowest_seen;
set<pair<int, int>> graph_bridges;
int timer;

void is_bridge(int &node, int &adjacent_node) {
    // cout << "bridge between node " << node << " and node " << adjacent_node << endl;
    graph_bridges.insert({min(node, adjacent_node), max(node, adjacent_node)});
}

void bridge_dfs(vector<node> &nodes, int node, int parent) {
    visited[node] = true;
    first_time_seen[node] = lowest_seen[node] = timer++;
    for(unsigned int i = 0; i < nodes[node].adj.size(); i++) {
        int adjacent_node = nodes[node].adj[i];
        if (parent == adjacent_node)
            continue;
        if (visited[adjacent_node])
            lowest_seen[node] = min(lowest_seen[node], first_time_seen[adjacent_node]);
        else {
            bridge_dfs(nodes, adjacent_node, node);
            lowest_seen[node] = min(lowest_seen[node], lowest_seen[adjacent_node]);
            if (lowest_seen[adjacent_node] > first_time_seen[node])
                is_bridge(node, adjacent_node);
        }
    }
}

void find_bridges(vector<node> &nodes, int &n) {
    timer = 0;
    visited.assign(n, false);
    first_time_seen.assign(n, -1);
    lowest_seen.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            bridge_dfs(nodes, i, -1);
    }
}

int main() {
    int n;  // nodes;
    cin >> n;
    vector<node> nodes(n);

    int e;  // edges
    cin >> e;
    for(int i = 0; i < e; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        nodes[n1].adj.push_back(n2);
        nodes[n2].adj.push_back(n1);
    }

    find_bridges(nodes, n);

    // BFS
    for(int i = 1; i < n + 1; i++)
        nodes[i].value = -1;
    nodes[0].value = 0;
    int count = 1;
    
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int a = q.front();
        q.pop();

        for(unsigned int i = 0; i < nodes[a].adj.size(); i++) {
            int b = nodes[a].adj[i];
            // cout << "checking node " << min(a, b) << " and node " << max(a, b) << endl;

            if (graph_bridges.count({min(a, b), max(a, b)}) > 0) {
                // cout << "bridge exists here" << endl;
                continue;
            }
            if (nodes[b].value != -1) {
                // cout << "already visited" << endl;
                continue;
            }
            nodes[b].value = nodes[a].value + 1;
            q.push(b);
            count++;
            // cout << "added node" << endl;
        }
    }

    cout << count << endl;

    return 0;
}