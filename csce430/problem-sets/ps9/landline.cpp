#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//union find implementation:
vector<int> parents;

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

// edges for MST
struct edge {
    int src;
    int dest;
    int weight;
};

bool cmp(edge lhs, edge rhs) {
    return lhs.weight < rhs.weight;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    // if all buildings are insecure
    if (n == p) {
        // complete graph
        int filler;
        for(int i = 0; i < n; i++)
            cin >> filler;
        if (m == ((n * (n - 1)) / 2)) {
            int total_edge_weight = 0;
            int current_edge_weight;
            int filler;
            for(int i = 0; i < m; i++) {
                cin >> filler >> filler >> current_edge_weight;
                total_edge_weight += current_edge_weight;
            }
            cout << total_edge_weight << endl;
        }
        else {
            cout << "impossible" << endl;
        }
    }
    else {
        // track which nodes are secure & which ones are insecure
        vector<bool> secure_nodes(n + 1, true);
        int x;
        for(int i = 0; i < p; i++) {
            cin >> x;
            secure_nodes[x] = false;
        }

        // track all edges
        vector<edge> edges(m);
        for(int i = 0; i < m; i++)
            cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        
        sort(edges.begin(), edges.end(), cmp);

        // cout << "# of edges: " << edges.size() << endl;

        // MST process
        int cost = 0;
        vector<edge> mst_edges;
        
        parents.resize(n + 1);
        for(int i = 1; i < n + 1; i++)
            parents[i] = i;
        
        // secure MST
        for(int i = 0; i < m; i++) {
            edge &e = edges[i];

            if (find(e.src) != find(e.dest)) {
                if (!secure_nodes[e.src] || !secure_nodes[e.dest])
                    continue;
                
                // cout << "node " << e.src << " and node " << e.dest << " added to the mst" << endl;
                cost += e.weight;
                mst_edges.push_back(e);
                merge(e.src, e.dest);
            }
        }

        // cout << "# of edges in secure mst: " << mst_edges.size() << endl;
        // cout << "current cost: " << cost << endl;

        // secure mst isn't possible
        if (n - p - 1 != (int) mst_edges.size()) {
            // cout << "secure mst isn't possible" << endl;
            cout << "impossible" << endl;
        }

        // adding insecure nodes
        else {
            for(int i = 0; i < m; i++) {
                edge &e = edges[i];

                if (find(e.src) != find(e.dest)) {
                    if (secure_nodes[e.src] && secure_nodes[e.dest])
                        continue;
                    if (!secure_nodes[e.src] && !secure_nodes[e.dest])
                        continue;

                    // cout << "node " << e.src << " and node " << e.dest << " added to the mst" << endl;
                    cost += e.weight;
                    mst_edges.push_back(e);
                    merge(e.src, e.dest);
                }
            }

            if (n - 1 != (int) mst_edges.size()) {
                // cout << "full mst isn't possible" << endl;
                cout << "impossible" << endl;
            }
            else {
                cout << cost << endl;
            }
        }
    }

    return 0;
}