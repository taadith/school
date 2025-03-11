#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

struct node {
    vector<int> adj;
    vector<int> weights;
    pair<double, double> coords;
};

double dist(pair<double, double> &coords1, pair<double, double> &coords2) {
    return sqrt(pow(coords1.first - coords2.first, 2) + pow(coords1.second - coords2.second, 2));
}



int modified_bfs(vector<node> &adj_list, vector<vector<int>> capacity, vector<int> &parents, int s, int t) {
    for(unsigned int i = 0; i < parents.size(); i++)
        parents[i] = -1;
    parents[s] = -2;

    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while(!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(unsigned int i = 0; i < adj_list[cur].adj.size(); i++) {
            int &adj_node = adj_list[cur].adj[i];
            if (parents[adj_node] == -1 && capacity[cur][adj_node]) {
                parents[adj_node] = cur;
                int new_flow = min(flow, capacity[cur][adj_node]);
                if (adj_node == t)
                    return new_flow;
                q.push({adj_node, new_flow});
            }
        }
    }

    return 0;
}

int max_flow(vector<node> &adj_list, vector<vector<int>> capacity, int s, int t) {
    int flow = 0;
    vector<int> parents(adj_list.size());
    int new_flow = 0;
    
    while((new_flow = modified_bfs(adj_list, capacity, parents, s, t))) {
        flow += new_flow;
        int cur = t;
        while(cur != s) {
            int prev = parents[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    int gophers,gopher_holes,max_seconds,velocity;
    while(cin >> gophers >> gopher_holes >> max_seconds >> velocity) {
        vector<node> adj_list(gophers + gopher_holes + 2);
        vector<vector<int>> capacity(gophers + gopher_holes + 2, vector<int>(gophers + gopher_holes + 2, 0));
        for(int i = 1; i < gophers + 1; i++) {
            cin >> adj_list[i].coords.first >> adj_list[i].coords.second;
            
            adj_list[0].adj.push_back(i);
            adj_list[0].weights.push_back(1);

            capacity[0][i] = 1;
        }
        for(int i = gophers + 1; i < gophers + gopher_holes + 1; i++) {
            cin >> adj_list[i].coords.first >> adj_list[i].coords.second;

            adj_list[gophers + gopher_holes + 1].adj.push_back(i);
            adj_list[gophers + gopher_holes + 1].weights.push_back(1);

            capacity[gophers + gopher_holes + 1][i] = 1;
        }
        
        for(int i = 1; i < gophers + 1; i++) {
            pair<double, double> &gopher = adj_list[i].coords;
            for(int j = gophers + 1; j < gophers + gopher_holes + 1; j++) {
                pair<double, double> &gopher_hole = adj_list[j].coords;
                if (dist(gopher, gopher_hole) / velocity <= max_seconds) {
                    adj_list[i].adj.push_back(j);
                    adj_list[i].weights.push_back(1);

                    capacity[i][j] = 1;
                }
            }
        }

        cout << gophers - max_flow(adj_list, capacity, 0, gophers + gopher_holes + 1) << endl;
    }

    return 0;
}