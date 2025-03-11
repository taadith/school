// data structures
#include <vector>
#include <queue>

// math & double limit
#include <cmath>
#include <limits>

#include <iostream>
#include <iomanip>

using namespace std;

const double DOUBLE_MAX = numeric_limits<double>::max();
const double WALKING_SPEED = 5.0; // 5 meters per second

double pairs_distance(const pair<double, double> &start, const pair<double, double> &end) {
    return sqrt(pow(start.first - end.first, 2) + pow(start.second - end.second, 2));
}

void dijkstra(const vector<vector<pair<int, double>>> &graph, vector<double> &min_time_reach, int start) {
    priority_queue<pair<double, int>> pq;
    pq.push({0, start});
    min_time_reach[start] = 0;

    while (!pq.empty()) {
        double time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (time > min_time_reach[u])
            continue;

        for(unsigned int i = 0; i < graph[u].size(); i++) {
            int node = graph[u][i].first;
            double time = graph[u][i].second;

            if (min_time_reach[u] + time < min_time_reach[node]) {
                min_time_reach[node] = min_time_reach[u] + time;
                pq.push({min_time_reach[node], node});
            }
        }
    }
}

int main() {
    pair<double, double> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;
    
    int n;
    cin >> n;

    vector<pair<double, double>> cannon_locs(n);
    for (int i = 0; i < n; ++i)
        cin >> cannon_locs[i].first >> cannon_locs[i].second;

    vector<vector<pair<int, double>>> graph(n + 2);
    for (int i = 0; i < n; ++i) {
        // start to cannons
        graph[0].push_back({i + 1, pairs_distance(start, cannon_locs[i]) / WALKING_SPEED});
        
        // cannons to end
        double taking_cannon = 2;
        taking_cannon += abs(pairs_distance(cannon_locs[i], end) - 50.0) / WALKING_SPEED;
        double walking = pairs_distance(cannon_locs[i], end) / WALKING_SPEED;
        graph[i + 1].push_back({n + 1, min(taking_cannon, walking)});
    }

    // directly from start to end
    graph[0].push_back({n + 1, pairs_distance(start, end) / WALKING_SPEED});

    // between cannons
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                double taking_cannon = 2;
                taking_cannon += abs(pairs_distance(cannon_locs[i], cannon_locs[j]) - 50.0) / WALKING_SPEED;
                double walking = pairs_distance(cannon_locs[i], cannon_locs[j]) / WALKING_SPEED;
                graph[i + 1].emplace_back(j + 1, min(taking_cannon, walking));
            }
        }
    }

    vector<double> min_time_reach(n + 2, DOUBLE_MAX);
    dijkstra(graph, min_time_reach, 0);

    cout << setprecision(10) << min_time_reach[n + 1] << endl;

    return 0;
}
