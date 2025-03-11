#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

#include <cmath>

#include <iostream>
#include <sstream>

using namespace std;

// (spoken language, (occurences, understood languages))
unordered_map<string, pair<int, vector<string>>> graph;

// edges are reversed
unordered_map<string, pair<int, vector<string>>> transposed_graph;

// for dfs
unordered_set<string> spoken_languages;
stack<string> decreasing_exit_time_nodes;

unordered_set<string> visited_nodes;

void modified_dfs(string curr_node) {
    // cout << "forward dfs" << endl;

    if (visited_nodes.count(curr_node) > 0)
        return;
    
    visited_nodes.insert(curr_node);

    for(unsigned int i = 0; i < graph[curr_node].second.size(); i++) {
        string &next_node = graph[curr_node].second[i];
        modified_dfs(next_node);
    }

    decreasing_exit_time_nodes.push(curr_node);
}

void transpose_dfs(vector<string> &vs, string &curr_node) {
    // cout << "reverse dfs" << endl;
    
    if (visited_nodes.count(curr_node) > 0)
        return;
    
    visited_nodes.insert(curr_node);
    vs.push_back(curr_node);

    for(unsigned int i = 0; i < transposed_graph[curr_node].second.size(); i++) {
        string &next_node = transposed_graph[curr_node].second[i];
        transpose_dfs(vs, next_node);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string filler, spoken_language;
        cin >> filler >> spoken_language;

        spoken_languages.insert(spoken_language);

        graph[spoken_language].first++;
        transposed_graph[spoken_language].first++;

        // grab understood languages overall string
        string remaining_understood_languages;
        getline(cin, remaining_understood_languages);

        // split string and feed to respective vector
        stringstream ss(remaining_understood_languages);
        string understood_language;
        while(ss >> understood_language) {
            // cout << "reading in understood languages" << endl;
            graph[spoken_language].second.push_back(understood_language);
            transposed_graph[understood_language].second.push_back(spoken_language);
        }
    }

    unordered_set<string>::iterator uss_it;
    for(uss_it = spoken_languages.begin(); uss_it != spoken_languages.end(); uss_it++) {
        // cout << *uss_it << endl;
        
        if(visited_nodes.count(*uss_it) > 0)
            continue;
        else
            modified_dfs(*uss_it);
    }

    visited_nodes.clear();
    int max_nodes_in_scc = 0;
    while(!decreasing_exit_time_nodes.empty()) {
        string curr_node = decreasing_exit_time_nodes.top();
        decreasing_exit_time_nodes.pop();

        if (visited_nodes.count(curr_node) > 0)
            continue;

        vector<string> comp_vector;
        transpose_dfs(comp_vector, curr_node);

        int current_scc_size = 0;
        for(unsigned int i = 0; i < comp_vector.size(); i++) {
            string &x = comp_vector[i];
            current_scc_size += graph[x].first;
        }

        max_nodes_in_scc = max(current_scc_size, max_nodes_in_scc);
    }

    cout << n - max_nodes_in_scc << endl;
}