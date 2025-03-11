#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n != 0) {
        // read in all luggage
        vector<int> dims(n);
        for(int i = 0; i < n; i++)
            cin >> dims[i];
        
        // sort luggage from smallest to greatest
        sort(dims.begin(), dims.end());


        // calculate mode of luggages
        priority_queue<pair<int,int>> pq;
        int mode = 0;
        int val = dims[0];
        int val_mode = 1;
        for(int i = 1; i < n; i++) {
            if (dims[i] == val)
                val_mode++;
            else {
                if (val_mode > mode)
                    mode = val_mode;
                pq.push(pair<int,int>(val_mode, val));
                // cout << val << " has " << val_mode << " occurence(s)!\n";
                val = dims[i];
                val_mode = 1;
            }
        }
        // for last value:
        // cout << val << " has " << val_mode << " occurence(s)!\n";
        pq.push(pair<int,int>(val_mode,val));
        if (val_mode > mode)
            mode = val_mode;
        
        cout << mode << "\n";

        vector<vector<int>> vv(mode, vector<int>());

        int i = 0;
        while(pq.size() != 0) {
            pair<int,int> p = pq.top();

            for(int j = 0; j < p.first;j++)
                vv[(i + j) % mode].push_back(p.second);
            
            i += p.first;

            pq.pop();
        }

        for(int i = 0; i < mode; i++) {
            for(unsigned long j = 0; j < vv[i].size(); j++)
                cout << vv[i][j] << " ";
            cout << endl;
        }


        cin >> n;
    }
}