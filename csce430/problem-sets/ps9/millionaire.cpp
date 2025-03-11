#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // min pq: (-weight, (x, y))
    priority_queue<pair<int, pair<int, int>>> pq;

    // starting at NW corner
    pq.push({0, {0, 0}});
    int max_edge = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first;
        pair<int, int> position = pq.top().second;
        
        pq.pop();

        int &x = position.first;
        int &y = position.second;

        // skip if we already visited this "node"
        if (visited[x][y])
            continue;
        
        visited[x][y] = true;

        // update largest edge added to MST so far!
        max_edge = max(max_edge, cost);

        // yay we're done
        if (x == n - 1 && y == m - 1) 
            break;

        // adding new nodes that are attached to current node
        for(int i = 0; i < 4; i++) {
            pair<int, int> direction = directions[i];

            int new_x = x + direction.first;
            int new_y = y + direction.second;

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !visited[new_x][new_y]) {
                int new_cost = -max(0, grid[new_x][new_y] - grid[x][y]);
                pq.push({new_cost, {new_x, new_y}});
            }
        }
    }

    cout << max_edge << endl;
    
    return 0;
}
