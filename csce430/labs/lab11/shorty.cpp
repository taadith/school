#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct node {
    vector<int> adj;
    vector<long double> weights;
};

int main() {

    int n, m;
    while(cin >> n >> m && n != 0 && m != 0) {

        vector<vector<pair<long double, int>>> graph(n);
        vector<node> node_graph(n);
        for(int i = 0; i < m; i++) {
            int n1, n2;
            long double w;
            cin >> n1 >> n2 >> w;
            graph[n1].push_back({w, n2});
            graph[n2].push_back({w, n1});

            node_graph[n1].adj.push_back(n2);
            node_graph[n1].weights.push_back(w);

            node_graph[n2].adj.push_back(n1);
            node_graph[n2].weights.push_back(w);
        }

        vector<bool> visited_nodes(n, false);
        vector<long double> final_factors(n, 0);

        // (weight/factor, node)
        priority_queue<pair<long double,int>> pq;
        pq.push({1,0});

        while(!pq.empty()) {
            long double factor = pq.top().first;
            int min_weight_node = pq.top().second;
            pq.pop();

            if(visited_nodes[min_weight_node])
                continue;

            visited_nodes[min_weight_node] = true;
            final_factors[min_weight_node] = factor;

            for(unsigned int i = 0; i < node_graph[min_weight_node].adj.size(); i++) {
                int &node = node_graph[min_weight_node].adj[i];
                long double &next_node_factor = node_graph[min_weight_node].weights[i];
                pq.push({factor * next_node_factor, node});
            }
        }

        cout << fixed << setprecision(4) << final_factors[n - 1] << endl;
    }
}