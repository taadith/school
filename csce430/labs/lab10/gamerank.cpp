#include <vector>
#include <string>

#include <iostream>

using namespace std;

int main() {
    vector<int> star_values_for_rank(26, 0);

    // populating rank (i) for stars (value at i)
    for(int i = 25; i >= 21; i--)
        star_values_for_rank[i] = 2;
    for(int i = 20; i >= 16; i--)
        star_values_for_rank[i] = 3;
    for(int i = 15; i >= 11; i--)
        star_values_for_rank[i] = 4;
    for(int i = 10; i >= 1; i--)
        star_values_for_rank[i] = 5;

    string matches;
    cin >> matches;
    
    int rank = 25;
    int stars = 0;
    int consecutive_wins = 0;

    for(unsigned int i = 0; i < matches.size(); i++) {
        const char &match = matches[i];
        if(match == 'W') {
            consecutive_wins++;

            // yay winstreak
            if(rank >= 6 && consecutive_wins >= 3) {
                stars++;
                if(star_values_for_rank[rank]+1 == stars) {
                    rank--;
                    stars = 1;
                }
            }

            // just comes from winning
            stars++;
            if(star_values_for_rank[rank]+1 == stars) {
                rank--;
                stars = 1;
            }

        }
        else {
            consecutive_wins = 0;

            if (rank == 0)
                continue;
            if(rank <= 20)
                stars--;
            if(stars == -1) {
                if(rank == 20)
                    stars = 0;
                else {
                    rank++;
                    stars = star_values_for_rank[rank] - 1;
                }
            }
        }
    }

    if(rank == 0)
        cout << "Legend" << endl;
    else
        cout << rank << endl;
}