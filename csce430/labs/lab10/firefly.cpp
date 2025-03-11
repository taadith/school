#include <iostream>
#include <vector>

using namespace std;

int main() {
    // fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, h;
    cin >> n >> h;

    vector<int> stalactites(h,0);
    vector<int> stalagmites(h,0);
    
    for(int i = 0; i < n; i++) {
        int obstacle_size;
        cin >> obstacle_size;
        if(i % 2 == 0)
            stalagmites[obstacle_size - 1]++;
        else
            stalactites[h - obstacle_size]++;
    }

    // can just use stalag & stalac as prefix sums
    for(int i = h - 2; i > -1; i--)
        stalagmites[i] += stalagmites[i + 1];
    
    for(int i = 1; i < h; i++)
        stalactites[i] += stalactites[i - 1];

    // count up min obstacles and occurences
    int min_obstacles = 500001;  // bigger than max height value
    int occurences = 0;
    for(int i = 0; i < h; i++) {
        if(stalactites[i] + stalagmites[i] < min_obstacles) {
            min_obstacles = stalactites[i] + stalagmites[i];
            occurences = 0;
        }
        if(stalactites[i] + stalagmites[i] == min_obstacles)
            occurences++;
    }
    
    cout << min_obstacles << " " << occurences << endl;
}