#include <iostream>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main() {
    long long n,m,p,c;
    cin >> n >> m;
    priority_queue<pair<long long,pair<long long, long long>>> pq;
    for(int i = 0; i < n; i++) {
        cin >> p >> c;
        long long d = ceil((c + m) / p);
        pair<long long, long long> pear = make_pair(p,c);
        pair<long long, pair<long long, long long>> pearpear = make_pair(-1 * d,pear);
        pq.push(pearpear);
    }
    long long min;
    min = -1 * pq.top().first;
    long long pmin = ceil((m + pq.top().second.second + pq.pop().top().second.second)/(pq.top().second.first + pq.pop().top().second.first));
}