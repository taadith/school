#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    long long n,t;
    cin >> n >> t;

    vector<long long> times_completed(n);

    long long a,b,c;
    cin >> a >> b >> c;

    cin >> times_completed[0];

    for(int i = 1; i < n; i++)
        times_completed[i] = (a * times_completed[i - 1] + b) % c + 1;
    sort(times_completed.begin(), times_completed.end());

    long long problems_solved = 0;
    long long sum_time_completed = 0;
    long long penalty = 0;
    for(int i = 0; i < n; i++) {
        if (sum_time_completed + times_completed[i] <= t) {
            problems_solved++;
            
            penalty += times_completed[i] + sum_time_completed;
            penalty %= (long long) 1e9 + 7;

            sum_time_completed += times_completed[i];
        }
        else
            break;
    }

    cout << problems_solved << " " << penalty << endl;

    return 0;
}