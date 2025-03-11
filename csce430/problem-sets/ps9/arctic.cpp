#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double distance_between_outposts(pair<double, double> &p1, pair<double, double> &p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

struct edge {
    double weight;
    int first_node;
    int second_node;
};

bool cmp(edge lhs, edge rhs) {
    return lhs.weight < rhs.weight;
}

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

int main() {
    int t;
    cin >> t;
    while(t--) {
        int s, p;
        cin >> s >> p;

        vector<pair<double,double>> outpost_points(p);
        
        for(int i = 0; i < p; i++)
            cin >> outpost_points[i].first >> outpost_points[i].second;
        
        vector<edge> edges;
        for(unsigned int i = 0; i < outpost_points.size() - 1; i++) {
            for(unsigned int j = i + 1; j < outpost_points.size(); j++) {
                double distance = distance_between_outposts(outpost_points[i], outpost_points[j]);
                
                edge e;
                e.first_node = i;
                e.second_node = j;
                e.weight = distance;

                edges.push_back(e);
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        parents.assign(p, 0);
        for(int i = 0; i < p; i++)
            parents[i] = i;
        
        vector<double> radio_post_distances;
        for(unsigned int i = 0; i < edges.size(); i++) {
            edge &e = edges[i];
            if (find(e.first_node) != find(e.second_node)) {
                merge(e.first_node, e.second_node);
                radio_post_distances.push_back(e.weight);
            }
        }

        cout << fixed << setprecision(2) << radio_post_distances[(p - 1) - (s - 1) - 1] << endl;
    }
    
    return 0;
}