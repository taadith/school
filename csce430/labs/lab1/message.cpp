#include <iostream>

using namespace std;

int main() {
    int n, len, square_len;
    string message;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> message;
        len = message.length();
        for(int j = 1; j < 101; j++) {
            if (len <= (j * j)) {
                square_len = j*j;
                break;
            }
        }
        
        vector<vector<char>> matrix (square_len, (vector<char> (square_len,'*')));
        for(int j = 0; j < len; j++) {
            matrix[j / square_len][j % square_len] = message[j];
        }

        char letter;
        for(int k = 0; k < square_len; k++) {
            for(int j = square_len - 1; j > -1; j--) {
                letter = matrix[j][k];
                if(letter == '*')
                    continue;
                else
                    cout << letter;
            }
        }
        cout << endl;
    }

}