#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

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

// bipartite graph implementation from the book
// modified function to take in and return colors from respective bipartite_graph
bool is_bipartite_graph(vector<vector<int>> &adj_list, vector<int>& colors, int start) {
    // if (colors.size() != n + 1) {
    //     cout << "incorrect colors vector" << endl;
    //     exit(1);
    // }

    queue<int> q;
    q.push(start);
    colors[start] = 0;

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        for(unsigned int i = 0; i < adj_list[a].size(); i++) {
            int b = adj_list[a][i];
            if (colors[a] == colors[b])
                return false;
            else if (colors[b] == -1) {
                q.push(b);
                colors[b] = 1 - colors[a];
            }
        } 
    }

    return true;
}

int main() {
    int n,m;
    cin >> n;

    // we know that we start w/ a fully connected graph
    // more important that we know what ingredients can't be together
    // this feels like a set!

    // adjacency list of graph that we don't want
    vector<vector<int>> bad_graph(n + 1, vector<int>());
    
    parents.resize(n + 1);
    for(int i = 0; i < n + 1; i++)
        parents[i] = i;
    
    // one-to-one mapping between node value and ingredient
    unordered_map<string,int> ingredients_to_nodes;
    vector<string> nodes_to_ingredients(n + 1, ""); // does this help w/ runtime?
    
    string x;
    for(int i = 1; i < n + 1; i++) {
        cin >> x;
        ingredients_to_nodes.emplace(x,i);
        nodes_to_ingredients[i] = x;
    }

    // identifying which nodes will be on one side of the disjoint set created in the bipartite graph
    cin >> m;
    string y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;

        // convert ingredient to it's respective node value
        int a = ingredients_to_nodes[x];
        int b = ingredients_to_nodes[y];

        // cout << "merging " << x << " (" << a << ") with " << y << " (" << b << ")" << endl;

        // create a set of edges that can't be combined
        merge(a,b);

        // creating the graph we don't want to see!
        bad_graph[a].push_back(b);
        bad_graph[b].push_back(a);
    }

    // for(int i = 1; i < n + 1; i++)
    //     cout << "parent of " << i << " is " << parents[i] << endl;
    // cout << endl;

    // for grabbing some child node of a parent node
    vector<int> parent_and_child(n + 1, -1);
    for(int i = 1; i < n + 1; i++) {
        int pi = find(i);
        parent_and_child[pi] = i;
    }

    // //if parent_and_child[i] == -1, this means i belongs to some other parent node
    // for(int i = 1; i < n + 1; i++)
    //     cout << "one of parent " << i << "'s children is " << parent_and_child[i] << endl;
    // cout << endl;

    // cout << "bad graph:" << endl;
    // for(int i = 1; i < n + 1; i++) {
    //     cout << i << ": ";
    //     for (unsigned int j = 0; j < bad_graph[i].size(); j++)
    //         cout << bad_graph[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
 
    bool valid_split = true;
    vector<int> colors(n + 1, -1);
    for(int i = 1; i < n + 1; i++) {
        // parent node doesn't have children bc it's a child node itself
        if(parent_and_child[i] == -1)
            continue;
        // start is set to the child of each set that is bad
        valid_split &= is_bipartite_graph(bad_graph, colors, parent_and_child[i]);
    }
        

    if (!valid_split)
        cout << "impossible" << endl;
    else {
        for(int i = 1; i < n + 1; i++) {
            if (colors[i] == 0)
                cout << nodes_to_ingredients[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n + 1; i++) {
            if (colors[i] == 1)
                cout << nodes_to_ingredients[i] << " ";
        }
        cout << endl;
    }

    return 0;
}