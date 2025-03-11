#include <iostream>
#include <queue>

const int INF = 1e9 + 1;

using namespace std;

int main() {
    int n,e;
    
    cin >> n;
    vector<vector<int>> adj_matrix(n, vector<int>(n, -1));

    cin >> e;
    
    for(int i = 0; i < e; i++) {
        int n1,n2,w;
        cin >> n1 >> n2 >> w;
        
        adj_matrix[n1][n2] = w;
        adj_matrix[n2][n1] = w;
    }

    vector<bool> in_nodes(n, false);
    priority_queue<pair<int, pair<int, int>>> pq_edges;
    int first_node = 0;
    for(int i = 0; i < n; i++) {
        if (adj_matrix[0][i] == -1)
            continue;
        pq_edges.insert({adj_matrix[0][i], {0, i}});
    }
}