#include <bits/stdc++.h>

using namespace std;

#define INFTY 600

int findMaxHeightClimbed(int height, int movesLeft, vector<int>& climbSequence, vector<vector<int>>& memo) {
    int m = climbSequence.size() - 1;   //m + 1 - 1 == m
    if (height < 0 || height > 500)
        return INFTY;   //returns 600
    if (height == 0 && movesLeft == m)
        return 0;
    else if (height > 0 && movesLeft == m) {
        memo[height][movesLeft] = INFTY;
        return memo[height][movesLeft];
    }
        
    if (memo[height][movesLeft] != -1)
        return memo[height][movesLeft];
    int currentClimbDistance = climbSequence[movesLeft + 1];
    memo[height][movesLeft] =
        min(
            findMaxHeightClimbed(height + currentClimbDistance, movesLeft + 1, climbSequence, memo),
            max(height,findMaxHeightClimbed(height - currentClimbDistance,movesLeft + 1, climbSequence,memo))
        );
    return memo[height][movesLeft];
}

void findMoves(int maxHeightClimbed, string& moves,vector<int>& climbSequence, vector<vector<int>>& memo) {
    //moves = "U";
    int prevHeight = 0;
    int currHeightMin, currHeightMax;
    for(int i = 1; i < climbSequence.size() - 1; i++) {
        currHeightMin = prevHeight - climbSequence[i];
        currHeightMax = prevHeight + climbSequence[i];
        if (currHeightMin < 0) {
            prevHeight = currHeightMax;
            // cout << "moving up to height " << prevHeight << endl;
            moves += "U";
        }
        else if (currHeightMax > maxHeightClimbed) {
            prevHeight = currHeightMin;
            // cout << "moving down to height " << prevHeight << endl;
            moves += "D";
        }
        else {
            if (memo[currHeightMin][i] <= maxHeightClimbed) {
                prevHeight = currHeightMin;
                // cout << "moving down to height " << prevHeight << endl;
                moves += "D";
            }
            else if (memo[currHeightMax][i] <= maxHeightClimbed) {
                prevHeight = currHeightMax;
                // cout << "moving up to height " << prevHeight << endl;
                moves += "U";
            }
        }
    }
    // cout << "moving down to height 0" << endl;
    moves += "D";
}

int main() {
    //fast input && output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        vector<int> climbSequence(m + 1,-1);
        vector<vector<int>> memo;
        for(int j = 0; j < 501; j++) {
            vector<int> memoVector(m + 1,-1);
            memo.push_back(memoVector);
            if (j >= 1 && j <= m)
                cin >> climbSequence[j];
        }
        
        int maxHeightClimbed = findMaxHeightClimbed(0,0,climbSequence,memo);
        if (maxHeightClimbed == INFTY)
            cout << "IMPOSSIBLE" << endl;
        else {
            string moves = "";
            findMoves(maxHeightClimbed,moves,climbSequence,memo);
            // cout << "Max Height Climbed: " << maxHeightClimbed << endl;
            cout << moves << endl;
        }
    }

    return 0;
}