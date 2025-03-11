#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

int main() {
    int n,k,x,t;
    cin >> n >> k;

    priority_queue<pair<int,int>> pq_neg;
    priority_queue<pair<int,int>> pq_pos;

    for(int i = 0; i < n; i++) {
        cin >> x >> t;
        if (x < 0)
            pq_neg.push({-x,t});
        else if (x > 0)
            pq_pos.push({x,t});
    }

    long long dist = 0;

    long long temp_dist = 0;
    int load = 0;
    bool passthru = false;
    while(true) {
        if(pq_neg.size() == 0)
            break;
        
        pair<int,int> p = pq_neg.top();
        pq_neg.pop();

        if (load + p.second < k) {
            if (!passthru) {
                temp_dist += 2 * p.first;
                // std::cout << "not passing thru, so adding 2 * " << p.first << endl;
            }
            
            load += p.second;
            passthru = true;
            
            // std::cout << "have some space left after adding " << p.second << " (load: " << load << ")" << endl;
        }
        else if (load + p.second == k) {
            if (!passthru) {
                temp_dist += 2 * p.first;
                // std::cout << "not passing thru, so adding 2 * " << p.first << endl;
            }

            load = 0;
            passthru = false;

            // std::cout << "have no space left after adding " << p.second << endl;
        }
        else if (load + p.second > k) {
            if (!passthru) {
                temp_dist += 2 * p.first;
                // std::cout << "not passing thru, so adding 2 * " << p.first << endl;
            }

            p.second -= k - load;
            pq_neg.push(p);
            
            load = 0;
            passthru = false;
            // std::cout << "need to come back to " << p.first << ", have " << p.second << " left" << endl;
        }
    }
    // std::cout << "temp_dist: " << temp_dist << endl;
    dist += temp_dist;

    temp_dist = 0;
    load = 0;
    passthru = false;
    while(true) {
        if(pq_pos.size() == 0)
            break;
        
        pair<int,int> p = pq_pos.top();
        pq_pos.pop();

        if (load + p.second < k) {
            if (!passthru) {
                temp_dist += 2 * p.first;
                // std::cout << "not passing thru, so adding 2 * " << p.first << endl;
            }
            
            load += p.second;
            passthru = true;
            
            // std::cout << "have some space left after adding " << p.second << " (load: " << load << ")" << endl;
        }
        else if (load + p.second == k) {
            if (!passthru) {
                temp_dist += 2 * p.first;
                // std::cout << "not passing thru, so adding 2 * " << p.first << endl;
            }

            load = 0;
            passthru = false;

            // std::cout << "have no space left after adding " << p.second << endl;
        }
        else if (load + p.second > k) {
            if (!passthru) {
                temp_dist += 2 * p.first;
                // std::cout << "not passing thru, so adding 2 * " << p.first << endl;
            }

            p.second -= k - load;
            pq_pos.push(p);
            
            load = 0;
            passthru = false;
            // std::cout << "need to come back to " << p.first << ", have " << p.second << " left" << endl;
        }
    }
    // std::cout << "temp_dist: " << temp_dist << endl;
    dist += temp_dist;

    std::cout << dist << endl;

    return 0;
}