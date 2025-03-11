#include <iostream>

using namespace std;

int main() {
    int n,r,x;
    cin >> n >> r;

    float minSum = (n - r) * -3;
    float maxSum = (n - r) * 3;

    for(int i = 0; i < r; i++) {
        cin >> x;
        minSum += x;
        maxSum += x;
    }

    cout << minSum / n << " " << maxSum / n << endl; 

    return 0;
}