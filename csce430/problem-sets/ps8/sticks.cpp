#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// (1) adjacency list approach
struct node {
    int state;
    int indegree;
    vector<int> adj;
};
// don't necessarily need a struct
//  - could have just made a vector<int> value, vector<vector<int>> adj, and vector<vector<int>> weights

bool check_for_cycle(vector<node> &nodes, int a) {
    // a is being processed rn
    nodes[a].state = 1;

    for(unsigned int i = 0; i < nodes[a].adj.size(); i++) {
        // adjacent node is b
        int b = nodes[a].adj[i];

        // b is currently being processed which means we ran into a cycle!
        if (nodes[b].state == 1)
            return true;
        
        // if b is not yet processed, check for a cycle from b
        if (nodes[b].state == 0 && check_for_cycle(nodes, b))
            return true;
    }

    nodes[a].state = 2;
    return false;
}

// modified Kahn's topological sort
void top_sort(vector<int> &sorted_nodes, vector<node> &nodes, unsigned int &n) {
    // vector<int> indegree(n + 1, 0);
    
    for(unsigned int i = 1; i < n + 1; i++) {
        for(unsigned int j = 0; j < nodes[i].adj.size(); j++) {
            int b = nodes[i].adj[j];
            nodes[b].indegree++;
        }   
    }

    queue<int> q;
    for(unsigned int i = 1; i < n + 1; i++) {
        if (nodes[i].indegree == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        sorted_nodes.push_back(a);

        //decrease indegree of adjacent vertices to a b/c it's been "fulfilled"
        for(unsigned int i = 0; i < nodes[a].adj.size(); i++) {
            int b = nodes[a].adj[i];
            nodes[b].indegree--;
            
            if (nodes[b].indegree == 0)
                q.push(b);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unsigned int n;  // nodes;
    std::cin >> n;
    vector<node> nodes(n + 1);
    for(unsigned int i = 1; i < n + 1; i++) {
        nodes[i].state = 0;
        nodes[i].indegree = 0;
    }

    int e;  // edges
    std::cin >> e;
    for(int i = 1; i < e + 1; i++) {
        int n1, n2;
        std::cin >> n1 >> n2;
        nodes[n1].adj.push_back(n2);
    }

    // Cycle Check
    bool is_cycle = false;
    for(unsigned int i = 1; i < n + 1; i++) {
        if (nodes[i].state == 0)
            is_cycle = check_for_cycle(nodes,i);
        if (is_cycle)
            break;
    }

    if (is_cycle)
        cout << "IMPOSSIBLE" << endl;
    else {
        // Topological Sort
        vector<int> sorted_nodes;
        sorted_nodes.push_back(-1);

        top_sort(sorted_nodes, nodes, n);
        
        for(unsigned int i = 1; i < n + 1; i++)
            cout << sorted_nodes[i] << endl;
    }

    
    
    return 0;
}