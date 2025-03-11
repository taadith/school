#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long n,m;
    cin >> n >> m;

    long total_of_mst_edges = 0;
    long number_of_nodes = 2;

    long current_weight = 1;

    while (number_of_nodes <= n) {
        total_of_mst_edges += current_weight;

        current_weight++;
        m--;

        long used_edges = max((long) 0, number_of_nodes - 2);
        long needed_edges = n - number_of_nodes;

        used_edges = min(used_edges, m - needed_edges);

        m -= used_edges;
        current_weight += used_edges;

        number_of_nodes++;
    }

    cout << total_of_mst_edges << endl;

    return 0;
}