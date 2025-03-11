#include <vector>
#include <iostream>

using namespace std;

struct edge {
	int first;
	int second;
};

bool fully_connected(const vector<vector<int>> &graph, const int &n) {
	// create reach matrix
	vector<vector<bool>> reach(n, vector<bool>(n, false));

	// initialize matrix
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (graph[i][j] == 1)
				reach[i][j] = true;
		}
		reach[i][i] = true;
	}
	
	// floyd warshall
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
		}
	}

	// now check if all nodes are available from others
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (!reach[i][j])
				return false;
		}
	}

	return true;
}

int main() {
	int n,e;
	int i = 1;
	while(cin >> n && cin >> e) {
		vector<vector<int>> graph(n, vector<int>(n, -1));
		vector<edge> edges(e);

		for(int i = 0; i < e; i++) {
			int src, dest;
			cin >> src >> dest;
			
			graph[src][dest] = 1;
			edges[i].first = src;
			edges[i].second = dest;
		}

		cout << "Case " << i << ": ";
		if(fully_connected(graph, n))
			cout << "valid" << endl;
		else {
			bool close_to_fully_connected = false;
			for(int i = 0; i < e; i++) {
				int &src = edges[i].first;
				int &dest = edges[i].second;

				if (graph[src][dest] == 1 && graph[dest][src] == -1) {
					graph[src][dest] = -1;
					graph[dest][src] = 1;
				}
				else
					continue;
				
				if (fully_connected(graph, n)) {
					cout << src << " " << dest << endl;
					close_to_fully_connected = true;
				}

				if (close_to_fully_connected)
					break;
				else {
					graph[src][dest] = 1;
					graph[dest][src] = -1;
				}
			}
			
			// for(int i = 0; i < n; i++) {
			// 	for(int j = 0; j < n; j++) {
			// 		if (graph[i][j] == 1 && graph[j][i] == -1) {
			// 			graph[i][j] = -1;
			// 			graph[j][i] = 1;
			// 		}
			// 		else
			// 			continue;
					
			// 		if (fully_connected(graph, n)) {
			// 			cout << i << " " << j << endl;
			// 			close_to_fully_connected = true;
			// 		}

			// 		if (close_to_fully_connected)
			// 			break;
			// 		else {
			// 			graph[i][j] = 1;
			// 			graph[j][i] = -1;
			// 		}
			// 	}

			// 	if (close_to_fully_connected)
			// 		break;
			// }

			if (!close_to_fully_connected)
				cout << "invalid" << endl;

		}

		i++;
	}
	return 0;
}