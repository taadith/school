#include <vector>
#include <queue>

#include <unordered_map>
#include <string>

#include <algorithm>

#include <iostream>
#include <sstream>

using namespace std;

struct node {
    int value;
    vector<int> adj;
};

vector<node> nodes;
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited_dfs;
vector<bool> visited_bfs;
vector<int> top_sorted_nodes;

void dfs(vector<node> &nodes, int src_node) {
    visited_dfs[src_node] = true;
    for(unsigned int i = 0; i < nodes[src_node].adj.size(); i++) {
        int &dest_node = nodes[src_node].adj[i];
        if (!visited_dfs[dest_node])
            dfs(nodes, dest_node);
    }
    top_sorted_nodes.push_back(src_node);
}

void bfs(vector<node> &nodes, int src_node) {
    visited_bfs.assign(nodes.size(), false);
    visited_bfs[src_node] = true;

    queue<int> q;
    q.push(src_node);
    while(!q.empty()) {
        int a = q.front();
        q.pop();

        for(unsigned int i = 0; i < nodes[a].adj.size(); i++) {
            int b = nodes[a].adj[i];
            if (!visited_bfs[b]){
                visited_bfs[b] = true;
                q.push(b);
            }
        }
    }
}

void topological_sort(vector<node> &nodes, int &n) {
    visited_dfs.assign(n, false);
    top_sorted_nodes.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited_dfs[i]) {
            dfs(nodes, i);
        }
    }
    reverse(top_sorted_nodes.begin(), top_sorted_nodes.end());
}

int main() {
    int n;
    cin >> n;
    vector<node> nodes(n);

    int unique_node_id = 0;
    unordered_map<string, int> files_as_nodes;
    unordered_map<int, string> nodes_as_files;
    for(int i = 0; i < n; i++) {
        // grab node
        string file;
        cin >> file;

        file = file.substr(0, file.size() - 1);
        // cout << file << endl;

        if (files_as_nodes.count(file) == 0) {
            files_as_nodes.emplace(file, unique_node_id);
            nodes_as_files.emplace(unique_node_id, file);
            unique_node_id++;
        }

        // grab in-edges of node
        string remaining_line;
        getline(cin, remaining_line);
        stringstream ss(remaining_line);

        string dependent_file;
        while(ss >> dependent_file) {
            if (files_as_nodes.count(dependent_file) == 0) {
                files_as_nodes.emplace(dependent_file, unique_node_id);
                nodes_as_files.emplace(unique_node_id, dependent_file);
                unique_node_id++;
            }
            nodes[files_as_nodes[dependent_file]].adj.push_back(files_as_nodes[file]);
        }
    }

    topological_sort(nodes, n);

    string edited_file;
    cin >> edited_file;
    
    bfs(nodes, files_as_nodes[edited_file]);
    
    for(int i = 0; i < n; i++) {
        if (visited_bfs[top_sorted_nodes[i]])
            cout << nodes_as_files[top_sorted_nodes[i]] << endl;
    }

    return 0;
}