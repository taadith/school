#include <vector>
#include <iostream>

using namespace std;

// string dp(map<pair<string,int>,string> &dict, vector<int> &possible_moves, string player, int stones_remaining) {
//     // cout << "Game State: Player - " << player << ", Stones Remaining: " << stones_remaining << endl;
//     // base cases, check if the player is k (belongs to possible_moves) stones away: 
//     for(unsigned int i = 0; i < possible_moves.size(); i++) {
//         if (stones_remaining - possible_moves[i] < 0)
//             continue;
//         if (stones_remaining - possible_moves[i] == 0)
//             return player;
//     }

//     // check if the game state already exists!
//     pair<string,int> game_state(player, stones_remaining);
//     if (dict.count(game_state) > 0)
//         return dict.at(game_state);
    
//     // who is the player for the next turn?
//     string winner = "";
//     string next_player;
//     if (player == "Stan")
//         next_player = "Ollie";
//     else
//         next_player = "Stan";
    
//     // run all next possible turns!
//     for(unsigned int i = 0; i < possible_moves.size(); i++) {
//         if (stones_remaining - possible_moves[i] < 0)
//             continue;
//         winner = dp(dict,possible_moves,next_player,stones_remaining - possible_moves[i]);
//         if (player == winner)
//             break;
//     }

//     dict.emplace(game_state,winner);

//     if (game_state.first == "Stan") {
//         game_state.first = "Ollie";
//         if (winner == "Stan")
//             dict.emplace(game_state, "Ollie");
//         else
//             dict.emplace(game_state, "Stan");
//     }
//     else if (game_state.first == "Ollie") {
//         game_state.first = "Stan";
//         if (winner == "Stan")
//             dict.emplace(game_state, "Ollie");
//         else
//             dict.emplace(game_state, "Stan");
//     }

//     return winner;
    
// }

int main() {
    int n,m;
    while(cin >> n) {
        cin >> m;
        vector<int> possible_moves(m);
        vector<bool> memo(1000001,false);
        for(int i = 0; i < m; i++)
            cin >> possible_moves[i];
        
        for(int i = 1; i < n + 1; i++) {
            for(unsigned int j = 0; j < possible_moves.size(); j++) {
                memo[i] = false;
                // can't go any further w/ this move
                if (i - possible_moves[j] < 0)
                    continue;
                if (i - possible_moves[j] >= 0 && memo[i - possible_moves[j]] == false) {
                    memo[i] = true;
                    break;
                }
            }
        }
        if (memo[n])
            cout << "Stan wins";
        else
            cout << "Ollie wins";
        cout << endl;
        // map<pair<string,int>,string> dict;
        // string winner = dp(dict, possible_moves, "Stan", n);
        // cout << winner << " wins" << endl;
    }

    return 0;
}