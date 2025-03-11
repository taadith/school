#include <iostream>
#include <vector>

using namespace std;

int main() {
    int queens = 0;
    bool found_invalid_queen = false;
    vector<vector<char>> vvc(8,vector<char>(8,'x'));
    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cin >> vvc[i][j];
    }

    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (vvc[i][j] == '*') {
                for(int c = j + 1; c < 8; c++) {
                    if (vvc[i][c] == '*') {
                        found_invalid_queen = true;
                        break;
                    }
                }
                for (int r = i + 1; r < 8; r++) {
                    if (vvc[r][j] == '*') {
                        found_invalid_queen = true;
                        break;
                    }
                        
                }
                int sq = 1;
                while(i + sq < 8 && j + sq < 8) {
                    if (vvc[i + sq][j + sq] == '*') {
                        found_invalid_queen = true;
                        break;
                    }
                    sq++;
                }
                sq = 1;
                while(i + sq < 8 && j - sq > -1) {
                    if (vvc[i + sq][j - sq] == '*') {
                        found_invalid_queen = true;
                        break;
                    }
                    sq++;
                }
                queens++;
            }
        }
    }

    if (queens == 8 && !found_invalid_queen)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
    return 0;
}