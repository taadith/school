#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void new_board_copy(vector<vector<char>> &o, vector<vector<char>> &c) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++)
            c[i][j] = o[i][j];
    }
}

void print_board(vector<vector<char>> &board) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int recursive_board_moves(vector<vector<char>> &board) {
    int remaining_pegs = 0;
    int pegs_left = 8;
    int pegs_right = 8;
    int pegs_above = 8;
    int pegs_below = 8;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            if (board[i][j] == 'o')
                remaining_pegs++;
        }
    }
    // cout << "there are " << remaining_pegs << " pegs remaining!\n";
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            if (board[i][j] == '#' || board[i][j] == '.')
                continue;
            else if (board[i][j] == 'o') {
                // capture peg above
                if (i - 1 >= 1 && i - 2 >= 0) {
                    if (board[i - 1][j] == 'o' && board[i - 2][j] == '.') { 
                        // cout << "at board[" << i << "][" << j << "], we are capturing peg above\n";
                        // cout << "original board:\n";
                        // print_board(board);

                        vector<vector<char>> board_copy(5, vector<char>(9));
                        new_board_copy(board,board_copy);
                        board_copy[i][j] = '.';
                        board_copy[i - 1][j] = '.';
                        board_copy[i - 2][j] = 'o';
                        
                        // cout << "new board:\n";
                        // print_board(board_copy);
                        
                        pegs_above = min(pegs_above, recursive_board_moves(board_copy));
                    }
                }
                // capture peg to the left
                if (j - 1 >= 1 && j - 2 >= 0) {
                    if (board[i][j - 1] == 'o' && board[i][j - 2] == '.') {
                        // cout << "at board[" << i << "][" << j << "], we are capturing peg to the left\n";
                        // cout << "original board:\n";
                        // print_board(board);
                        
                        vector<vector<char>> board_copy(5, vector<char>(9));
                        new_board_copy(board,board_copy);
                        board_copy[i][j] = '.';
                        board_copy[i][j - 1] = '.';
                        board_copy[i][j - 2] = 'o';

                        // cout << "new board:\n";
                        // print_board(board_copy);

                        pegs_left = min(pegs_left, recursive_board_moves(board_copy));
                    }
                }
                // capture peg below
                if (i + 1 <= 3 && i <= 4) {
                    if (board[i + 1][j] == 'o' && board[i + 2][j] == '.') {
                        // cout << "at board[" << i << "][" << j << "], we are capturing peg below\n";
                        // cout << "original board:\n";
                        // print_board(board);

                        vector<vector<char>> board_copy(5, vector<char>(9));
                        new_board_copy(board,board_copy);
                        board_copy[i][j] = '.';
                        board_copy[i + 1][j] = '.';
                        board_copy[i + 2][j] = 'o';

                        // cout << "new board:\n";
                        // print_board(board_copy);

                        pegs_below = min(pegs_below, recursive_board_moves(board_copy));
                    }
                }
                // capture peg to the right {
                if (j + 1 <= 7 && j + 2 <= 8) {
                    if (board[i][j + 1] == 'o' && board[i][j + 2] == '.') {
                        // cout << "at board[" << i << "][" << j << "], we are capturing peg to the right\n";
                        // cout << "original board:\n";
                        // print_board(board);

                        vector<vector<char>> board_copy(5, vector<char>(9));
                        new_board_copy(board,board_copy);
                        board_copy[i][j] = '.';
                        board_copy[i][j + 1] = '.';
                        board_copy[i][j + 2] = 'o';

                        // cout << "new board:\n";
                        // print_board(board_copy);

                        pegs_right = min(pegs_right, recursive_board_moves(board_copy));
                    }
                }
            }
        }
    }
    return min(remaining_pegs, min(pegs_left, min(pegs_right, min(pegs_above, pegs_below))));
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        // creating and reading in board
        int starting_pegs = 0;
        vector<vector<char>> board(5,vector<char>(9));
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> board[i][j];
                if(board[i][j] == 'o')
                    starting_pegs++;
            }
        }

        // cout << "starting w/ " << starting_pegs << " pegs on the board!\n";

        // check all around pegs
        int ending_pegs = recursive_board_moves(board);

        // cout << "ending w/ " << ending_pegs << "!\n";

        cout << ending_pegs << " "  << starting_pegs - ending_pegs << endl;

    }
    

    return 0;
}