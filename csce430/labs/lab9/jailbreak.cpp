#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 102;

// prison_grid plan all values to all zero
char prison_grid[MAX][MAX] = {};

// dp tables for min doors travelled from each source
int outside_bfs_dp[MAX][MAX];
int p1_bfs_dp[MAX][MAX];
int p2_bfs_dp[MAX][MAX];

//start & prisoner coords
vector<pair<int, int>> path_nodes;

int bfs_directions[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

int h, w, current_min_doors, curr_doors, result;

// queue for bfs nodes
queue<pair<int, int>> queue_for_sources_and_nodes[2] = {
    queue<pair<int, int>>(),
    queue<pair<int, int>>()
};

void bfs(int x, int y, int dp[MAX][MAX]) {
    curr_doors = 0;
    current_min_doors = 0;

    // set all values to not updated
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++)
            dp[i][j] = -1;
    }

    // push source into bfs queue
    queue_for_sources_and_nodes[curr_doors].push({x, y});
    dp[x][y] = 0;

    while (!queue_for_sources_and_nodes[0].empty() || !queue_for_sources_and_nodes[1].empty()) {
        // alternate queue if current one is empty
        if (queue_for_sources_and_nodes[curr_doors].empty()) { 
            current_min_doors++;

            // flips the value between 0 & 1
            curr_doors ^= 1;
        }

        pair<int, int> a = queue_for_sources_and_nodes[curr_doors].front();
        queue_for_sources_and_nodes[curr_doors].pop();
        
        // go through each search direction
        for (int i = 0; i < 4; i++) {
            int b_x = a.first + bfs_directions[i][0];
            int b_y = a.second + bfs_directions[i][1];

            // hvaen't traversed -> update min doors to pass through to this point from source
            if (b_x >= 0 && b_x < h + 2 && b_y >= 0 && b_y < w + 2 && prison_grid[b_x][b_y] != '*' && dp[b_x][b_y] == -1) { 
                dp[b_x][b_y] = current_min_doors;

                // reached door so add to other queue
                if (prison_grid[b_x][b_y] == '#')
                    queue_for_sources_and_nodes[curr_doors^1].push({b_x, b_y});
                else
                    queue_for_sources_and_nodes[curr_doors].push({b_x, b_y});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> h >> w;

        // top left of outside is starting pt
        path_nodes.push_back({0, 0});

        for (int i = 0; i <= h + 1; i++) {
            // padding outside rows with '.'
            if (i == 0 || i == h+1) {
                for (int j = 0; j <= w+1; j++)
                    prison_grid[i][j] = '.';
            } 
            else {
                for(int j = 1; j <= w; j++)
                    cin >> prison_grid[i][j];

                // padding outside columns with '.'
                prison_grid[i][0] = '.';
                prison_grid[i][w+1] = '.';
            }
        }

        for (int i = 0; i <= h+1; i++) {
            for (int j = 0; j <= w+1; j++) {
                if (prison_grid[i][j] == '$')
                    path_nodes.push_back({i, j});
            }
        }

        // Run minimum path from source and each prisoner
        bfs(path_nodes[0].first, path_nodes[0].second, outside_bfs_dp);
        bfs(path_nodes[1].first, path_nodes[1].second, p1_bfs_dp);
        bfs(path_nodes[2].first, path_nodes[2].second, p2_bfs_dp);
        
        current_min_doors = outside_bfs_dp[0][0] + p1_bfs_dp[0][0] + p2_bfs_dp[0][0];
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {

                // node is reachable
                if (outside_bfs_dp[i][j] >= 0) {
                    curr_doors = outside_bfs_dp[i][j] + p1_bfs_dp[i][j] + p2_bfs_dp[i][j];
                    if (prison_grid[i][j] == '#')
                        curr_doors++;
                    current_min_doors = min(current_min_doors, curr_doors);
                }
            }
        }

        cout << current_min_doors << endl;
        path_nodes.clear();
    }

    return 0;
}