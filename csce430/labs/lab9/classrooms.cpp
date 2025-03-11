#include <vector>
#include <set>
#include <iostream>

#include <algorithm>

using namespace std;

int main() {
    // super fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    // (end time, start time)
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        int start_time, end_time;
        cin >> start_time >> end_time;
        activities.push_back({end_time, start_time});
    }

    sort(activities.begin(), activities.end());

    int scheduled_activities = 0;
    multiset<int> ms;
    for (int i = 0; i < k; i++) 
        ms.insert(0);
    
    for(int i = 0; i < n; i++) {
        pair<int, int> &activity = activities[i];
        int start_time = activity.second;
        int end_time = activity.first;
        multiset<int>::iterator ms_it = ms.upper_bound(start_time);

        if (ms_it != ms.begin()) {
            ms.erase(prev(ms_it));
            ms.insert(end_time + 1);
            scheduled_activities++;
        }
    }

    cout << scheduled_activities << endl;

	return 0;
}