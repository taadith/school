#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// adjacency list approach
struct node {
    vector<int> adj;
};

// need to keep track of edges somehow
struct edge {
    int first_node;
    int second_node;
    int weight;

    // bool operator<(edge const& other) {
    //     return weight < other.weight;
    // }
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
    int n;  // nodes;
    cin >> n;
    vector<node> nodes(n);

    parents.resize(n);
    for(int i = 0; i < n + 1; i++)
        parents[i] = i;

    int e;
    cin >> e;
    vector<edge> edges(e);
    for(int i = 0; i < e; i++) {
        cin >> edges[i].first_node >> edges[i].second_node >> edges[i].weight;

    sort(edges.begin(), edges.end(), cmp);

    int mst_edges = 0;
    int mst_indices = 0;
    

    return 0;
}