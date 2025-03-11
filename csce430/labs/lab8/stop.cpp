#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    double sum = 0;
    double avg = 0;
    for(int i = 0; i < n; i++) {
        sum += v[i];
        avg = max(avg, sum / (i + 1.0));
    }

    sum = 0;
    for(int i = n - 1; i > -1; i--) {
        sum += v[i];
        avg = max(avg, sum / ((n - i - 1) + 1.0));
    }

    cout << fixed << setprecision(9) << avg << endl;

    return 0;
}