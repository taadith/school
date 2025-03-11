#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> outcomes = {
    "NNN",  // 0
    "NNY",  // 1
    "NYN",  // 2
    "NYY",  // 3
    "YNN",  // 4
    "YNY",  // 5
    "YYN",  // 6
    "YYY"   // 7
};

// bitwise operation for individual bit flips
int bit_flip(const int &x, int left_shift) {
    return x ^ (1 << left_shift);
}


// could have done something iterative, but easier to visualize for me!
void dp(vector<vector<int>> &memo, vector<vector<int>> &preferences, int i) {
    if (i == 0)
        return;
    
    for (int j = 0; j < 8; j++) {
        // incorrect bit flip implementation
        // int a = i ^ 0xb001;
        // int b = i ^ 0xb010;
        // int c = i ^ 0xb100;

        int a = bit_flip(j, 0);
        int b = bit_flip(j, 1);
        int c = bit_flip(j, 2);

        int config_a = preferences[i][memo[i + 1][a]];
        int config_b = preferences[i][memo[i + 1][b]];
        int config_c = preferences[i][memo[i + 1][c]];

        if (config_a < config_b && config_a < config_c) 
            memo[i][j] = memo[i + 1][a];
        else if (config_b < config_c) 
            memo[i][j] = memo[i + 1][b];
        else 
            memo[i][j] = memo[i + 1][c];
    }
    
    return dp(memo, preferences, i - 1);
    
}

int main(){
	int n,m,config_a,config_b,config_c;
	cin >> n;
	while(n--){
		cin >> m;
        
        vector<vector<int>> preferences(m + 1, vector<int>(8,0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 0; j < 8; j++) 
                cin >> preferences[i][j];
        }
        
        // memo[i][j] = ending position if person i given starting position j
        vector<vector<int>> memo(m + 1, vector<int>(8,0));
		
		for (int i = 0; i < 8; i++){
            // incorrect bit flip implementation
            // int a = i ^ 0xb001;
            // int b = i ^ 0xb010;
            // int c = i ^ 0xb100;

            int a = bit_flip(i, 0);
            int b = bit_flip(i, 1);
            int c = bit_flip(i, 2);
            
			config_a = preferences[m][a];
			config_b = preferences[m][b];
			config_c = preferences[m][c];

			if (config_a < config_b && config_a < config_c) 
                memo[m][i] = a;
			else if (config_b < config_c) 
                memo[m][i] = b;
			else 
                memo[m][i] = c;
		}

        dp(memo, preferences, m - 1);
        
		cout << outcomes[memo[1][0]] << endl;
	}
	return 0;
}