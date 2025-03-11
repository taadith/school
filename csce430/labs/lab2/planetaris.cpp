#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n,a,e;
    cin >> n >> a;
    
    vector<long long> ships;
    for(int i = 0; i < n; i++) {
        cin >> e;
        ships.push_back(e);
    }

    sort(ships.begin(), ships.end());

    int ship;
    int wins = 0;
    for(int i = 0; i < n; i++) {
        ship = ships[i];
        if (ship + 1 <= a) {
            a -= ship + 1;
            wins++;
        }
            
    }

    cout << wins << endl;

    return 0;
}