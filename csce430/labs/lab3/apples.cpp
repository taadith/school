#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r,c;
    char x;
    cin >> r >> c;
    vector<vector<char>> grid;
    // vector<vector<char>> fall_grid;
    for(int i = 0; i < r; i++) {
        vector<char> row;
        for(int j = 0; j < c; j++) {
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }

    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++)
    //         cout << grid[i][j];
    //     cout << endl;
    // }

    int empty_space;
    int apples;
    // int ground;
    for(int j = 0; j < c; j++) {
        apples = 0;
        empty_space = 0;
        // ground = r - 1;
        for(int i = r - 1; i > -1; i--) {
            // "base case"
            if (grid[i][j] == '#')
                empty_space = 0;
            else if (grid[i][j] == '.')
                empty_space++;
            // in case, it's an apple!
            else if (empty_space > 0) {
                grid[i][j] = '.';
                grid[i + empty_space][j] = 'a'; // go x == empty_spaces empty spaces down and put the apple there
            }
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << grid[i][j];
        cout << endl;
    }

    return 0;
}