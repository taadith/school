#include <iostream>
#include <vector>

using namespace std;

//union find implementation:
vector<int> parents;
// vector<int> maxsize;

int find(int x) {
    if (parents[x] == x)
        return x;
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void merge(int x, int y) {
    int a,b;
    a = find(x);
    b = find(y);
    
    if (a == b)
        return;
    parents[b] = a;
}

// adjacency list approach
struct node {
    vector<int> adj;
};

vector<bool> visited;
vector<int> first_time_seen, lowest_seen;
int timer;


bool bridge_dfs(vector<node> &nodes, int node, int parent) {
    visited[node] = true;
    first_time_seen[node] = lowest_seen[node] = timer++;
    for(unsigned int i = 0; i < nodes[node].adj.size(); i++) {
        int adjacent_node = nodes[node].adj[i];
        if (parent == adjacent_node)
            continue;
        if (visited[adjacent_node])
            lowest_seen[node] = min(lowest_seen[node], first_time_seen[adjacent_node]);
        else {
            if(bridge_dfs(nodes, adjacent_node, node))
                return true;
            lowest_seen[node] = min(lowest_seen[node], lowest_seen[adjacent_node]);
            if (lowest_seen[adjacent_node] > first_time_seen[node])
                return true;
        }
    }
    return false;
}

bool bridge_exists(vector<node> &nodes) {
    bool bridge_exists = false;

    timer = 0;
    visited.assign(nodes.size(), false);
    first_time_seen.assign(nodes.size(), -1);
    lowest_seen.assign(nodes.size(), -1);

    for (unsigned int i = 0; i < nodes.size(); ++i) {
        if (!visited[i])
            bridge_exists = bridge_dfs(nodes, i, -1);
        if (bridge_exists)
            break;
    }
    return bridge_exists;
}

int main() {
	int n,e;
    while((cin >> n) && (cin >> e) && !(n == 0 && e == 0)) {
        vector<node> nodes(n);

        parents.assign(n,0);
        // parents.resize(n);
        for(int i = 0; i < n; i++)
            parents[i] = i;

        int n1, n2;
        for(int i = 0; i < e; i++) {
            cin >> n1 >> n2;
            
            nodes[n1].adj.push_back(n2);
            nodes[n2].adj.push_back(n1);
            
            merge(n1,n2);
        }
        
        bool all_nodes_connected = true;
        int zero_parent = find(0);
        for(int i = 1; i < n; i++) {
            if (zero_parent != find(i)) {
                all_nodes_connected = false;
                break;
            }
        }

        if (!all_nodes_connected || bridge_exists(nodes))
            cout << "Yes" << endl;
        // if (bridge_exists(nodes))
        //     cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

	return 0;
}
