#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// (1) adjacency list approach
struct node {
    // int value; // storing a value per node
    vector<int> adj;
    // vector<int> weights;
};

// int n; // number of nodes
// vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void IS_BRIDGE(int node, int adjacent_node) {
    cout << "bridge between node " << node << " and node " << adjacent_node << endl;
}

void bridge_dfs(vector<node> &nodes, int node, int parent) {
    visited[node] = true;
    tin[node] = low[node] = timer++;
    for(unsigned int i = 0; i < nodes[node].adj.size(); i++) {
        int adjacent_node = nodes[node].adj[i];
        if (parent == adjacent_node)
            continue;
        if (visited[adjacent_node])
            low[node] = min(low[node], tin[adjacent_node]);
        else {
            bridge_dfs(nodes, adjacent_node, node);
            low[node] = min(low[node], low[adjacent_node]);
            if (low[adjacent_node] > tin[node])
                IS_BRIDGE(node, adjacent_node);
        }
    }
}

void find_bridges(vector<node> &nodes, int &n) {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            bridge_dfs(nodes, i, -1);
    }
}

int main() {
    int n;  // nodes;
    cin >> n;
    vector<node> nodes(n + 1);

    // // read in values for nodes
    // for (int i = 1; i < n + 1; i++) {
    //     cin >> v[i].value;
    // }

    int e;  // edges
    cin >> e;
    for(int i = 1; i < e + 1; i++) {
        int n1, n2 /*, w*/;
        std::cin >> n1 >> n2 /* >> w */;
        nodes[n1].adj.push_back(n2);
        // v[n1].weights.push_back(w);

        // skip these lines if we're dealing w/ a directed graph
        nodes[n2].adj.push_back(n1);
        // v[n2].weights.push_back(w);
    }

    find_bridges(nodes, n);

    return 0;
}