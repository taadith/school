#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//union find implementation:
vector<int> parents;
vector<int> maxsize;

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
    if (maxsize[a] == maxsize[b]) {
        parents[b] = a;
        maxsize[a]++;
    }
    else if (maxsize[a] > maxsize[b]) {
        parents[b] = a;
    }
    else if (maxsize[a] < maxsize[b]) {
        parents[a] = b;
    }
}

bool is_bipartite_graph(vector<vector<bool>> &graph, int &n, int start) {
    vector<int> colors(n + 1, -1);
    queue<int> q;

    q.push(start);
    colors[start] = 0;

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        for(int b = 1; b < n + 1; b++) {
            if (a == b)
                continue;
            else if (!graph[a][b])
                continue;
            else if (graph[a][b] == true && colors[b] == -1) {
                q.push(b);
                colors[b] = 1 - colors[a];
            }
            else if (graph[a][b] == true && colors[a] == colors[b])
                return false;
        }
    }

    return true;
}

int main() {
    // initialization:
    int n;
    cin >> n;
    parents.resize(n);
    maxsize.resize(n);

    for(int i = 0; i < n; i++) {
        parents[i] = i;
        maxsize[i] = 1;
    }

    // perform operations
    int op = 1;
    cin >> op;
    while (op != 0) {
        if (op == 1) {
            int a;
            cin >> a;
            cout << "element " << a << " is in set " << find(a) << endl;
        }
        else {
            int a,b;
            cin >> a >> b;
            merge(a,b);
            cout << "merged the set that element " << a << " belongs to and the set that element " << b << " belongs to " << endl;
        }
        cin >> op;
    }

    return 0;
}