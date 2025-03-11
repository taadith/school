#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//union find implementation:
vector<long> parents;
// vector<long> maxsize;

long find(long x) {
    if (parents[x] == x)
        return x;
    else {
        parents[x] = find(parents[x]);
        return parents[x];
    }
}

void merge(long x, long y) {
    long a,b;
    a = find(x);
    b = find(y);
    
    if (a == b)
        return;
    parents[b] = a;

    // if (maxsize[a] == maxsize[b]) {
    //     parents[b] = a;
    //     maxsize[a]++;
    // }
    // else if (maxsize[a] > maxsize[b]) {
    //     parents[b] = a;
    // }
    // else if (maxsize[a] < maxsize[b]) {
    //     parents[a] = b;
    // }
}

int main() {
    long t;
    cin >> t;

    while(t--) {
        long max_milk;
        long number_of_cats;
        cin >> max_milk >> number_of_cats;
        
        parents.assign(number_of_cats, 0);
        for(long i = 0; i < number_of_cats; i++)
            parents[i] = i;
        
        // (weight, (node 1, node 2))
        priority_queue<pair<long, pair<long, long>>> pq;
        for(long i = 0; i < (number_of_cats * (number_of_cats - 1) / 2); i++) {
            long n1, n2, w;
            cin >> n1 >> n2 >> w;
            pq.push({-w, {n1, n2}});
        }

        long mst_edges = 0;
        long total_milk_used = number_of_cats;
        while(mst_edges < number_of_cats - 1) {
            pair<long, pair<long, long>> p = pq.top();
            pq.pop();
            if (find(p.second.first) != find(p.second.second)) {
                merge(p.second.first, p.second.second);
                mst_edges++;
                total_milk_used += -p.first;
            }
        }

        if (max_milk >= total_milk_used)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

    }

    return 0;
}