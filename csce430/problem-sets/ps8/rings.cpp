#include <vector>
#include <iostream>

using namespace std;

int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<char>> char_grid(r, vector<char>(c));
    vector<vector<int>> int_grid(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> char_grid[i][j];
            if (char_grid[i][j] == 'T')
                
        }
            
    }

    return 0;
}