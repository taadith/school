#include <queue>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;

    // (start time, finish time)
    vector<pair<int, int>> requests;

    // (-finish time, start time)
    priority_queue<pair<int, int>> min_pq;

    for(int i = 0; i < n; i++) {
        int start_time, duration, finish_time;
        cin >> start_time >> duration;
        finish_time = start_time + duration;

        requests.push_back({start_time, finish_time});
    }
    sort(requests.begin(), requests.end());

    int saved_counter = 0;
    for(int i = 0; i < n; i++) {
        int &start_time = requests[i].first;
        int &end_time = requests[i].second;
        // int sign_off_time = requests[i].second + m;
        
        // cout << "current request:\n";
        // cout << "\tstart: " << start_time << endl;
        // cout << "\tend: " << end_time << endl;
        // cout << "\tsign-off time: " << end_time + m << endl << endl;

        while(!min_pq.empty() && (start_time > (-min_pq.top().first) + m)) {
            // cout << "popping workstation with..." << endl;
            // cout << "\tstart time: " << min_pq.top().second << endl;
            // cout << "\tfinish time: " << -min_pq.top().first << endl;
            // cout << "\tsign-off time: " << end_time + m << endl << endl;
            min_pq.pop();
        }
            
        
        if(!min_pq.empty() && (start_time >= -min_pq.top().first)) {
            // cout << "using workstation with finish time: " << -min_pq.top().first << endl;
            // cout << "\tsign-off time: " << -min_pq.top().first + m << endl << endl;
            saved_counter++;
            min_pq.pop();
        }

        min_pq.push({-end_time, start_time});
    }

    cout << saved_counter << endl;

    return 0;
}