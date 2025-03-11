#include <iostream>
#include <vector>

using namespace std;

// approximately near max int value
const int BELLMAN_FORD_INF = 1e9;

const vector<pair<int, int>> directions = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int main(){
	// vector<vector<int>> dist_grid(30, vector<int>(30));
	vector<int> dist(900);
	
	int src_nodes[3600];
	int dest_nodes[3600];
	int weights[3600];
	
	vector<bool> reached(900);
	
	while(true) {
		int w, h;
        cin >> w >> h;
		if(w == 0) 
            break;

		int total_nodes = w * h;
		
		vector<vector<bool>> grave_locs(30, vector<bool>(30, false));
		vector<vector<bool>> hole_locs(30, vector<bool>(30, false));
		
		int g;
        cin >> g;
		for(int i = 0; i < g; i++){
			int grave_x, grave_y;
            cin >> grave_x >> grave_y;
			grave_locs[grave_x][grave_y] = true;
		}
		
		int holes;
		cin >> holes;
		
		int E = holes;
		
		// reading in graveyard
		for(int i = 0; i < holes; i++){
			int x1, y1, x2, y2, t;
            cin >> x1 >> y1 >> x2 >> y2 >> t;

			hole_locs[x1][y1] = true;

			src_nodes[i] = (x1 * h) + y1;
            dest_nodes[i] = (x2 * h) + y2;
            weights[i] = t;
		}

		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				if (grave_locs[i][j] || hole_locs[i][j] || (i == w - 1 && j == h - 1))
					continue;
				
				int from = (i * h) + j;
				for(int k = 0; k < 4; k++) {
					int r2 = i + directions[k].first;
					int c2 = j + directions[k].second;

					if (r2 >= 0 && r2 < w && c2 >= 0 && c2 < h && !grave_locs[r2][c2]) {
						src_nodes[E] = from; 
						dest_nodes[E] = (r2 * h) + c2; 
						weights[E] = 1;
						E++;
					}
				}
			}
		}
		
		// bellman-ford:
		for(int i = 0; i < total_nodes; i++) {
			dist[i] = BELLMAN_FORD_INF;
			reached[i] = false;
		}
	
		dist[0] = 0; 
		reached[0] = true;
		
		for(int i = 1; i < total_nodes; i++) {
			for(int e = 0; e < E; e++) {
				if (dist[src_nodes[e]] + weights[e] < dist[dest_nodes[e]]) {
					if (reached[src_nodes[e]])
						reached[dest_nodes[e]] = true;
					dist[dest_nodes[e]] = dist[src_nodes[e]] + weights[e];
				}
			}
		}

		bool never_passes_exit = false;
		for(int e = 0; e < E; e++){
			if(reached[src_nodes[e]] && dist[src_nodes[e]] + weights[e] < dist[dest_nodes[e]]){
				never_passes_exit = true;
				break;
			}
		}

		if (never_passes_exit)
			cout << "Never" << endl;
		else if(!reached[total_nodes - 1])
			cout << "Impossible" << endl;
		else
			cout << dist[total_nodes - 1] << endl;
	}

	return 0;
}