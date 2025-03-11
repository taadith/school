#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const pair<string,deque<int>> &p1, const pair<string,deque<int>> &p2){
    // first go thru all elements of the vectors
    for(int i = 0; i < 10; i++) {
        if (p1.second[i] < p2.second[i])
            return true;
        else if (p1.second[i] == p2.second[i])
            continue;
        else
            return false;
    }
    return p1.first > p2.first;
}

deque<int> split(string s, char t) {
    // vector<string> vs;
    deque<int> di;
    // cout << "original string: " << s << endl;
    while(s.find(t) != string::npos) {
        size_t idx = s.find(t);
        string n = s.substr(0, idx);
        // cout << "split string: " << n << endl;
        if (n == "lower")
            di.push_back(1);
        else if (n == "middle")
            di.push_back(2);
        else if (n == "upper")
            di.push_back(3);
        // vs.push_back(n);
        s = s.substr(idx + 1);
        // cout << "new s: " << s << endl;
        
    }
    if (s == "lower")
        di.push_back(1);
    else if (s == "middle")
        di.push_back(2);
    else if (s == "upper")
        di.push_back(3);
    
    reverse(di.begin(), di.end());
    return di;
}

int main() {
    int t,n;

    cin >> t;
    while(t--) {
        // priority_queue<pair<long double,string>> pq;
        vector<pair<string,deque<int>>> vp;
        cin >> n;

        string name;
        string cat;
        string x;
        while(n--) {
            cin >> name >> cat >> x;

            name = name.substr(0, name.length() - 1);

            deque<int> di = split(cat,'-');
            int middles_needed = 10 - di.size();
            for(int i = 0; i < middles_needed; i++)
                di.push_back(2);
            
            // reverse(di.begin(), di.end());

            pair<string,deque<int>> p(name,di);
            vp.push_back(p);
        }

        sort(vp.begin(), vp.end(), cmp);
        reverse(vp.begin(), vp.end());

        for(unsigned int i = 0; i < vp.size(); i++) {
            cout << vp[i].first << endl;
                // for(unsigned long j = 0; j < vp[i].second.size(); j++)
                //     cout << "\tvalue at j: " << j << " , " << vp[i].second[j] << endl;
        }
            
        
        for(int i = 0; i < 30; i++)
            cout << "=";
        cout << endl;
    }



    return 0;
}