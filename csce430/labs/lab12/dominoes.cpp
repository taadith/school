#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node {
    vector<int> adj;
    int value;
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int domino_tiles,connections,num_by_hand;

        cin >> domino_tiles;
        vector<node> adj_list(domino_tiles + 1);
        
        cin >> connections >> num_by_hand;
        for(int i = 0; i < connections; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            adj_list[n1].adj.push_back(n2);
        }
        
        vector<int> hand_dominoes(num_by_hand);
        for(int i = 0; i < num_by_hand; i++)
            cin >> hand_dominoes[i];

        // BFS time!
        int max_reached_nodes = 0;
        for(int i = 1; i < domino_tiles + 1; i++)
            adj_list[i].value = -1;

        for(int i = 0; i < num_by_hand; i++) {

            //BFS
            queue<int> q;
            q.push(hand_dominoes[i]);
            while(!q.empty()) {
                int a = q.front();
                q.pop();
                if (adj_list[a].value == 0)
                    continue;
                adj_list[a].value = 0;
                max_reached_nodes++;
                // cout << "encountered node " << a << " at time " << time << endl;
                for(unsigned int i = 0; i < adj_list[a].adj.size(); i++) {
                    int b = adj_list[a].adj[i];
                    if (adj_list[b].value == -1)
                        q.push(b);
                }
            }
        }

        cout << max_reached_nodes << endl;
    }

    return 0;
}