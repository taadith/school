#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<double, string>> first_lap(n);
    vector<pair<double, string>> other_laps(n);
    for(int i = 0; i < n; i++) {
        string player;
        cin >> player;

        cin >> first_lap[i].first >> other_laps[i].first;

        first_lap[i].second = player;
        other_laps[i].second = player;
    }

    sort(first_lap.begin(), first_lap.end());
    sort(other_laps.begin(), other_laps.end());
    
    vector<string> winning_config;
    double min_time = 20000.0;
    for(int i = 0; i < n; i++) {
        vector<string> temp_config;
        temp_config.push_back(first_lap[i].second);
        double temp_time = first_lap[i].first;
        
        int runners = 0;
        for(int j = 0; j < n; j++) {
            if (other_laps[j].second == first_lap[i].second)
                continue;
            
            temp_time += other_laps[j].first;
            temp_config.push_back(other_laps[j].second);
            runners++;

            if (runners == 3)
                break;
        }

        if (temp_time < min_time) {
            min_time = temp_time;
            winning_config = temp_config;
        }
    }

    cout << min_time << endl;
    for(int i = 0; i < 4; i++)
        cout << setprecision(10) << winning_config[i] << endl;

    return 0;
}