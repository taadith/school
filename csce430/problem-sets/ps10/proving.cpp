#include <vector>
#include <stack>
#include <unordered_set>
#include <cmath>

#include <iostream>

using namespace std;

struct node {
    // adjacency list
    unordered_set<int> adj;
};

void modified_dfs(vector<node> &graph, stack<int> & dfs_stack, vector<bool> &visited, int curr_node) {
    visited[curr_node] = true;

    for(unsigned int i = 0; i < graph.size(); i++) {
        unordered_set<int>::iterator us_it;
        for(us_it = graph[i].adj.begin(); us_it != graph[i].adj.end(); us_it++) {
            if (!visited[*us_it])
                modified_dfs(graph, dfs_stack, visited, *us_it);
        }
    }

    dfs_stack.push(curr_node);
}

vector<vector<int>> find_scc(vector<node> &graph, vector<node> &transposed_graph, int &n) {
    vector<vector<int>> sccs;
    vector<bool> visited(n + 1, false);

    stack<int> s;

    for(int i = 1; i < n + 1; i++) {
        if (!visited[i])
            modified_dfs(graph, s, visited, i);
    }

    visited.assign(n + 1, false);

    while(!s.empty()) {
        int a = s.top();
        s.pop();

        if(!visited[a]) {
            vector<int> scc;
            modified_dfs(transposed_graph, s, visited, a);

            while(!s.empty()) {
                int vertex = s.top();
                s.pop();
                scc.push_back(vertex);
            }
            scc.push_back(a);
            sccs.push_back(scc);
        }
    }

    return sccs;
}

vector<node> create_condensed_graph(vector<node> &graph, const vector<vector<int>> &sccs) {
    vector<node> condensed_graph(sccs.size());

    // map each vertex to corresponding scc index
    vector<int> vertex_to_scc(graph.size(), -1);
    for(unsigned int i = 0; i < sccs.size(); i++) {
        for(unsigned int j = 0; j < sccs[i].size(); j++)
            vertex_to_scc[sccs[i][j]] = i;
    }

    // add edges between sccs
    for(unsigned i = 1; i < graph.size() + 1; i++) {
        unordered_set<int>::iterator us_it;
        for (us_it = graph[i].adj.begin(); us_it != graph[i].adj.end(); us_it++) {
            if (vertex_to_scc[i] != vertex_to_scc[*us_it])
                condensed_graph[i].adj.insert(*us_it);
        }
    }

    return condensed_graph;
}



int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<node> graph(n + 1);
        vector<node> transposed_graph(n + 1);
        for(int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;

            graph[n1].adj.insert(n2);
            transposed_graph[n2].adj.insert(n1);
        }
        
        vector<vector<int>> sccs = find_scc(graph, transposed_graph, n);

        vector<node> cg = create_condensed_graph(graph, sccs);
        vector<bool> is_root_node(sccs.size(), true);

        cout << "stuff" << endl;
        unsigned int root_nodes = sccs.size();
        unsigned int leaf_nodes = 0;

        cout << "roots and leafs" << endl;
        for(unsigned int i = 0; i < cg.size(); i++) {
            if (cg[i].adj.size() == 0) {
                leaf_nodes++;
                continue;
            }

            unordered_set<int>::iterator us_it;
            for(us_it = cg[i].adj.begin(); us_it != cg[i].adj.end(); us_it++) {
                if (!is_root_node[*us_it]) {
                    is_root_node[*us_it] = false;
                    root_nodes--;
                }
                    
            }
            
        }

        cout << min(root_nodes, leaf_nodes) << endl;
        
    }

    return 0;
}
