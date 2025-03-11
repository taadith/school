#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    unordered_map<int,pair<int,int>> um;
    // -score (min heap), +penalty (max heap), team #
    priority_queue<pair<int,pair<int,int>>> pq;
    
    um.emplace(1,pair<int,int>(0,0));

    int a,b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        if (um.count(a) == 0)
            um.emplace(a,pair<int,int>(-1,b));
        else if (a == 1) {
            um.at(1).first++;
            um.at(1).second += b;
            
            // TODO: check pq
            while(true) {
                if ((-1 * pq.top().first)) {

                }
                break;
            }
        }
        else {
            um.at(a).first++;
            um.at(a).second += b;

            if ((um.at(a).first > um.at(1).first) || ((um.at(a).first == um.at(1).first) && um.at(a).second < um.at(1).second)) {
                pair<int,int> p(um.at(a).second,a);
                pair<int,pair<int,int>> pp(-1 * um.at(a).first,p);
                pq.push(pp);
            }
        }
        
        cout << pq.size() + 1 << endl;
    }
    
}