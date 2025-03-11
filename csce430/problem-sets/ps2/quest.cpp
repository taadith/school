#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
    // FAST IO:
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string op;
    int e,g;
    map<int, priority_queue<int>> m;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++) {
        cin >> op;
        if (op == "add") {
            cin >> e >> g;
            if(m.count(e) == 0)
                m.emplace( e,priority_queue<int>());
            // cout << "adding quest w/ " << e << " energy for " << g << " gold" << endl;
            // pair<int,int> p(e,g);
            // pq.push(p);
            m.at(e).push(g);
        }
        if (op == "query") {
            long long g_sum = 0;
            map<int,priority_queue<int>>::iterator map_iterator = m.end();
            cin >> e;
            // cout << "querying quests with " << e << " energy" << endl;
            // vector<pair<int,int>> v;
            while(m.size() != 0) {
                // grabs the lowest value at or above e
                map_iterator = m.lower_bound(e);

                // if this is the end, we go one below
                if (map_iterator == m.end())
                    map_iterator--;

                while(map_iterator -> first > e && map_iterator != m.begin())
                    map_iterator--;
                
                if (map_iterator -> first > e)
                    break;

                e -= map_iterator -> first;  
                g_sum += map_iterator -> second.top();
                map_iterator -> second.pop();

                if (map_iterator -> second.size() == 0)
                    m.erase(map_iterator);
            }
            
            cout << g_sum << endl;      
        }
    }

    return 0;
}