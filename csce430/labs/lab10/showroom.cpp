#include <vector>
#include <deque>

#include <iostream>

using namespace std;

const vector<pair<int, int>> directions = {
    {0,-1},
    {0,1},
    {-1,0},
    {1,0}
};

int main() {
    int r,c;
    cin >> r >> c;

    vector<vector<char>> showroom(r + 2, vector<char>(c + 2, '.'));
    for(int i = 1; i < r + 1; i++) {
        for(int j = 1; j < c + 1; j++)
            cin >> showroom[i][j];
    }

    pair<int, int> start;
    cin >> start.first >> start.second;
    // // bfs
    // vector<int> values(n + 1, -1);
    // values[1] = 0;

    vector<vector<int>> values(r + 2, vector<int>(c + 2, 0));
    values[start.first][start.second] = 1;
    // queue<int> q;
    // q.push(1);

    deque<pair<int, int>> d;
    d.push_front(start);

    // while(!q.empty()) {
    //     int a = q.front();
    //     q.pop();
    //
    //     for(int b = 1; b < n + 1; b++) {
    //         if (v[a][b] != -1 && values[b] == -1) {
    //             values[b] = values[a] + 1;
    //             q.push(b);
    //         }
    //     }
    // }

    
    bool found_door = false;
    while(!d.empty()) {
        pair<int, int> p = d.front();
        d.pop_front();

        for(int i = 0; i < 4; i++) {
            // cout << "hey we are looking arooooooound" << endl;
            int newx = p.first + directions[i].first;
            int newy = p.second + directions[i].second;

            if(showroom[p.first][p.second] == 'D' && showroom[newx][newy] == '.') {
                // cout << "found a door to the outside" << endl;
                cout << values[p.first][p.second] << endl;
                found_door = true;
                break;
            }
            if(showroom[newx][newy] == 'c' && values[newx][newy] == 0) {
                // cout << "found another car, rats" << endl;
                d.push_back({newx,newy});
                values[newx][newy] = values[p.first][p.second] + 1;
            }
            if(showroom[newx][newy] == 'D' && values[newx][newy] == 0) {
                // cout << "a door??? what's behind the door???" << endl;
                d.push_front({newx,newy});
                values[newx][newy] = values[p.first][p.second];
            }
        }

        if (found_door)
            break;
    }

    return 0;
}