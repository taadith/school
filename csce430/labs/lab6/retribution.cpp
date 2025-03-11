#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

long double compute_dist(pair<int,int> &p1, pair<int,int> &p2) {
    return sqrt((pow(p1.first - p2.first, 2)/1.0) + (pow(p1.second - p2.second, 2) / 1.0));
}

int main() {
    int judges, tar_repos, feather_stores;
    cin >> judges >> tar_repos >> feather_stores;

    // cout << "creating jlocs" << endl;
    vector<pair<int,int>> jlocs(judges);
    for(int i = 0; i < judges; i++)
        cin >> jlocs[i].first >> jlocs[i].second;
    
    // cout << "creating tlocs" << endl;
    vector<pair<int,int>> tlocs(tar_repos);
    for(int i = 0; i < tar_repos; i++)
        cin >> tlocs[i].first >> tlocs[i].second;
    
    // cout << "creating flocs" << endl;
    vector<pair<int,int>> flocs(feather_stores);
    for(int i = 0; i < feather_stores; i++)
        cin >> flocs[i].first >> flocs[i].second;
    
    // cout << "creating judges_tar" << endl;
    priority_queue<pair<long double,pair<int,int>>> judges_tar;
    for(int j = 0; j < judges; j++) {
        for(int t = 0; t < tar_repos; t++) {
            pair<int,int> p(j,t);
            pair<long double,pair<int,int>> pp(-1 * compute_dist(jlocs[j], tlocs[t]),p);
            judges_tar.push(pp);
        }
    }

    // cout << "creating judges_feathers" << endl;
    priority_queue<pair<long double,pair<int,int>>> judges_feathers;
    for(int j = 0; j < judges; j++) {
        for(int f = 0; f < feather_stores; f++) {
            pair<int,int> p(j,f);
            pair<long double, pair<int, int>> pp(-1 * compute_dist(jlocs[j], flocs[f]), p);
            judges_feathers.push(pp);
        }
    }

    long double dist = 0.0;

    vector<bool> judges_used(judges,false);
    vector<bool> tar_repos_used(tar_repos, false);
    while(true) {
        if (judges_tar.size() == 0)
            break;
        
        pair<long double, pair<int,int>> pp = judges_tar.top();
        if (judges_used[pp.second.first] || tar_repos_used[pp.second.second]) {

        }
        else {
            judges_used[pp.second.first] = true;
            tar_repos_used[pp.second.second] = true;
            dist += -pp.first;
        }
        judges_tar.pop();
    }
    
    judges_used.assign(judges, false);
    vector<bool> feather_stores_used(feather_stores, false);
    while(true) {
        if (judges_feathers.size() == 0)
            break;
        
        pair<long double, pair<int,int>> pp = judges_feathers.top();
        if (judges_used[pp.second.first] || tar_repos_used[pp.second.second]) {

        }
        else {
            judges_used[pp.second.first] = true;
            feather_stores_used[pp.second.second] = true;
            dist += -pp.first;
        }
        judges_feathers.pop();
    }

    cout << dist << endl;

    return 0;
}